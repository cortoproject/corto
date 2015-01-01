/* io__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "io__type.h"

/* Variable definitions */
cx_object _o;
cx_void (*io_o);
io_file io_err_o;
cx_class io_file_o;
cx_member io_file_binary_o;
cx_callback io_file_construct_o;
cx_callback io_file_destruct_o;
cx_method io_file_flush_o;
cx_member io_file_handle_o;
cx_member io_file_mode_o;
cx_member io_file_name_o;
cx_method io_file_read_o;
cx_method io_file_readAll_o;
cx_method io_file_readLn_o;
cx_method io_file_readText_o;
cx_method io_file_write_o;
cx_method io_file_writeText_o;
cx_enum io_fileMode_o;
cx_constant (*io_fileMode_Append_o);
cx_constant (*io_fileMode_Read_o);
cx_constant (*io_fileMode_ReadAppend_o);
cx_constant (*io_fileMode_ReadWrite_o);
cx_constant (*io_fileMode_Write_o);
io_file io_in_o;
io_file io_out_o;
cx_function io_print_o;
cx_function io_println_o;
cx_function io_readln_o;

/* Load objects in database */
int io_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = cx_declare(root_o, "cortex", cx_typedef(cx_object_o));
    if (!_o) {
        cx_error("io_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!cx_checkState(_o, CX_DEFINED)) {
        if (cx_define(_o)) {
            cx_error("io_load: failed to define object '::cortex'.");
            goto error;
        }
    }
    /* Declare ::cortex::io */
    io_o = cx_declare(_o, "io", cx_typedef(cx_void_o));
    if (!io_o) {
        cx_error("io_load: failed to declare object '::cortex::io'.");
        goto error;
    }

    /* Declare ::cortex::io::file */
    io_file_o = cx_declare(io_o, "file", cx_typedef(cx_class_o));
    if (!io_file_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file'.");
        goto error;
    }

    /* Declare ::cortex::io::file::binary */
    io_file_binary_o = cx_declare(io_file_o, "binary", cx_typedef(cx_member_o));
    if (!io_file_binary_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::binary'.");
        goto error;
    }

    /* Define ::cortex::io::file::binary */
    if (!cx_checkState(io_file_binary_o, CX_DEFINED)) {
        io_file_binary_o->type = cx_resolve_ext(io_file_binary_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::io::file::binary.type");
        io_file_binary_o->modifiers = 0x0;
        io_file_binary_o->state = 0x6;
        io_file_binary_o->weak = FALSE;
        io_file_binary_o->id = 2;
        if (cx_define(io_file_binary_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::binary'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::flush() */
    io_file_flush_o = cx_declare(io_file_o, "flush()", cx_typedef(cx_method_o));
    if (!io_file_flush_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::flush()'.");
        goto error;
    }

    /* Define ::cortex::io::file::flush() */
    if (!cx_checkState(io_file_flush_o, CX_DEFINED)) {
        cx_function(io_file_flush_o)->returnType = cx_resolve_ext(io_file_flush_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::file::flush().returnType");
        cx_function(io_file_flush_o)->returnsReference = FALSE;
        io_file_flush_o->virtual = FALSE;
        
        /* Bind io_file_flush_o with C-function */
        cx_function(io_file_flush_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_flush(void *args, void *result);
        cx_function(io_file_flush_o)->impl = (cx_word)__io_file_flush;
        if (cx_define(io_file_flush_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::flush()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::handle */
    io_file_handle_o = cx_declare(io_file_o, "handle", cx_typedef(cx_member_o));
    if (!io_file_handle_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::handle'.");
        goto error;
    }

    /* Define ::cortex::io::file::handle */
    if (!cx_checkState(io_file_handle_o, CX_DEFINED)) {
        io_file_handle_o->type = cx_resolve_ext(io_file_handle_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::io::file::handle.type");
        io_file_handle_o->modifiers = 0x1;
        io_file_handle_o->state = 0x6;
        io_file_handle_o->weak = FALSE;
        io_file_handle_o->id = 3;
        if (cx_define(io_file_handle_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::handle'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::mode */
    io_file_mode_o = cx_declare(io_file_o, "mode", cx_typedef(cx_member_o));
    if (!io_file_mode_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::mode'.");
        goto error;
    }

    /* Declare ::cortex::io::file::name */
    io_file_name_o = cx_declare(io_file_o, "name", cx_typedef(cx_member_o));
    if (!io_file_name_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::name'.");
        goto error;
    }

    /* Define ::cortex::io::file::name */
    if (!cx_checkState(io_file_name_o, CX_DEFINED)) {
        io_file_name_o->type = cx_resolve_ext(io_file_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::name.type");
        io_file_name_o->modifiers = 0x0;
        io_file_name_o->state = 0x6;
        io_file_name_o->weak = FALSE;
        io_file_name_o->id = 0;
        if (cx_define(io_file_name_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::name'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
    io_file_read_o = cx_declare(io_file_o, "read(::cortex::lang::uint32 bytes)", cx_typedef(cx_method_o));
    if (!io_file_read_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::read(::cortex::lang::uint32 bytes)'.");
        goto error;
    }

    /* Declare ::cortex::io::file::readAll() */
    io_file_readAll_o = cx_declare(io_file_o, "readAll()", cx_typedef(cx_method_o));
    if (!io_file_readAll_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::readAll()'.");
        goto error;
    }

    /* Declare ::cortex::io::file::readLn() */
    io_file_readLn_o = cx_declare(io_file_o, "readLn()", cx_typedef(cx_method_o));
    if (!io_file_readLn_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::readLn()'.");
        goto error;
    }

    /* Define ::cortex::io::file::readLn() */
    if (!cx_checkState(io_file_readLn_o, CX_DEFINED)) {
        cx_function(io_file_readLn_o)->returnType = cx_resolve_ext(io_file_readLn_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::readLn().returnType");
        cx_function(io_file_readLn_o)->returnsReference = FALSE;
        io_file_readLn_o->virtual = FALSE;
        
        /* Bind io_file_readLn_o with C-function */
        cx_function(io_file_readLn_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_readLn(void *args, void *result);
        cx_function(io_file_readLn_o)->impl = (cx_word)__io_file_readLn;
        if (cx_define(io_file_readLn_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::readLn()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::readText() */
    io_file_readText_o = cx_declare(io_file_o, "readText()", cx_typedef(cx_method_o));
    if (!io_file_readText_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::readText()'.");
        goto error;
    }

    /* Define ::cortex::io::file::readText() */
    if (!cx_checkState(io_file_readText_o, CX_DEFINED)) {
        cx_function(io_file_readText_o)->returnType = cx_resolve_ext(io_file_readText_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::readText().returnType");
        cx_function(io_file_readText_o)->returnsReference = FALSE;
        io_file_readText_o->virtual = FALSE;
        
        /* Bind io_file_readText_o with C-function */
        cx_function(io_file_readText_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_readText(void *args, void *result);
        cx_function(io_file_readText_o)->impl = (cx_word)__io_file_readText;
        if (cx_define(io_file_readText_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::readText()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::writeText(::cortex::lang::string txt) */
    io_file_writeText_o = cx_declare(io_file_o, "writeText(::cortex::lang::string txt)", cx_typedef(cx_method_o));
    if (!io_file_writeText_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::writeText(::cortex::lang::string txt)'.");
        goto error;
    }

    /* Define ::cortex::io::file::writeText(::cortex::lang::string txt) */
    if (!cx_checkState(io_file_writeText_o, CX_DEFINED)) {
        cx_function(io_file_writeText_o)->returnType = cx_resolve_ext(io_file_writeText_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::io::file::writeText(::cortex::lang::string txt).returnType");
        cx_function(io_file_writeText_o)->returnsReference = FALSE;
        io_file_writeText_o->virtual = FALSE;
        
        /* Bind io_file_writeText_o with C-function */
        cx_function(io_file_writeText_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_writeText(void *args, void *result);
        cx_function(io_file_writeText_o)->impl = (cx_word)__io_file_writeText;
        if (cx_define(io_file_writeText_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::writeText(::cortex::lang::string txt)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode */
    io_fileMode_o = cx_declare(io_o, "fileMode", cx_typedef(cx_enum_o));
    if (!io_fileMode_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode'.");
        goto error;
    }

    /* Declare ::cortex::io::fileMode::Append */
    io_fileMode_Append_o = cx_declare(io_fileMode_o, "Append", cx_typedef(cx_constant_o));
    if (!io_fileMode_Append_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode::Append'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Append */
    if (!cx_checkState(io_fileMode_Append_o, CX_DEFINED)) {
        (*io_fileMode_Append_o) = 2;
        if (cx_define(io_fileMode_Append_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode::Append'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::Read */
    io_fileMode_Read_o = cx_declare(io_fileMode_o, "Read", cx_typedef(cx_constant_o));
    if (!io_fileMode_Read_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode::Read'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Read */
    if (!cx_checkState(io_fileMode_Read_o, CX_DEFINED)) {
        (*io_fileMode_Read_o) = 0;
        if (cx_define(io_fileMode_Read_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode::Read'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::ReadAppend */
    io_fileMode_ReadAppend_o = cx_declare(io_fileMode_o, "ReadAppend", cx_typedef(cx_constant_o));
    if (!io_fileMode_ReadAppend_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode::ReadAppend'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::ReadAppend */
    if (!cx_checkState(io_fileMode_ReadAppend_o, CX_DEFINED)) {
        (*io_fileMode_ReadAppend_o) = 4;
        if (cx_define(io_fileMode_ReadAppend_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode::ReadAppend'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::ReadWrite */
    io_fileMode_ReadWrite_o = cx_declare(io_fileMode_o, "ReadWrite", cx_typedef(cx_constant_o));
    if (!io_fileMode_ReadWrite_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode::ReadWrite'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::ReadWrite */
    if (!cx_checkState(io_fileMode_ReadWrite_o, CX_DEFINED)) {
        (*io_fileMode_ReadWrite_o) = 3;
        if (cx_define(io_fileMode_ReadWrite_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode::ReadWrite'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::Write */
    io_fileMode_Write_o = cx_declare(io_fileMode_o, "Write", cx_typedef(cx_constant_o));
    if (!io_fileMode_Write_o) {
        cx_error("io_load: failed to declare object '::cortex::io::fileMode::Write'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Write */
    if (!cx_checkState(io_fileMode_Write_o, CX_DEFINED)) {
        (*io_fileMode_Write_o) = 1;
        if (cx_define(io_fileMode_Write_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode::Write'.");
            goto error;
        }
    }
    /* Define ::cortex::io::fileMode */
    if (!cx_checkState(io_fileMode_o, CX_DEFINED)) {
        if (cx_define(io_fileMode_o)) {
            cx_error("io_load: failed to define object '::cortex::io::fileMode'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::mode */
    if (!cx_checkState(io_file_mode_o, CX_DEFINED)) {
        io_file_mode_o->type = cx_resolve_ext(io_file_mode_o, NULL, "::cortex::io::fileMode", FALSE, "element ::cortex::io::file::mode.type");
        io_file_mode_o->modifiers = 0x0;
        io_file_mode_o->state = 0x6;
        io_file_mode_o->weak = FALSE;
        io_file_mode_o->id = 1;
        if (cx_define(io_file_mode_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::mode'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::print(::cortex::lang::string str) */
    io_print_o = cx_declare(io_o, "print(::cortex::lang::string str)", cx_typedef(cx_function_o));
    if (!io_print_o) {
        cx_error("io_load: failed to declare object '::cortex::io::print(::cortex::lang::string str)'.");
        goto error;
    }

    /* Define ::cortex::io::print(::cortex::lang::string str) */
    if (!cx_checkState(io_print_o, CX_DEFINED)) {
        io_print_o->returnType = cx_resolve_ext(io_print_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::print(::cortex::lang::string str).returnType");
        io_print_o->returnsReference = FALSE;
        
        /* Bind io_print_o with C-function */
        cx_function(io_print_o)->kind = CX_PROCEDURE_CDECL;
        void __io_print(void *args, void *result);
        cx_function(io_print_o)->impl = (cx_word)__io_print;
        if (cx_define(io_print_o)) {
            cx_error("io_load: failed to define object '::cortex::io::print(::cortex::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::println(::cortex::lang::string str) */
    io_println_o = cx_declare(io_o, "println(::cortex::lang::string str)", cx_typedef(cx_function_o));
    if (!io_println_o) {
        cx_error("io_load: failed to declare object '::cortex::io::println(::cortex::lang::string str)'.");
        goto error;
    }

    /* Define ::cortex::io::println(::cortex::lang::string str) */
    if (!cx_checkState(io_println_o, CX_DEFINED)) {
        io_println_o->returnType = cx_resolve_ext(io_println_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::println(::cortex::lang::string str).returnType");
        io_println_o->returnsReference = FALSE;
        
        /* Bind io_println_o with C-function */
        cx_function(io_println_o)->kind = CX_PROCEDURE_CDECL;
        void __io_println(void *args, void *result);
        cx_function(io_println_o)->impl = (cx_word)__io_println;
        if (cx_define(io_println_o)) {
            cx_error("io_load: failed to define object '::cortex::io::println(::cortex::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::readln() */
    io_readln_o = cx_declare(io_o, "readln()", cx_typedef(cx_function_o));
    if (!io_readln_o) {
        cx_error("io_load: failed to declare object '::cortex::io::readln()'.");
        goto error;
    }

    /* Define ::cortex::io::readln() */
    if (!cx_checkState(io_readln_o, CX_DEFINED)) {
        io_readln_o->returnType = cx_resolve_ext(io_readln_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::readln().returnType");
        io_readln_o->returnsReference = FALSE;
        
        /* Bind io_readln_o with C-function */
        cx_function(io_readln_o)->kind = CX_PROCEDURE_CDECL;
        void __io_readln(void *args, void *result);
        cx_function(io_readln_o)->impl = (cx_word)__io_readln;
        if (cx_define(io_readln_o)) {
            cx_error("io_load: failed to define object '::cortex::io::readln()'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
    if (!cx_checkState(io_file_read_o, CX_DEFINED)) {
        cx_function(io_file_read_o)->returnType = cx_resolve_ext(io_file_read_o, NULL, "::cortex::lang::sequence{::cortex::lang::octet,0}", FALSE, "element ::cortex::io::file::read(::cortex::lang::uint32 bytes).returnType");
        cx_function(io_file_read_o)->returnsReference = FALSE;
        io_file_read_o->virtual = FALSE;
        
        /* Bind io_file_read_o with C-function */
        cx_function(io_file_read_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_read(void *args, void *result);
        cx_function(io_file_read_o)->impl = (cx_word)__io_file_read;
        if (cx_define(io_file_read_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::read(::cortex::lang::uint32 bytes)'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::readAll() */
    if (!cx_checkState(io_file_readAll_o, CX_DEFINED)) {
        cx_function(io_file_readAll_o)->returnType = cx_resolve_ext(io_file_readAll_o, NULL, "::cortex::lang::sequence{::cortex::lang::octet,0}", FALSE, "element ::cortex::io::file::readAll().returnType");
        cx_function(io_file_readAll_o)->returnsReference = FALSE;
        io_file_readAll_o->virtual = FALSE;
        
        /* Bind io_file_readAll_o with C-function */
        cx_function(io_file_readAll_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_readAll(void *args, void *result);
        cx_function(io_file_readAll_o)->impl = (cx_word)__io_file_readAll;
        if (cx_define(io_file_readAll_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::readAll()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
    io_file_write_o = cx_declare(io_file_o, "write(::cortex::lang::sequence{::cortex::lang::octet,0} data)", cx_typedef(cx_method_o));
    if (!io_file_write_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data)'.");
        goto error;
    }

    /* Define ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
    if (!cx_checkState(io_file_write_o, CX_DEFINED)) {
        cx_function(io_file_write_o)->returnType = cx_resolve_ext(io_file_write_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data).returnType");
        cx_function(io_file_write_o)->returnsReference = FALSE;
        io_file_write_o->virtual = FALSE;
        
        /* Bind io_file_write_o with C-function */
        cx_function(io_file_write_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_write(void *args, void *result);
        cx_function(io_file_write_o)->impl = (cx_word)__io_file_write;
        if (cx_define(io_file_write_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::construct(::cortex::io::file object) */
    io_file_construct_o = cx_declare(io_file_o, "construct(::cortex::io::file object)", cx_typedef(cx_callback_o));
    if (!io_file_construct_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::construct(::cortex::io::file object)'.");
        goto error;
    }

    /* Define ::cortex::io::file::construct(::cortex::io::file object) */
    if (!cx_checkState(io_file_construct_o, CX_DEFINED)) {
        cx_function(io_file_construct_o)->returnType = cx_resolve_ext(io_file_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::io::file::construct(::cortex::io::file object).returnType");
        cx_function(io_file_construct_o)->returnsReference = FALSE;
        io_file_construct_o->delegate = cx_resolve_ext(io_file_construct_o, NULL, "::cortex::lang::class::construct(lang::object object)", FALSE, "element ::cortex::io::file::construct(::cortex::io::file object).delegate");
        
        /* Bind io_file_construct_o with C-function */
        cx_function(io_file_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_construct(void *args, void *result);
        cx_function(io_file_construct_o)->impl = (cx_word)__io_file_construct;
        if (cx_define(io_file_construct_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::construct(::cortex::io::file object)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::destruct(::cortex::io::file object) */
    io_file_destruct_o = cx_declare(io_file_o, "destruct(::cortex::io::file object)", cx_typedef(cx_callback_o));
    if (!io_file_destruct_o) {
        cx_error("io_load: failed to declare object '::cortex::io::file::destruct(::cortex::io::file object)'.");
        goto error;
    }

    /* Define ::cortex::io::file::destruct(::cortex::io::file object) */
    if (!cx_checkState(io_file_destruct_o, CX_DEFINED)) {
        cx_function(io_file_destruct_o)->returnType = cx_resolve_ext(io_file_destruct_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::file::destruct(::cortex::io::file object).returnType");
        cx_function(io_file_destruct_o)->returnsReference = FALSE;
        io_file_destruct_o->delegate = cx_resolve_ext(io_file_destruct_o, NULL, "::cortex::lang::class::destruct(lang::object object)", FALSE, "element ::cortex::io::file::destruct(::cortex::io::file object).delegate");
        
        /* Bind io_file_destruct_o with C-function */
        cx_function(io_file_destruct_o)->kind = CX_PROCEDURE_CDECL;
        void __io_file_destruct(void *args, void *result);
        cx_function(io_file_destruct_o)->impl = (cx_word)__io_file_destruct;
        if (cx_define(io_file_destruct_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file::destruct(::cortex::io::file object)'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file */
    if (!cx_checkState(io_file_o, CX_DEFINED)) {
        cx_type(io_file_o)->defaultType = cx_resolve_ext(io_file_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::io::file.defaultType");
        cx_type(io_file_o)->parentType = NULL;
        cx_type(io_file_o)->parentState = 0x0;
        cx_interface(io_file_o)->base = NULL;
        cx_struct(io_file_o)->baseAccess = 0x0;
        io_file_o->implements.length = 0;
        io_file_o->implements.buffer = NULL;
        if (cx_define(io_file_o)) {
            cx_error("io_load: failed to define object '::cortex::io::file'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::err */
    io_err_o = cx_declare(io_o, "err", cx_typedef(io_file_o));
    if (!io_err_o) {
        cx_error("io_load: failed to declare object '::cortex::io::err'.");
        goto error;
    }

    /* Define ::cortex::io::err */
    if (!cx_checkState(io_err_o, CX_DEFINED)) {
        io_err_o->name = cx_strdup("#err");
        io_err_o->mode = IO_Write;
        io_err_o->binary = FALSE;
        if (cx_define(io_err_o)) {
            cx_error("io_load: failed to define object '::cortex::io::err'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::in */
    io_in_o = cx_declare(io_o, "in", cx_typedef(io_file_o));
    if (!io_in_o) {
        cx_error("io_load: failed to declare object '::cortex::io::in'.");
        goto error;
    }

    /* Define ::cortex::io::in */
    if (!cx_checkState(io_in_o, CX_DEFINED)) {
        io_in_o->name = cx_strdup("#in");
        io_in_o->mode = IO_Read;
        io_in_o->binary = FALSE;
        if (cx_define(io_in_o)) {
            cx_error("io_load: failed to define object '::cortex::io::in'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::out */
    io_out_o = cx_declare(io_o, "out", cx_typedef(io_file_o));
    if (!io_out_o) {
        cx_error("io_load: failed to declare object '::cortex::io::out'.");
        goto error;
    }

    /* Define ::cortex::io::out */
    if (!cx_checkState(io_out_o, CX_DEFINED)) {
        io_out_o->name = cx_strdup("#out");
        io_out_o->mode = IO_Write;
        io_out_o->binary = FALSE;
        if (cx_define(io_out_o)) {
            cx_error("io_load: failed to define object '::cortex::io::out'.");
            goto error;
        }
    }
    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
