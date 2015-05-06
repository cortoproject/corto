export TARGET
export SOURCES
export LIBPATH
export INCLUDE
export LIBS
export LEX
export YACC

LIBS += lang

TARGET_OBJECT = $(CORTEX_HOME)/bin/$(dir $(TARGET))lib$(notdir $(TARGET)).so
DEFINITION_FILE = $(wildcard $(TARGET).*)
GENERATED_C_FILES = src/$(TARGET)__api.c \
				  src/$(TARGET)__meta.c \
				  src/$(TARGET)__wrapper.c

GENERATED_FILES = $(GENERATED_C_FILES) \
				  include/$(TARGET)__api.h \
				  include/$(TARGET)__meta.h

PACKAGE_SOURCES += $(wildcard src/*.c)
PACKAGE_SOURCES_NODIR = $(notdir $(sort $(PACKAGE_SOURCES)))
PACKAGE_OBJECTS += $(PACKAGE_SOURCES_NODIR:%.c=obj/%.o)

PREFIX_ARG =$(PREFIX:%=--prefix %)

MAKEFILE ?= component

all: include/$(TARGET)__meta.h $(TARGET_OBJECT)

$(TARGET_OBJECT): objects

objects: $(DEFINITION_FILE) $(PACKAGE_SOURCES)
	@make -f $(CORTEX_HOME)/build/$(MAKEFILE).makefile all

include/$(TARGET)__meta.h: $(DEFINITION_FILE)
	cxgen $(TARGET) $(PREFIX_ARG) --lang c

.PHONY: clean
clean:
	@make -f $(CORTEX_HOME)/build/component.makefile clean
	@rm -rf $(GENERATED_FILES)
