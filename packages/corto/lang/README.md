# /corto/lang
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

Attributes can be set with the `corto_setattr` function. This function sets the
attributes for all subsequently created objects in the thread from which the
function is called. By default the attribute is set to `ATTR_DEFAULT`.

The `corto_checkAttr` function can be used to check which attributes are enabled
for an object. The following example checks whether an object is SCOPED:

```
if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
    printf("name of o is %s\n", corto_nameof(o));
}
```
### ATTR_DEFAULT
Corto automatically selects the attributes of an object based on its type.
### ATTR_OBSERVABLE
The object will be observable.
### ATTR_PERSISTENT
The object will be timestamped and notifications will be aligned to observers
upon subscription. ATTR_PERSISTENT requires ATTR_SCOPED.
### ATTR_SCOPED
The object will be added to the Corto hierarchical datastore. Scoped objects can
only be created with corto_declareChild or corto_createChild, which automatically sets
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
Enables creating composite types that can inherit from & implement interfaces.
A class is a reference type, which means that any object created by a
class by definition is an object. Therefore, a class can offer additional
functionality over what is provided by a `struct`, which is a valuetype.

Firstly, a class contains a constructor and destructor delegate, which are invoked
when a class instance is respectively defined and deleted. A constructor returns a
16 bit integer value, which should be zero upon success, and non-zero upon failure.
When a non-zero value is returned, the  instance will be invalidated.

An example of a class definition with a constructor and destructor:

```
class Foo::
    int16 construct()
    void destruct()
```

Secondly, a class can *implement* one or more interfaces. During definition a class constructor
will validate that all methods of an implemented interface are implemented by
the class. Any composite type can be used as an interface. Interface variables
require run time type information to invoke interface methods, which is why this
behavior can only be implemented on reference types.

An example of a class that implements the `dispatcher` interface (notice that
implements expects a sequence of interfaces):

```
class Foo: implements = {dispatcher}::
    void post() // Implement dispatcher::post

```

Thirdly, a class can contain *instance observers*. These are observers that start
observing an observable whenever a new instance of the class is created. The instance
can set the observable, as well as other observer parameters in the constructor. The
subscription will take place right after the constructor has finished. Instance observers
pass the `this` pointer to the observer callback.

An example of a class with an instance observer:

```
class Foo::
    int16 construct()
    void onUpdate() observer // Set parameters for observer in constructor
```
An alternative way of specifying an instance observer:

```
class Foo::
    observer onUpdate: ON_UPDATE | ON_TREE, ::corto
```
### allocSize()
#### Returns
### base
### baseAccess
### bindObserver(observer observer)
Should not be invoked directly. Bind an observer with a class.
#### observer
### construct
### construct()
#### Returns
### defaultProcedureType
### defaultType
### destruct
### destruct()
### eventMaskOf(observer observer)
Return the event mask of an instance instance observer.
#### observer
#### Returns
### findObserver(object observable)
Find an instance observer for a given observable.
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
Should not be invoked directly (use `corto_listen`). Start listening to an observable.
#### observer
#### mask
#### observable
#### dispatcher
### observableOf(observer observer)
Return the observable for a given instance observer.
#### observer
#### Returns
### observers
### parentState
### parentType
### resolveInterfaceMethod(interface interface,uint32 method)
Resolve a method for a given interface and method id.
#### interface
#### method
#### Returns
### setDispatcher(observer observer,dispatcher dispatcher
#### observer
#### dispatcher
### setMask(observer observer,eventMask mask)
Set the eventmask for a given instance observer.
#### observer
#### mask
### setObservable(observer observer,object observable)
Set the observable for a given instance observer.
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
Returns whether memory has to be allocated to accommodate for a new element.
Arrays and sequences will always return false, since memory for elements is
allocated in a consecutive block. Lists and maps require allocations for
value types as element type that are larger than the size of a word.
#### Returns
### elementType
The type of which the elements in a collection will be. Depending on the kind
of collection, elements might require allocation. The `elementRequiresAlloc`
returns whether allocation is required.
### init()
#### Returns
### kind
Specifies the kind of collection. See `collectionKind` for a more detailed
description of the available options.
### max
The maximum number of elements for a given collection type.
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
Delegates are composite types, which allows a user to add custom members
and methods to a delegate type. Each delegate type inherits from the
delegatedata struct, which provides it with an instance and procedure object.
### instance
The instance of the delegate.
This member may be `null` when the procedure is not an
instance method.
### procedure
The procedure of the delegate.
The procedure must match the delegate type. Any
procedure that inherits from `corto/lang/function` is allowed.

## destructAction
Delegate used for class destructors.

## dispatcher
Interface for manual dispatching of events.
Dispatchers allow for intercepting various Corto events, which can then be
handled by a user in an appropriate way. An example could be to handle an event
in a different thread (threadpools) or to forward an event to a different
process.

A typical use for a dispatcher is to be associated with an observer, in which
case all object notifications are delivered to the post method as
`corto/lang/observableEvent` objects.
### post(event e)
The post method is invoked when an event is intercepted.
#### e

## enum
Enables construction of enumeration types.
### constant(int32 value)
Lookup a constant object by value.
Example:
```
corto_constant *Red = enum_constant(Color, Color_Red);
```
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
Event masks provide an easy mechanism to get notified of changes in
the lifecycle of objects. Different constants can be combined in a mask
to subscribe for multiple events at once.

Typically, a mask selects a type of event (`ON_DECLARE`, `ON_DEFINE`, `ON_UPDATE`,
`ON_DELETE`, `ON_INVALIDATE`), a scope modifier (`ON_SELF`, `ON_SCOPE`, `ON_TREE`)
and a value modifier (`ON_METAVALUE`, `ON_VALUE`). A mask has to at least provide one
event type. When no scope modifier is provided, `ON_SELF` will be
implicitly added. When no value modifier is provided, `ON_VALUE` will be implicitly
added.

The following example code subscribes to updates of direct children of the root:
```
corto_observerCreate(CORTO_ON_UPDATE | CORTO_ON_SCOPE, root_o, callback);
```
### ON_DECLARE
Notify when an object is declared.
### ON_DEFINE
Notify when an object is defined.
### ON_DELETE
Notify when an object is deleted.
### ON_INVALIDATE
Notify when an object is invalidated.
### ON_METAVALUE
Subscribe to object metadata (does not require lock on object value).
### ON_SCOPE
Subscribe to direct descendants in scope of observable.
### ON_SELF
Subscribe to observable (default).
### ON_TREE
Subscribe recursively to all descendants in scope of observable.
### ON_UPDATE
Notify when an object is updated.
### ON_VALUE
Subscribe to object value (requires locking object value)

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
Callback to the language-binding specific handler for invoking functions.
### implData
A pointer to userdata containing the language-binding specific function object.
### init()
#### Returns
### kind
### nextParameterId
### overloaded
Indicates whether a function is overloaded.
This member is set automatically when a function is declared that overloads an
already existing function.
### parameters
List of function parameters.
### resource
Deprecated. Allows a user to associate an object with the lifecycle of a
function.
### returnsReference
Indicates whether the function returns a reference.
This field does not need to be set when the return type is a reference type.
### returnType
The return type of the function.
### size
The size on stack of the function argument list.
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
Mask that specifies access to members.
### CONST
The member can only be set before an object is defined.
### GLOBAL
The member will be serialized (default).
### HIDDEN
The  member will be hidden from initializers.
### LOCAL
The member will not be serialized.
### PRIVATE
The member will not be accessible from outside of the interface.
### READONLY
The member can only be read from outside of the interface.

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
Operators supported by the core.
The operator kind is used by the core in the `corto_unaryOperator` and
`corto_binaryOperator` functions. The following code shows an example:

```
corto_int32 a = 10, b = 20, result = 0;
corto_binaryOperator(corto_int32_o, CORTO_ADD, &a, &b, &result);
// result = 30
```
### ADD
Add operator (+).
### AND
Logica and operator (&).
### ASSIGN
Assign operator (=).
### ASSIGN_ADD
Assign and add operator (+=)
### ASSIGN_AND
Assign and logical and operator (&=)
### ASSIGN_DIV
Assign and divide operator (/=)
### ASSIGN_MOD
Assign and modulo operator (%=)
### ASSIGN_MUL
Assign and multiply operator (*=)
### ASSIGN_OR
Assign and logical or operator (|=)
### ASSIGN_SUB
Assign and subtract operator (-=)
### ASSIGN_UPDATE
Assign and update operator (:=)
### ASSIGN_XOR
Assign and exclusive or operator (^=)
### COND_AND
Conditional and operator (&&)
### COND_EQ
Conditional equality operator (==)
### COND_GT
Conditional greater than operator (>)
### COND_GTEQ
Conditional greater than/equals operator (>=)
### COND_LT
Conditional lesser than operator (<)
### COND_LTEQ
Conditional lesser than/equals operator (<=)
### COND_NEQ
Conditional not equals operator (!=)
### COND_NOT
Conditional not operator (!)
### COND_OR
Conditional or operator (||)
### DEC
Decrease by one operator (--)
### DIV
Divide operator (/)
### INC
Increase by one operator (++)
### MOD
Modulo operator (%)
### MUL
Multiply operator (*)
### NOT
Logical not operator (!)
### OR
Logical or operator (|)
### REF
Reference operator (&)
### SHIFT_LEFT
Bitwise leftshift operator (<<)
### SHIFT_RIGHT
Bitwise rightshift operator (>>)
### SUB
Subtract opereator (-)
### XOR
Exclusive or operator (^)

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
Lists the possible primitive types in Corto.
The `primitiveKind` enumeration is used in `corto::lang::primitive` to quickly
determine what kind of primitive is described by a type. The kind is automatically
set by each primitive subclass.

A typical application of `primitiveKind` would be in code that serializes an object.
The following example shows how `primitiveKind` is used to check whether a type
represents a string:

```
if ((type->kind == CORTO_PRIMITIVE) && (corto_primitive(type)->kind == CORTO_TEXT)) {
    printf("%s represents a string\n", corto_nameof(type));
}
```
### BINARY
Binary values are not byte swapped when serialized.
### BITMASK
Enumeration value where each constant represents a bit in a 32 bit integer.
### BOOLEAN
Value that can hold either true or false.
### CHARACTER
A single ASCII character.
### ENUM
A list of constants.
### FLOAT
A floating point value.
### INTEGER
An integer value.
### TEXT
A string value.
### UINTEGER
An unsigned integer value.

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
A regular procedure with a returntype and argumentlist.
### METAPROCEDURE
A procedure that is defined on the type of type of an object.
### METHOD
An instance procedure. Can be virtual.
### OBSERVER
A procedure that is called upon a notification.

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

## selectResult
### name
### parent
### type

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
Object states provide information about where in its lifecycle an object is. This
information is important when determining whether to interpret the value of the
object. The value of an undefined objects should not be interpreted.

The state of an object changes when a lifecycle event occurs. This either means
that the object is declared, defined, destructed or invalidated. The following code
shows object states and lifecycle events:

```
corto_int32 *i = corto_declare(corto_int32_o);

// i is DECLARED

*i = 10;
if (corto_define(i)) {
    // error: i is INVALID
} else {
    // ok: i is DEFINED
}

corto_delete(i);

// i is DESTRUCTED and may no longer point to valid memory
```

An object loses its `VALID` flag it could not be defined. Typically this
happens when a constructor fails (it returned a non-zero value). When this happens,
the application can retry with a different value.

There can be other causes for an object to become invalid, for example when
an object is replicated from another source, and its time to live expires. In that
case the application can decide to delete the object, or wait until its source becomes
available again.

The `corto_checkState` function can be used to determine in what state an object is:

```
if (corto_checkState(i, CORTO_VALID | CORTO_DEFINED)) {
    printf("the value of i is %d\n", *i);
}
```
### DECLARED
The object is declared (initializer has been called).
### DEFINED
The object is defined (constructor has been called).
### DESTRUCTED
The object is destructed (destructor has been called).
### VALID
The object is valid.

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
Self describing value that hold data of any type.
### COLLECTION
An iterable collection of elements (see collectionKind).
### COMPOSITE
A set of members (see compositeKind).
### ITERATOR
An type that allows iterating over collections.
### PRIMITIVE
A primitive value (see primitiveKind).
### VOID
A type that represents nothing.

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
Example:
```
if ((type->kind == CORTO_PRIMITIVE) &&
    (corto_primitive(type)->kind == CORTO_INTEGER) &&
    (corto_primitive(type)->width == CORTO_WIDTH_32))
{
    printf("int32 value = %d\n", *(corto_int32*)value);
}
```
### WIDTH_16
16 bit value.
### WIDTH_32
32 bit value.
### WIDTH_64
64 bit value.
### WIDTH_8
8 bit value.
### WIDTH_WORD
Word sized value (architecture dependent)

## word
Scalar word-sized binary type.
