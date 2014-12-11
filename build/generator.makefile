TARGET_OBJECT = $(HYVE_HOME)/bin/generator/bin/$(TARGET)
LIBPATH += $(HYVE_HOME)/bin/generator/bin

include $(HYVE_HOME)/build/makefile.makefile

$(TARGET_OBJECT): $(OBJECTS)
	@mkdir -p $(dir $(TARGET_OBJECT))
	$(CC) $(COVFLAGS) $(OBJECTS) $(LINK) -shared -o $@
	
clean: 
	@rm -f obj/$(PPREFIX)/*
	@rm -f gcov/*
	@rm -f $(HYVE_HOME)/bin/$(TARGET) >/dev/null
