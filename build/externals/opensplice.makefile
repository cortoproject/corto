OSPL_SRC_HOME		= $(OSPL_HOME)/src/src
OSPL_SRC_INCLUDE	= "$(OSPL_SRC_HOME)/user/include" "$(OSPL_SRC_HOME)/kernel/include"
OSPL_INCLUDES		= "$(OSPL_HOME)/include" "$(OSPL_HOME)/include/sys" "$(OSPL_HOME)/include/dcps/C/SAC" $(OSPL_SRC_INCLUDE)
OSPL_LIBS			= dcpssac ddsdatabase ddsuser dcpsgapi
OSPL_LIBPATH		= "$(OSPL_HOME)/lib"