# Contributing

Follow these steps to contribute to Hyve.

## Requirements

As of now, Hyve can only be built in 32-bit Linux. We recommend using an Ubuntu virtual machine. The examples hereby provided for apt-get.

Install the GNU C++ compiler.

```
apt-get install g++
```

If you want to build Hyve, install libxml2-dev; if you will only run it, libxml2 will do (which comes with every Linux distribution).

```
apt-get install libxml2-dev
```

Install Flex, the lexer.

```
apt-get install flex
```

Install Bison, the parser.

```
apt-get install bison
```

## Download the project from GitHub.

You can use the GitHub desktop application, or type:

```
git clone https://github.com/SanderMertens/Hyve.git
```

## Building

From the Hyve root directory, run the command:

```
make
```

Now add the `hyve` command to your environment:

```
source release.com
```

Now you can use the command `hyve` to run file

```
hyve filename.hyve
```

You can run test cases using:

```
test/language/run.sh
```

You should get `OK` or `FAIL: not implemented` for all test cases.

## Making changes

Modify any files. Then build again (`make` from the root directory). Run test cases.

If your changes include the core, you may want to run `make clean all` instead of `make`.

When committing your changes:
- Make sure that all tests pass.
- Generate test cases for your work.
- Prefer the 50-character rule.
- Avoid dots (.) at the end of titles.
- Use full grammar and spelling and punctuation for descriptions.

## Submitting issues

- Use concise but precise titles
- Avoid dots (.) at the end of titles.
- Use full grammar and spelling and punctuation for descriptions.
