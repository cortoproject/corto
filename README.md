# Corto
Corto is a developer-friendly and super extensible framework for building a virtual version of the real world (or a fake one, we don't mind). In corto you first design what your world looks like, and then populate it with real data. We slapped a single, unified API on top of all that data, so you (aka 'the software engineer') never have to worry about where that data came from!

Because there is likely more data in the world than your computer can process at once, corto has a smart design where it only loads the data you need in memory. You can have petabytes of data at your fingertips, and never spend more than 70Kb in footprint!

If any of these is not green, somebody is not sleeping well.

Linux/OSX | Windows | Coverity
----------|---------|---------
[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto) | not yet available | [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)

## Getting Started
These instructions will get the project up and running on your local machine for development and testing purposes.

### Prerequisites
A Linux or macOS system with `curl` installed. That's all!

### Installing
Installing the corto development environment is simple. Just run this command to install corto to `/usr/local`:
```
curl https://corto.io/install-dev-src | sh
```

### Code example
To get started quickly, run the following command after installing corto:
```
corto create MyApp
```
In the generated `MyApp` directory you will find a source directory with a file
called `MyApp.c`. In the main routine of this application, enter the following
hello world program:

```c
corto_object home = corto_create(root_o, "MyHome", corto_void_o);
float *temp = corto_create(home, "RoomTemperature", corto_float32_o);
*temp = 71.5;

char *str_value = corto_serialize_value(temp, "text/corto");
printf("object %s of type %s has value %s\n",
    corto_fullpath(NULL, temp),
    corto_fullpath(NULL, corto_typeof(temp)),
    str_value);

free(str_value);
corto_delete(home);
```
You can now build the project by running this command from the project root:
```
bake
```
After the build is finished, you can run the executable in the `bin/<platform>` directory!

### Running the tests
To make sure that corto is running smoothly on your system, it is always a good idea to run the tests. To run them, you need a local copy of the corto runtime repository. Running these commands in sequence will run the corto runtime testsuites:

```
curl https://corto.io/install-dev-src | sh
cd ~/.corto/src/corto
corto test
```
Don't worry if you see some `missing implementation` messages. This just means we have some work ahead of us. What is important is that after the test run, you see a message that says that everything is ok!

If the tests fail, please submit a bug report (check out [CONTRIBUTING.md](CONTRIBUTING.md)).

## Built With
* [bake](https://github.com/cortoproject/bake) - The tailor-made buildsystem for corto.
* [libffi](https://github.com/libffi/libffi) - We harness the powerful magic of libffi to call functions dynamically

## Contributing
Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute, and the process for submitting pull requests to us. Also please follow our [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) so that everything remains civilized!

## Versioning
We use [SemVer](http://semver.org/) for versioning.

## Authors
* [**Sander Mertens**](https://github.com/SanderMertens) - *Initial work*

See also the list of [contributors](https://github.com/cortoproject/corto/contributors) who participated in this project.

## Legal stuff
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments
The following people (in chronological order of appearance) need a callout as corto would be nowhere near where it is without their unwavering support and dedication:
* **Spiros Motsenigos** - *Invented the name! Pushed corto to greater heights with boundless enthusiasm*
* [**Johnny Lee Othon**](https://github.com/jleeothon) - *First one crazy enough to try out corto. Origin of many, **many** features and improvements*
* [**Alex Hendren**](https://github.com/ahendren) - *Early adopter and evangelist (in the broadest sense of the word)*
* [**Roberto Flores**](https://github.com/rfloresx) - *Probably the most experienced corto developer worldwide. Even better at finding bugs*
* **Pepijn van Kesteren** - *Ever willing to ask the hard questions & able to offer advice on all of them*
* **Nathan Petkus** - *True™ corto believer. Perpetually in the business of rallying good people for the good cause*
* **Luke Peng** - *Reliable source of (sometimes painful) reminders that it is not just about the code*
