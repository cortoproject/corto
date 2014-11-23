
Generator example

This example shows how dbgen can be utilized to generate code from a hyve interface. 
Invoking run.sh regenerates the code. Note that if you add implementation the regeneration
process will keep this code intact.

Foo.hyve
Contains the interface to be implemented

src/Foo__api.c
Contains type-safe functions to create objects

src/Foo__meta.c
Contains function to load objects in Foo scope in database

src/Foo_Point.c
Contains skeleton code for the Point class

include/Foo__api.h
Contains declarations to type-safe object-creation functions

include/Foo__meta.h
Contains declarations to database objects

include/Foo__type.h
Contains type-mapping for C

include/Foo_Point.h
Contains declarations to methods in Foo::Point

