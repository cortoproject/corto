### Cortex [![Build Status](https://travis-ci.org/cortexlang/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)
A light weight, collaborative playground designed for fast-paced, technology-heavy environments with rapidly evolving requirements and short delivery timescales. 

Currently Cortex is in alpha. It is expected to reach v1.0 status by the end of 2015. The current release only supports 32/64 bit Linux.

### Building Cortex
Download and unpack Cortex on your machine. Run the following commands to build it:
```
source configure
make clean all
```
### Quick start
Put the following code snippets in a `foo.cx` file. Execute the code with `cortex foo.cx`.
#### Hello World
```
"Hi Cortex!"
```
#### A simple object
```
struct Point::      // Create a new composite type
   x, y: int32
   
Point imHere: 1, 2  // Create an object

"$imHere"           // Print object value
```
### Create and implement a package from scratch
Run the following commands to create a new C package called `StarWars`
```
cxgen --package --lang c StarWars
```
You'll find a new directory called 'StarWars' with the following structure:
```
StarWars/
├── StarWars.cx
├── makefile
├── src/
│   ├── StarWars__api.c
│   ├── StarWars__load.c
│   └── StarWars__meta.c
└── include/
    ├── StarWars__api.c
    ├── StarWars__meta.c
    └── StarWars__type.c
```
When inspecting the `StarWars.cx` file, you'll find:
```
#package ::StarWars
```
Add the following lines to this file:
```
enum SpaceShipKind:: XWing, MilleniumFalcon, Destroyer, DeathStar 

class SpaceShip::
    kind: SpaceShipKind
    hp: int32, readonly
    strenght: int32, readonly
    int16 construct()
    bool attack(SpaceShip target)
```
Run `make -C StarWars` to re-generate and make the package. Notice that there are two additional files:
```
StarWars/
├── src/
│   └── StarWars_SpaceShip.c
└── include/
    └── StarWars_SpaceShip.h
```

In `StarWars_SpaceShip.c`, add the following code to the `StarWars_SpaceShip_construct` method between the `$begin` and `$end` markers:
```c
/* $begin(::StarWars::SpaceShip::construct) */
    switch(_this->kind) {
    case StarWars_XWing:
       _this->hp = 100;
       _this->strength = 500;
       break;
    case StarWars_MillenumFalcon:
       _this->hp = 500;
       _this->strength = 1000;
       break;
    case StarWars_Destroyer:
       _this->hp = 3000;
       _this->strength = 5000;
       break;
    case StarWars_DeathStar:
       _this->hp = 2000000000;
       _this->strength = 2000000000;
       break;
    }
    return 0;
/* $end */
```

In the `StarWars_SpaceShip_attack` method, add the following code:
```c
/* $begin(::StarWars::SpaceShip::attack) */
    if ((_this->kind == StarWars_MilleniumFalcon) && (target->kind == StarWars_DeathStar)) {
        target->hp = 0;
    } else if (_this->strength > target->hp) {
        target->hp = 0;
    } else {
        target->hp -= _this->strength;
    }
    if (!target->hp) {
        printf("%s: I have defeated %s!\n", cx_nameof(_this), cx_nameof(target));
    } else {
        if (_this->hp <= 500) {
            printf("%s: May the force be with me\n", cx_nameof(target));
        } else if (_this->hp <= 1000) {
            printf("%s: Taking some serious damage...\n", cx_nameof(target));
        } else {
            printf("%s: It's just a flesh wound\n", cx_nameof(target));
        }
    }
    return target->hp == 0;
/* $end */
```

That's it! Run `make -C StarWars` again. You can now use this package in scripts! An example:

In a new file called `epicbattle.cx`, add the following (historically incorrect) lines:
```
StarWars::SpaceShip Luke: XWing
StarWars::SpaceShip DarthVader: Destroyer

while !Luke.attack(DarthVader)
```
Run the script with `cortex epicbattle.cx`. Your output should look like:
```
DarthVader: It's just a flesh wound
DarthVader: It's just a flesh wound
DarthVader: It's just a flesh wound
DarthVader: Taking some serious damage...
DarthVader: May the force be with me
Luke: I have defeated DarthVader!
```





