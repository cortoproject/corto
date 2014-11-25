TARGET_OBJECT = $(BIN)/$(dir $(TARGET))lib$(notdir $(TARGET)).so

include $(BUILD)/makefilecpp.makefile

$(TARGET_OBJECT): $(OBJECTS)
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -rf obj/$(PPREFIX)/*
	@rm -rf gcov/*
	@rm -rf $(BIN)/$(TARGET) >/dev/null
