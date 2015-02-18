.PHONY: all
.PHONY: clean
.PHONY: gcov

all:
	@make -C common
	@make -C type
	@make -C load
	@make -C interface
	@make -C api
	@make -C project
	
clean:
	@make clean -C common
	@make clean -C type
	@make clean -C load
	@make clean -C interface
	@make clean -C api
	@make clean -C project
	
gcov:
	@make gcov -C common
	@make gcov -C type
	@make gcov -C load
	@make gcov -C interface
	@make gcov -C api
	@make gcov -C project
