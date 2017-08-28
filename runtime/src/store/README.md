# The Object Store
This is the source code of the in-memory object store, which is compiled into
the corto runtime. The object store works like a hierarchically organized object
mapping on top of the virtualized datasources in the virtual store. Whenever a
user needs an object in his application, it is loaded from the virtual store and
stored into the object store.

Objects are strongly typed (they cannot change type after creation). The types
with which to create the objects can be found in the [typesystem](runtime/src/lang).

## Files
An overview of the files, and what they do:

| file | description |
|------|-------------|
| bootstrap.c | Contains the code that starts and stops corto |
| call.c | Interface for dynamically calling various kinds of functions |
| cdeclhandler.c | Implementation of call interface for native (C/C++) functions |
| contentType.c | Utility to load serializers (uses packages in `driver/fmt`) |
| convert.c | Utility to cast between primitive types |
| copy_ser.c | Serializer for doing deep object copies |
| depresolver.c | Serialize a (cyclic) object graph to operations that recreate the graph |
| expr.c | Stub for `corto/expr` package that allows the core to evaluate expressions |
| init_ser.c | Serializer that initializes object values |
| load.c | The corto file loader (uses packages in `driver/ext`) |
| memory_ser.c | Serializer that frees resources in an object value |
| metawalk.c | Serialize over a virtual instance of a type |
| object.c | Functions to manipulate contents of the object store |
| operator.c | Utility to perform operators on primitive values |
| ptr.c | Functions that accept raw pointers to corto values |
| resolver.c | Implementation of the `corto_resolve` function |
| string_deser.c | Deserializer for corto string format |
| string_ser.c | Serializer for corto string format |
| value.c | Widely used type that encapsulates a corto value with metadata |
| walk.c | Extensive ramework for walking over object values |

## Bootstrapping corto
Because corto uses a self-referential typesystem (the typesystem is defined in 
itself), the bootstrap of corto happens in a carefully orchestrated series of
actions.

Objects that are created in the bootstrap are so called "builtin" objects. They
are special, because they are not allocated on the heap like regular objects.
Instead, the builtin objects are statically defined as global variables in the
process. This makes booting up corto super fast (hardly any allocs!), and 
reduces the amount of setup code to a minimum.

Still, quite a bit of code has to be written in order to add an object to the
core. This section guides you through it.

### 1. Adding a new type
New types are first defined in the `bootstrap.h` file. This file is quite large,
and contains all the type definitions for the corto runtime. The file is very
macro-heavy to keep the definitions somewhat clean, but it also inevitably 
obscures what is exactly happening. For now, lets look at a simple type definition:

```c
// defines the vstore/time type
CORTO_STRUCT_O(vstore, time, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_time, sec, lang_int32, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_time, nanosec, lang_uint32, CORTO_GLOBAL);
```

In this definition, three objects are defined:
* corto/vstore/time
* corto/vstore/time/sec
* corto/vstore/time/nanosec

There is a bunch of arguments which are not important right now. The ones that
are important are:

```c
// defines the vstore/time type
CORTO_STRUCT_O(parent, id, ... );
    CORTO_MEMBER_O(parent, id, type, ... );
    CORTO_MEMBER_O(parent, id, type, ... );
```

When you want to define a new type, just copy a type that looks most like what
you want to achieve, and tailor it to your own definition.

### 2. Create a C type definition
We now need to create the equivalent type in C. Usually corto does this for us
with code generators, but since we are bootstrapping, we can't do that here.
Part of the bootstrap is validating that the calculated size of the type 
metadata is the same as the actual type, and for that we need an actual type.

For the type we defined earlier, this is what the C definition looks like:
```c
struct corto_time {
    int32_t sec;
    int32_t nanosec;
}
```
This type needs to be added to `vstore/include/_type.h`.

You'll notice that `vstore` does not show up here anywhere. That is because 
packages can define their own rules for how package names are encoded in 
typenames. The golden rule here is: just follow the mapping of the other types
and don't think too hard about this.

### 3. Declare a global variable for the type
To make the type accessible for other files inside and outside the runtime, we
need to define a global variable that points to the type. For this, go to the
`vstore/include/_meta.h` file, and add the following definition:

```c
CORTO_META_OBJECT(struct, time);
```

This will forward declare a variable called `corto_time_o` that points to the 
type object. We haven't actually defined this variable yet however. For that we
need to add the following definition to `bootstrap.h` (just add it alongside 
with the other forward declarations):

```c
CORTO_FWDECL_VSTORE(struct, time);
```

### 4. Add the type to the bootstrap
We're almost done. The only thing left is to add the types to the bootstrap 
code. This ensures that the objects are properly defined and added to the
hierarchy (encoding a binary tree in static memory was too much trouble). First,
add the struct object to the `SSO_OP_TYPE` macro with this line:

```c
SSO_OP_VALUE(vstore_, time),\
```
Becuase this is a macro, don't forget the final `\`! Without it, you'll get lots
and lots of ugly errors.

Now we need to add the member objects. Add the following two lines to the
`SSO_OP_OBJECT` macro:
```c
/* time */\
SSO_OP_OBJ(vstore_time_sec),\
SSO_OP_OBJ(vstore_time_nanosec),\
```
It is good practice to add a comment above the objects that indicates to which
parent object they belong. That keeps the bootstrap (somewhat more) readable.

### 5. Try it out!
The type should now be added to the core! Rebuild the core by going to the root
of this repository and type:
```
rake clobber default
```

Now start the corto shell by doing:
```
corto sh
``` 
If all is well you did not get any errors. If you did, it probably complains about
a size mismatch between the metadata and the C type. That means you made a mistake
in the type mapping. No worries- as long as nobody is using your type (and since
you just added it, who would) we can deal with that later.

If the core crashes, you have a bigger problem. In that case, `gdb` and `valgrind`
are your best friend, but it may be worth it to retrace your steps and see if you
made any typos, as these errors can be quite hard to debug.

Assuming you did not crash, while in the shell, type in your type identifier:
```
< / > corto/vstore/time
```

You should now see something like this:
```
name:         time
parent:       /corto/vstore
state:        valid
attributes:   named|builtin
type:         struct
value:        { ... TMI ... }
initializer:  {sec=0 nanosec=0}
```

Congratulations! You added your first type! Now lets get rid of that pesky size
error (if you had one).

### 6. Regenerate core
Because the core is defined in itself, we can use the default code generators to
generate code for the core, based on the definitions we just created. This will
fix any inconsistencies between the metadata and the type, generate functions for
this type in the `c` package and make the formatting of the type consistent with
the other types.

In other words, it is good practice to always regenerate the core after making a
change to the builtin objects.

Regenerating the core is super easy, but because it can nuke your core if you do
it wrong, ** MAKE A BACKUP **. You wouldn't believe how often I kicked myself for
forgetting to do this, and having to manually correct the mess I made for myself.

To backup the runtime source, do something like this (from the root):
```
cp -r runtime runtime_tmp
```

Now go to the runtime directory:
```
cd runtime
```

and run this command:
```
corto pp --core
```

You may see some additional size errors if you had them before. No worries. The
code has been regenerated, it just has to be rebuilt. From the root of the
repository do yet again:

```
rake clobber default
```
Now repeat the steps to display your object in the corto shell. If all is well,
you should no longer see any errors, and your type is showing up nicely alongside
the rest of the corto types!

If not... happy debugging :-p






