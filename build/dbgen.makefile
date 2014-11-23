
G_SOURCES = $(GEN:c_%.so=$(NAME)_%.c)
SOURCES += $(G_SOURCES)

src/%_api.c: $(DEFS)
	$(BIN)/dbgen $(DEFS) --scope $(SCOPE) --name $(NAME) -g c_api.so
	mv $(NAME)_api.c src/$(NAME)_api.c
	mv $(NAME)_api.h include/$(NAME)_api.h

src/%_load.c: $(DEFS)
	$(BIN)/dbgen $(DEFS) --scope $(SCOPE) --name $(NAME) -g c_load.so
	mv $(NAME)_load.c src/$(NAME)_load.c
	mv $(NAME)_load.h include/$(NAME)_load.h

include $(BUILD)/component.makefile

clean:
	@rm -f obj/*
	@rm -f gcov/*
	@rm -f $(BIN)/$(TARGET) >/dev/null
	@rm -f src/$(NAME)_load.c
	@rm -f src/$(NAME)_api.c
	@rm -f include/$(NAME)_load.h
	@rm -f include/$(NAME)_api.h	