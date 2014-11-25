
TARGET_OBJECT = $(BIN)/$(dir $(TARGET))lib$(notdir $(TARGET)).so

include $(BUILD)/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(HYVE_HOME)/bin
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -rf obj/$(PPREFIX)/
	@rm -rf gcov/
