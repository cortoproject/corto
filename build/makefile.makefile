# default makefile
IFLAGS	= -O3 -march=native -xT -unroll -fp-model fast=2 -rcd -no-prec-div
OFLAGS	= -O0
# COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS	= $(OFLAGS) $(COVFLAGS) -g -Wall -Wextra -Wno-gnu-label-as-value -Wno-unknown-pragmas -Wstrict-prototypes -pedantic -std=c99 -fPIC -D_GNU_SOURCE -D_XOPEN_SOURCE=500 -D_POSIX_C_SOURCE=199506

PSOURCES = $(SOURCES:%.c=$(PPREFIX)%.c)

INCLUDES = $(INCLUDE:%=-I"%")
OBJECTS += $(PSOURCES:%.c=obj/%.o)
OBJECTS += $(ASMSOURCES:%.s=asm/%.o)
GCOV = $(PSOURCES:%.c=gcov/%.c.gcov)
SPLINT = $(PSOURCES:%.c=src/%.c)
LINKPATH = $(LIBPATH:%=-L%)
LINK = -L$(BIN) $(LINKPATH) $(LIBS:%=-l%)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

asm/%.o: src/%.s
	@mkdir -p asm
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
