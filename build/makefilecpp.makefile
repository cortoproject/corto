# default makefile

IFLAGS	= -O3 -march=native -xT -unroll -fp-model fast=2 -rcd -no-prec-div
OFLAGS	= -O0
# COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS	= $(OFLAGS) $(COVFLAGS) -g -Werror -Wall -Wextra -pedantic -std=c++0x

PSOURCES = $(SOURCES:%.cpp=$(PPREFIX)%.cpp)

INCLUDES = $(INCLUDE:%=-I"%")
OBJECTS += $(PSOURCES:%.cpp=obj/%.o)
GCOV = $(PSOURCES:%.cpp=gcov/%.cpp.gcov)
SPLINT = $(PSOURCES:%.cpp=src/%.cpp)
LINKPATH = $(LIBPATH:%=-L%)
LINK = -L$(CORTEX_HOME)/bin $(LINKPATH) $(LIBS:%=-l%)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

%.cpp.gcov: src/%.cpp
	gcov --object-directory obj $<
	
gcov/%.cpp.gcov: %.cpp.gcov
	mv $< $@

all: $(TARGET_OBJECT)

gcov: $(GCOV)

splint: $(SPLINT)
	clang $(INCLUDES) $<
