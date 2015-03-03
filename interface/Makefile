.PHONY: all
.PHONY: clean
.PHONY: gcov

all:
	@make -C xml
	@make -C json
	@make -C fast
	@make -C sqlite
	
clean:
	@make clean -C xml
	@make clean -C json
	@make clean -C fast
	@make clean -C sqlite
	
gcov:
	@make gcov -C xml
	@make gcov -C json
	@make gcov -C fast
	@make gcov -C sqlite
