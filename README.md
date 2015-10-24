[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortolang/corto](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortoproject/corto?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A tiny API that lets you browse data like you browse the internet, so you can build distributed services faster than ever before.

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
 * flex
 * bison
 * libxml2-dev
 * rake

## Getting started
Our tutorial will take you about 15 minutes to learn everything you need to know to start writing Corto applications: http://www.corto.io/getstarted.html

Check out our examples for a quick start:
http://www.github.com/cortoproject/examples
