[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto)
[![Build Status](https://tea-ci.org/api/badges/cortoproject/corto/status.svg)](https://tea-ci.org/cortoproject/corto)
[![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortolang/corto](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortoproject/corto?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Corto is a tested, proven architecture for normalizing data from different technologies into one view regardless of location, format or datamodel. This repository contains the core library of corto and the corto tool, which makes it easy to build, run and test corto projects.

Corto has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)
 * Yocto 2.1 (32 bit)

## Building Corto
Corto uses rake for building, which is a platform-independent, ruby based buildsystem. Before building corto, make sure to have rake installed. To build the latest version, use the following commands (on Ubuntu):
```
sudo apt-get install rake libffi-dev
git clone https://github.com/cortoproject/corto
cd corto
source configure
rake
```

This README contains information for people that want to do development with the latest version of the repository, and also serves as a good background on the internal workings of corto package management. Most of the things described here are automated when using the corto tools and buildsystem, however if you want to use your own buildsystem you'll find this information helpful.

## Building development add-ons
It is recommended to install the following packages if you will be doing corto development. These packages are development only, and not required when you're deploying your application:
 * c-binding
 * xml
 * corto-language

To build these from scratch, ensure the following libraries are installed on your machine:
 * libxml2-dev
 * flex
 * bison

Also make sure to have corto built using the steps in the previous section. To build the latest versions of these packages, do (on Ubuntu):
```
sudo apt-get install libxml2-dev flex bison
git clone https://github.com/cortoproject/c-binding
git clone https://github.com/cortoproject/xml
git clone https://github.com/cortoproject/corto-language
corto build c-binding xml corto-language
```
The `corto build` tool is a front-end for the rake buildsystem. You can also manually invoke rake, like this:
```
rake -f c-binding/rakefile
```

## Creating a project
You can either use your own buildsystem to create a new project, or you can use corto's rake-based buildsystem. If you use the latter, the corto tool that comes with this repository makes it easy to create, run and test projects. Before trying this out, make sure to have the development packages installed. To create a new, buildable project, simply type:
```
corto create MyApp
```
Subsequently, you can run this project by typing (it will build automatically):
```
corto run MyApp
```
If you want to use your own buildsystem, you'll need to know where corto libraries and include files are located. This is detailed in the next section on packages.

## Using packages
Corto features a plugin-architecture with add-ons stored in a hierarchically organized package repository. Packages are stored in well-defined locations, so corto can load packages just by their logical name, rather than their physical location. This makes it easy to share packages and their dependencies across systems.

If you built the corto repository from scratch, the package repository has been instantiated in `~/.corto`, where `~` is your home directory. Inside you will find the following subdirectories:
```
bin etc include lib
```
`bin` contains executables, `lib` contains package libraries, `include` contains package include files and `etc` contains supporting files for packages. It is not a coïncidence that this structure looks similar to your `/usr` and `/usr/local` directory. When installing corto, files are copied to `/usr/local`.

The actual files in each of these directories are stored in `/corto/0.2`, where `0.2` is your current major and minor corto version. From there the file structure mimics the hierarchy of the package repository. For example, the corto library, which is a package itself, is stored here:
```
~/.corto/lib/corto/0.2/corto/libcorto.so
```
Include files for the corto project are stored here:
```
~/.corto/include/corto/0.2/corto
```
Corto projects use the fully qualified include path, so that name clashes between packages are prevented. The main corto include file should be included like this:
```
#include <corto/corto.h>
```
Also, since not all packages are stored in a single location (again, to prevent name clashes) it is recommended to hard-code the library path in your executable. This will ensure that your application always uses the right library, regardless of your environment. This is also a security measure, when a library is installed in a protected location a user with ill intentions won't be able to spoof the library. Alternatively, you can use the less robust method of specifying each path in `LD_LIBRARY_PATH`.

The following command shows the recommended way of building a corto project, using gcc (or similar):
```
gcc -I$(CORTO_TARGET)/include/corto/0.2 -fPIC $(CORTO_TARGET)/lib/corto/0.2/corto/libcorto.so -o myApp 
```

## The Corto code generator
One of the most prominent features of corto is to translate a language-independent description of a datamodel into a specific language. The corto library has an extensive API for describing types, and with these types code can be generated. At this point the only well-supported language is `C`, with `C++` and `python` bindings underway.

Before generating code, typedefinitions have to be inserted into corto. The easiest way to do this is by writing a definition file that contains the types, and then invoking a generator on the inserted types. A definition file can be in any format supported by corto. Currently projects are using `XML`, `IDL` and the native corto definition language. See this link for an example definition file (IPSO definitions, in IDL): https://github.com/cortoproject/ipso/blob/master/ipso.idl

The code is generated by invoking the corto preprocessor, which comes with this repository. If you are using the corto buildsystem, it will automatically invoke the preprocessor when it detects a definition file in your project root. It can be invoked manually like this:
```
corto pp <definition file> --scope <package name> -g <generator>
```
For example, to generate C type definitions for a file `foo.xml` that defines the `foo` package, run the following command:
```
corto pp foo.xml --scope foo -g c/type
```
When you want to run all code generators for a specific language, you can use the `--lang` convenience option:
```
corto pp foo.xml --scope foo --lang c
```
