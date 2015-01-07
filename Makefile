
all:
	@make -C cx
	@make -C dev
	@make -C tools
	@make -C generator
	@make -C interface
	@make -C generator/html
	@make -C packages
	@make -C test
	
clean:
	@make clean -C cx
	@make clean -C dev
	@make clean -C tools
	@make clean -C generator
	@make clean -C interface
	@make clean -C generator/html
	@make clean -C packages
	@make clean -C test
	@rm -f ./bin/*
	
gcov:
	@make gcov -C cx
	@make gcov -C dev
	@make gcov -C tools
	@make gcov -C generator
	@make gcov -C interface
	@make gcov -C generator/html
	@make gcov -C packages
	@make gcov -C test
	
splint:
	@make splint -C cx
	@make splint -C dev
	@make splint -C tools
	@make splint -C generator
	@make splint -C interface
	@make splint -C generator/html
	@make splint -C packages
	@make splint -C test
	

