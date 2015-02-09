### The Cortex platform [![Build Status](https://travis-ci.org/Seldomberry/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)
Cortex is a light weight, collaborative playground designed for fast-paced, technology-heavy environments with rapidly evolving requirements and short delivery timescales. 

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

### From apification to datafication
APIs are the things through which us developers have been accustomed to interface with technology. APIs are nice. They provide us with friendly abstractions of things we like, but don't want to know the insides of. Like, you could be a nice person and I want to talk to you, but I don't need to see your organs. Your face and body language provide me with an apt abstraction of your inner workings.

Because we like APIs so much, we tend to APIfy everything. We even create APIs on top of APIs. Good developers have achieved mastery of one or more APIs. And that was fine... for a while.

Nowadays we churn out new APIs at incredulous rates. Pretty much anything that bears the prefix "smart" has an API. We cannot possibly master all of them. But we don't want to miss out on all of those smart things either.

If only all of these APIs would follow a limited set of patterns and paradigms. That would decrease learning curves and would make it much easier to integrate everything. Yet if done wrong such an abstraction can easily hide much of the expressiveness of todays technologies. 

To find the right balance between expressiveness and uniformity a paradigm was borrowed that is already commonplace in defense and industrial IT systems. It builds upon the notion that information is the beating heart of all systems. With the right language to describe this information, there should be no additional needs for APIs. In a way, the information *becomes* the API. This paradigm is called information centricity.

