
export BIN			= $(CURDIR)/bin
export BUILD		= $(CURDIR)/build
export BUILDHOME	= $(CURDIR)

all:
	@make -C db
	@make -C dev
	@make -C tools
	@make -C generator
	@make -C interface
#	@make -C public
	@make -C namespaces
	@make -C test
	
clean:
	@make clean -C db
	@make clean -C dev
	@make clean -C tools
	@make clean -C generator
	@make clean -C interface
	@make clean -C namespaces
#	@make clean -C public
	@make clean -C test
	
gcov:
	@make gcov -C db
	@make gcov -C dev
	@make gcov -C tools
	@make gcov -C generator
	@make gcov -C interface
	@make gcov -C namespaces
#	@make gcov -C public
	@make gcov -C test
	
splint:
	@make splint -C db
	@make splint -C dev
	@make splint -C tools
	@make splint -C generator
	@make splint -C interface
	@make splint -C namespaces
	@make splint -C namespaces
	@make splint -C test
	

