/* io__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "io__type.h"

/* Variable definitions */
db_object _o;
db_void (*io_o);
io_file io_err_o;
db_class io_file_o;
db_member io_file_binary_o;
db_callback io_file_construct_o;
db_callback io_file_destruct_o;
db_method io_file_flush_o;
db_member io_file_handle_o;
db_member io_file_mode_o;
db_member io_file_name_o;
db_method io_file_read_o;
db_method io_file_readAll_o;
db_method io_file_readLn_o;
db_method io_file_readText_o;
db_method io_file_write_o;
db_method io_file_writeText_o;
db_enum io_fileMode_o;
db_constant (*io_fileMode_Append_o);
db_constant (*io_fileMode_Read_o);
db_constant (*io_fileMode_ReadAppend_o);
db_constant (*io_fileMode_ReadWrite_o);
db_constant (*io_fileMode_Write_o);
io_file io_in_o;
io_file io_out_o;
db_function io_print_o;
db_function io_println_o;
db_function io_readln_o;

/* Load objects in database */
int io_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = db_declare(root_o, "cortex", db_typedef(db_object_o));
    if (!_o) {
        db_error("io_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("io_load: failed to define object '::cortex'.");
            goto error;
        }
    }
    /* Declare ::cortex::io */
    io_o = db_declare(_o, "io", db_typedef(db_void_o));
    if (!io_o) {
        db_error("io_load: failed to declare object '::cortex::io'.");
        goto error;
    }

    /* Declare ::cortex::io::file */
    io_file_o = db_declare(io_o, "file", db_typedef(db_class_o));
    if (!io_file_o) {
        db_error("io_load: failed to declare object '::cortex::io::file'.");
        goto error;
    }

    /* Declare ::cortex::io::file::binary */
    io_file_binary_o = db_declare(io_file_o, "binary", db_typedef(db_member_o));
    if (!io_file_binary_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::binary'.");
        goto error;
    }

    /* Define ::cortex::io::file::binary */
    if (!db_checkState(io_file_binary_o, DB_DEFINED)) {
        io_file_binary_o->type = db_resolve_ext(io_file_binary_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::io::file::binary.type");
        io_file_binary_o->modifiers = 0x0;
        io_file_binary_o->state = 0x6;
        io_file_binary_o->weak = FALSE;
        io_file_binary_o->id = 2;
        if (db_define(io_file_binary_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::binary'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::flush() */
    io_file_flush_o = db_declare(io_file_o, "flush()", db_typedef(db_method_o));
    if (!io_file_flush_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::flush()'.");
        goto error;
    }

    /* Define ::cortex::io::file::flush() */
    if (!db_checkState(io_file_flush_o, DB_DEFINED)) {
        db_function(io_file_flush_o)->returnType = db_resolve_ext(io_file_flush_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::file::flush().returnType");
        db_function(io_file_flush_o)->returnsReference = FALSE;
        io_file_flush_o->virtual = FALSE;
        
        /* Bind io_file_flush_o with C-function */
        db_function(io_file_flush_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_flush(void *args, void *result);
        db_function(io_file_flush_o)->impl = (db_word)__io_file_flush;
        if (db_define(io_file_flush_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::flush()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::handle */
    io_file_handle_o = db_declare(io_file_o, "handle", db_typedef(db_member_o));
    if (!io_file_handle_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::handle'.");
        goto error;
    }

    /* Define ::cortex::io::file::handle */
    if (!db_checkState(io_file_handle_o, DB_DEFINED)) {
        io_file_handle_o->type = db_resolve_ext(io_file_handle_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::io::file::handle.type");
        io_file_handle_o->modifiers = 0x1;
        io_file_handle_o->state = 0x6;
        io_file_handle_o->weak = FALSE;
        io_file_handle_o->id = 3;
        if (db_define(io_file_handle_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::handle'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::mode */
    io_file_mode_o = db_declare(io_file_o, "mode", db_typedef(db_member_o));
    if (!io_file_mode_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::mode'.");
        goto error;
    }

    /* Declare ::cortex::io::file::name */
    io_file_name_o = db_declare(io_file_o, "name", db_typedef(db_member_o));
    if (!io_file_name_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::name'.");
        goto error;
    }

    /* Define ::cortex::io::file::name */
    if (!db_checkState(io_file_name_o, DB_DEFINED)) {
        io_file_name_o->type = db_resolve_ext(io_file_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::name.type");
        io_file_name_o->modifiers = 0x0;
        io_file_name_o->state = 0x6;
        io_file_name_o->weak = FALSE;
        io_file_name_o->id = 0;
        if (db_define(io_file_name_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::name'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
    io_file_read_o = db_declare(io_file_o, "read(::cortex::lang::uint32 bytes)", db_typedef(db_method_o));
    if (!io_file_read_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::read(::cortex::lang::uint32 bytes)'.");
        goto error;
    }

    /* Declare ::cortex::io::file::readAll() */
    io_file_readAll_o = db_declare(io_file_o, "readAll()", db_typedef(db_method_o));
    if (!io_file_readAll_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::readAll()'.");
        goto error;
    }

    /* Declare ::cortex::io::file::readLn() */
    io_file_readLn_o = db_declare(io_file_o, "readLn()", db_typedef(db_method_o));
    if (!io_file_readLn_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::readLn()'.");
        goto error;
    }

    /* Define ::cortex::io::file::readLn() */
    if (!db_checkState(io_file_readLn_o, DB_DEFINED)) {
        db_function(io_file_readLn_o)->returnType = db_resolve_ext(io_file_readLn_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::readLn().returnType");
        db_function(io_file_readLn_o)->returnsReference = FALSE;
        io_file_readLn_o->virtual = FALSE;
        
        /* Bind io_file_readLn_o with C-function */
        db_function(io_file_readLn_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_readLn(void *args, void *result);
        db_function(io_file_readLn_o)->impl = (db_word)__io_file_readLn;
        if (db_define(io_file_readLn_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::readLn()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::readText() */
    io_file_readText_o = db_declare(io_file_o, "readText()", db_typedef(db_method_o));
    if (!io_file_readText_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::readText()'.");
        goto error;
    }

    /* Define ::cortex::io::file::readText() */
    if (!db_checkState(io_file_readText_o, DB_DEFINED)) {
        db_function(io_file_readText_o)->returnType = db_resolve_ext(io_file_readText_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::file::readText().returnType");
        db_function(io_file_readText_o)->returnsReference = FALSE;
        io_file_readText_o->virtual = FALSE;
        
        /* Bind io_file_readText_o with C-function */
        db_function(io_file_readText_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_readText(void *args, void *result);
        db_function(io_file_readText_o)->impl = (db_word)__io_file_readText;
        if (db_define(io_file_readText_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::readText()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::writeText(::cortex::lang::string txt) */
    io_file_writeText_o = db_declare(io_file_o, "writeText(::cortex::lang::string txt)", db_typedef(db_method_o));
    if (!io_file_writeText_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::writeText(::cortex::lang::string txt)'.");
        goto error;
    }

    /* Define ::cortex::io::file::writeText(::cortex::lang::string txt) */
    if (!db_checkState(io_file_writeText_o, DB_DEFINED)) {
        db_function(io_file_writeText_o)->returnType = db_resolve_ext(io_file_writeText_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::io::file::writeText(::cortex::lang::string txt).returnType");
        db_function(io_file_writeText_o)->returnsReference = FALSE;
        io_file_writeText_o->virtual = FALSE;
        
        /* Bind io_file_writeText_o with C-function */
        db_function(io_file_writeText_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_writeText(void *args, void *result);
        db_function(io_file_writeText_o)->impl = (db_word)__io_file_writeText;
        if (db_define(io_file_writeText_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::writeText(::cortex::lang::string txt)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode */
    io_fileMode_o = db_declare(io_o, "fileMode", db_typedef(db_enum_o));
    if (!io_fileMode_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode'.");
        goto error;
    }

    /* Declare ::cortex::io::fileMode::Append */
    io_fileMode_Append_o = db_declare(io_fileMode_o, "Append", db_typedef(db_constant_o));
    if (!io_fileMode_Append_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode::Append'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Append */
    if (!db_checkState(io_fileMode_Append_o, DB_DEFINED)) {
        (*io_fileMode_Append_o) = 2;
        if (db_define(io_fileMode_Append_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode::Append'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::Read */
    io_fileMode_Read_o = db_declare(io_fileMode_o, "Read", db_typedef(db_constant_o));
    if (!io_fileMode_Read_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode::Read'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Read */
    if (!db_checkState(io_fileMode_Read_o, DB_DEFINED)) {
        (*io_fileMode_Read_o) = 0;
        if (db_define(io_fileMode_Read_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode::Read'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::ReadAppend */
    io_fileMode_ReadAppend_o = db_declare(io_fileMode_o, "ReadAppend", db_typedef(db_constant_o));
    if (!io_fileMode_ReadAppend_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode::ReadAppend'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::ReadAppend */
    if (!db_checkState(io_fileMode_ReadAppend_o, DB_DEFINED)) {
        (*io_fileMode_ReadAppend_o) = 4;
        if (db_define(io_fileMode_ReadAppend_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode::ReadAppend'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::ReadWrite */
    io_fileMode_ReadWrite_o = db_declare(io_fileMode_o, "ReadWrite", db_typedef(db_constant_o));
    if (!io_fileMode_ReadWrite_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode::ReadWrite'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::ReadWrite */
    if (!db_checkState(io_fileMode_ReadWrite_o, DB_DEFINED)) {
        (*io_fileMode_ReadWrite_o) = 3;
        if (db_define(io_fileMode_ReadWrite_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode::ReadWrite'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::fileMode::Write */
    io_fileMode_Write_o = db_declare(io_fileMode_o, "Write", db_typedef(db_constant_o));
    if (!io_fileMode_Write_o) {
        db_error("io_load: failed to declare object '::cortex::io::fileMode::Write'.");
        goto error;
    }

    /* Define ::cortex::io::fileMode::Write */
    if (!db_checkState(io_fileMode_Write_o, DB_DEFINED)) {
        (*io_fileMode_Write_o) = 1;
        if (db_define(io_fileMode_Write_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode::Write'.");
            goto error;
        }
    }
    /* Define ::cortex::io::fileMode */
    if (!db_checkState(io_fileMode_o, DB_DEFINED)) {
        if (db_define(io_fileMode_o)) {
            db_error("io_load: failed to define object '::cortex::io::fileMode'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::mode */
    if (!db_checkState(io_file_mode_o, DB_DEFINED)) {
        io_file_mode_o->type = db_resolve_ext(io_file_mode_o, NULL, "::cortex::io::fileMode", FALSE, "element ::cortex::io::file::mode.type");
        io_file_mode_o->modifiers = 0x0;
        io_file_mode_o->state = 0x6;
        io_file_mode_o->weak = FALSE;
        io_file_mode_o->id = 1;
        if (db_define(io_file_mode_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::mode'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::print(::cortex::lang::string str) */
    io_print_o = db_declare(io_o, "print(::cortex::lang::string str)", db_typedef(db_function_o));
    if (!io_print_o) {
        db_error("io_load: failed to declare object '::cortex::io::print(::cortex::lang::string str)'.");
        goto error;
    }

    /* Define ::cortex::io::print(::cortex::lang::string str) */
    if (!db_checkState(io_print_o, DB_DEFINED)) {
        io_print_o->returnType = db_resolve_ext(io_print_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::print(::cortex::lang::string str).returnType");
        io_print_o->returnsReference = FALSE;
        
        /* Bind io_print_o with C-function */
        db_function(io_print_o)->kind = DB_PROCEDURE_CDECL;
        void __io_print(void *args, void *result);
        db_function(io_print_o)->impl = (db_word)__io_print;
        if (db_define(io_print_o)) {
            db_error("io_load: failed to define object '::cortex::io::print(::cortex::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::println(::cortex::lang::string str) */
    io_println_o = db_declare(io_o, "println(::cortex::lang::string str)", db_typedef(db_function_o));
    if (!io_println_o) {
        db_error("io_load: failed to declare object '::cortex::io::println(::cortex::lang::string str)'.");
        goto error;
    }

    /* Define ::cortex::io::println(::cortex::lang::string str) */
    if (!db_checkState(io_println_o, DB_DEFINED)) {
        io_println_o->returnType = db_resolve_ext(io_println_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::println(::cortex::lang::string str).returnType");
        io_println_o->returnsReference = FALSE;
        
        /* Bind io_println_o with C-function */
        db_function(io_println_o)->kind = DB_PROCEDURE_CDECL;
        void __io_println(void *args, void *result);
        db_function(io_println_o)->impl = (db_word)__io_println;
        if (db_define(io_println_o)) {
            db_error("io_load: failed to define object '::cortex::io::println(::cortex::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::readln() */
    io_readln_o = db_declare(io_o, "readln()", db_typedef(db_function_o));
    if (!io_readln_o) {
        db_error("io_load: failed to declare object '::cortex::io::readln()'.");
        goto error;
    }

    /* Define ::cortex::io::readln() */
    if (!db_checkState(io_readln_o, DB_DEFINED)) {
        io_readln_o->returnType = db_resolve_ext(io_readln_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::io::readln().returnType");
        io_readln_o->returnsReference = FALSE;
        
        /* Bind io_readln_o with C-function */
        db_function(io_readln_o)->kind = DB_PROCEDURE_CDECL;
        void __io_readln(void *args, void *result);
        db_function(io_readln_o)->impl = (db_word)__io_readln;
        if (db_define(io_readln_o)) {
            db_error("io_load: failed to define object '::cortex::io::readln()'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::read(::cortex::lang::uint32 bytes) */
    if (!db_checkState(io_file_read_o, DB_DEFINED)) {
        db_function(io_file_read_o)->returnType = db_resolve_ext(io_file_read_o, NULL, "::cortex::lang::sequence{::cortex::lang::octet,0}", FALSE, "element ::cortex::io::file::read(::cortex::lang::uint32 bytes).returnType");
        db_function(io_file_read_o)->returnsReference = FALSE;
        io_file_read_o->virtual = FALSE;
        
        /* Bind io_file_read_o with C-function */
        db_function(io_file_read_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_read(void *args, void *result);
        db_function(io_file_read_o)->impl = (db_word)__io_file_read;
        if (db_define(io_file_read_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::read(::cortex::lang::uint32 bytes)'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file::readAll() */
    if (!db_checkState(io_file_readAll_o, DB_DEFINED)) {
        db_function(io_file_readAll_o)->returnType = db_resolve_ext(io_file_readAll_o, NULL, "::cortex::lang::sequence{::cortex::lang::octet,0}", FALSE, "element ::cortex::io::file::readAll().returnType");
        db_function(io_file_readAll_o)->returnsReference = FALSE;
        io_file_readAll_o->virtual = FALSE;
        
        /* Bind io_file_readAll_o with C-function */
        db_function(io_file_readAll_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_readAll(void *args, void *result);
        db_function(io_file_readAll_o)->impl = (db_word)__io_file_readAll;
        if (db_define(io_file_readAll_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::readAll()'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
    io_file_write_o = db_declare(io_file_o, "write(::cortex::lang::sequence{::cortex::lang::octet,0} data)", db_typedef(db_method_o));
    if (!io_file_write_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data)'.");
        goto error;
    }

    /* Define ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data) */
    if (!db_checkState(io_file_write_o, DB_DEFINED)) {
        db_function(io_file_write_o)->returnType = db_resolve_ext(io_file_write_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data).returnType");
        db_function(io_file_write_o)->returnsReference = FALSE;
        io_file_write_o->virtual = FALSE;
        
        /* Bind io_file_write_o with C-function */
        db_function(io_file_write_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_write(void *args, void *result);
        db_function(io_file_write_o)->impl = (db_word)__io_file_write;
        if (db_define(io_file_write_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::write(::cortex::lang::sequence{::cortex::lang::octet,0} data)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::construct(::cortex::io::file object) */
    io_file_construct_o = db_declare(io_file_o, "construct(::cortex::io::file object)", db_typedef(db_callback_o));
    if (!io_file_construct_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::construct(::cortex::io::file object)'.");
        goto error;
    }

    /* Define ::cortex::io::file::construct(::cortex::io::file object) */
    if (!db_checkState(io_file_construct_o, DB_DEFINED)) {
        db_function(io_file_construct_o)->returnType = db_resolve_ext(io_file_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::io::file::construct(::cortex::io::file object).returnType");
        db_function(io_file_construct_o)->returnsReference = FALSE;
        io_file_construct_o->delegate = db_resolve_ext(io_file_construct_o, NULL, "::cortex::lang::class::construct(lang::object object)", FALSE, "element ::cortex::io::file::construct(::cortex::io::file object).delegate");
        
        /* Bind io_file_construct_o with C-function */
        db_function(io_file_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_construct(void *args, void *result);
        db_function(io_file_construct_o)->impl = (db_word)__io_file_construct;
        if (db_define(io_file_construct_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::construct(::cortex::io::file object)'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::file::destruct(::cortex::io::file object) */
    io_file_destruct_o = db_declare(io_file_o, "destruct(::cortex::io::file object)", db_typedef(db_callback_o));
    if (!io_file_destruct_o) {
        db_error("io_load: failed to declare object '::cortex::io::file::destruct(::cortex::io::file object)'.");
        goto error;
    }

    /* Define ::cortex::io::file::destruct(::cortex::io::file object) */
    if (!db_checkState(io_file_destruct_o, DB_DEFINED)) {
        db_function(io_file_destruct_o)->returnType = db_resolve_ext(io_file_destruct_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::io::file::destruct(::cortex::io::file object).returnType");
        db_function(io_file_destruct_o)->returnsReference = FALSE;
        io_file_destruct_o->delegate = db_resolve_ext(io_file_destruct_o, NULL, "::cortex::lang::class::destruct(lang::object object)", FALSE, "element ::cortex::io::file::destruct(::cortex::io::file object).delegate");
        
        /* Bind io_file_destruct_o with C-function */
        db_function(io_file_destruct_o)->kind = DB_PROCEDURE_CDECL;
        void __io_file_destruct(void *args, void *result);
        db_function(io_file_destruct_o)->impl = (db_word)__io_file_destruct;
        if (db_define(io_file_destruct_o)) {
            db_error("io_load: failed to define object '::cortex::io::file::destruct(::cortex::io::file object)'.");
            goto error;
        }
    }
    /* Define ::cortex::io::file */
    if (!db_checkState(io_file_o, DB_DEFINED)) {
        db_type(io_file_o)->defaultType = db_resolve_ext(io_file_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::io::file.defaultType");
        db_type(io_file_o)->parentType = NULL;
        db_type(io_file_o)->parentState = 0x0;
        db_interface(io_file_o)->base = NULL;
        db_struct(io_file_o)->baseAccess = 0x0;
        io_file_o->implements.length = 0;
        io_file_o->implements.buffer = NULL;
        if (db_define(io_file_o)) {
            db_error("io_load: failed to define object '::cortex::io::file'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::err */
    io_err_o = db_declare(io_o, "err", db_typedef(io_file_o));
    if (!io_err_o) {
        db_error("io_load: failed to declare object '::cortex::io::err'.");
        goto error;
    }

    /* Define ::cortex::io::err */
    if (!db_checkState(io_err_o, DB_DEFINED)) {
        io_err_o->name = db_strdup("#err");
        io_err_o->mode = IO_Write;
        io_err_o->binary = FALSE;
        if (db_define(io_err_o)) {
            db_error("io_load: failed to define object '::cortex::io::err'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::in */
    io_in_o = db_declare(io_o, "in", db_typedef(io_file_o));
    if (!io_in_o) {
        db_error("io_load: failed to declare object '::cortex::io::in'.");
        goto error;
    }

    /* Define ::cortex::io::in */
    if (!db_checkState(io_in_o, DB_DEFINED)) {
        io_in_o->name = db_strdup("#in");
        io_in_o->mode = IO_Read;
        io_in_o->binary = FALSE;
        if (db_define(io_in_o)) {
            db_error("io_load: failed to define object '::cortex::io::in'.");
            goto error;
        }
    }
    /* Declare ::cortex::io::out */
    io_out_o = db_declare(io_o, "out", db_typedef(io_file_o));
    if (!io_out_o) {
        db_error("io_load: failed to declare object '::cortex::io::out'.");
        goto error;
    }

    /* Define ::cortex::io::out */
    if (!db_checkState(io_out_o, DB_DEFINED)) {
        io_out_o->name = db_strdup("#out");
        io_out_o->mode = IO_Write;
        io_out_o->binary = FALSE;
        if (db_define(io_out_o)) {
            db_error("io_load: failed to define object '::cortex::io::out'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
