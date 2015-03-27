
TARGET =	lang


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
LIBS	= rt dl m
else
LIBS	= dl m
endif


include $(CORTEX_HOME)/build/component.makefile
