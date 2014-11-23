TARGET = lib$(IDL_MODULE).so

include $(BUILD)/externals/opensplice.makefile

include $(BUILD)/makefile.makefile

IDL=idlpp

IDL_OBJECTS = $(IDL_MODULE:%=obj/%SacDcps.o) $(IDL_MODULE:%=obj/%SplDcps.o)

obj/%.c: $(IDL_MODULE).idl
	$(IDL) -S -lc $< -d obj

obj/%.o: obj/%.c
	$(CC) $(CFLAGS) $(OSPL_INCLUDES:%=-I%) $< -c -o $@

$(TARGET_OBJECT): $(IDL_OBJECTS)
	$(CC) $(IDL_OBJECTS) $(OSPL_LIBPATH:%=-L%) $(OSPL_LIBS:%=-l%) -shared -o $@

