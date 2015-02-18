TARGET_OBJECT = $(CORTEX_HOME)/bin/$(TARGET)

include $(CORTEX_HOME)/build/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -o $@

.PHONY: clean
clean: 
	@rm -rf obj/
	@rm -rf gcov/
	@rm -rf $(CORTEX_HOME)/bin/$(TARGET) >/dev/null