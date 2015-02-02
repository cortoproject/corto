.PHONY: all
.PHONY: clean
.PHONY: gcov

all:
	@make -C test
	@make -C io
	@make -C os
	@make -C math

clean:
	@make clean -C test
	@make clean -C io
	@make clean -C os
	@make clean -C math
	
gcov:
	@make gcov -C test
	@make gcov -C io
	@make gcov -C os
	@make gcov -C math
