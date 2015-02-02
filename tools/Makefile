.PHONY: all
.PHONY: clean
.PHONY: gcov

all:
	@make -C cxsh
	@make -C cortex
	@make -C cxgen

clean:
	@make clean -C cxsh
	@make clean -C cortex
	@make clean -C cxgen
	
gcov:
	@make gcov -C cxsh
	@make gcov -C cortex
	@make clean -C cxgen
