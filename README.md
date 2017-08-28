# Corto
Corto is a developer-friendly and super extensible framework for building a virtual version of the real world (or a fake one, we don't mind). In corto you first design what your world looks like, and then populate it with real data. We slapped a single, unified API on top of all that data, so you (aka 'the software engineer') never have to worry about where that data came from!

Because there is likely more data in the world than your computer can process at once, corto has a smart design where it only loads the data you need in memory. You can have petabytes of data at your fingertips, and never spend more than 70Kb in footprint!

Linux/OSX | Windows | Coverity
----------|---------|---------
[![Build Status](https://travis-ci.org/cortoproject/corto.svg?branch=master)](https://travis-ci.org/cortoproject/corto) | [![Build status](https://ci.appveyor.com/api/projects/status/549itmv72ut0ia51?svg=true)](https://ci.appveyor.com/project/SanderMertens/corto) | [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807)

## Getting Started
These instructions will get the project up and running on your local machine for development and testing purposes. Check out the deployment section for notes on how to deploy corto to a live system.

### Prerequisites
A Linux or macOS system with `curl` installed. That's all!

### Installing
Installing the corto development environment is simple. Just run this command to install corto to `/usr/local`:
```
curl https://corto.io/install-dev-src | sh
```
If you'd rather not install to `/usr/local` but to a location of your own choosing, run this:
```
curl https://corto.io/build-dev-src | sh
```
This command downloads the source code to `{current working directory}/corto-src`.

The development environment contains the corto runtime, development tools and some goodies to get you started quickly. When you want to actually deploy an application, know that you can strip most of these packages from your deployment! Also note that these commands build a `development` version. Development versions are slow because they enable lots of checking. To install a `release` version, just replace `dev` by `release`!

### Running the tests
To make sure that corto is running smoothly on your system, it is always a good idea to run the tests. To run them, you need a local copy of the corto runtime repository. Running these commands in sequence will run the corto runtime testsuites:

```
curl https://corto.io/build-dev-src | sh
cd corto-src/corto
corto test
```
Don't worry if you see some `missing implementation` messages. This just means we have some work ahead of us. What is important is that after the test run, you see a message that says that everything is ok!

If the tests fail, please submit a bug report (check out [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426)). 

## Built With
* [rake](https://github.com/ruby/rake) - The bedrock of our buildsystem
* [libffi](https://github.com/libffi/libffi) - We harness the powerful magic of libffi to call functions dynamically

## Contributing
Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning
We use [SemVer](http://semver.org/) for versioning.

## Authors
* [**Sander Mertens**](https://github.com/SanderMertens) - *Initial work*

See also the list of [contributors](https://github.com/cortoproject/corto/contributors) who participated in this project.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments
The following people need a callout as corto would be nowhere near where it is without their unwavering support and dedication:
* [**Johnny Lee Othon**](https://github.com/jleeothon) - *First one crazy enough to try out corto. Origin of many, **many** features and improvements*
* [**Alex Hendren**](https://github.com/ahendren) - *Early adopter and evangelist (in the broadest sense of the word)*
* [**Roberto Flores**](https://github.com/rfloresx) - *Probably the most experienced corto developer worldwide. Even better at finding bugs*
* **Spiros Motsenigos** - *Invented the name! Pushed corto to greater heights with boundless enthusiasm*
* **Luke Peng** - *Reliable source of (sometimes painful) reminders it is not just about the code*
* **Pepijn van Kesteren** - *Ever willing to ask the hard questions & able to offer advice for all of them*
