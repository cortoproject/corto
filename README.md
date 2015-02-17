### Cortex [![Build Status](https://travis-ci.org/cortexlang/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)
A light weight, collaborative playground designed for fast-paced, technology-heavy environments with rapidly evolving requirements and short delivery timescales. 

Currently Cortex is in alpha. It is expected to reach v1.0 status by the end of 2015. The current release only supports 32/64 bit Linux.

### Getting started
Download and unpack Cortex on your machine. Run the following commands to build it:
```
source configure
make clean all
```
Create your first C package, named `HelloWorld`:
```
cxgen --package --lang c HelloWorld
make -C HelloWorld
```
Inspect the empty package with the REPL shell:
```
cxsh ::HelloWorld
```


