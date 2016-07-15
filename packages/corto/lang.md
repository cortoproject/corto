# /corto/lang
Contains the Corto typesystem.


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
### base
### baseAccess
### construct
### construct()
#### Returns
### defaultProcedureType
### defaultType
### destruct
### destruct()
### implements
Specifies the interfaces implemented by the class.

### init()
#### Returns
### instanceof(object object)
#### object
#### Returns
### interfaceVector
### parentState
### parentType
### resolveInterfaceMethod(interface interface,uint32 method)
#### interface
#### method
#### Returns

## collection
Enables construction of collection types.

### castable(type type)
#### type
#### Returns
### compatible(type type)
#### type
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

### requiresAlloc(type elementType)
#### elementType
#### Returns
### size()
#### Returns

## collectionKind
Lists the different corto collection kinds.

The collectionKind enumeration is used in the collection class to be able to
quickly determine what kind of collection it describes. This enumeration is
interpreted primarily by code that relies on metadata, such as the serializer
framework, code generators and data visualization tools.
### ARRAY
### LIST
### MAP
### SEQUENCE

## compositeKind
Composite typekinds.

The compositeKind enumeration is used in the interface class to be able to
quickly determine what kind of composite it describes. This enumeration is
interpreted primarily by code that relies on metadata, such as the serializer
framework, code generators and data visualization tools.
### CLASS
### DELEGATE
### INTERFACE
### PROCEDURE
### STRUCT

## constant
Scalar integer type used for enumerations and bitmasks.

### init()
#### Returns

## delegate
Enables construction of delegate types.

### construct(function object)
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

## destructAction
Delegate used for class destructors.


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

### construct()
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
### destruct(function object)
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

### construct()
#### Returns
### referenceOnly

## method
Procedure type that provides instance methods.

### construct()
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


## object
Type that allows for storing references to objects of any type.


## objectseq
Sequence of object elements.


## octet
Scalar 8 bit binary type.


## octetseq
Sequence of octet elements


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
### BITMASK
### BOOLEAN
### CHARACTER
### ENUM
### FLOAT
### INTEGER
An integer value.

### TEXT
### UINTEGER
An unsigned integer value.


## procedure
Enables construction of procedure types.

### construct
### init()
#### Returns
### kind
### destruct(function object)
#### object

## procedureKind
Procedure typekinds.

### FUNCTION
### METAPROCEDURE
### METHOD
### OBSERVER
A procedure that is called upon a notification.


## sequence
Enables construction of variable length, consecutive collection.

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
### COLLECTION
### COMPOSITE
A set of members (see compositeKind).

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
