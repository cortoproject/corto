### The Cortex way [![Build Status](https://travis-ci.org/Seldomberry/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)
Fail often. Fail fast. Fail cheap. Innovation is achieved through iteration.

Cortex is a feature-rich playground designed for fast-paced, technology-heavy environments with rapidly evolving requirements and short delivery timescales. With code generation, document generation, a test framework, profiling, visualization tools and package management, the platform gives entrepreneurs a definitive competitive edge in getting that next big thing out of the door. Oh, and it's free.

Currently Cortex is in alpha. It is expected to reach v1.0 status by the end of 2015.

### Getting started
Cortex is currently only provided for 32/64 bit Linux. 
Download and unpack Cortex on your machine. Run the following commands to build it:
```
source configure
make clean all
```
Verify your build by running the test suite:
```
sh test/language/run.sh
```
Create a new C package called `HelloWorld`:
```
cxgen --package --lang c HelloWorld
make -C HelloWorld
```
Load and inspect the empty package with the REPL shell:
```
cxsh ::HelloWorld
```

### From apification to datafication
APIs are the things through which us developers have been accustomed to interface with technology. APIs are nice. They provide us with friendly abstractions of things we like, but don't want to know the insides of. Like, you could be a nice person and I want to talk to you, but I don't need to see your organs. Your face and body language provide me with an apt abstraction of your inner workings.

Because we like APIs so much, we tend to APIfy everything. We even create APIs on top of APIs. Good developers have achieved mastery of one or more APIs. And that was fine... for a while.

Nowadays we churn out new APIs at incredulous rates. Pretty much anything that bears the prefix "smart" has an API. We cannot possibly master all of them. But we don't want to miss out on the smart's either.

If only all of these APIs would follow a limited set of patterns and paradigms. That would make things a lot more manageable. But what would that look like? Can this even be done? We happen to believe so.

To figure out this puzzle, we borrowed a paradigm that is already commonplace in defense and industrial IT systems. The paradigm is built upon the premise that information is at the heart of everything and if we capture the essence of it really well, then that is all we will ever need. This paradigm is called information centricity.

