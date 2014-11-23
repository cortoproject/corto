include $(BUILD)/externals/opensplice.makefile

TARGET =	Sigar

SOURCES	=	sigar_main.c \
			Sigar__api.c \
			Sigar__meta.c \
			Sigar_Host.c

INCLUDE = 	include \
			$(BUILDHOME)/db/include \
			$(BUILDHOME)/public/c/include \
			$(BUILDHOME)/infra/include \
			$(BUILDHOME)/interface/api/include \
			$(BUILDHOME)/namespaces/sigar/lib/include

LIBS	=	lang fl api sigar-x86-linux

include $(BUILD)/component.makefile

