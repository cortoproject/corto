# Corto Runtime
This is the source code of the corto runtime library. In theory, this is all 
your application needs to link with to use corto!

## Code organization
In the `src` and `include` you will find a few different directories. Here's 
what they do:

| directory | description |
|-----------|-------------|
| lang | Corto's typesystem |
| store | Corto's in-memory object store |
| vstore | Corto's virtual object store |
| secure | Corto's security framework |
| native | Utilities for using native types and functions |

The files in the `src` and `include` directories itself are mostly generic
functionality that is not specific to corto, like a linked list, a red black
tree, operating system abstractions and so on.

The `c` directory contains generated code from the corto builtin types that make
it easier to work with them. Because this generated code is quite big, it is
stored in a separate package, so each application can decide for itself whether
to make use of the generated code or not.

## Files
An overview of the files, and what they do:

| file | description |
|------|-------------|
| async.c | Abstraction for multi-threaded programming |
| buffer.c | Functions for efficient appending to a string |
| dl.c | Abstraction for dynamic libraries |
| entityadmin.c | lock-free hierarchical administration of generic entities |
| err.c | Logging and error framework |
| file.c | File utility functions |
| iter.c | Corto iterator abstraction |
| jsw_rbtree.c | A red black tree. The original is by Julienne Walker |
| ll.c | A linked list |
| os.c | Generic operating system abstraction functions |
| rbtree.c | Wrapper around jsw_rbtree.c |
| string.c | String utility functions |
| time.c | Time utility functions |
| util.c | Generic utility functions |

## Documentation generation
The files in this project are documented using the doxygen syntax. A Doxygen
file is attached that generates doxygen comments to XML that can be used by the
corto documentation framework. To generate the doxygen documentation, simply do
```
doxygen
```
from this directory.

