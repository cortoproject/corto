
#include "ic_vmStorage.h"
#include "ic_vmProgram.h"

static void ic_vmProgram_fillInLabels(ic_vmProgram *program) {
    cx_iter labelIter;
    ic_vmLabel *label;
    cx_uint32 referee;

    if (program->labels) {
        labelIter = cx_llIter(program->labels);
        while(cx_iterHasNext(&labelIter)) {
            label = cx_iterNext(&labelIter);
            for(referee=0; referee < label->refereeCount; referee++) {
                *(void**)CX_OFFSET(label->referees[referee], program->program->program) = &program->program->program[label->pc];
            }

            /* Free label */
            cx_dealloc(label);
        }

        /* Free label list */
        cx_llFree(program->labels);
        program->labels = NULL;
    }
}

static void ic_vmProgram_allocateAccumulators(ic_vmProgram *program) {
    cx_iter accumulatorIter;
    ic_vmStorage *storage;
    cx_uint16 offset;
    ic_registerClaim claims[256];
    ic_registerClaim *claim;
    cx_uint32 i, referee;
    cx_bool overlap;

    memset(claims, 0, sizeof(claims));
    offset = program->maxScopeSize;

    if (program->storages) {
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            storage = cx_iterNext(&accumulatorIter);

            if (ic_vmStorage_mustAllocate(storage)) {

                /* Find lfree claim */
                claim = claims;
                while(claim->storage) {
                    if (claim->end < storage->firstUsed) { /* Accumulators are chronologically ordered, so this is valid */
                        break;
                    }
                    claim++;
                }

                claim->storage = storage;
                claim->start = storage->firstUsed;
                claim->end = storage->lastUsed;
                claim->addr = offset;
                
                /* If storage has to be allocated and it has a base, storage represents a member address */
                if (storage->base || storage->ic->isReference) {
                    claim->size = sizeof(cx_word);
                } else {
                    claim->size = cx_type_sizeof(storage->ic->type);
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
                } while (overlap);

                if ((claim->addr + claim->size) > program->maxScopeSize) {
                    program->maxScopeSize = claim->addr + claim->size;
                }

                for(referee=0; referee < storage->refereeCount; referee++) {
                    *(cx_uint16*)CX_OFFSET(storage->referees[referee], program->program->program) = claim->addr;
                }
                storage->addr = claim->addr;
            }
        }

        /* Free resources */
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            storage = cx_iterNext(&accumulatorIter);
            cx_dealloc(storage);
        }
        cx_llFree(program->storages);
        program->storages = NULL;
    }
}

ic_vmStorage *ic_vmProgram_getStorage(ic_vmProgram *program, ic_storage icAccumulator) {
    cx_iter accumulatorIter;
    ic_vmStorage *accumulator = NULL;

    if (program->storages) {
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            accumulator = cx_iterNext(&accumulatorIter);
            if (accumulator->ic == icAccumulator) {
                break;
            } else {
                accumulator = NULL;
            }
        }
    }

    if (!accumulator) {
        if (!program->program) {
            program->program = cx_vmProgram_new(program->icProgram->filename, program->function->function);
        }
        accumulator = ic_vmStorage__create(program, icAccumulator, program->program->size);
        if (!program->storages) {
            program->storages = cx_llNew();
        }
        cx_llAppend(program->storages, accumulator);
    }

    /* Keep track of where an accumulator is last used */
    accumulator->lastUsed = program->program->size;

    return accumulator;
}

void ic_vmProgram_finalize(ic_vmProgram *vmProgram) {
    cx_vmOp  *stop;

    /* Add STOP instruction if this is the main-module */
    if (vmProgram->main == vmProgram->program) {
        stop = cx_vmProgram_addOp(vmProgram->program, 0);
        stop->op = CX_VM_STOP;
    }

    /* Fill in labels */
    ic_vmProgram_fillInLabels(vmProgram);

    /* Allocate and fill in accumulators */
    ic_vmProgram_allocateAccumulators(vmProgram);

    /* Set size of program */
    vmProgram->program->storage = vmProgram->maxScopeSize;
    vmProgram->program->stack = vmProgram->maxStackSize;

    /* If program is a function, set the function-implementation to the program */
    if (vmProgram->function) {
        cx_function function = vmProgram->function->function;
        function->impl = (cx_word)cx_call_vm;
        function->implData = (cx_word)vmProgram->program;
        cx_define(function);

#ifdef IC_TRACING
        if (CX_DEBUG_ENABLED)
        {
            cx_id id;
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("%s %s\n%s\n", cx_nameof(cx_typeof(function)), cx_fullname(function, id), programStr);
            cx_dealloc(programStr);
        }
#endif
    }

#ifdef IC_TRACING
    if (CX_DEBUG_ENABLED) {
        if (vmProgram->main == vmProgram->program) {
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("main\n%s\n", programStr);
            cx_dealloc(programStr);
        }
    }
#endif

    /* Clean resources */
    ic_vmProgram_clean(vmProgram);
}

cx_uint16 ic_vmProgram_push(ic_vmProgram *program) {
    cx_uint16 result = 0;

    if (program->scope) {
        result = program->scopeSize[program->scope - 1];
    }

    program->scope++;
    program->scopeSize[program->scope-1] = 0;

    return result;
}

void ic_vmProgram_setScopeSize(ic_vmProgram *program, cx_uint16 size) {
    program->scopeSize[program->scope-1] = size;
    if (size > program->maxScopeSize) {
        program->maxScopeSize = size;
    }
}

void ic_vmProgram_pop(ic_vmProgram *program) {
    program->scope--;
}

void ic_vmProgram_clean(ic_vmProgram *vmProgram) {
    /* Reset values */
    vmProgram->scope = 0;
    vmProgram->maxScopeSize = 0;
    vmProgram->stackSize = 0;
    vmProgram->maxStackSize = 0;
    vmProgram->program = NULL;
}
