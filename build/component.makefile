
TARGET_OBJECT = $(HYVE_HOME)/bin/$(dir $(TARGET))lib$(notdir $(TARGET)).so

include $(HYVE_HOME)/build/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -rf obj/$(PPREFIX)/
	@rm -rf gcov/
