
TARGET =	../benchmark/bin/pingpong

SOURCES	=	PingPong__meta.c \
			pingpong.c \
			pp_Dispatcher.c \
			pp_Pinger.c

INCLUDE = 	include \
			$(BUILDHOME)/db/include \
			$(BUILDHOME)/public/c/include \
			$(BUILDHOME)/infra/include \
			$(BUILDHOME)/namespaces/os/include

LIBS	=	lang infra os

include $(BUILD)/executable.makefile

