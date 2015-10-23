[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortolang/corto](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortolang/corto?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

An open source, easy to use, multi-language CRUD API and scripting language for connecting to your technology stack.

Corto is in alpha. It is expected to reach v1.0 status by the end of 2015. The project has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)
 * Yocto 2.1 (32 bit)

## Building Corto
Download and unpack Corto on your machine. Run the following command to build it:
```
source configure; rake
```
#### Dependencies
Building Corto requires the following packages - make sure to have them installed:
 * flex
 * bison
 * libxml2-dev
 * rake

#### Try it out
To verify whether the build was succesful, run the following command: `corto --version`, which will show the current version.

## Getting started
#### Creating an application
It's very easy to create and run your first corto application. Simply type the following commands:
```
corto create MyFirstApp
corto run MyFirstApp
```
Your program should print `Hello Corto!`. If you look at the generated sources, you'll see a file called `src/MyFirstApp.c`. It looks like this:
```c
#include "corto.h"

int MyFirstAppmain(int argc, char *argv[]) {

    printf("Hello Corto!\n");

    return 0;
}
```
Change this to:
```c
#include "corto.h"

int MyFirstAppmain(int argc, char *argv[]) {

    while (1) {
        printf("Hello Corto!\n");
        corto_sleep(1, 0);
    }
    
    return 0;
}
```
In the terminal, type `corto run MyFirstApp` again. You should see that your program repeatedly prints `Hello Corto!`. 

Now in `MyFirstApp.c` change the line 
```c
printf("Hello Corto!\n");
``` 
to 
```c
printf("I love cupcakes!\n");
```
... and then save your file. Observe that the running process is automatically restarted, and is now printing `"I love cupcakes"`!
