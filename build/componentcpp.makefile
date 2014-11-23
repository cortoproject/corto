TARGET_OBJECT = $(BIN)/$(dir $(TARGET))lib$(notdir $(TARGET)).so

include $(BUILD)/makefilecpp.makefile

$(TARGET_OBJECT): $(OBJECTS)
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -f obj/$(PPREFIX)/*
	@rm -f gcov/*
	@rm -f $(BIN)/$(TARGET) >/dev/null
