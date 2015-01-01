TARGET_OBJECT = $(CORTEX_HOME)/bin/$(dir $(TARGET))lib$(notdir $(TARGET)).so

include $(CORTEX_HOME)/build/makefilecpp.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -rf obj/$(PPREFIX)/*
	@rm -rf gcov/*
	@rm -rf $(CORTEX_HOME)/bin/$(TARGET) >/dev/null
