# ::corto::lang
The lang package contains the types of the Corto typesystem.


## alias
Enables creating an alias to a (hidden) member in an interface.

### construct()
#### Returns
### init()
#### Returns
### member

## any
Type that can represent any value.

## array
Enables construction of fixed length, consecutively stored collections.

### construct()
#### Returns
### destruct()
### elementType
Element type of the array. 

This field can be any type except for non-reference VOID types. The elementType
for an array must be DEFINED, whereas in other collections this is not required.
The rationale behind this is that at construction time, the type will calculate
it's size, which in the case of an array depends on the size of its elementType.

### init()
#### Returns

## attr
Object attributes.

`ATTR_DEFAULT` will automatically add `ATTR_OBSERVABLE` for all types, `ATTR_WRITABLE`
for non-VOID objects and `ATTR_PERSISTENT` when `ATTR_SCOPED` is selected.

`ATTR_OBSERVABLE` objects emit notifications on lifecycle events. 

`ATTR_PERSISTENT` objects have an additional timestamp and owner field. These fields 
are used by replicators to synchronize objects between datastores. Additionally,
to ensure consistency across stores, `ATTR_PERSISTENT` objects will align `DECLARED` and
`DEFINED` events to a 'late joining' observer, when the observable is respectfully
`DECLARED` and/or `DEFINED`. This ensures that regardless of when the replication
process starts, the two datastores will end up with the same object state.

Attributes can be set with the `cx_setattr` function. This function sets the
attributes for all subsequently created objects in the thread from which the 
function is called. By default the attribute is set to `ATTR_DEFAULT`.

### ATTR_DEFAULT
Corto automatically selects the attributes of an object based on its type.

### ATTR_OBSERVABLE
The object will be observable.

### ATTR_PERSISTENT
The object will be timestamped and notifications will be aligned to observers 
upon subscription. ATTR_PERSISTENT requires ATTR_SCOPED.

### ATTR_SCOPED
The object will be added to the Corto hierarchical datastore. Scoped objects can
only be created with cx_declareChild or cx_createChild, which automatically sets
the ATTR_SCOPED attribute.

### ATTR_WRITABLE
The object will be writable, which means its value can be locked.

## binary
Enables construction of binary types.

A binary type is a type that does not undergo translation when it is transmitted
over a (networked) medium. For example, some network protocols may require byte
swapping to match endianness, but binary values will be left intact.

When binary values are used in code, they behave just like unsigned integers. Binary
values are usually visualized using hexadecimal notation.
 

**Example**
```
binary{width_16} bin16
bin16 b: 0xFF
```

### init()
#### Returns

## bitmask
Enables construction of bitmask types.

Bitmasks are values of which each bit is assigned a semantical meaning. Bits can
be enabled (set to 1) or disabled (set to 0).

The bitmask type provides a convenient method of working with bitmasks. A bitmask
type contains, much like an enumeration, a set of constants. These constants by
default describe the meaning of one bit.

Take for example:
```
bitmask Color::
    Red, Yellow, Blue
```
Here, the constants `Red`, `Yellow` and `Blue` would be assigned the following values:

| Constant | Value |
|----------|-------|
|Red     |0x1  |
|Yellow  |0x2  |
|Blue    |0x4  |

A value of this type can enable multiple bits by specifying the corresponding constants:
```
Color purple: Red | Blue
```
Additionally, a bitmask may contain constants that enable multiple bits:
```
bitmask Color::
    Red, Yellow, Blue,
    Purple: Red | Blue
```

### init()
#### Returns

## bool
Scalar boolean type.

## boolean
Enables construction of boolean types.

Boolean values can be either `true` or `false`. 

### init()
#### Returns

## char
Scalar character type.

## character
Enables construction of character types.

Characters are types that can represent a single character. Currently only the ASCII
character set is supported. Future versions of Corto will add support for UTF-8.

### init()
#### Returns

## class
Enables creating composite reference types.

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
Specifies the interfaces implemented by the class.

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
Enables construction of collection types.

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
Lists the different corto collection kinds.

The collectionKind enumeration is used in the collection class to be able to
quickly determine what kind of collection it describes. This enumeration is
interpreted primarily by code that relies on metadata, such as the serializer
framework, code generators and data visualization tools.

### ARRAY
Indicates an array collection. 

### LIST
Indicates a list collection.

### MAP
Indicates a map collection.

### SEQUENCE
Indicates a sequence collection.


## compositeKind
Composite typekinds.

The compositeKind enumeration is used in the interface class to be able to
quickly determine what kind of composite it describes. This enumeration is
interpreted primarily by code that relies on metadata, such as the serializer
framework, code generators and data visualization tools.

### CLASS
Indicates a class composite.

### DELEGATE
Indicates a delegate composite.

### INTERFACE
Indicates an interface composite.

### PROCEDURE
Indicates a procedure composite.

### STRUCT
Indicates a struct composite.


## constant
Scalar integer type used for enumerations and bitmasks.

### init()
#### Returns

## delegate
Enables construction of delegate types.

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
Base for all delegate types.

### instance
### procedure

## destructAction
Delegate used for class destructors.


## dispatcher
Interface for manual dispatching of events.

### post(event e)
#### e

## enum
Enables construction of enumeration types.

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
Used as result of equality comparisons.

The most common use of equalityKind is in the core compare functions, which
are used for various purposes. Both the typesystem and core rely on comparisons
for storing objects in tree structures, where the hierarchical object store is
the most visible example.
NEQ might be returned in a scenario where the two values cannot be compared, for
example, when they are of incompatible types.

### EQ
The provided values are equal.

### GT
The first value that is first provided is larger than the second value.

### LT
The first value that is first provided is smaller than the second value.

### NEQ
The provided values are not equal.


## event
Base class for all events.

### handle()
### handled
### kind
### uniqueKind()
#### Returns

## eventMask
Flags that can be provided to subscribe for object notifications.

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
Enables construction of floating point types.

### init()
#### Returns
### max
### min

## float32
32 bit floating point type.


## float64
64 bit floating point type.


## function
Enables construction of procedure objects.

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
Delegate used for type initializers and class constructors.


## int
Enables construction of signed integer types.

### init()
#### Returns
### max
### min

## int16
16 bit signed integer


## int32
32 bit signed integer


## int64
64 bit signed integer


## int8
8 bit signed integer


## interface
Enables programming by contract.

### base
Specifies the interface from which to inherit.

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
Sequence of interface elements.


## interfaceVector
Enables quick lookups of interface methods.

### interface
### vector

## interfaceVectorseq
Sequence of interfaceVector elements.


## invokeAction
Delegate used by replicators to forward calls.


## invokeEvent
Event used by delegates to forward calls.

### args
### function
### handle()
### instance
### replicator

## iterator
Provides generic iterator functionality for collections.

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
Enables construction of variable length, linked list collections.

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
Enables construction of key-value pair collections.

### construct()
#### Returns
### elementType
### init()
#### Returns
### keyType
### max

## member
Provides capability to add members to composite types.

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
Sequence of member elements.


## metaprocedure
Procedure defined on the meta (type of type) level.

### bind()
#### Returns
### referenceOnly

## method
Procedure type that provides instance methods.

### bind()
#### Returns
### init()
#### Returns
### virtual

## modifier
Mask that enables specifying access to members.

### CONST
### GLOBAL
### HIDDEN
### LOCAL
### PRIVATE
### READONLY

## notifyAction
Delegate used by replicators to receive object notifications.


## object
Type that allows for storing references to objects of any type.


## objectseq
Sequence of object elements.


## observableEvent
Event used to forward observable notifications.

### handle()
### me
### observable
### observer
### source

## observer
Procedure that is invoked when an interest matching notification occurs. 

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
Sequence of observer elements.


## octet
Scalar 8 bit binary type.


## octetseq
Sequence of octet elements


## operatorKind
Operators supported by core.

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
Container for types that can be shared across projects.

### url

## parameter
Describes a function parameter.

### name
### passByReference
### type

## parameterseq
Sequence of parameter elements.


## primitive
Enables construction of primitive types.

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
Primitive typekinds.

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
Enables construction of procedure types.

### bind
### init()
#### Returns
### kind
### unbind(function object)
#### object

## procedureKind
Procedure typekinds.

### FUNCTION
### METAPROCEDURE
### METHOD
### OBSERVER

## query
Provides the capability to select and query subsections of the corto store.

### from
### mask

## replicator
Base for classes that replicate data between datasources.

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
Enables construction of variable length, consecutive collection.

### construct()
#### Returns
### init()
#### Returns
### size(uint32 size)
#### size

## state
Object states.

### DECLARED
### DEFINED
### DESTRUCTED
### VALID

## string
Allows representing text.


## struct
Enables construction of composite valuetypes.

### base
### baseAccess
Access modifiers for members of the inherited interface.

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
Enables construction of types that allow representing text.

### charWidth
### init()
#### Returns
### length

## type
Base class for all types.

### alignment
### alignmentof()
Returns C alignment of type.

#### Returns
### allocSize()
Returns allocation size for type.

#### Returns
### castable(type type)
Can provided type be casted to this type.

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
Can provided type be assigned to this type.

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
The type to use when no explicit type is provided in a procedure declaration.

### defaultType
The type to use when no explicit type is provided in an object declaration.

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
Specifies the whether the type is (amongst others) a primitive, composite or collection type.

### lookup(string name)
#### name
#### Returns
### metaprocedures
### nameof()
#### Returns
### parentof()
#### Returns
### parentState
When declaring a scoped object, its parent must be in the specified state.

### parentType
When declaring a scoped object, its parent must be of the specified type.

### reference
Specifies whether type type is a reference type (TRUE) or a value type (FALSE)

### relname(object from)
#### from
#### Returns
### resolve(string name)
#### name
#### Returns
### resolveProcedure(string name)
Find a procedure with the specified name in this type.

#### name
The name of the procedure to be resolved.

#### Returns
### size
### sizeof()
Returns database size of type.

#### Returns
### templateId
### toString()
#### Returns
### typeof()
#### Returns

## typeKind
Core type kinds.

### ANY
### COLLECTION
### COMPOSITE
### ITERATOR
### PRIMITIVE
### VOID

## uint
Enables construction of unsigned integer types.

### init()
#### Returns
### max
### min

## uint16
16 bit unsigned integer.


## uint32
32 bit unsigned integer.


## uint64
64 bit unsigned integer.


## uint8
8 bit unsigned integer.


## virtual
Method that can be overridden by a method in a subclass.

### init()
#### Returns

## void
Type that represents nothing.


## vtable
Type used to represent the method table of interface types.


## width
Enables representing width in bits.

### WIDTH_16
### WIDTH_32
### WIDTH_64
### WIDTH_8
### WIDTH_WORD

## word
Scalar word-sized binary type.

