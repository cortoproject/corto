[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortolang/corto](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortoproject/corto?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Corto is an open source, super easy to use ORM that can connect to any source of data, so you can build native apps faster.

Corto has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)
 * Yocto 2.1 (32 bit)

## Building Corto
Download and unpack Corto on your machine. Run the following command to build it:
```
source configure; rake
```
### Dependencies
Building Corto depends on the following libraries for building - make sure to have them installed:
 * rake

## Getting started
The corto library is at the core of the corto platform. You can use the library by itself as a powerful embedded data management abstraction, but we recommend you also check out the rest of the platform. It comes with many nice things such as package management, XML and JSON bindings, a documentation and test framework and a scripting language.

To install the Corto platform to your computer, simply do (the installer will ask for your computer password):
```
curl http://corto.io/install | sh
```

We have a tutorial that will take about 15 minutes to finish, and you'll learn everything you need to start writing your first Corto applications: http://www.corto.io/getstarted.html

Check out our examples for a quick start:
http://www.github.com/cortoproject/examples
