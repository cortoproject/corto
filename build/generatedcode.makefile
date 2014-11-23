# makefile for generated code - less strict compiler options
CC		= clang

IFLAGS	= -O3 -march=native -xT -unroll -fp-model fast=2 -rcd -no-prec-div
OFLAGS	= -O3
CFLAGS	= $(OFLAGS) -g -Wall -Wextra -Wstrict-prototypes -std=c99 -D_GNU_SOURCE -D_XOPEN_SOURCE=500 -D_POSIX_C_SOURCE=199506

TARGET_OBJECT = $(BIN)/$(TARGET)
INCLUDES = $(INCLUDE:%=-I"%")
OBJECTS = $(SOURCES:%.c=obj/%.o)
LINKPATH = $(LIBPATH:%=-L%)
LINK = -L$(BIN) $(LINKPATH) $(LIBS:%=-l%)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

all: $(TARGET_OBJECT)
	
clean: 
	@rm -f obj/*.o >/dev/null
	@rm -f $(BIN)/$(TARGET) >/dev/null