
all:
	@make -C dbsh
	@make -C cortex
	@make -C dbgen
	
clean:
	@make clean -C dbsh
	@make clean -C cortex
	@make clean -C dbgen
	
gcov:
	@make gcov -C dbsh
	@make gcov -C cortex
	@make clean -C dbgen
	
splint:
	@make splint -C dbsh
	@make splint -C cortex
	@make clean -C dbgen
	

