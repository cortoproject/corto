TARGET_OBJECT = $(BIN)/$(TARGET)

include $(BUILD)/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -o $@
	
clean: 
	@rm -rf obj/
	@rm -rf gcov/
	@rm -rf $(BIN)/$(TARGET) >/dev/null