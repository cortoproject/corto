/*
 * db_ic_assemble.c
 *
 *  Created on: Aug 28, 2013
 *      Author: sander
 */

#include "db_ic.h"
#include "db_ll.h"
#include "db_mem.h"
#include "db_util.h"
#include "db_err.h"
#include "db__meta.h"
#include "db_value.h"
#include "db__vm_operands.h"
#include "db_object.h"
#include "db_struct.h"

typedef struct db_ic_vmLabel {
	db_uint32 id;
	db_uint32 pc;
	void *referees[256]; /* The jumps to this label. At assemble-time, the exact address of the label is not yet known
	                      * so this information is filled in after the program is assembled for each referee */
	db_uint32 refereeCount;
}db_ic_vmLabel;

typedef struct db_ic_vmStorage db_ic_vmStorage;
struct db_ic_vmStorage {
    db_icStorage accumulator;
    db_uint32 firstUsed;
    db_uint32 lastUsed;
    void *referees[256]; /* The jumps to this accumulator. At assemble-time, the exact address of the accumulator is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    db_uint32 refereeCount;
    db_uint16 addr;

    /* Member & element accumulators have a base and offset */
    db_uint16 offset;
    db_ic_vmStorage *base;
    db_bool assembled; /* Offsets of multiple member-operations are accumulated into one register so that
    					* instead of calculating multiple offsets at runtime, only one operation is required. This
    					* variable remains FALSE until the storage is used after which an operation is inserted
    					* to calculate the accumulated offset.
    					* This is only applicable for access to dynamically allocated objects or storages with dynamic
    					* components (elements with variable indexes). By default this value is TRUE. */
    db_bool dynamic;   /* A dynamic storage needs to be assembled each time it is evaluated because the storage depends
                        * on the value of other storages, for example the index-expression of an element storage. */
};

typedef struct db_ic_vmInlineFunction {
    db_vmProgram program;
    db_function function;
}db_ic_vmInlineFunction;

typedef struct db_ic_vmProgram {
	db_icProgram icProgram;
    db_vmProgram main; /* Keep track of what is the main-module of a program (where the program starts) */
	db_vmProgram program;
	db_icFunction function;
	db_ll labels;
	db_ll accumulators;
	db_ll inlineFunctions;
	db_uint16 scopeSize[256];
	db_uint32 scope;
	db_uint32 maxScopeSize; /* The maximum scope-size is where accumulators are allocated (thus after the locals) */
	db_uint32 stackSize;
	db_uint32 maxStackSize; /* The maximum stack-size is the maximum amount of space a call needs for its arguments */
}db_ic_vmProgram;

typedef enum db_ic_vmType {
	DB_IC_VMTYPE_B,
	DB_IC_VMTYPE_S,
	DB_IC_VMTYPE_L,
	DB_IC_VMTYPE_D
}db_ic_vmType;

typedef enum db_ic_vmOperand {
	DB_IC_VMOPERAND_NONE,
	DB_IC_VMOPERAND_V,
	DB_IC_VMOPERAND_R,
	DB_IC_VMOPERAND_P,
	DB_IC_VMOPERAND_Q,
	DB_IC_VMOPERAND_X,
	DB_IC_VMOPERAND_L
}db_ic_vmOperand;

db_string db_ic_vmOperandStr(db_ic_vmOperand op) {
    switch(op) {
        case DB_IC_VMOPERAND_NONE: return "none";
        case DB_IC_VMOPERAND_V: return "V";
        case DB_IC_VMOPERAND_R: return "R";
        case DB_IC_VMOPERAND_P: return "P";
        case DB_IC_VMOPERAND_Q: return "Q";
        case DB_IC_VMOPERAND_X: return "X";
        case DB_IC_VMOPERAND_L: return "L";
    };
    return "<?>";
}

static db_ic_vmStorage *db_ic_vmStorageGet(db_ic_vmProgram *program, db_icStorage icAccumulator);

static void db_ic_vmProgram_fillInLabels(db_ic_vmProgram *program) {
    db_iter labelIter;
    db_ic_vmLabel *label;
    db_uint32 referee;

    if (program->labels) {
        labelIter = db_llIter(program->labels);
        while(db_iterHasNext(&labelIter)) {
            label = db_iterNext(&labelIter);
            for(referee=0; referee < label->refereeCount; referee++) {
                *(void**)DB_OFFSET(label->referees[referee], program->program->program) = &program->program->program[label->pc];
            }

            /* Free label */
            db_dealloc(label);
        }

        /* Free label list */
        db_llFree(program->labels);
        program->labels = NULL;
    }
}

/* Administration that keeps track of claims accumulators have on the register */
typedef struct db_ic_registerClaim {
    db_ic_vmStorage *accumulator;
    db_uint16 addr;
    db_uint16 size;
    db_uint32 start;
    db_uint32 end;
}db_ic_registerClaim;

/* Determine whether storage is of a reference type or passed by reference. */
db_bool db_ic_isReference(db_icStorage storage) {
	db_type t = storage->type;
	db_bool result = FALSE;

	if (storage->isReference) {
		result = TRUE;
	} else {
		if (storage->kind == DB_STORAGE_LOCAL) {
			if (((db_icLocal)storage)->isParameter) {
				if (t->kind != DB_PRIMITIVE) {
					result = TRUE;
				}
			}
		}
	}

	return result;
}

/* Determine whether for a storage space must be allocated or whether a storage is pointing
 * directly to an object\local. */
db_bool db_ic_storageMustAllocate(db_ic_vmProgram *program, db_ic_vmStorage *accumulator, db_bool *collapsed) {
	db_bool result = FALSE;

	/* Accumulator must be referred otherwise it should not take up space */
	if (accumulator->refereeCount) {
        db_icStorageKind kind = accumulator->accumulator->kind;

        /* Accumulators must always be allocated */
        if (kind == DB_STORAGE_ACCUMULATOR) {
        	result = TRUE;
        } else {
        	if ((kind == DB_STORAGE_MEMBER) || (kind == DB_STORAGE_ELEMENT)) {
        		db_bool collapse = FALSE;
        		db_icStorage base = accumulator->base->accumulator;

        		/* Determine whether accumulator must be collapsed with base because its offset
        		 * is zero. Only applicable for member-storages and element-storages of which the
        		 * collection-type is an ARRAY. In these cases the calculated address with offset
        		 * zero is equal to the base-address. */
        		if (!accumulator->offset) {
        			if (kind == DB_STORAGE_MEMBER) {
        				collapse = TRUE;
        			} else {
        				db_collection type = db_collection(accumulator->accumulator->type);
        				switch(type->kind) {
        				case DB_ARRAY:
        					collapse = TRUE;
        					break;
        				default:
        					break;
        				}
        			}
        		}
        		if (collapsed) {
        			*collapsed = collapse;
        		}

        		/* If the base is of a reference type and the base is not an object, address
        		 * is stored in an accumulator for which space must be allocated. If the offset of the
        		 * member is zero do not allocate the accumulator, instead use the base (see below). */
        		if (!collapse && (db_ic_isReference(base) && (base->kind != DB_STORAGE_OBJECT))) {
        			result = TRUE;

        		/* If storage is dynamic, address must be temporarily stored in an accumulator
        		 * for which space must be allocated. */
        		} else if (accumulator->dynamic) {
        			result = TRUE;
        		} else {
        		    db_uint32 referee;
                    /* If base is dynamic or offset is 0 (meaning address is equal to base), collapse this accumulator into the base. */
                    for(referee=0; referee < accumulator->refereeCount; referee++) {
                        *(db_uint16*)DB_OFFSET(accumulator->referees[referee], program->program->program) = accumulator->base->addr;
                        if(!accumulator->base->dynamic) {
                            *(db_uint16*)DB_OFFSET(accumulator->referees[referee], program->program->program) += accumulator->offset;
                        }
                    }
                    /* No need to allocate this accumulator */
                    result = FALSE;
        		}
        	}
        }
	}

	return result;
}

static void db_ic_vmProgram_allocateAccumulators(db_ic_vmProgram *program) {
    db_iter accumulatorIter;
    db_ic_vmStorage *accumulator;
    db_uint16 offset;
    db_ic_registerClaim claims[256];
    db_ic_registerClaim *claim;
    db_uint32 i, referee;
    db_bool overlap;

    memset(claims, 0, sizeof(claims));
    offset = program->maxScopeSize;

    if (program->accumulators) {
        accumulatorIter = db_llIter(program->accumulators);
        while(db_iterHasNext(&accumulatorIter)) {
            accumulator = db_iterNext(&accumulatorIter);

            if (db_ic_storageMustAllocate(program, accumulator, NULL)) {
            	/* Find lfree claim */
                claim = claims;
                while(claim->accumulator) {
                    if (claim->end < accumulator->firstUsed) { /* Accumulators are chronologically ordered, so this is valid */
                        break;
                    }
                    claim++;
                }

                claim->accumulator = accumulator;
                claim->start = accumulator->firstUsed;
                claim->end = accumulator->lastUsed;
                claim->addr = offset;
                
                /* If accumulator has to be allocated and it has a base, accumulator represents a member address */
                if (accumulator->base) {
                    claim->size = sizeof(db_word);
                } else {
                    claim->size = db_type_sizeof(accumulator->accumulator->type);
                }
                /* Find free register */
                do {
                    overlap = FALSE;
                    for(i=0; i<256; i++) {
                        /* If claim has expired, remove from list */
                        if (claims[i].end < claim->start) {
                            claims[i].end = 0;
                            continue;
                        }

                        /* Check if claim overlaps with this claim */
                        if ( (claim != &claims[i]) && ((claims[i].end >= claim->start) || (claims[i].start <= claim->end)) ) {
                            /* Check if claim overlaps address */
                            if ( ((claims[i].addr + claims[i].size) > claim->addr) && (claims[i].addr < (claim->addr + claim->size)) ) {
                                /* Choose new address and try again */
                                claim->addr = claims[i].addr + claims[i].size;
                                overlap = TRUE;
                                break;
                            }
                        }
                    }
                }while (overlap);

                if ((claim->addr + claim->size) > program->maxScopeSize) {
                    program->maxScopeSize = claim->addr + claim->size;
                }

            	/* Walk referees */
                for(referee=0; referee < accumulator->refereeCount; referee++) {
                    *(db_uint16*)DB_OFFSET(accumulator->referees[referee], program->program->program) = claim->addr;
                }
                accumulator->addr = claim->addr;
            }
        }

        /* Free resources */
        accumulatorIter = db_llIter(program->accumulators);
        while(db_iterHasNext(&accumulatorIter)) {
            accumulator = db_iterNext(&accumulatorIter);
            db_dealloc(accumulator);
        }
        db_llFree(program->accumulators);
        program->accumulators = NULL;
    }
}

void db_ic_vmProgram_clean(db_ic_vmProgram *vmProgram) {
    /* Reset values */
    vmProgram->scope = 0;
    vmProgram->maxScopeSize = 0;
    vmProgram->stackSize = 0;
    vmProgram->maxStackSize = 0;
    vmProgram->program = NULL;
}

extern db_bool DB_DEBUG_ENABLED;

void db_ic_vmProgram_finalize(db_ic_vmProgram *vmProgram) {
    db_vmOp  *stop;

    /* Add STOP instruction if this is the main-module */
    if (vmProgram->main == vmProgram->program) {
        stop = db_vmProgram_addOp(vmProgram->program, 0);
        stop->op = DB_VM_STOP;
    }

    /* Fill in labels */
    db_ic_vmProgram_fillInLabels(vmProgram);

    /* Allocate and fill in accumulators */
    db_ic_vmProgram_allocateAccumulators(vmProgram);

    /* Set size of program */
    vmProgram->program->storage = vmProgram->maxScopeSize;
    vmProgram->program->stack = vmProgram->maxStackSize;

    /* If program is a function, set the function-implementation to the program */
    if (vmProgram->function) {
        db_function function = vmProgram->function->function;
        function->impl = (db_word)vmProgram->program;
        db_define(function);

#ifdef DB_IC_TRACING
        if (DB_DEBUG_ENABLED)
        {
            db_id id;
            db_string programStr = db_vmProgram_toString(vmProgram->program, NULL);
            printf("%s %s\n%s\n", db_nameof(db_typeof(function)), db_fullname(function, id), programStr);
            db_dealloc(programStr);
        }
#endif
    }

#ifdef DB_IC_TRACING
    if (DB_DEBUG_ENABLED) {
        if (vmProgram->main == vmProgram->program) {
            db_string programStr = db_vmProgram_toString(vmProgram->program, NULL);
            printf("main\n%s\n", programStr);
            db_dealloc(programStr);
        }
    }
#endif

    /* Clean resources */
    db_ic_vmProgram_clean(vmProgram);
}

static db_ic_vmLabel *db_ic_vmLabelNew(db_uint32 id) {
	db_ic_vmLabel *result;

	result = db_malloc(sizeof(db_ic_vmLabel));
	result->id = id;
	result->pc = 0;
	result->refereeCount = 0;

	return result;
}

static db_ic_vmLabel *db_ic_vmLabelGet(db_ic_vmProgram *program, db_uint32 id) {
	db_iter labelIter;
	db_ic_vmLabel *label = NULL;

	if (program->labels) {
		labelIter = db_llIter(program->labels);
		while(db_iterHasNext(&labelIter)) {
			label = db_iterNext(&labelIter);
			if (label->id == id) {
				break;
			} else {
				label = NULL;
			}
		}
	}

	if (!label) {
		label = db_ic_vmLabelNew(id);
		if (!program->labels) {
			program->labels = db_llNew();
		}
		db_llAppend(program->labels, label);
	}

	return label;
}

static void db_ic_vmLabelAddReferee(db_ic_vmProgram *program, db_ic_vmLabel *label, void *referee) {
    label->referees[label->refereeCount] = DB_OFFSET(referee, -(intptr_t)program->program->program);;
    db_assert(label->refereeCount < 256, "unsupported number of references to one label (max is 256)");
    label->refereeCount++;
}

static db_ic_vmStorage *db_ic_vmStorageNew(db_ic_vmProgram *program, db_icStorage accumulator, db_uint32 firstUsed) {
    db_ic_vmStorage *result;

    result = db_malloc(sizeof(db_ic_vmStorage));
    result->accumulator = accumulator;
    result->refereeCount = 0;
    result->firstUsed = firstUsed;
    result->addr = 0;
    result->offset = 0;
    result->base = NULL;
    result->dynamic = FALSE;
    result->assembled = TRUE;

    if (accumulator->kind == DB_STORAGE_MEMBER) {
        db_icMember member = ((db_icMember)accumulator);
    	result->assembled = FALSE;

    	if (member->base) {
    		result->base = db_ic_vmStorageGet(program, member->base);
    		if (member->member) {
    		    result->offset = result->base->offset + member->member->offset;
    		}

    		if (!result->base->dynamic && result->base->base) {
    		    result->base = result->base->base;
    		}
       	}
    } else if (accumulator->kind == DB_STORAGE_ELEMENT) {
        db_icElement element = ((db_icElement)accumulator);
        result->assembled = FALSE;

        if (element->base) {
        	result->base = db_ic_vmStorageGet(program, element->base);

        	/* If element is an array and index-expression is a literal, offset is determined at compile-time. */
            if (element->index->_parent.kind == DB_IC_LITERAL) {
                if (element->collectionType->kind == DB_ARRAY) {
            		db_uint32 index = ((db_icLiteral)element->index)->value.is.literal.v._unsigned_integer;
            		result->offset = index * db_type_sizeof(element->collectionType->elementType->real);
                    result->dynamic = FALSE;
            	} else {
            		result->dynamic = TRUE;
            	}
            } else {
                result->dynamic = TRUE;

                /* Inherit the offset of the base. The actual offset is determined at runtime but this static offset will be added at
                 * compile-time. Setting this offset on a dynamic storage negates the need to set base to any member\element storages
                 * rather than just the dynamic storages and variable storages. */
                result->offset = result->base->offset;
            }
            
            result->offset += result->base->offset;

     		if (!result->base->dynamic && result->base->base) {
    		    result->base = result->base->base;
    		}
        }
     }
    
    /* Now the base of a member or element always points to either the variable or the first encountered dynamic storage.
     * Storages which are itself dynamic or storages with a dynamic base must always be evaluated for accumulator-allocation. */

    return result;
}

static void db_ic_vmStorageAddReferee(db_ic_vmProgram *program, db_ic_vmStorage *accumulator, void *referee) {
    accumulator->referees[accumulator->refereeCount] = DB_OFFSET(referee, -(intptr_t)program->program->program);
    db_assert(accumulator->refereeCount < 256, "unsupported number of references to one accumulator (max is 256)");
    accumulator->refereeCount++;
}

static db_ic_vmStorage *db_ic_vmStorageGet(db_ic_vmProgram *program, db_icStorage icAccumulator) {
    db_iter accumulatorIter;
    db_ic_vmStorage *accumulator = NULL;

    if (program->accumulators) {
        accumulatorIter = db_llIter(program->accumulators);
        while(db_iterHasNext(&accumulatorIter)) {
            accumulator = db_iterNext(&accumulatorIter);
            if (accumulator->accumulator == icAccumulator) {
                break;
            } else {
                accumulator = NULL;
            }
        }
    }

    if (!accumulator) {
    	if (!program->program) {
    		program->program = db_vmProgram_new(program->icProgram->filename, program->function->function);
    	}
        accumulator = db_ic_vmStorageNew(program, icAccumulator, program->program->size);
        if (!program->accumulators) {
            program->accumulators = db_llNew();
        }
        db_llAppend(program->accumulators, accumulator);
    }

    /* Keep track of where an accumulator is last used */
    accumulator->lastUsed = program->program->size;

    return accumulator;
}

db_type db_ic_valueType(db_icValue s) {
	db_type t = NULL;

	switch(s->_parent.kind) {
	case DB_IC_LITERAL:
		t = ((db_icLiteral)s)->type;
		break;
	case DB_IC_STORAGE:
		t = ((db_icStorage)s)->type;
		break;
	default:
		db_assert(0, "invalid operand type");
		break;
	}

	return t;
}

db_void *db_ic_valueValue_width(db_ic_vmProgram *program, db_icValue s, void* truncated, int width) {
	void *result = NULL;

	switch(s->_parent.kind) {
	case DB_IC_LITERAL: {
	    db_value *v = &((db_icLiteral)s)->value;
	    switch(v->is.literal.kind) {
	    case DB_LITERAL_BOOLEAN:
	    	*(db_uint16*)truncated = *(db_bool*)db_valueValue(v);
	    	result = truncated;
	    	break;
	    case DB_LITERAL_FLOATING_POINT:
	        if (width == sizeof(db_float32)) {
	            if (truncated) {
	                *(db_float32*)truncated = *(db_float64*)db_valueValue(v);
	                result = truncated;
	            } else {
	                result = db_valueValue(v);
	            }
	        } else {
	            result = db_valueValue(v);
	        }
	        break;
	    case DB_LITERAL_NULL:
	    	*(db_uint32*)truncated = 0;
	    	result = truncated;
	    	break;
	    default:
	        result = db_valueValue(v);
	        break;
	    }
		break;
	}
	case DB_IC_STORAGE:
		switch(((db_icStorage)s)->kind) {
		case DB_STORAGE_OBJECT:
			result = &((db_icObject)s)->ptr;
			break;
		case DB_STORAGE_LOCAL:
		    db_assert(0, "local cannot be interpreted as a value");
			result = NULL;
			break;
		case DB_STORAGE_ACCUMULATOR:
			result = &((db_icAccumulator)s)->accumulatorId;
			break;
		case DB_STORAGE_MEMBER:
		    if (((db_icMember)s)->base->kind == DB_STORAGE_OBJECT) {
		    	db_ic_vmStorage *vmStorage = db_ic_vmStorageGet(program, (db_icStorage)s);
		    	db_object obj = ((db_icObject)vmStorage->base->accumulator)->ptr;
		        *(void**)truncated = DB_OFFSET(obj, ((db_icMember)s)->member->offset);
		        result = truncated;
		    } else {
		    	db_assert(0, "local/dynamic member '%s' cannot be interpreted as a value", ((db_icStorage)s)->name);
		    }
		    break;
		case DB_STORAGE_ELEMENT:
		    if (!((db_icElement)s)->dynamic) {
		    	db_ic_vmStorage *vmStorage = db_ic_vmStorageGet(program, (db_icStorage)s);
		    	db_object obj = ((db_icObject)vmStorage->base->accumulator)->ptr;
		        *(void**)truncated = DB_OFFSET(obj, vmStorage->offset);
		        result = truncated;
		    } else {
		    	db_assert(0, "local/dynamic member '%s' cannot be interpreted as a value", ((db_icStorage)s)->name);
		    }
			break;
		default:
			db_assert(0, "invalid storage kind");
			break;
		}
		break;
    case DB_IC_LABEL:
        result = &((db_icLabel)s)->id;
        break;
	default:
		db_assert(0, "invalid operand type");
		break;
	}

	return result;
}

db_ic_vmType db_ic_getVmType(db_icValue s, db_icDerefMode deref) {
	db_ic_vmType result = DB_IC_VMTYPE_B;
	db_type t = db_ic_valueType(s);

	/* Determine VM type based on width of a type. If the value is
	 * a storage and derefMode is value, the value is considered a
	 * pointer and thus the type is L */
	if ((((db_ic)s)->kind == DB_IC_STORAGE) && (((db_icStorage)s)->kind == DB_STORAGE_OBJECT) && (deref == DB_IC_DEREF_ADDRESS)) {
	    result = DB_IC_VMTYPE_L;
	} else {
        if (t->kind == DB_PRIMITIVE) {
            switch(db_primitive(t)->width) {
            case DB_WIDTH_8:
                result = DB_IC_VMTYPE_B;
                break;
            case DB_WIDTH_16:
                result = DB_IC_VMTYPE_S;
                break;
            case DB_WIDTH_32:
                result = DB_IC_VMTYPE_L;
                break;
            case DB_WIDTH_64:
                result = DB_IC_VMTYPE_D;
                break;
            case DB_WIDTH_WORD:
                result = DB_IC_VMTYPE_L;
                break;
            }
        /* If type is not primitive instruction will take the address of the operand */
        } else {
            result = DB_IC_VMTYPE_L;
        }
	}

	return result;
}

db_ic_vmOperand db_ic_getVmOperand(db_ic_vmProgram *program, db_icDerefMode deref, db_icValue s) {
	db_ic_vmOperand result = DB_IC_VMOPERAND_V;

	switch(s->_parent.kind) {
	case DB_IC_LABEL:
		result = DB_IC_VMOPERAND_L;
		break;
	case DB_IC_LITERAL:
		result = DB_IC_VMOPERAND_V;
		break;
	case DB_IC_STORAGE: {
		db_ic_vmStorage *acc = db_ic_vmStorageGet(program, (db_icStorage)s);
		db_icStorage base = acc->base ? acc->base->accumulator : NULL;
		db_icStorageKind kind = ((db_icStorage)s)->kind;
		db_bool isReference = base ? db_ic_isReference(base) : db_ic_isReference((db_icStorage)s);
		db_bool isRefType = ((db_icStorage)s)->type->reference;
		db_bool isPrimitiveType = ((db_icStorage)s)->type->kind == DB_PRIMITIVE;
		db_bool isObject = kind == DB_STORAGE_OBJECT;
		db_bool isStatic = !acc->dynamic && (!base || !acc->base->dynamic);
		db_bool collapse = FALSE;
		db_ic_storageMustAllocate(program, acc, &collapse);

		if (!acc->dynamic && base && !acc->base->dynamic) {
			isObject = base->kind == DB_STORAGE_OBJECT;
		}
 
        switch(deref) {
        case DB_IC_DEREF_ADDRESS:
        	if (isObject) {
        		if (!(base && isRefType)) {
        			result = DB_IC_VMOPERAND_V;
        		} else {
        			result = DB_IC_VMOPERAND_P;
        		}
        	} else {
        		if (isReference) {
                    if (base) {
                         result = DB_IC_VMOPERAND_Q;
                    } else {
                        result = DB_IC_VMOPERAND_R;
                    }
        		} else {
                    if (isRefType) {
                        if (isStatic) {
                            result = DB_IC_VMOPERAND_R;
                        } else {
                            result = DB_IC_VMOPERAND_Q;
                        }
                    } else {
                        result = DB_IC_VMOPERAND_X;
                    }
                }
        	}
        	break;
        case DB_IC_DEREF_PUSH:
        case DB_IC_DEREF_VALUE:
        	if (isObject) {
        		/* When pushing either objects of a reference type or a non-primitive type,
        		 * push object-address. */
        		if ((deref == DB_IC_DEREF_PUSH) && (isRefType || !isPrimitiveType)) {
        			result = DB_IC_VMOPERAND_V;

        		/* When accessing non-reference primitive values, obtain value of object. */
        		} else {
        			result = DB_IC_VMOPERAND_P;
        		}
        	} else {
        		if ((deref == DB_IC_DEREF_PUSH) && !isPrimitiveType && !isReference) {
        			if (isStatic) {
        				/* If value is not a primitive it must always be passed as reference. If the object is
        				 * not already a reference, take the address of the register/local. */
        				result = DB_IC_VMOPERAND_X;
        			} else {
        				result = DB_IC_VMOPERAND_R;
        			}
        		} else {
        			if (isStatic) {
        				if (!isRefType && isReference && isPrimitiveType) {
        					result = DB_IC_VMOPERAND_Q; /* When a primitive type is a reference, it must have been passed as a reference
        												 * parameter. Use Q to directly obtain the value of the reference. */
        				} else {
        					if (!collapse && base && db_ic_isReference(base) && ((deref != DB_IC_DEREF_PUSH) || isRefType)) {
        						result = DB_IC_VMOPERAND_Q;
        					} else {
        						result = DB_IC_VMOPERAND_R;
        					}
        				}
        			} else {
                        /* When getting value of a non-static value (for example, member of a local) use Q */
        				result = DB_IC_VMOPERAND_Q;
        			}
        		}
        	}
        	break;
        }
        break;
	}
	default:
		db_assert(0, "invalid value-kind");
		break;
	}

	return result;
}

static db_int16 db_icLabel_toVm(db_icLabel label, db_ic_vmProgram *program) {
	db_ic_vmLabel *lbl;

	lbl = db_ic_vmLabelGet(program, label->id);
	lbl->pc = program->program->size;

	return 0;
}

db_void *db_ic_valueValue(db_ic_vmProgram *program, db_icValue s) {
    return db_ic_valueValue_width(program, s, NULL, 0);
}

/* Retrieve operand-addresses by using the operand-macros from the VM. Though the code is somewhat complex it negates the need
 * to duplicate all knowledge about which operands are used for every permutation of operand-kinds. */
#define DB_IC_OPADDR_GET_V(op,type,caseval,code)\
	case DB_IC_VMOPERAND_##caseval:\
		result = (void*) ((db_word) op##_##type##code);\
		break;\

#define DB_IC_OPADDR_GET_RP(op,type,caseval,code)\
	case DB_IC_VMOPERAND_##caseval:\
		result = (void*) (& op##_##type##code);\
		break;\

#define DB_IC_OPADDR_GET_Q(op,type,caseval,code)\
	case DB_IC_VMOPERAND_##caseval:\
		reg = qreg;\
		result = (void*) (& op##_##type##code);\
		reg = NULL;\
		switch((db_word)result) {\
		case 0x1000000:\
			result = (void*)1;\
			break;\
		case 0x10000:\
			result = (void*)2;\
			break;\
        default:\
            db_assert(0, "Q-operand kind (%u - %x) invalid for " #op "_" #type #code "\n", (db_word)result, (db_word)result);\
            break;\
		}\
		break;\

/* Expand for one operand */
#define DB_IC_OPADDR_GET1(op_,type,n,prefix,rp,v,q)\
	switch(op##n##Kind) {\
	DB_IC_OPADDR_GET_##rp(op_,type,P,prefix##P)\
	DB_IC_OPADDR_GET_##q(op_,type,Q,prefix##Q)\
	DB_IC_OPADDR_GET_##rp(op_,type,R,prefix##R)\
	DB_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
	default:\
		db_assert(0,"operand-kind other than PQRV not valid");\
		break;\
	}\

/* Expand for one operand (labels included) */
#define DB_IC_OPADDR_GET1_LABEL(op_,type,n,prefix,rp,v,q)\
	switch(op##n##Kind) {\
	DB_IC_OPADDR_GET_##rp(op_,type,P,prefix##P)\
	DB_IC_OPADDR_GET_##q(op_,type,Q,prefix##Q)\
	DB_IC_OPADDR_GET_##rp(op_,type,R,prefix##R)\
	DB_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
	DB_IC_OPADDR_GET_##v(op_,type,L,prefix##L)\
	default:\
		db_assert(0,"invalid operand-kind");\
		break;\
	}\

/* Expand for one operand (V only) */
#define DB_IC_OPADDR_GET1_VONLY(op_,type,n,prefix,rp,v,q)\
	switch(op##n##Kind) {\
	DB_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
	default:\
		db_error("operand other than V not valid for operand " #n " of type " #type " (%d)", op##n##Kind);\
		break;\
	}\
/*
 * op: op, op1, op2, op3
 * type: B,S,L,D
 * nX: actual operand being evaluated (used for opXKind)
 * prefix: for 2 & 3 ops, prefix the GET1-macro with previous operand codes
 * rp,v,q: select correct macro
 * op1func: select which operands are applicable (only V, labels included)
 */
#define DB_IC_OPADDR_GET1_(op,type,n2,prefix,rp,v,q,op1func) DB_IC_OPADDR_GET1##op1func(op,type,n2,prefix,rp,v,q)
#define DB_IC_OPADDR_GET1__LAST(op,type,n2,prefix,rp,v,q,op1func) DB_IC_OPADDR_GET1##op1func(op,type,n2,prefix,RP,V,Q)
#define DB_IC_OPADDR_GET1__RP(op,type,n2,prefix,rp,v,q,op1func) DB_IC_OPADDR_GET1##op1func(op,type,n2,prefix,RP,RP,RP)
#define DB_IC_OPADDR_GET1__Q(op,type,n2,prefix,rp,v,q,op1func) DB_IC_OPADDR_GET1##op1func(op,type,n2,prefix,Q,Q,Q)
#define DB_IC_OPADDR_GET1__V(op,type,n2,prefix,rp,v,q,op1func) DB_IC_OPADDR_GET1##op1func(op,type,n2,prefix,V,V,V)

/* Expand for 2 operands */
#define DB_IC_OPADDR_GET2(op_,type,n1,n2,prefix,func,op1func)\
	switch(op##n1##Kind) {\
	case DB_IC_VMOPERAND_P:\
		DB_IC_OPADDR_GET1_##func(op_,type,n2,prefix##P,RP,RP,RP,op1func)\
		break;\
	case DB_IC_VMOPERAND_Q:\
		DB_IC_OPADDR_GET1_##func(op_,type,n2,prefix##Q,Q,Q,Q,op1func)\
		break;\
	case DB_IC_VMOPERAND_R:\
		DB_IC_OPADDR_GET1_##func(op_,type,n2,prefix##R,RP,RP,RP,op1func)\
		break;\
	case DB_IC_VMOPERAND_V:\
		DB_IC_OPADDR_GET1_##func(op_,type,n2,prefix##V,V,V,V,op1func)\
		break;\
	default:\
		db_assert(0,"invalid operand-kind");\
		break;\
	}

#define DB_IC_OPADDR_GET2_LAST(op,type,n1,n2,prefix,func,op1func) DB_IC_OPADDR_GET2(op,type,n1,n2,prefix,_LAST,op1func)
#define DB_IC_OPADDR_GET2_RP(op,type,n1,n2,prefix,func,op1func) DB_IC_OPADDR_GET2(op,type,n1,n2,prefix,_RP,op1func)
#define DB_IC_OPADDR_GET2_Q(op,type,n1,n2,prefix,func,op1func) DB_IC_OPADDR_GET2(op,type,n1,n2,prefix,_Q,op1func)
#define DB_IC_OPADDR_GET2_V(op,type,n1,n2,prefix,func,op1func) DB_IC_OPADDR_GET2(op,type,n1,n2,prefix,_V,op1func)

/* Expand for three operands */
#define DB_IC_OPADDR_GET3(op,type,func,rp,v,q)\
	switch(op1Kind) {\
	case DB_IC_VMOPERAND_P:\
		DB_IC_OPADDR_GET2##func(op,type,2,3,P,rp,_VONLY)\
		break;\
	case DB_IC_VMOPERAND_Q:\
		DB_IC_OPADDR_GET2##func(op,type,2,3,Q,q,_VONLY)\
		break;\
	case DB_IC_VMOPERAND_R:\
		DB_IC_OPADDR_GET2##func(op,type,2,3,R,rp,_VONLY)\
		break;\
	/*case DB_IC_VMOPERAND_V:\
		DB_IC_OPADDR_GET2##func(op,type,2,3,V,v)\
		break;\*/\
	default:\
		db_assert(0,"operand-kind other than PQR not valid for first operand of 3-operand instruction");\
		break;\
	}\

#define DB_IC_OP1ADDR(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET1(op,type,1,,RP,V,Q) break;
#define DB_IC_OP2ADDR1(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET2(op1,type,1,2,,,_LABEL) break;
#define DB_IC_OP2ADDR2(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET2(op2,type,1,2,,_LAST,_LABEL) break;

#define DB_IC_OP3ADDR1(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET3(op1,type,,_RP,_V,_Q) break;
#define DB_IC_OP3ADDR2(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET3(op2,type,,,,) break;
#define DB_IC_OP3ADDR3(type) case DB_IC_VMTYPE_##type: DB_IC_OPADDR_GET3(op3,type,_LAST,,,) break;

#define DB_IC_SWITCH_TYPE_ALL(macro)\
		macro(B)\
		macro(S)\
		macro(L)\
		macro(D)\

#define DB_IC_SWITCH_TYPE_L(macro)\
		macro(L)

#define DB_IC_ASSIGN_OPERAND(typeSwitch,macro,vId)\
		switch(typeKind) {\
		typeSwitch(macro)\
		default:\
			db_error("type %d not valid for macro " #macro"\n",typeKind);\
			break;\
		}\
\
		switch((db_word)result) {\
		case 1: vmOpAddr = &op->ic.b._1; size = sizeof(db_int16); break;\
		case 2: vmOpAddr = &op->ic.b._2; size = sizeof(db_int16); break;\
		case 4: vmOpAddr = &op->ic.s;  size = sizeof(db_int32);break;\
		case 7: vmOpAddr = &op->lo.s.b._1; size = sizeof(db_int8); break;\
		case 8: vmOpAddr = &op->lo.s.b._2; size = sizeof(db_int8); break;\
		case 11: vmOpAddr = &op->hi.s.b._1; size = sizeof(db_int8); break;\
		case 12: vmOpAddr = &op->hi.s.b._2; size = sizeof(db_int8); break;\
		case 13: vmOpAddr = &op->lo; size = sizeof(db_uint64); break;\
        case 3: vmOpAddr = &op->ic; size = sizeof(db_int32);break;\
		case 5: vmOpAddr = &op->lo.w;  size = sizeof(db_int32);break;\
		case 9: vmOpAddr = &op->hi.w;  size = sizeof(db_int32);break;\
		default:\
			db_assert(0, "operand-macro " #macro " returned invalid value (%u) for operand " #vId " and type %d", (db_word)result, typeKind);\
			break;\
		}\
\
		memset(vmOpAddr, 0, size);\
		switch(op##vId##Kind) {\
		case DB_IC_VMOPERAND_V:{\
		    db_float32 truncated;\
            memcpy(vmOpAddr, db_ic_valueValue_width(program, v##vId, &truncated, size), size);\
			break;\
		}\
		case DB_IC_VMOPERAND_P:\
		    /* If storage is an object, copy address, otherwise calculate pointer + offset */\
		    if (((db_icStorage)v##vId)->kind == DB_STORAGE_OBJECT) {\
			    *(db_object*)vmOpAddr = *(db_object*)db_ic_valueValue(program, v##vId);\
		    } else {\
		        db_object ptr;\
		        db_ic_vmStorage *acc;\
		        /*db_assert(((db_icStorage)v##vId)->kind == DB_STORAGE_MEMBER, "P operand without storage being either an object or a member");*/\
		        acc = db_ic_vmStorageGet(program, (db_icStorage)v##vId);\
		        ptr = ((db_icObject)acc->base->accumulator)->ptr;\
		        *(db_object*)vmOpAddr = DB_OFFSET(ptr, acc->offset);\
		    }\
		    break;\
		case DB_IC_VMOPERAND_Q:\
		case DB_IC_VMOPERAND_R:\
		case DB_IC_VMOPERAND_X:\
			if (v##vId->_parent.kind == DB_IC_STORAGE) {\
				if (((db_icStorage)v##vId)->kind == DB_STORAGE_LOCAL) {\
					db_ic_vmStorage *local;\
					local = db_ic_vmStorageGet(program, (db_icStorage)v##vId);\
					*(db_uint16*)vmOpAddr = local->addr;\
				} else if (((db_icStorage)v##vId)->kind == DB_STORAGE_ACCUMULATOR){\
				    db_ic_vmStorage *accumulator;\
				    accumulator = db_ic_vmStorageGet(program, (db_icStorage)v##vId);\
				    db_ic_vmStorageAddReferee(program, accumulator, vmOpAddr);\
				} else if ((((db_icStorage)v##vId)->kind == DB_STORAGE_MEMBER) || (((db_icStorage)v##vId)->kind == DB_STORAGE_ELEMENT)){\
				    db_ic_vmStorage *accumulator;\
				    accumulator = db_ic_vmStorageGet(program, (db_icStorage)v##vId);\
				    switch(accumulator->base->accumulator->kind) {\
                    case DB_STORAGE_LOCAL:\
                        if (!accumulator->dynamic && !db_ic_isReference(accumulator->base->accumulator)) {\
                            *(db_uint16*)vmOpAddr = accumulator->base->addr + accumulator->offset;\
                            break;\
                        }\
                    /* If base is member or element it is a dynamic storage which requires allocation. */\
                    case DB_STORAGE_MEMBER:\
                    case DB_STORAGE_ELEMENT:\
                    case DB_STORAGE_ACCUMULATOR:\
                    default:\
                        db_ic_vmStorageAddReferee(program, accumulator, vmOpAddr);\
                        break;\
				    }\
				}\
			}\
			break;\
		case DB_IC_VMOPERAND_L: {\
		    db_ic_vmLabel *label;\
		    label = db_ic_vmLabelGet(program, *(db_uint32*)db_ic_valueValue(program, v##vId));\
		    db_ic_vmLabelAddReferee(program, label, vmOpAddr);\
		    break;\
		}\
		default:\
			db_assert(0, "invalid operand kind %d", op##vId##Kind);\
			break;\
		}\

/* Define structs instead of unions for the simulated VM-environment. This will make identifying
 * the appropriate operands easier */
typedef struct _vmParameter16 {
    struct {
        uint16_t _1;
        uint16_t _2;
    } b;
    uint16_t s;
    uint32_t w;
}_vmParameter16;

typedef struct _vmParameter {
    _vmParameter16 s;
    uint32_t w;
}_vmParameter;

static void db_ic_vmSetOp1Addr(db_ic_vmProgram *program, db_vmOp *op, db_ic_vmType typeKind, db_ic_vmOperand op1Kind, db_icValue v1) {
	db_word qreg[] = {0,1};
    struct {
        _vmParameter16 ic;
        _vmParameter lo;
        db_uint64 dbl;
    } c;
    db_word *reg = NULL;
	void *result = NULL;
	void *vmOpAddr = NULL;
	db_uint32 size = 0;

	DB_UNUSED(op);
	DB_UNUSED(typeKind);
	DB_UNUSED(op1Kind);
	DB_UNUSED(v1);

	/* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
	 * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
	c.ic.b._1 = 1;
	c.ic.b._2 = 2;
	c.lo.w = 5;
    c.lo.s.s = 6;
	c.lo.s.b._1 = 7;
	c.lo.s.b._2 = 8;
	c.dbl = 13;

	op1Kind = op1Kind == DB_IC_VMOPERAND_X ? DB_IC_VMOPERAND_R : op1Kind;

	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_ALL,DB_IC_OP1ADDR,1)
}

static void db_ic_vmSetOp2Addr(db_ic_vmProgram *program, db_vmOp *op, db_ic_vmType typeKind, db_ic_vmOperand op1Kind, db_ic_vmOperand op2Kind, db_icValue v1, db_icValue v2) {
	db_word qreg[] = {0,1};
    struct {
        _vmParameter16 ic;
        _vmParameter lo, hi;
        db_uint64 dbl;
    } c;
    db_word *reg = NULL;
	void *result = NULL;
	void *vmOpAddr = NULL;
	db_uint32 size = 0;

	/* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
	 * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
	c.ic.b._1 = 1;
	c.ic.b._2 = 2;
	c.lo.w = 5;
    c.lo.s.s = 6;
	c.lo.s.b._1 = 7;
	c.lo.s.b._2 = 8;
	c.hi.w = 9;
    c.hi.s.s = 10;
	c.hi.s.b._1 = 11;
	c.hi.s.b._2 = 12;
	c.dbl = 13;

	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_ALL,DB_IC_OP2ADDR1,1)
	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_ALL,DB_IC_OP2ADDR2,2)
}

static void db_ic_vmSetOp3Addr(db_ic_vmProgram *program, db_vmOp *op, db_ic_vmType typeKind, db_ic_vmOperand op1Kind, db_ic_vmOperand op2Kind, db_ic_vmOperand op3Kind, db_icValue v1, db_icValue v2, db_icValue v3) {
	db_word qreg[] = {0,1};
	struct {
        _vmParameter16 ic;
        _vmParameter lo;
        _vmParameter hi;
    } c;
    db_word *reg = NULL;
	void *result = NULL;
	void *vmOpAddr = NULL;
	db_uint32 size = 0;

	/* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
	 * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
	c.ic.b._1 = 1;
	c.ic.b._2 = 2;
	c.lo.w = 5;
    c.lo.s.s = 6;
	c.lo.s.b._1 = 7;
	c.lo.s.b._2 = 8;
	c.hi.w = 9;
    c.hi.s.s = 10;
	c.hi.s.b._1 = 11;
	c.hi.s.b._2 = 12;

	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_L,DB_IC_OP3ADDR1,1)
	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_L,DB_IC_OP3ADDR2,2)
	DB_IC_ASSIGN_OPERAND(DB_IC_SWITCH_TYPE_L,DB_IC_OP3ADDR3,3)
}

static db_ic_vmInlineFunction *db_ic_vmInlineFunctionNew(db_vmProgram program, db_function function) {
    db_ic_vmInlineFunction *result;

    result = db_malloc(sizeof(db_ic_vmInlineFunction));
    result->program = program;
    result->function = function;

    return result;
}

static void db_ic_vmInlineFunctionMark(db_ic_vmProgram *program, db_vmProgram vmProgram, db_function function) {
    db_iter inlineFunctionIter;
    db_ic_vmInlineFunction *inlineFunction = NULL;

    if (program->labels) {
        inlineFunctionIter = db_llIter(program->labels);
        while(db_iterHasNext(&inlineFunctionIter)) {
            inlineFunction = db_iterNext(&inlineFunctionIter);
            if (inlineFunction->program == vmProgram) {
                if (inlineFunction->function == function) {
                    break;
                }
            } else {
                inlineFunction = NULL;
            }
        }
    }

    if (!inlineFunction) {
        inlineFunction = db_ic_vmInlineFunctionNew(vmProgram, function);
        if (!program->inlineFunctions) {
            program->inlineFunctions = db_llNew();
        }
        db_llAppend(program->inlineFunctions, inlineFunction);
    }
}

#define DB_IC_OPERAND(op, code, operand)\
    case DB_IC_VMOPERAND_##operand:\
        result = DB_VM_##op##_##code;\
        break;\

#define DB_IC_OP2_PQRV(op, type, lvalue)\
	case DB_IC_VMOPERAND_##lvalue:\
		switch(op2) {\
			DB_IC_OPERAND(op,type##lvalue##V,V)\
			DB_IC_OPERAND(op,type##lvalue##R,R)\
			DB_IC_OPERAND(op,type##lvalue##P,P)\
			DB_IC_OPERAND(op,type##lvalue##Q,Q)\
			default:\
				db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op2));\
				break;\
		}\
		break;\

#define DB_IC_OP2_PQR(op, type, lvalue)\
    case DB_IC_VMOPERAND_##lvalue:\
        switch(op2) {\
            DB_IC_OPERAND(op,type##lvalue##R,R)\
            DB_IC_OPERAND(op,type##lvalue##P,P)\
            DB_IC_OPERAND(op,type##lvalue##Q,Q)\
            default:\
                db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op2));\
                break;\
        }\
        break;\

#define DB_IC_OP1_LVALUE_ANY(op, type, lvalue)\
		case DB_IC_VMOPERAND_##lvalue:\
			if (db_primitive(t)->kind == DB_UINTEGER) {\
				result = DB_VM_##op##_##type##lvalue##U;\
			} else if (db_primitive(t)->kind == DB_INTEGER) {\
				result = DB_VM_##op##_##type##lvalue##I;\
			} else if (db_primitive(t)->kind == DB_FLOAT) {\
				result = DB_VM_##op##_##type##lvalue##F;\
			}\
			break;\

#define DB_IC_OP2_(op,type,postfix)\
case DB_IC_VMTYPE_##type:\
	switch(op1) {\
		DB_IC_OP2_##postfix(op,type,R)\
		DB_IC_OP2_##postfix(op,type,P)\
		DB_IC_OP2_##postfix(op,type,Q)\
		default:\
			db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
			break;\
	}\
	break;\

#define DB_IC_OP2V_(op,type,postfix)\
case DB_IC_VMTYPE_##type:\
	switch(op1) {\
		DB_IC_OP2_##postfix(op,type,R)\
		DB_IC_OP2_##postfix(op,type,P)\
		DB_IC_OP2_##postfix(op,type,Q)\
		DB_IC_OP2_##postfix(op,type,V)\
		default:\
			db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
			break;\
	}\
	break;\

#define DB_IC_OP2_R(op, type,postfix)\
case DB_IC_VMTYPE_##type:\
	switch(op1) {\
		DB_IC_OP2_##postfix(op,type, R)\
		default:\
			db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
			break;\
	}\
	break;\

#define DB_IC_OP1_ANY(op, type)\
case DB_IC_VMTYPE_##type:\
	switch(op1) {\
		DB_IC_OP1_LVALUE_ANY(op,type,V)\
		DB_IC_OPERAND(op,type##R,R)\
		DB_IC_OPERAND(op,type##P,P)\
		DB_IC_OPERAND(op,type##Q,Q)\
		default:\
			db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
			break;\
	}\
	break;\

#define DB_IC_OP1_PQRV(op, type)\
case DB_IC_VMTYPE_##type:\
    switch(op1) {\
        DB_IC_OPERAND(op,type##V,V)\
        DB_IC_OPERAND(op,type##R,R)\
        DB_IC_OPERAND(op,type##P,P)\
        DB_IC_OPERAND(op,type##Q,Q)\
        default:\
            db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define DB_IC_OP1_PQR(op, type)\
case DB_IC_VMTYPE_##type:\
	switch(op1) {\
		DB_IC_OPERAND(op,type##R,R)\
		DB_IC_OPERAND(op,type##P,P)\
		DB_IC_OPERAND(op,type##Q,Q)\
		default:\
			db_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, db_ic_vmOperandStr(op1));\
			break;\
	}\
	break;\

#define DB_IC_GETOP1(op,postfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP1_##postfix(op,B)\
		DB_IC_OP1_##postfix(op,S)\
		DB_IC_OP1_##postfix(op,L)\
		DB_IC_OP1_##postfix(op,D)\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP1_L(op,postfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP1_##postfix(op,L)\
        default:\
            db_assert(0, "Type other than L not valid for " #op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP1_B(op,postfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP1_##postfix(op,B)\
        default:\
            db_assert(0, "Type other than B not valid for " #op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP1_COND(op, postfix)\
	DB_IC_GETOP1_B(op##B,postfix)\
	DB_IC_GETOP1_B(op##S,postfix)\
	DB_IC_GETOP1_B(op##L,postfix)\
	DB_IC_GETOP1_B(op##D,postfix)\
\
static db_vmOpKind db_ic_getVm##op(db_type t, db_ic_vmType op1Type, db_ic_vmOperand op1) {\
	db_vmOpKind result = DB_VM_STOP;\
	DB_UNUSED(t);\
	switch(op1Type) {\
	case DB_IC_VMTYPE_B:\
		result = db_ic_getVm##op##B(DB_IC_VMTYPE_B, op1);\
		break;\
	case DB_IC_VMTYPE_S:\
		result = db_ic_getVm##op##S(DB_IC_VMTYPE_B, op1);\
		break;\
	case DB_IC_VMTYPE_L:\
		result = db_ic_getVm##op##L(DB_IC_VMTYPE_B, op1);\
		break;\
	case DB_IC_VMTYPE_D:\
		result = db_ic_getVm##op##D(DB_IC_VMTYPE_B, op1);\
		break;\
	}\
	return result;\
}\

#define DB_IC_GETOP1_COND_LD(op, postfix)\
	DB_IC_GETOP1_B(op##L,postfix)\
	DB_IC_GETOP1_B(op##D,postfix)\
\
static db_vmOpKind db_ic_getVm##op(db_type t, db_ic_vmType op1Type, db_ic_vmOperand op1) {\
	db_vmOpKind result = DB_VM_STOP;\
	DB_UNUSED(t);\
	switch(op1Type) {\
	case DB_IC_VMTYPE_L:\
		result = db_ic_getVm##op##L(DB_IC_VMTYPE_B, op1);\
		break;\
	case DB_IC_VMTYPE_D:\
		result = db_ic_getVm##op##D(DB_IC_VMTYPE_B, op1);\
		break;\
	default:\
		db_assert(0,"byte or short operands not valid for " #op);\
		break;\
	}\
	return result;\
}\

#define DB_IC_GETOP1_COND_SIGN(op, postfix)\
	DB_IC_GETOP1_COND(op##I,postfix)\
	DB_IC_GETOP1_COND(op##U,postfix)\
	DB_IC_GETOP1_COND_LD(op##F,postfix)\
static db_vmOpKind db_ic_getVm##op(db_type t, db_ic_vmType op1Type, db_ic_vmOperand op1) {\
	db_vmOpKind result = DB_VM_STOP;\
	if (t->kind == DB_PRIMITIVE) {\
		switch(db_primitive(t)->kind) {\
		case DB_ENUM:\
		case DB_INTEGER:\
			result = db_ic_getVm##op##I(t, op1Type, op1);\
			break;\
		case DB_BINARY:\
		case DB_CHARACTER:\
		case DB_UINTEGER:\
			result = db_ic_getVm##op##U(t, op1Type, op1);\
			break;\
		case DB_FLOAT:\
			result = db_ic_getVm##op##F(t, op1Type, op1);\
			break;\
		default:\
			db_assert(0, "conditional operation " #op " works only for INTEGER, UINTEGER and FLOAT primitives (got %s)", db_nameof(t));\
			break;\
		}\
	} else {\
		db_assert(0, "conditional operation " #op " works only for primitive types");\
	}\
	return result;\
}\

#define DB_IC_GETOP2(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP2_##lpostfix(op,B,rpostfix)\
		DB_IC_OP2_##lpostfix(op,S,rpostfix)\
		DB_IC_OP2_##lpostfix(op,L,rpostfix)\
		DB_IC_OP2_##lpostfix(op,D,rpostfix)\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP2_V(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP2V_##lpostfix(op,B,rpostfix)\
		DB_IC_OP2V_##lpostfix(op,S,rpostfix)\
		DB_IC_OP2V_##lpostfix(op,L,rpostfix)\
		DB_IC_OP2V_##lpostfix(op,D,rpostfix)\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP2_L(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP2_##lpostfix(op,L,rpostfix)\
		default:\
            db_assert(0, "Type other than L (%d) not valid for " #op, type);\
            break;\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP2_D(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP2_##lpostfix(op,D,rpostfix)\
		default:\
            db_assert(0, "Type other than L (%d) not valid for " #op, type);\
            break;\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP2V_L(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	switch(type) {\
		DB_IC_OP2V_##lpostfix(op,L,rpostfix)\
		default:\
            db_assert(0, "Type other than L (%d) not valid for " #op, type);\
            break;\
	}\
	\
	return result;\
}\

#define DB_IC_GETOP2_LD(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP2_##lpostfix(op,L,rpostfix)\
        DB_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            db_assert(0, "type not applicable for floating point operation " # op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP2_SLD(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP2_##lpostfix(op,S,rpostfix)\
        DB_IC_OP2_##lpostfix(op,L,rpostfix)\
        DB_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            db_assert(0, "B not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP2_BLD(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP2_##lpostfix(op,B,rpostfix)\
        DB_IC_OP2_##lpostfix(op,L,rpostfix)\
        DB_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            db_assert(0, "S not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP2_BSD(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP2_##lpostfix(op,B,rpostfix)\
        DB_IC_OP2_##lpostfix(op,S,rpostfix)\
        DB_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            db_assert(0, "L not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP2_BSL(op,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_ic_vmType type, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
    db_vmOpKind result = DB_VM_STOP;\
    \
    switch(type) {\
        DB_IC_OP2_##lpostfix(op,B,rpostfix)\
        DB_IC_OP2_##lpostfix(op,S,rpostfix)\
        DB_IC_OP2_##lpostfix(op,L,rpostfix)\
        default:\
            db_assert(0, "D not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define DB_IC_GETOP1_ANY(op)\
static db_vmOpKind db_ic_getVm##op(db_type t, db_ic_vmType type, db_ic_vmOperand op1) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
    if (op1 == DB_IC_VMOPERAND_V) {\
        if (t->kind == DB_PRIMITIVE) {\
            if (db_primitive(t)->width == DB_WIDTH_64) {\
                type = DB_IC_VMTYPE_D;\
            } else {\
                type = DB_IC_VMTYPE_L;\
            }\
        }\
    }\
	switch(type) {\
		DB_IC_OP1_PQRV(op,L)\
		DB_IC_OP1_ANY(op,D)\
        default:\
            db_assert(0, "B or S not applicable for instruction " #op);\
            break;\
	}\
	\
	return result;\
}\

/* Arithmic operations need to distinct between integer and floating point types */
#define DB_IC_GETOP2_ARITH(op,lpostfix,rpostfix)\
DB_IC_GETOP2(op##I,lpostfix,rpostfix)\
DB_IC_GETOP2_LD(op##F,lpostfix,rpostfix)\
static db_vmOpKind db_ic_getVm##op(db_type t, db_ic_vmType typeKind, db_ic_vmOperand op1, db_ic_vmOperand op2) {\
	db_vmOpKind result = DB_VM_STOP;\
	\
	if (t->kind == DB_PRIMITIVE) {\
		switch(db_primitive(t)->kind) {\
		case DB_INTEGER:\
		case DB_UINTEGER:\
		case DB_ENUM:\
		case DB_BINARY:\
		case DB_CHARACTER:\
			result = db_ic_getVm##op##I(typeKind, op1, op2);\
			break;\
		case DB_FLOAT:\
			result = db_ic_getVm##op##F(typeKind, op1, op2);\
			break;\
		default:\
			db_assert(0, "invalid primitive-kind for operation " #op);\
			break;\
		}\
	} else {\
		db_assert(0, "invalid type-kind for operation");\
	}\
	return result;\
}\

static db_vmOpKind db_ic_getVmSTAGE12(db_ic_vmType typeKind, db_ic_vmOperand op1) {
    if (typeKind == DB_IC_VMTYPE_D) {
        switch(op1) {
            case DB_IC_VMOPERAND_P: return DB_VM_STAGE12_DP;
            case DB_IC_VMOPERAND_V: return DB_VM_STAGE12_DV;
            default: db_assert(0, "invalid operand-kind for STAGE12");
        }
    } else {
        db_assert(0, "invalid type-kind for STAGE12");
    }
    return DB_VM_STOP;
}

DB_IC_GETOP2(SET,,PQRV)
DB_IC_GETOP2_L(SETREF,,PQRV)
DB_IC_GETOP2_L(SETSTRDUP,,PQRV)

DB_IC_GETOP2_ARITH(ADD,,PQRV)
DB_IC_GETOP2_ARITH(SUB,,PQRV)
DB_IC_GETOP2_ARITH(MUL,,PQRV)
DB_IC_GETOP2_ARITH(DIV,,PQRV)
DB_IC_GETOP2(MODI,,PQRV)

DB_IC_GETOP1(INC,PQR)
DB_IC_GETOP1(DEC,PQR)

DB_IC_GETOP2(XOR,,PQRV)
DB_IC_GETOP2(OR,,PQRV)
DB_IC_GETOP2(AND,,PQRV)
DB_IC_GETOP1(NOT,PQR)
DB_IC_GETOP2(SHIFT_LEFT,,PQRV)
DB_IC_GETOP2(SHIFT_RIGHT,,PQRV)

DB_IC_GETOP1(STAGE1,PQRV)
DB_IC_GETOP2_V(STAGE2,,PQRV)

DB_IC_GETOP1_COND(COR,PQR)
DB_IC_GETOP1_COND(CAND,PQR)
DB_IC_GETOP1_COND(CNOT,PQR)
DB_IC_GETOP1_COND(CEQ,PQR)
DB_IC_GETOP1_COND(CNEQ,PQR)

DB_IC_GETOP1_B(CEQSTR,PQR)
DB_IC_GETOP1_B(CNEQSTR,PQR)

DB_IC_GETOP1_COND_SIGN(CGT,PQR)
DB_IC_GETOP1_COND_SIGN(CLT,PQR)
DB_IC_GETOP1_COND_SIGN(CGTEQ,PQR)
DB_IC_GETOP1_COND_SIGN(CLTEQ,PQR)

DB_IC_GETOP1(JEQ,PQR)
DB_IC_GETOP1(JNEQ,PQR)

DB_IC_GETOP2_L(ELEMA,R,PQRV)
DB_IC_GETOP2_L(ELEMS,R,PQRV)
DB_IC_GETOP2_L(ELEML,R,PQRV)
DB_IC_GETOP2_L(ELEMLX,R,PQRV)
DB_IC_GETOP2_L(ELEMM,R,PQRV)
DB_IC_GETOP2_L(ELEMMX,R,PQRV)

DB_IC_GETOP1(PUSH,PQRV)
DB_IC_GETOP1(PUSHX,PQR)
DB_IC_GETOP1_L(PUSHANY,PQRV)
DB_IC_GETOP1_ANY(PUSHANYX)
DB_IC_GETOP1_L(CALL,PQR)
DB_IC_GETOP1_L(CALLVM,PQR)
DB_IC_GETOP1(RET,PQR)
DB_IC_GETOP1_L(RETCPY,PQR)

DB_IC_GETOP2_L(CAST,,PQRV)
DB_IC_GETOP2(PCAST,,PQR)

DB_IC_GETOP2V_L(STRCAT,,PQRV)
DB_IC_GETOP2_L(STRCPY,,PQRV)

DB_IC_GETOP2_L(NEW,,PQRV)
DB_IC_GETOP1_L(DEALLOC,PQR)
DB_IC_GETOP1_L(KEEP,PQR)
DB_IC_GETOP1_L(FREE,PQR)

DB_IC_GETOP1_L(DEFINE,PQRV)

DB_IC_GETOP1_L(UPDATE,PQRV)
DB_IC_GETOP1_L(UPDATEBEGIN,PQRV)
DB_IC_GETOP1_L(UPDATEEND,PQRV)
DB_IC_GETOP2_L(UPDATEFROM,,PQR)
DB_IC_GETOP2_L(UPDATEENDFROM,,PQR)
DB_IC_GETOP1_L(UPDATECANCEL,PQRV)

DB_IC_GETOP1_L(WAITFOR,PQRV)
DB_IC_GETOP2_L(WAIT,,PQRV)

static db_vmOp *db_ic_vmStorageAssembleElement(db_icStorage storage, db_ic_vmProgram *program, db_vmOp *vmOp, db_icStorage topLevelStorage) {
	db_ic_vmOperand indexKind;
	db_icValue icElementSize;
	db_collection type = db_collection(((db_icElement)storage)->base->type); /* Obtain collectiontype */
	db_value elementSizeValue;
	db_uint64 elementSize;

	/* Obtain kind for index */
	indexKind = db_ic_getVmOperand(program, DB_IC_DEREF_VALUE, ((db_icElement)storage)->index);

	/* Create value for elementSize */
	elementSize = db_type_sizeof(type->elementType->real);
	db_valueLiteralInit(&elementSizeValue, DB_LITERAL_UNSIGNED_INTEGER, &elementSize);
	icElementSize = (db_icValue)db_icLiteral__create(program->icProgram, ((db_ic)storage)->line, elementSizeValue, (db_type)db_uint32_o);

	switch(type->kind) {
	case DB_ARRAY:
		vmOp->op = db_ic_getVmELEMA(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
		db_ic_vmSetOp3Addr(program, vmOp, DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind, DB_IC_VMOPERAND_V, (db_icValue)topLevelStorage, ((db_icElement)storage)->index, icElementSize);
		break;
	case DB_SEQUENCE:
		vmOp->op = db_ic_getVmELEMS(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
		db_ic_vmSetOp3Addr(program, vmOp, DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind, DB_IC_VMOPERAND_V, (db_icValue)topLevelStorage, ((db_icElement)storage)->index, icElementSize);
		break;
	case DB_LIST:
		if (db_collection_elementRequiresAlloc(type)) {
			vmOp->op = db_ic_getVmELEML(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
		} else {
			vmOp->op = db_ic_getVmELEMLX(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
		}
		db_ic_vmSetOp2Addr(program, vmOp, DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind, (db_icValue)topLevelStorage, ((db_icElement)storage)->index);
		break;
	case DB_MAP:
        if (db_collection_elementRequiresAlloc(type)) {
            vmOp->op = db_ic_getVmELEMM(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
        } else {
            vmOp->op = db_ic_getVmELEMMX(DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind);
        }
		db_ic_vmSetOp2Addr(program, vmOp, DB_IC_VMTYPE_L, DB_IC_VMOPERAND_R, indexKind, (db_icValue)topLevelStorage, ((db_icElement)storage)->index);
		break;
	}

	return db_vmProgram_addOp(program->program, ((db_ic)storage)->line);
}

static db_vmOp *db_ic_vmStorageAssembleNested(db_icStorage icStorage, db_ic_vmProgram *program, db_vmOp *vmOp, db_icStorage icTopLevelStorage) {
    db_ic_vmStorage *storage = db_ic_vmStorageGet(program, icStorage);
    
	if (!storage->assembled && (storage->accumulator->used || storage->dynamic)) {
	    if (storage->accumulator->kind == DB_STORAGE_MEMBER) {
	    	if ((storage->base->accumulator->kind != DB_STORAGE_OBJECT) && (db_ic_isReference(storage->base->accumulator) || storage->base->dynamic)) {
				db_icStorage base = storage->base->accumulator;
				db_uint32 offset = storage->offset;

				/* Assemble base */
				vmOp = db_ic_vmStorageAssembleNested(base, program, vmOp, base);

				if (storage->offset) {
				    db_ic_vmStorage *vmBase = db_ic_vmStorageGet(program, base);
                    /* Set the base-address in the accumulator, conserve the register value where the original
                     * address is stored. This conserved value can be used as base for other member-storages. If
                     * the base is dynamic this value doesn't need to be conserved because the storage it points
                     * to is not static. */
				    if (!vmBase->dynamic) {
                        vmOp->op = DB_VM_MEMBER; /* Member instruction takes a destination, base and offset */
                        db_ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
                        if (base->kind == DB_STORAGE_LOCAL) {
                            vmOp->ic.b._2 = storage->base->addr;
                        } else {
                            db_ic_vmStorageAddReferee(program, storage->base, &vmOp->ic.b._2);
                        }
                        vmOp->lo.w = offset;
                        
                        /* If base is a local and a reference, storage has to be recomputed each time */
                        if (!((base->kind == DB_STORAGE_LOCAL) && (base->isReference))) {
                            storage->assembled = TRUE;
                        }
				    } else {
						/* Calculate address at runtime by adding the offset to the base-address */
						vmOp->op = DB_VM_ADDI_LRV;
						if (storage->accumulator->kind == DB_STORAGE_LOCAL) {
							vmOp->ic.b._1 = storage->addr;
						} else {
							db_ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
						}

						vmOp->lo.w = offset;
				    }

                    /* Give new operation to assembler */
                    vmOp = db_vmProgram_addOp(program->program, ((db_ic)icStorage)->line);
				}
	    	}
		} else if (storage->accumulator->kind == DB_STORAGE_ELEMENT) {
			db_icStorage base = storage->base->accumulator;
            db_ic_vmStorage *topLevelStorage = db_ic_vmStorageGet(program, icTopLevelStorage);

			/* Assemble base */
			vmOp = db_ic_vmStorageAssembleNested(base, program, vmOp, icTopLevelStorage);

			/* If element is not dynamic the address can be determined at compile-time. When the element
			 * is dynamic the address will be calculated at runtime. */
			if (storage->dynamic || db_ic_isReference(storage->base->accumulator)) {
				/* If the base is an object store the address in the accumulator */
				if (base->kind == DB_STORAGE_OBJECT) {
                    vmOp->op = DB_VM_SET_LRV;
                    db_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
                    vmOp->lo.w = (intptr_t)((db_icObject)base)->ptr;
				    if (storage->offset) {
				        vmOp->lo.w += storage->offset;
				    }
				    vmOp = db_vmProgram_addOp(program->program, ((db_ic)icStorage)->line);

				/* If the base is a local store the address of the local in the accumulator */
				} else if (base->kind == DB_STORAGE_LOCAL) {
					if (!db_ic_isReference(storage->base->accumulator)) {
						vmOp->op = DB_VM_SET_LRX;
						db_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
						vmOp->ic.b._2 = storage->base->addr;
						if (storage->offset) {
							vmOp->ic.b._2 += storage->offset;
						}
						vmOp = db_vmProgram_addOp(program->program, ((db_ic)icStorage)->line);
					} else {
						vmOp->op = DB_VM_SET_LRR;
						db_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
						vmOp->ic.b._2 = storage->base->addr;
						vmOp = db_vmProgram_addOp(program->program, ((db_ic)icStorage)->line);
					}
				}

				/* Insert element-instruction */
				vmOp = db_ic_vmStorageAssembleElement(icStorage, program, vmOp, icTopLevelStorage);
			}
		}
	}

	return vmOp;
}

static db_vmOp *db_ic_vmStorageAssemble(db_icStorage icStorage, db_ic_vmProgram *program, db_vmOp *vmOp) {
    return db_ic_vmStorageAssembleNested(icStorage, program, vmOp, icStorage);
}

static db_vmOpKind db_ic_getVmCast(db_ic_vmProgram *program, db_icOp op, db_type t, db_ic_vmType typeKind, db_ic_vmOperand storage, db_ic_vmOperand op1) {
    db_type srcType, dstType;
    db_vmOpKind result = DB_VM_STOP;

    DB_UNUSED(op);
    DB_UNUSED(t);

    dstType = *(db_type*)db_ic_valueValue(program, op->s3);
    srcType = db_ic_valueType(op->s2);

    if (srcType->kind == dstType->kind) {
        if (srcType->kind == DB_PRIMITIVE) {
            result = db_ic_getVmPCAST(typeKind, storage, op1);
        } else {
            if (srcType->reference) {
                result = db_ic_getVmCAST(typeKind, storage, DB_IC_VMOPERAND_P);
            } else {
                /* No cast for non-reference types */
            }
        }
    } else if ((srcType->kind == DB_VOID) && srcType->reference) {
        result = db_ic_getVmCAST(typeKind, storage, DB_IC_VMOPERAND_P);
    }

    db_assert(result != DB_VM_STOP, "no cast-instruction found from type '%s' to '%s'", db_nameof(srcType), db_nameof(dstType));

    return result;
}

static db_vmOpKind db_ic_getVmFree(db_icOp op, db_type t, db_ic_vmType typeKind, db_ic_vmOperand op1) {
    db_vmOpKind result = DB_VM_STOP;
    DB_UNUSED(t);

    if (((db_icStorage)op->s1)->isReference) {
        result = db_ic_getVmFREE(typeKind, op1);
    } else {
        result = db_ic_getVmDEALLOC(typeKind, op1);
    }

    return result;
}

static db_vmOpKind db_ic_getVmSet(db_type type, db_icStorage op1, db_ic_vmType typeKind, db_ic_vmOperand opKind1, db_ic_vmOperand opKind2, db_icDerefMode deref1, db_icDerefMode deref2) {
	db_vmOpKind result;
    
    DB_UNUSED(deref2);

	/* Accummulators are only meant as temporary storage and therefore don't do resource management */
	if (op1->kind == DB_STORAGE_ACCUMULATOR) {
	    result = db_ic_getVmSET(typeKind, opKind1, opKind2);
	} else {
        /* printf("op1->isReference=%d, deref==value=%d, typeKind=%d, opKind1=%d, opKind2=%d\n",
               op1->isReference, deref==DB_IC_DEREF_VALUE, typeKind, opKind1, opKind2); */
        if (op1->type->reference || (deref1 == DB_IC_DEREF_ADDRESS)) {
            result = db_ic_getVmSETREF(typeKind, opKind1, opKind2);
        } else {
            if ((type->kind == DB_PRIMITIVE) && (db_primitive(type)->kind == DB_TEXT)) {
                result = db_ic_getVmSETSTRDUP(typeKind, opKind1, opKind2);
            } else {
                result = db_ic_getVmSET(typeKind, opKind1, opKind2);
            }
        }
	}

	return result;
}

static db_vmOpKind db_ic_getVmOpKind(db_ic_vmProgram *program, db_icOp op, db_icValue storage, db_type t, db_ic_vmType typeKind, db_ic_vmOperand op1, db_ic_vmOperand op2, db_icDerefMode deref1, db_icDerefMode deref2) {
	db_vmOpKind result = DB_VM_STOP;

	switch(op->kind) {
	/* Set (assign) */
	case DB_IC_SET:
	    result = db_ic_getVmSet(t, (db_icStorage)storage, typeKind, op1, op2, deref1, deref2);
	    break;

    /* Casting */
    case DB_IC_CAST:
    	result = db_ic_getVmCast(program, op, t, typeKind,
    			db_ic_getVmOperand(program, op->s1Deref, op->s1),
    			db_ic_getVmOperand(program, op->s2Deref, op->s2));
    	break;

    /* String concatenation */
    case DB_IC_STRCAT: result = db_ic_getVmSTRCAT(typeKind, op1, op2); break;
    case DB_IC_STRCPY: result = db_ic_getVmSTRCPY(typeKind, op1, op2); break;

	/* Operators */
	case DB_IC_ADD: result = db_ic_getVmADD(t, typeKind, op1, op2); break;
	case DB_IC_SUB: result = db_ic_getVmSUB(t, typeKind, op1, op2); break;
	case DB_IC_MUL: result = db_ic_getVmMUL(t, typeKind, op1, op2); break;
	case DB_IC_DIV: result = db_ic_getVmDIV(t, typeKind, op1, op2); break;
	case DB_IC_MOD: result = db_ic_getVmMODI(typeKind, op1, op2); break;
	case DB_IC_INC: result = db_ic_getVmINC(typeKind, op1); break;
	case DB_IC_DEC: result = db_ic_getVmDEC(typeKind, op1); break;
	case DB_IC_XOR: result = db_ic_getVmXOR(typeKind, op1, op2); break;
	case DB_IC_OR: result = db_ic_getVmOR(typeKind, op1, op2); break;
	case DB_IC_AND: result = db_ic_getVmAND(typeKind, op1, op2); break;
	case DB_IC_NOT: result = db_ic_getVmNOT(typeKind, op1); break;
	case DB_IC_SHIFT_LEFT: result = db_ic_getVmSHIFT_LEFT(typeKind, op1, op2); break;
	case DB_IC_SHIFT_RIGHT: result = db_ic_getVmSHIFT_RIGHT(typeKind, op1, op2); break;
	case DB_IC_STAGE1: result = db_ic_getVmSTAGE1(typeKind, op1); break;
	case DB_IC_STAGE2: result = db_ic_getVmSTAGE2(typeKind, op1, op2); break;
	case DB_IC_COND_OR: result = db_ic_getVmCOR(t, typeKind, op1); break;
	case DB_IC_COND_AND: result = db_ic_getVmCAND(t, typeKind, op1); break;
	case DB_IC_COND_NOT: result = db_ic_getVmCNOT(t, typeKind, op1); break;
	case DB_IC_COND_EQ: {
		if ((t->kind == DB_PRIMITIVE) && (db_primitive(t)->kind == DB_TEXT)) {
			result = db_ic_getVmCEQSTR(DB_IC_VMTYPE_B, op1);
		} else {
			result = db_ic_getVmCEQ(t, typeKind, op1);
		}
		break;
	}
	case DB_IC_COND_NEQ: {
		if ((t->kind == DB_PRIMITIVE) && (db_primitive(t)->kind == DB_TEXT)) {
			result = db_ic_getVmCNEQSTR(DB_IC_VMTYPE_B, op1);
		} else {
			result = db_ic_getVmCNEQ(t, typeKind, op1);
		}
		break;
	}
	case DB_IC_COND_GT: result = db_ic_getVmCGT(t, typeKind, op1); break;
	case DB_IC_COND_LT: result = db_ic_getVmCLT(t, typeKind, op1); break;
	case DB_IC_COND_GTEQ: result = db_ic_getVmCGTEQ(t, typeKind, op1); break;
	case DB_IC_COND_LTEQ: result = db_ic_getVmCLTEQ(t, typeKind, op1); break;

	/* Program control */
	case DB_IC_JUMP: result = DB_VM_JUMP; break;
	case DB_IC_JEQ: result = db_ic_getVmJEQ(typeKind, op1); break;
	case DB_IC_JNEQ: result = db_ic_getVmJNEQ(typeKind, op1); break;
	case DB_IC_STOP: result = DB_VM_STOP; break;

	/* Function calls */
	case DB_IC_PUSH: {
		if (op->s1Any) {
			if ((op1 != DB_IC_VMOPERAND_X) && (op->s1->_parent.kind != DB_IC_LITERAL) ) {
				result = db_ic_getVmPUSHANY(typeKind, op1);
			} else {
				result = db_ic_getVmPUSHANYX(t, typeKind, op1 == DB_IC_VMOPERAND_X ? DB_IC_VMOPERAND_R : op1);
			}
		} else {
			if (op1 != DB_IC_VMOPERAND_X) {
				result = db_ic_getVmPUSH(typeKind, op1);
			} else {
				result = db_ic_getVmPUSHX(typeKind, DB_IC_VMOPERAND_R);
			}
		}
		break;
	}

	case DB_IC_CALL: {
        db_function f = ((db_icObject)op->s2)->ptr;
        if (f->kind == DB_PROCEDURE_VM) {
            if ((f->returnType->real->kind == DB_VOID) && (!f->returnType->real->reference)) {
                result = DB_VM_CALLVMVOID;
            } else {
                result = db_ic_getVmCALLVM(DB_IC_VMTYPE_L, op1);
            }
        } else {
            if ((f->returnType->real->kind == DB_VOID) && (!f->returnType->real->reference)) {
                result = DB_VM_CALLVOID;
            } else {
                result = db_ic_getVmCALL(DB_IC_VMTYPE_L, op1);
            }
        }
        break;
	}

	case DB_IC_RET:
        if (db_type_sizeof(t) <= 8) {
            if (db_type_sizeof(t) == 8) {
                result = db_ic_getVmRET(DB_IC_VMTYPE_D, op1);
            } else {
                result = db_ic_getVmRET(typeKind, op1);
            }
        } else {
            result = db_ic_getVmRETCPY(DB_IC_VMTYPE_L, op1);
        }
        break;

    /* Memory management */
	case DB_IC_NEW: result = db_ic_getVmNEW(typeKind, op1, op2); break;
    case DB_IC_FREE: result = db_ic_getVmFree(op, t, typeKind, op1); break;
    case DB_IC_KEEP: result = db_ic_getVmKEEP(typeKind, op1); break;

    case DB_IC_DEFINE: result = db_ic_getVmDEFINE(typeKind, op1); break;

    /* Notifications */
    case DB_IC_UPDATE:
    	if (op->s2) {
    		result = db_ic_getVmUPDATEFROM(typeKind, op1, op2);
    	} else {
    		result = db_ic_getVmUPDATE(typeKind, op1);
    	}
    	break;

    case DB_IC_UPDATEEND:
    	if (op->s2) {
    		result = db_ic_getVmUPDATEENDFROM(typeKind, op1, op2);
    	} else {
    		result = db_ic_getVmUPDATEEND(typeKind, op1);
    	}
    	break;

    case DB_IC_UPDATEBEGIN: result = db_ic_getVmUPDATEBEGIN(typeKind, op1); break;
    case DB_IC_UPDATECANCEL: result = db_ic_getVmUPDATECANCEL(typeKind, op1); break;

    case DB_IC_WAITFOR: result = db_ic_getVmWAITFOR(typeKind, op1); break;
    case DB_IC_WAIT: result = db_ic_getVmWAIT(typeKind, op1, op2); break;

	default:
		db_assert(0, "invalid intermediate op-code");
		break;
	}

	return result;
}

/* Get type and storage kind for operands and assemble operand when necessary (in case an
 * offset-instruction has to be inserted for a dynamically allocated object). */
static db_vmOp* db_vmGetTypeAndAssemble(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_bool threeOperands, db_icValue storage, db_icValue op1, db_icValue op2, db_icDerefMode storageDeref, db_icDerefMode opDeref1, db_icDerefMode opDeref2, db_type *t, db_ic_vmType *type, db_ic_vmOperand *storageKind, db_ic_vmOperand *opKind1, db_ic_vmOperand *opKind2) {
    
    if (op1) {
        *opKind1 = db_ic_getVmOperand(program, opDeref1, op1);
        *t = db_ic_valueType(op1);
        
        if (!op->s1Any && !threeOperands) {
            *type = db_ic_getVmType(op1, opDeref1);
        } else if (op->s1Any) {
            if (((op->s1->_parent.kind != DB_IC_LITERAL) || (((*t)->kind != DB_PRIMITIVE) || (db_primitive(*t)->width != DB_WIDTH_64)))) {
                *type = DB_IC_VMTYPE_L;
            } else {
               *type = db_ic_getVmType(op1, opDeref1);
            }
        } else {
            *type = DB_IC_VMTYPE_L;
        }
        if (((db_ic)op1)->kind == DB_IC_STORAGE) {
            vmOp = db_ic_vmStorageAssemble((db_icStorage)op1, program, vmOp);
        }
    }
    if (op2) {
        if (((db_ic)op2)->kind == DB_IC_STORAGE) {
            if (op2 != op1) {
                vmOp = db_ic_vmStorageAssemble((db_icStorage)op2, program, vmOp);
            }
        }
        *opKind2 = db_ic_getVmOperand(program, opDeref2, op2);
    }
    if (storage) {
        if (((db_ic)storage)->kind == DB_IC_STORAGE) {
            if ((storage != op1) && (storage != op2))
                vmOp = db_ic_vmStorageAssemble((db_icStorage)storage, program, vmOp);
        }
        *storageKind = db_ic_getVmOperand(program, storageDeref, storage);
    }
    
    /* If storage is any, set hi to storage-type. However, don't set the type when the
     * operand is a literal and the value is 64 bit. In that case there is no space
     * for the type, and the assembler will select an instruction that hard-codes the type. */
	if (op->s1Any && !((((db_ic)op1)->kind == DB_IC_LITERAL) &&
                       (*opKind1 == DB_IC_VMOPERAND_V) &&
                       (((*t)->kind == DB_PRIMITIVE) &&
                       (db_primitive(*t)->width == DB_WIDTH_64)))) {
		vmOp->hi.w = (db_word)db_ic_valueType(op1);
	}
    
    return vmOp;
}

/* DPV operands can't be encoded in the addressspace for one instruction. Therefore they must be split up into staged
 * instructions */
static db_bool db_vmIsDPV(db_ic_vmType type, db_ic_vmOperand opKind1, db_ic_vmOperand opKind2) {
    db_bool result = FALSE;
    if (type == DB_IC_VMTYPE_D) {
        if (((opKind1 == DB_IC_VMOPERAND_P) && (opKind2 == DB_IC_VMOPERAND_V)) || ((opKind1 == DB_IC_VMOPERAND_V) && (opKind2 == DB_IC_VMOPERAND_P))) {
            result = TRUE;
        }
    }
    return result;
}

/* Instruction without operands */
static void db_vmOp0(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue op1, db_icDerefMode opDeref1) {
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1;
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = db_ic_getVmOpKind(program, op, op1, NULL, 0, 0, 0, 0, 0);
}

/* Instruction with one operand */
static void db_vmOp1(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue op1, db_icDerefMode opDeref1) {
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1;
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = db_ic_getVmOpKind(program, op, op1, t, type, opKind1, DB_IC_VMOPERAND_NONE, opDeref1, 0);

    /* Set size of type in case return instruction needs to do a memcpy */ 
    if (op->kind == DB_IC_RET) {
        vmOp->hi.w = db_type_sizeof(t);
    }

    db_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
}

/* Instruction with one operand and one staged operand
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void db_vmOp1Staged(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue storage, db_icValue op1, db_icDerefMode storageDeref, db_icDerefMode opDeref1) {
    db_vmOp *vmStoredOp;
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, storageKind;

    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, NULL, storageDeref, opDeref1, 0,  &t, &type, &storageKind, &opKind1, NULL);
    vmOp->op = db_ic_getVmSTAGE1(type, opKind1);
    db_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
    
    vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
    vmStoredOp->op = db_ic_getVmOpKind(program, op, op1, t, type, storageKind, opKind1, storageDeref, opDeref1);
    db_ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Instruction with two operands */
static void db_vmOp2(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue op1, db_icValue op2, db_icDerefMode opDeref1, db_icDerefMode opDeref2) {
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, opKind2;
    
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);
    
    /* If instruction is DPV, stage first operand. DPV cannot be addressed in one instruction */
    if (db_vmIsDPV(type, opKind1, opKind2)) {
        /* Stage double argument */
        vmOp->op = db_ic_getVmSTAGE1(type, opKind2);
        db_ic_vmSetOp1Addr(program, vmOp, type, opKind2, op2);
        vmOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
        
        /* Perform a small trick: the actual instruction is still called DPV even though it only has one operand encoded. This
         * reduces overall complexity in the assembler and VM */
        vmOp->op = db_ic_getVmOpKind(program, op, op1, t, type, opKind1, opKind2, opDeref1, opDeref2);
        db_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
    } else {
        vmOp->op = db_ic_getVmOpKind(program, op, op1, t, type, opKind1, opKind2, opDeref1, opDeref2);
        db_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
    }
}

/* Instruction with two operands and a storage
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain the set. The result of these two ops will look like:
 *
 * set  Storage Operand1 (vmOp)
 * [op] Storage Operand2 (vmStoredOp)
 * */
static void db_vmOp2Storage(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue storage, db_icValue op1, db_icValue op2, db_icDerefMode storageDeref, db_icDerefMode opDeref1, db_icDerefMode opDeref2) {
    db_vmOp *vmStoredOp;
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = db_ic_getVmSet(t, (db_icStorage)storage, type, storageKind, opKind1, storageDeref, opDeref1);
    db_ic_vmSetOp2Addr(program, vmOp, type, storageKind, opKind1, storage, op1);
    
    vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
    vmStoredOp->op = db_ic_getVmOpKind(program, op, storage, t, type, storageKind, opKind2, storageDeref, opDeref2);
    db_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind2, storage, op2);
}

/* Set-instruction with two operands and a storage
 * Create extra operation. This will contain a set-operation and an extra set-operation
 * to store the result of the first set in storage. The result of these two ops will look like:
 *
 * set  Operand1 Operand2 (vmOp)
 * set  Storage Operand1 (vmStoredOp)
 * */
static void db_vmOp2Set(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue storage, db_icValue op1, db_icValue op2, db_icDerefMode storageDeref, db_icDerefMode opDeref1, db_icDerefMode opDeref2) {
    db_vmOp *vmStoredOp;
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    
    if (db_vmIsDPV(type, opKind1, opKind2)) {
        /* Stage double argument */
        vmOp->op = db_ic_getVmSTAGE1(type, opKind2);
        db_ic_vmSetOp1Addr(program, vmOp, type, opKind2, op2);
        vmOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
        
        /* Perform a small trick: the actual instruction is still called DPV even though it only has one operand encoded. This
         * reduces overall complexity in the assembler and VM */
        vmOp->op = db_ic_getVmOpKind(program, op, op1, t, type, opKind1, opKind2, opDeref1, opDeref2);
        db_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
    } else {
        vmOp->op = db_ic_getVmSet(t, (db_icStorage)op1, type, opKind1, opKind2, opDeref1, opDeref2);
        db_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
    }

    vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
    vmStoredOp->op = db_ic_getVmSet(t, (db_icStorage)storage, type, storageKind, opKind1, storageDeref, opDeref1);
    db_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
}

/* Instruction with two operands and two staged
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void db_vmOp2Staged(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue storage, db_icValue op1, db_icValue op2, db_icDerefMode storageDeref, db_icDerefMode opDeref1, db_icDerefMode opDeref2) {
    db_vmOp *vmStoredOp;
    db_type t;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);

    if (db_vmIsDPV(type, opKind1, opKind2)) {
        /* Stage argument #1 */
        vmOp->op = db_ic_getVmSTAGE1(type, opKind1);
        db_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
        
        /* Stage argument #2 */
        vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
        vmStoredOp->op = db_ic_getVmSTAGE12(type, opKind2);
        db_ic_vmSetOp1Addr(program, vmStoredOp, type, opKind2, op2);
    } else {
        vmOp->op = db_ic_getVmSTAGE2(type, opKind1, opKind2);
        db_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
    }
    
    vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
    vmStoredOp->op = db_ic_getVmOpKind(program, op, storage, t, type, storageKind, opKind1, storageDeref, opDeref1);
    db_ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Cast instruction with either a reference cast or two staged types, a source and storage */
static void db_vmOp2Cast(db_ic_vmProgram *program, db_vmOp *vmOp, db_icOp op, db_icValue storage, db_icValue op1, db_icValue op2, db_icDerefMode storageDeref, db_icDerefMode opDeref1, db_icDerefMode opDeref2) {
    db_vmOp *vmStoredOp;
    db_type sourceType, destinationType;
    db_ic_vmType type;
    db_ic_vmOperand opKind1, opKind2, storageKind;
    
    destinationType = db_ic_valueType(storage);
    
    /* If destinationType is a reference, insert regular 2-operand instruction */
    if (destinationType->reference) {
        db_vmOp2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
    /* If destinationType is not a reference, stage types and insert primitive cast */
    } else {
        vmOp = db_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &sourceType, &type, &storageKind, &opKind1, &opKind2);

        vmOp->op = DB_VM_STAGE2_LVV;
        vmOp->lo.w = (db_word)sourceType;
        vmOp->hi.w = (db_word)destinationType;
        
        vmStoredOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);
        vmStoredOp->op = db_ic_getVmOpKind(program, op, storage, sourceType, type, storageKind, opKind1, storageDeref, opDeref1);
        db_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
    }
}

static void db_ic_getVmOp(db_ic_vmProgram *program, db_icOp op) {
	db_icDerefMode opDeref1=0, opDeref2=0, storageDeref=0;
	db_icValue op1 = NULL, op2 = NULL, storage = NULL;
	db_vmOp *vmOp;
	db_bool stageOperands = FALSE;
    db_bool castOperands = FALSE;

	/* Allocate operation */
	vmOp = db_vmProgram_addOp(program->program, ((db_ic)op)->line);

	switch(op->kind) {
	/* Following operations do not have storage and one operand (op->s1 points to 1st operand) */
	case DB_IC_UPDATE:
	case DB_IC_UPDATEEND:
        /* Update-from parameter requires a 2nd operand */
		if (op->s2) {
			op2 = op->s2;
			opDeref2 = op->s2Deref;
		}
		/* no break */
	case DB_IC_DEFINE:
	case DB_IC_INC:
	case DB_IC_DEC:
	case DB_IC_RET:
	case DB_IC_FREE:
	case DB_IC_KEEP:
	case DB_IC_UPDATEBEGIN:
	case DB_IC_UPDATECANCEL:
	case DB_IC_PUSH:
	case DB_IC_WAITFOR:
		op1 = op->s1;
		storage = NULL;
		opDeref1 = op->s1Deref;
		break;

	/* Following operations have one operand and a storage. This category is unusual but is used when the result has a different
	 * type than the operands. */
	case DB_IC_COND_NOT:
		stageOperands = TRUE;
		storage = op->s1;
		storageDeref = op->s1Deref;
		op1 = op->s2;
		opDeref1 = op->s2Deref;
		break;

	/* Following operations do not have storage and two operands (op->s1 to 1st, op->s2 to 2nd operand) */
	case DB_IC_JEQ:
	case DB_IC_JNEQ:
	case DB_IC_NEW:
	case DB_IC_WAIT:
		op1 = op->s1;
		op2 = op->s2;
		storage = NULL;
		opDeref1 = op->s1Deref;
		opDeref2 = op->s2Deref;
		break;

	/* Jump sets jump address */
	case DB_IC_JUMP: {
        db_ic_vmLabel *label;
        label = db_ic_vmLabelGet(program, *(db_uint32*)db_ic_valueValue(program, op->s1));
        db_ic_vmLabelAddReferee(program, label, &vmOp->lo.w);
        op1 = NULL;
        op2 = NULL;
        storage = NULL;
	    break;
	}

	/* Call sets function address */
	case DB_IC_CALL:
		op1 = op->s1;
		storage = NULL;
		vmOp->hi.w = (db_word)((db_icObject)op->s2)->ptr;
		opDeref1 = op->s1Deref;
		break;

	/* Cast */
	case DB_IC_CAST:
        castOperands = TRUE;

    /* no break */
	case DB_IC_COND_OR:
	case DB_IC_COND_AND:
	case DB_IC_COND_EQ:
	case DB_IC_COND_NEQ:
	case DB_IC_COND_GT:
	case DB_IC_COND_GTEQ:
	case DB_IC_COND_LT:
	case DB_IC_COND_LTEQ:
        /* Conditional operations require staging */
        if (op->kind != DB_IC_CAST) {
            stageOperands = TRUE;
        }
	default:
		op1 = op->s2;
		op2 = op->s3;
		storage = op->s1;
		opDeref1 = op->s2Deref;
		opDeref2 = op->s3Deref;
		storageDeref = op->s1Deref;
		break;
	}

	/* Assemble the actual operation, differentiate between 1 and 2-operand operations */
	if (op1) {
		/* Operation has two operands */
		if (op2) {
			/* If operation has a storage-operand, insert set-operation */
			if (storage && (storage != op1)) {
				if (op->kind == DB_IC_SET) {
					db_vmOp2Set(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
				} else{
					if (!stageOperands) {
                        if (castOperands) {
                            db_vmOp2Cast(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        } else {
                            db_vmOp2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        }
                    } else {
                        db_vmOp2Staged(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
					}
				}
			} else {
				db_vmOp2(program, vmOp, op, op1, op2, opDeref1, opDeref2);
			}
		/* Operation has one operand */
		} else {
			if (!stageOperands) {
				db_vmOp1(program, vmOp, op, op1, opDeref1);
			} else {
                db_vmOp1Staged(program, vmOp, op, storage, op1, storageDeref, opDeref1);
			}
		}
	} else {
	    db_vmOp0(program, vmOp, op, storage, storageDeref);
	}
}

static db_int16 db_icOp_toVm(db_icOp op, db_ic_vmProgram *program) {
	DB_UNUSED(program);

	if (!program->program) {
	    program->program = db_vmProgram_new(program->icProgram->filename, program->function->function);
	}

	/* If operation is push, increase stack-size */
	if (op->kind == DB_IC_PUSH) {
	    db_type t = db_ic_valueType(op->s1);
	    program->stackSize += db_type_sizeof(t);
	    if (program->stackSize > program->maxStackSize) {
	        program->maxStackSize = program->stackSize;
	    }
	}

	if (op->kind == DB_IC_CALL) {
	    db_function f;

	    /* When the function is a vm-function the vm will directly invoke the function
	     * without using db_call. To avoid memcpy'ing between the stack of the calling
	     * function and the storage of the called function the stack is made as big as the
	     * largest storage of all called functions.
	     *
	     * Because the storage-size of the function is not known when the function is not
	     * yet defined, setting the stack-size is in this case delayed until all functions
	     * are assembled.
	     */
	    f = ((db_icObject)op->s2)->ptr;
        if (f->kind == DB_PROCEDURE_VM) {
            if (db_checkState(f, DB_DEFINED)) {
                db_vmProgram inlineProgram = (db_vmProgram)f->impl;
                if (inlineProgram->storage > program->maxStackSize) {
                    program->maxStackSize = inlineProgram->storage;
                }
            } else {
                db_ic_vmInlineFunctionMark(program, program->program, f);
            }
	    }

        /* Reset stacksize */
	    program->stackSize = 0;
	}

	db_ic_getVmOp(program, op);

	return 0;
}

static db_uint16 db_ic_vmProgram_push(db_ic_vmProgram *program) {
    db_uint16 result = 0;

    if (program->scope) {
        result = program->scopeSize[program->scope - 1];
    }

	program->scope++;
	program->scopeSize[program->scope-1] = 0;

	return result;
}

static void db_ic_vmProgram_setScopeSize(db_ic_vmProgram *program, db_uint16 size) {
    program->scopeSize[program->scope-1] = size;
    if (size > program->maxScopeSize) {
    	program->maxScopeSize = size;
    }
}

static void db_ic_vmProgram_pop(db_ic_vmProgram *program) {
	program->scope--;
}

static void db_icZeroLocal(db_ic_vmProgram *program, db_uint16 initStart, db_uint16 size) {
    db_vmOp *vmOp;

	vmOp = db_vmProgram_addOp(program->program, 0);

	switch(size) {
	case sizeof(db_uint8):
		vmOp->op = DB_VM_SET_BRV;
		vmOp->ic.b._1 = initStart;
		vmOp->ic.b._2 = 0;
		break;
	case sizeof(db_uint16):
		vmOp->op = DB_VM_SET_SRV;
		vmOp->ic.b._1 = initStart;
		vmOp->ic.b._2 = 0;
		break;
	case sizeof(db_word):
		vmOp->op = DB_VM_SET_LRV;
		vmOp->ic.b._1 = initStart;
		vmOp->lo.w = 0;
		break;
	case sizeof(db_uint64):
		vmOp->op = DB_VM_SET_DRV;
		vmOp->ic.b._1 = initStart;
		vmOp->lo.w = 0;
		break;
	default:
		vmOp->op = DB_VM_ZERO;
		vmOp->ic.b._1 = initStart;
		vmOp->lo.w = size;
		break;
	}
}

static void db_icInitLocal(db_ic_vmProgram *program, db_uint16 localAddr, db_type type) {
    db_vmOp *vmOp;
    
	vmOp = db_vmProgram_addOp(program->program, 0);

    vmOp->op = DB_VM_INIT;
    vmOp->ic.b._1 = localAddr;
    vmOp->lo.w = (db_word)type;
}

static db_int16 db_icScope_toVm(db_icScope scope, db_ic_vmProgram *program) {
    db_iter programIter, localIter;
    db_ic ic;
    db_int16 result = 0;
    db_icStorage storage = NULL, local = NULL;
    db_uint16 size, initStart;
	db_ic_vmStorage *thisLocal = NULL;

    /* Push a new scope to the program. This manages an administration
     * which keeps track of how much memory each scope requires. */
    size = db_ic_vmProgram_push(program);

    /* Add locals to program */
    localIter = db_llIter(scope->storages);
    initStart = size;
    while(db_iterHasNext(&localIter)) {
    	storage = db_iterNext(&localIter);
    	if (storage->kind == DB_STORAGE_LOCAL) {
    	    db_ic_vmStorage *vmLocal;
            db_bool zeroLocal = TRUE;
    	    local = storage;

    		/* Lookup local in program */
	    	vmLocal = db_ic_vmStorageGet(program, local);

	    	/* The 'super' local is actually an alias for the 'this' local
	    	 * with a different type. As such it doesn't need extra space and
	    	 * the address is equal to this. */
    	    if (!strcmp(local->name, "super")) {
    	    	if (thisLocal) {
    	    		vmLocal->addr = thisLocal->addr; /* Use address of this */
    	    	}
    	    } else {
    	    	vmLocal->addr = size;
    	    	if (!strcmp(local->name, "this")) {
    	    		thisLocal = vmLocal;
    	    	}

        		if (((db_icLocal)local)->isParameter) {
        			/* Parameters are not zero'd, so zero all locals up to this point */
        			if (initStart != size) {
        				db_icZeroLocal(program, initStart, size - initStart);
        			}
                    zeroLocal = FALSE;
        		} else if (!local->isReference && (local->type->kind == DB_COLLECTION) && (db_collection(local->type)->kind == DB_LIST)) {
                    db_icZeroLocal(program, initStart, size - initStart);
                    db_icInitLocal(program, size, local->type);
                    zeroLocal = FALSE;
                }

        		/* Increase size */
        		if (db_ic_isReference(local)) {
					size += sizeof(db_word);
        		} else {
                    size += db_type_sizeof(local->type);
        		}

                if (!zeroLocal) {
                	initStart = size;
        		}
    	    }
    	}
    }

    if (size != initStart) {
    	if (!((db_icLocal)local)->isParameter) {
    		db_icZeroLocal(program, initStart, size - initStart);
    	}
    }

    /* Set size of scope so that child-scopes know where there locals starts. */
    db_ic_vmProgram_setScopeSize(program, size);

    programIter = db_llIter(scope->program);
    while(db_iterHasNext(&programIter)) {
        ic = db_iterNext(&programIter);
        switch(ic->kind) {
        case DB_IC_FUNCTION:
            db_ic_vmProgram_finalize(program);
            program->function = (db_icFunction)ic;
            break;
        case DB_IC_STORAGE:
        case DB_IC_LITERAL:
        	break;
        case DB_IC_LABEL:
        	result = db_icLabel_toVm((db_icLabel)ic, program);
        	break;
        case DB_IC_SCOPE:
        	result = db_icScope_toVm((db_icScope)ic, program);
        	break;
        case DB_IC_OP:
        	result = db_icOp_toVm((db_icOp)ic, program);
        	break;
        }
    }

    db_ic_vmProgram_pop(program);

    return result;
}

db_vmProgram db_icProgram_toVm(db_icProgram program) {
    db_ic_vmProgram vmProgram;
    db_iter functionIter;
    db_function function;
    db_iter inlineFunctionIter;
    db_ic_vmInlineFunction *inlineFunction;
    
    if (!program->errors) {
        /* Parse main-program */
        vmProgram.icProgram = program;
        vmProgram.main = db_vmProgram_new(program->filename, NULL);
        vmProgram.program = vmProgram.main;
        vmProgram.function = NULL;
        vmProgram.labels = NULL;
        vmProgram.accumulators = NULL;
        vmProgram.inlineFunctions = NULL;
        vmProgram.scope = 0;
        vmProgram.maxScopeSize = 0;
        vmProgram.stackSize = 0;
        vmProgram.maxStackSize = 0;

        /* Set kind of functions to VM - that way they can be
         * recognized as such and make usage of optimzations available
         * when calling vm-to-vm functions. */
        functionIter = db_llIter(program->functions);
        while(db_iterHasNext(&functionIter)) {
            function = ((db_icFunction)db_iterNext(&functionIter))->function;
            function->kind = DB_PROCEDURE_VM;
        }

        /* Start assembling */
        if (db_icScope_toVm(program->scope, &vmProgram)) {
            goto error;
        }

        /* Finalize last program */
        db_ic_vmProgram_finalize(&vmProgram);

        /* Correct stack-sizes for inline functions that have been finalized
         * after they were encountered */
        if (vmProgram.inlineFunctions) {
            inlineFunctionIter = db_llIter(vmProgram.inlineFunctions);
            while(db_iterHasNext(&inlineFunctionIter)) {
                db_vmProgram program;
                inlineFunction = db_iterNext(&inlineFunctionIter);
                program = (db_vmProgram)inlineFunction->function->impl;
                if (program->storage > inlineFunction->program->stack) {
                    inlineFunction->program->stack = program->storage;
                }
                db_dealloc(inlineFunction);
            }
            db_llFree(vmProgram.inlineFunctions);
        }
    } else {
        printf("%s: program contains errors, cannot compile.\n", program->filename);
        goto error;
    }

    return vmProgram.main;
error:
	return NULL;
}



