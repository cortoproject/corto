# Glossary

## Object
A temporary representation of real-life or abstract concepts that resides in an object store.

## Class
A class is an object that can be instanced to permit the creation of other objects. This concept is similar to other languages'.

A class is declared by instancing the `class` object. For example:

```
class Dog::
    name: string;
```

In this example, `Dog` is a class because it is an instance of `class` and therefore it can create `Dog` objects and `Dog` variables, for example:

```
Dog myDogObject;
var Dog myDogVar;
```

Careful! While `int32` lets you create objects of type `int32`, `int32` itself is not an instance of `class` and therefore it is technically not a class. Instead, it is an instance of the `int` class.

| Object | Type / Instance of | Parent class / Inherits from | Can be used to create objects 
---------|-------------|--------------|------------------------------
| `class` | `class` | None | Yes
| `Dog` | `class` | None | Yes
| `GoldenRetriever` | `class` | `Dog` | Yes
| `randomDog` | `Dog` | N.A. | No
| `gijs` | `GoldenRetriever` | N.A. | No
| `int` | `class` | None | Yes
| `int32` | `int` | None | Yes
| `myNumber` | `int32` | N.A. | No

## Identifier
In the traditional sense of the word, any "name" that can be used in code. Identifiers include both objects and variables.

## Namespace
Because every object has a scope, every object works like a namespace. Pure namespaces are `void` objects and solely serve the purpose of namespacing.

## Package

A package is a *.so file that may be loaded along a script.

## Scope

May refer to:
- The scope of an object is the collection of elements that are declared "under" it.
- The segment of code in which an identifier is usable. See [code scope](#code-scope).

## Code scope

Is the fragment of code during which a variable lives and its identifier can be used. Code scopes include values of procedures, scope of control flow structures, and pure scopes.

## Parent class

The class from which another class can inherit members and behavior. May be referred to as superclass.

## Parent

Parent may refer to either of a [parent class](#parent-class) (superclass) or the (hierarchical) parent of an object. In the latter case
