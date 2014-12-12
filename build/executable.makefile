TARGET_OBJECT = $(HYVE_HOME)/bin/$(TARGET)

include $(HYVE_HOME)/build/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -o $@
	
clean: 
	@rm -rf obj/
	@rm -rf gcov/
	@rm -rf $(HYVE_HOME)/bin/$(TARGET) >/dev/null