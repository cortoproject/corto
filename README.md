[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto)
[![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortolang/corto](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortoproject/corto?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Corto is a small library that provides:

1. a connector framework for connecting any kind of data (realtime or at rest)
2. a simple application-facing CRUD (Create, Read, Update, Delete) API to interact with this data

The small footprint of Corto makes it a handy building block in IoT systems where you can run it on small devices. The library is optimized to be very fast (~30 **nanoseconds** event latency) and to enable working with large datasets in resource-constrained environments. Corto never loads more data in memory than the application needs.

Corto takes a holistic approach to usability. That means we provide integrated tools to build, test, document and deploy corto projects. Basically we made our devtools available for the community, so that when you begin a new project you can get right to it!

People have used Corto to forward data from one technologies to another (for example, MQTT to InfluxDB), as an application API in industrial automation systems, and even as a low-footprint web backend!

This repository contains the core library of corto and the corto tool. The corto tool is like your swiss army knife when using Corto. It helps you create, build, debug, test and install corto projects, and a whole lot more.

Corto has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)
 * Yocto 2.1 (32 bit)

Make sure to also explore the other repositories in the cortoproject organization:

The `cortoproject/web` project in particular is worth checking out. It automatically adds web connectivity to your applications, like a REST interface and websockets.

The `cortoproject/admin` project is a very handy web-application that allows you to browse through the data that is connected to Corto. Make sure to also install `cortoproject/web` if you want to use admin.

## Building Corto
Corto uses rake (https://en.wikipedia.org/wiki/Rake_(software) for building, which is a platform-independent, ruby based buildsystem written by Jim Weirich. Before building corto, make sure to have rake installed. To build the latest version, use the following commands (on Ubuntu):
```
sudo apt-get install rake libffi-dev
git clone https://github.com/cortoproject/corto
cd corto
source configure
rake
```

This will build the core API and corto tool. The core API is typically used for writing connectors and generic tools. All other corto APIs are built on top of the core API.

## Building development add-ons
The following packages are useful when you want to do corto application development (all in the cortoproject organization):
 * c-binding
 * xml
 * corto-language
 * test

These packages are only required during development, and you do not need them when you are distributing your application. The `c-binding` API contains code generators that take as input a datamodel, which can be specified in either `xml` or the native corto description language (`corto-language`). The `test` package contains a testframework for testing corto projects.

The following libraries are required for these packages:
 * libxml2-dev
 * flex
 * bison

To build the latest versions of these packages, do (on Ubuntu):
```
sudo apt-get install libxml2-dev flex bison
git clone https://github.com/cortoproject/c-binding
git clone https://github.com/cortoproject/xml
git clone https://github.com/cortoproject/corto-language
git clone https://github.com/cortoproject/test
corto build c-binding xml corto-language test
```
The `corto build` tool is a front-end for the rake-based buildsystem. The buildsystem automates many tasks like code generation, dependencies between packages and installation of binaries.

## Creating a project
Before you try out these examples, make sure to have both corto and the development packages installed. To create a new project, use the following command:
```
corto create MyApp
```
Subsequently, you can run this project by typing (it will build automatically):
```
corto run MyApp
```

## Creating a package
Creating a package is similar to creating an application. To create a new package, use the following command:
```
corto create package mypackage
```
Notice that the package has been created with a `mypackage.cx` file. This file will contain the datamodel for the package in the native corto language. Here's an example datamodel:
```
#package /mypackage

class WeatherStation::
    temperature: float64
    pressure: float64
    precipitation: float64
```
When you change the `mypackage.cx` file, simply use `corto build mypackage` to generate code from the updated definition and rebuild the project. Corto generates a simple CRUD API to interact with data in a corto system.  Here is a small C application that uses the generated code from the example datamodel:

```c
// Create a new weatherstation instance
mypackage_WeatherStation ws = mypackage_WeatherStationCreateChild(root_o, "ws", 65.0, 500.0, 0.5);

// Update the instance with new sensor readings
mypackage_WeatherStationUpdate(ws, 67, 600, 0.5);
```

## Package management
Corto has a plugin-architecture with add-ons stored in a hierarchically organized package repository. Corto stores packages in well-defined locations, so you can load packages by their logical name, instead of some path to a file. This makes it easier to share packages and their dependencies across operating systems.

Packages are stored in `~/.corto`, where `~` is your home directory. Inside you will find the following subdirectories:
```
bin etc include lib
```
`bin` contains applications, `lib` contains packages, `include` contains include files and `etc` contains all kinds of supporting files. It is not a coïncidence that this structure looks similar to the `/usr/local` directory on Linux. When you install a corto project, files are copied to `/usr/local`.

Files in each of these directories are stored in `corto/0.2`, where `0.2` is your current major and minor corto version. From there the file structure represents the hierarchical organization of the packages. For example, the `corto/fmt/xml` package is stored here:
```
~/.corto/lib/corto/0.2/corto/fmt/xml/libxml.so
```
Include files for the `xml` package are stored here:
```
~/.corto/include/corto/0.2/corto/fmt/xml
```
Corto projects use the fully qualified include path, so that name clashes between packages are prevented. To include the XML project, do:
```
#include <corto/fmt/xml/xml.h>
```
Because packages are not stored in a single directory (to prevent name clashes) corto bakes hard-coded paths to packages path into your applications. This ensures that application always uses the right library.

Sometimes these hardcoded paths can be inconvenient, for example when you want to put corto libraries in another project. For this purpose, the corto buildsystem also builds a binary that does not hardcoded paths, and you can easily embed in other projects. The buildsystem will tell you where it stores this binary.

## Code generation
Corto can translate a language-independent description of a datamodel into a target programming language. The corto library has an comprehensive framework for describing types, and from these types code can be generated. At this point the only well-supported language is `C`, with `C++` and `python` bindings underway.

Corto generates code by running the corto preprocessor, which is part of the corto tool. The buildsystem calls corto pp automatically when you have a definition file in your project that has the same name as your project. For example, the `foo` project can have a `foo.cx` definition file that contains the datamodel.

When you want to use corto code generation, just put a definition file in your project, and build it with `corto build`.
 
