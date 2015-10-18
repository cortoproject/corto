# ::corto::lang

## alias
### construct()
#### Returns
### init()
#### Returns
### member

## any

## array
### construct()
#### Returns
### destruct()
### elementType
### init()
#### Returns

## attr
### ATTR_DEFAULT
### ATTR_OBSERVABLE
### ATTR_PERSISTENT
### ATTR_SCOPED
### ATTR_WRITABLE

## binary
### init()
#### Returns

## bitmask
### init()
#### Returns

## bool

## boolean
### init()
#### Returns

## char

## character
### init()
#### Returns

## class
### allocSize()
#### Returns
### base
### baseAccess
### bindObserver(observer observer)
#### observer
### construct
### construct()
#### Returns
### defaultProcedureType
### defaultType
### destruct
### destruct()
### eventMaskOf(observer observer)
#### observer
#### Returns
### findObserver(object observable)
#### observable
#### Returns
### implements
### init()
#### Returns
### instanceof(object object)
#### object
#### Returns
### interfaceVector
### listen(observer observer,eventMask mask,object observable,dispatcher dispatcher)
#### observer
#### mask
#### observable
#### dispatcher
### observableOf(observer observer)
#### observer
#### Returns
### observers
### parentState
### parentType
### privateObserver(object object,observer observer)
#### object
#### observer
#### Returns
### resolveInterfaceMethod(interface interface,uint32 method)
#### interface
#### method
#### Returns
### setDispatcher(observer observer,dispatcher dispatcher
#### observer
#### dispatcher
### setMask(observer observer,eventMask mask)
#### observer
#### mask
### setObservable(observer observer,object observable)
#### observer
#### observable

## collection
### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
#### Returns
### elementRequiresAlloc()
#### Returns
### elementType
### init()
#### Returns
### kind
### max
### size()
#### Returns

## collectionKind
### ARRAY
### LIST
### MAP
### SEQUENCE

## compositeKind
### CLASS
### DELEGATE
### INTERFACE
### PROCEDURE
### STRUCT

## constant
### init()
#### Returns

## delegate
### bind(function object)
#### object
#### Returns
### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
#### Returns
### init()
#### Returns
### instanceof(object object)
#### object
#### Returns
### parameters
### returnsReference
### returnType

## delegatedata
### instance
### procedure

## destructAction

## dispatcher
### post(event e)
#### e

## enum
### constant(int32 value)
#### value
#### Returns
### constants
### construct()
#### Returns
### destruct()
### init()
#### Returns

## equalityKind
### EQ
### GT
### LT
### NEQ

## event
### handle()
### handled
### kind
### uniqueKind()
#### Returns

## eventMask
### ON_DECLARE
### ON_DEFINE
### ON_DELETE
### ON_INVALIDATE
### ON_METAVALUE
### ON_SCOPE
### ON_SELF
### ON_TREE
### ON_UPDATE
### ON_VALUE

## float
### init()
#### Returns
### max
### min

## float32

## float64

## function
### bind()
#### Returns
### impl
### implData
### init()
#### Returns
### kind
### nextParameterId
### overloaded
### parameters
### resource
### returnsReference
### returnType
### size
### stringToParameterSeq(string name,object scope)
#### name
#### scope
#### Returns
### unbind(function object)
#### object

## initAction

## int
### init()
#### Returns
### max
### min

## int16

## int32

## int64

## int8

## interface
### base
### baseof(interface type)
#### type
#### Returns
### bindMethod(method method)
#### method
#### Returns
### compatible(type type)
#### type
#### Returns
### construct()
#### Returns
### defaultProcedureType
### defaultType
### destruct()
### init()
#### Returns
### kind
### members
### methods
### nextMemberId
### parentState
### parentType
### resolveMember(string name)
#### name
#### Returns
### resolveMethod(string name)
#### name
#### Returns
### resolveMethodById(uint32 id)
#### id
#### Returns
### resolveMethodId(string name)
#### name
#### Returns

## interfaceseq

## interfaceVector
### interface
### vector

## interfaceVectorseq

## invokeAction

## invokeEvent
### args
### function
### handle()
### instance
### replicator

## iterator
### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
#### Returns
### elementType
### init()
#### Returns

## list
### append()
#### Returns
### append(any element)
#### element
### clear()
### construct()
#### Returns
### init()
#### Returns
### insert()
#### Returns
### insert(any element)
#### element
### reverse()

## map
### construct()
#### Returns
### elementType
### init()
#### Returns
### keyType
### max

## member
### construct()
#### Returns
### id
### init()
#### Returns
### modifiers
### offset
### state
### type
### weak

## memberseq

## metaprocedure
### bind()
#### Returns
### referenceOnly

## method
### bind()
#### Returns
### init()
#### Returns
### virtual

## modifier
### CONST
### GLOBAL
### HIDDEN
### LOCAL
### PRIVATE
### READONLY

## notifyAction

## object

## objectseq

## observableEvent
### handle()
### me
### observable
### observer
### source

## observer
### bind()
#### Returns
### delayedBinder
### dispatcher
### init()
#### Returns
### listen(object observable,object me)
#### observable
#### me
#### Returns
### mask
### me
### observable
### observing
### setDispatcher(dispatcher dispatcher)
#### dispatcher
### silence(object me)
#### me
#### Returns
### template
### unbind(observer object)
#### object

## observerseq

## octet

## octetseq

## operatorKind
### ADD
### AND
### ASSIGN
### ASSIGN_ADD
### ASSIGN_AND
### ASSIGN_DIV
### ASSIGN_MOD
### ASSIGN_MUL
### ASSIGN_OR
### ASSIGN_SUB
### ASSIGN_UPDATE
### ASSIGN_XOR
### COND_AND
### COND_EQ
### COND_GT
### COND_GTEQ
### COND_LT
### COND_LTEQ
### COND_NEQ
### COND_NOT
### COND_OR
### DEC
### DIV
### INC
### MOD
### MUL
### NOT
### OR
### REF
### SHIFT_LEFT
### SHIFT_RIGHT
### SUB
### XOR

## package
### url

## parameter
### name
### passByReference
### type

## parameterseq

## primitive
### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
#### Returns
### construct()
#### Returns
### convertId
### init()
#### Returns
### isInteger()
#### Returns
### isNumber()
#### Returns
### kind
### width

## primitiveKind
### BINARY
### BITMASK
### BOOLEAN
### CHARACTER
### ENUM
### FLOAT
### INTEGER
### TEXT
### UINTEGER

## procedure
### bind
### init()
#### Returns
### kind
### unbind(function object)
#### object

## procedureKind
### FUNCTION
### METAPROCEDURE
### METHOD
### OBSERVER

## query
### from
### mask

## replicator
### construct()
#### Returns
### destruct()
### invoke(object instance,function proc,octetseq args)
#### instance
#### proc
#### args
### mount
### on_declare
#### observable
### on_delete
#### observable
### on_update
#### observable
### onDeclare
### onDelete
### onInvoke
### onUpdate
### post(event e)
#### e
### query

## sequence
### construct()
#### Returns
### init()
#### Returns
### size(uint32 size)
#### size

## state
### DECLARED
### DEFINED
### DESTRUCTED
### VALID

## string

## struct
### base
### baseAccess
### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
#### Returns
### construct()
#### Returns
### defaultProcedureType
### defaultType
### init()
#### Returns
### parentState
### parentType
### resolveMember(string name)
#### name
#### Returns

## text
### charWidth
### init()
#### Returns
### length

## type
### alignment
### alignmentof()
#### Returns
### allocSize()
#### Returns
### castable(type type)
#### type
#### Returns
### checkAttr(attr attributes)
#### attributes
#### Returns
### checkState(state state)
#### state
#### Returns
### compare(any value)
#### value
#### Returns
### compatible(type type)
#### type
#### Returns
### construct()
#### Returns
### copy(any value)
#### value
#### Returns
### declare(string name,type type)
#### name
#### type
#### Returns
### defaultProcedureType
### defaultType
### define()
#### Returns
### delete()
### destruct()
### fullname()
#### Returns
### hasResources
### init
### init()
#### Returns
### instanceof(type type)
#### type
#### Returns
### invalidate()
### kind
### lookup(string name)
#### name
#### Returns
### metaprocedures
### nameof()
#### Returns
### parentof()
#### Returns
### parentState
### parentType
### reference
### relname(object from)
#### from
#### Returns
### resolve(string name)
#### name
#### Returns
### resolveProcedure(string name)
#### name
#### Returns
### size
### sizeof()
#### Returns
### templateId
### toString()
#### Returns
### typeof()
#### Returns

## typeKind
### ANY
### COLLECTION
### COMPOSITE
### ITERATOR
### PRIMITIVE
### VOID

## uint
### init()
#### Returns
### max
### min

## uint16

## uint32

## uint64

## uint8

## virtual
### init()
#### Returns

## void

## vtable

## width
### WIDTH_16
### WIDTH_32
### WIDTH_64
### WIDTH_8
### WIDTH_WORD

## word
