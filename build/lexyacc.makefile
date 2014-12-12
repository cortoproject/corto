SOURCES += 	y.tab.c \
			lex.yy.c			

include $(HYVE_HOME)/build/component.makefile

src/lex.yy.c: src/$(LEX) src/y.tab.c
	flex -o$@ src/$(LEX)

src/y.tab.c: src/$(YACC)
	yacc -d -v -o $@ src/$(YACC) 

	