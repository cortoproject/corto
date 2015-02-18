TARGET_OBJECT = $(CORTEX_HOME)/generator/bin/$(TARGET)
LIBPATH += $(CORTEX_HOME)/generator/bin

include $(CORTEX_HOME)/build/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	@mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@

.PHONY: clean	
clean: 
	@rm -f obj/$(PPREFIX)/*
	@rm -f gcov/*
	@rm -f $(CORTEX_HOME)/$(TARGET) >/dev/null
