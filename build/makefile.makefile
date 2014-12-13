# default makefile
IFLAGS	= -O3 -march=native -xT -unroll -fp-model fast=2 -rcd -no-prec-div
OFLAGS	= -O0
# COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS	= $(OFLAGS) $(COVFLAGS) -g -Wall -Wextra -Wno-gnu-label-as-value -Wno-unknown-pragmas -Wstrict-prototypes -pedantic -std=c99 -fPIC -D_GNU_SOURCE -D_XOPEN_SOURCE=500 -D_POSIX_C_SOURCE=199506

# default libraries and includes
INCLUDE += include $(HYVE_HOME)/db/include

INCLUDES = $(INCLUDE:%=-I"%")
SOURCES += $(wildcard src/*.c)
SOURCES_NODIR = $(notdir $(sort $(SOURCES)))
OBJECTS += $(SOURCES_NODIR:%.c=obj/%.o)
GCOV = $(SOURCES:%.c=gcov/%.c.gcov)
SPLINT = $(SOURCES:%.c=src/%.c)
LINKPATH = $(LIBPATH:%=-L%)
LINK = -L$(HYVE_HOME)/bin $(LINKPATH) $(LIBS:%=-l%)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

%.c.gcov: src/%.c
	@mkdir -p gcov
	gcov --object-directory obj $<
	
gcov/%.c.gcov: %.c.gcov
	mv $< $@

all: $(TARGET_OBJECT)

gcov: $(GCOV)

splint: $(SPLINT)
	clang $(INCLUDES) $<
