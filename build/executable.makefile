TARGET_OBJECT = $(BIN)/$(TARGET)

include $(BUILD)/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -o $@
	
clean: 
	@rm -rf obj/
	@rm -rf gcov/
	@rm -rf $(BIN)/$(TARGET) >/dev/null