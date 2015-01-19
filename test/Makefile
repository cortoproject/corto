
all:
	@make -C tc_cx
	@make -C tc_event
	@make -C tc_jsonser
	@make -C tc_stringser

clean:
	@make clean -C tc_cx
	@make clean -C tc_event
	@make clean -C tc_jsonser
	@make clean -C tc_stringser

gcov:
	@make gcov -C tc_cx
	@make gcov -C tc_event
	@make gcov -C tc_jsonser
	@make gcov -C tc_stringser

splint:
	@make splint -C tc_cx
	@make splint -C tc_event
	@make splint -C tc_jsonser
	@make splint -C tc_stringser
