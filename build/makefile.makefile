# default makefile
IFLAGS	= -O3 -march=native -xT -unroll -fp-model fast=2 -rcd -no-prec-div
OFLAGS	= -O0
# COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS	= $(OFLAGS) $(COVFLAGS) -g -Wall -Wextra -Wno-gnu-label-as-value -Wno-unknown-pragmas -Wstrict-prototypes -pedantic -std=c99 -fPIC -D_XOPEN_SOURCE=600 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CC = clang
endif

# default libraries and includes
INCLUDE += include $(CORTEX_HOME)/cx/include

INCLUDES = $(INCLUDE:%=-I"%")
SOURCES += $(wildcard src/*.c)
SOURCES_NODIR = $(notdir $(sort $(SOURCES)))
OBJECTS += $(SOURCES_NODIR:%.c=obj/%.o)
GCOV = $(SOURCES:%.c=gcov/%.c.gcov)
SPLINT = $(SOURCES:%.c=src/%.c)
LINKPATH = $(LIBPATH:%=-L%)
LINK = -L$(CORTEX_HOME)/bin $(LINKPATH) $(LIBS:%=-l%)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

%.c.gcov: src/%.c
	@mkdir -p gcov
	gcov --object-directory obj $<
	
gcov/%.c.gcov: %.c.gcov
	mv $< $@

.PHONY: all
all: $(TARGET_OBJECT)

.PHONY: gcov
gcov: $(GCOV)
