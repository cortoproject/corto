[![Build Status](https://travis-ci.org/cortexlang/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortexlang/cortex](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortexlang/cortex?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

An open source, easy to use, multi-language CRUD API and scripting language for connecting to your technology stack.

Cortex is in alpha. It is expected to reach v1.0 status by the end of 2015. The project has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)
 * Yocto 2.1 (32 bit)

## Building Cortex
Download and unpack Cortex on your machine. Run the following command to build it:
```
source configure; rake
```
#### Dependencies
Building Cortex requires the following packages - make sure to have them installed:
 * flex
 * bison
 * libxml2-dev
 * rake

#### Try it out
To verify whether the build was succesful, run the following command: `cortex --version`, which will show the current version.

## Getting started
#### Creating a package
It's very easy to create your first cortex project. Simply run the following command:
```
cxgen --package MyApp --lang c
```
which should give the following output:
```
cxgen: create package 'MyApp'
cxgen: done
```
A new directory called `MyApp` is created. Now run the following two commands:
```
cd MyApp
rake
```
If all is well, you should see:
```
src/MyApp.c
src/MyApp_RedPanda.c
[ libMyApp.so ]
```
Congratulations! You've just created your first package! 

#### Load the package
To load our package, run the following command:
```
cortex ::MyApp
```
which should give this output:
```
Hurray, Albert the panda is born!
Albert the panda is chewing on something omnomnom (his weight: 11)
```
#### Explore the package with the shell
Alternatively, you can also load the package with the shell, like this:
```
cxsh ::MyApp
```
This should give the following output:
```
cortex shell - type 'help' for instructions.
Hurray, Albert the panda is born!
Albert the panda is chewing on something omnomnom (his weight: 11)
:: $ 
```
To explore what's in the store, type `ls`. You should see this:
```
  name                                  type                  state       attr    
================================================================================
  Albert                                ::MyApp::RedPanda     V|DCL|DEF   S|W|O   
  cortex                                package               V|DCL|DEF   S|O     
  MyApp                                 package               V|DCL|DEF   S|W|O   
total: 3 objects
:: $ 
```
Now type 'Albert', followed by a return. You should see this:
```
name:         ::Albert
parent:       ::
timestamp:    1439121375.370321000
state:        V|DCL|DEF
attributes:   S|W|O|P
type:         ::MyApp::RedPanda
value:        {weight=11}

:: $ 
```
If you only want to see his weight, you can type `Albert.weight` which outputs:
```
11
```
The shell allows for many more things (try for example `Albert.weight ++`!). Happy exploring!
