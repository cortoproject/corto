
TARGET =	Fast

LEX		=	fast.l
YACC	= 	fast.y

INCLUDE = 	$(CORTEX_HOME)/dev/include

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
LIBS	=	lang cortexdev fl
else
LIBS	=	lang cortexdev l
endif

MAKEFILE = lexyacc

include $(CORTEX_HOME)/build/package.makefile
