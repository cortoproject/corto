
all:
	@make -C dbsh
	@make -C hyve
	@make -C dbgen
	
clean:
	@make clean -C dbsh
	@make clean -C hyve
	@make clean -C dbgen
	
gcov:
	@make gcov -C dbsh
	@make gcov -C hyve
	@make clean -C dbgen
	
splint:
	@make splint -C dbsh
	@make splint -C hyve
	@make clean -C dbgen
	

