/* io__meta.c
 *
 *  Generated on Sep  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
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

    /* Declare ::hyve */
    _o = db_declare(root_o, "hyve", db_typedef(db_object_o));
    if (!_o) {
        db_error("io_load: failed to declare object '::hyve'.");
        goto error;
    }

    /* Define ::hyve */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("io_load: failed to define object '::hyve'.");
            goto error;
        }
    }
    /* Declare ::hyve::io */
    io_o = db_declare(_o, "io", db_typedef(db_void_o));
    if (!io_o) {
        db_error("io_load: failed to declare object '::hyve::io'.");
        goto error;
    }

    /* Declare ::hyve::io::file */
    io_file_o = db_declare(io_o, "file", db_typedef(db_class_o));
    if (!io_file_o) {
        db_error("io_load: failed to declare object '::hyve::io::file'.");
        goto error;
    }

    /* Declare ::hyve::io::file::binary */
    io_file_binary_o = db_declare(io_file_o, "binary", db_typedef(db_member_o));
    if (!io_file_binary_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::binary'.");
        goto error;
    }

    /* Define ::hyve::io::file::binary */
    if (!db_checkState(io_file_binary_o, DB_DEFINED)) {
        io_file_binary_o->type = db_resolve_ext(io_file_binary_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::io::file::binary.type");
        io_file_binary_o->modifiers = 0x0;
        io_file_binary_o->state = 0x6;
        io_file_binary_o->weak = FALSE;
        io_file_binary_o->id = 2;
        if (db_define(io_file_binary_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::binary'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::flush() */
    io_file_flush_o = db_declare(io_file_o, "flush()", db_typedef(db_method_o));
    if (!io_file_flush_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::flush()'.");
        goto error;
    }

    /* Define ::hyve::io::file::flush() */
    if (!db_checkState(io_file_flush_o, DB_DEFINED)) {
        db_function(io_file_flush_o)->returnType = db_resolve_ext(io_file_flush_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::io::file::flush().returnType");
        io_file_flush_o->virtual = FALSE;
        
        /* Bind io_file_flush_o with C-function */
        db_function(io_file_flush_o)->kind = DB_PROCEDURE_CDECL;
        db_void io_file_flush(io_file _this);
        db_function(io_file_flush_o)->impl = (db_word)io_file_flush;
        if (db_define(io_file_flush_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::flush()'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::handle */
    io_file_handle_o = db_declare(io_file_o, "handle", db_typedef(db_member_o));
    if (!io_file_handle_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::handle'.");
        goto error;
    }

    /* Define ::hyve::io::file::handle */
    if (!db_checkState(io_file_handle_o, DB_DEFINED)) {
        io_file_handle_o->type = db_resolve_ext(io_file_handle_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::io::file::handle.type");
        io_file_handle_o->modifiers = 0x1;
        io_file_handle_o->state = 0x6;
        io_file_handle_o->weak = FALSE;
        io_file_handle_o->id = 3;
        if (db_define(io_file_handle_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::handle'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::mode */
    io_file_mode_o = db_declare(io_file_o, "mode", db_typedef(db_member_o));
    if (!io_file_mode_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::mode'.");
        goto error;
    }

    /* Declare ::hyve::io::file::name */
    io_file_name_o = db_declare(io_file_o, "name", db_typedef(db_member_o));
    if (!io_file_name_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::name'.");
        goto error;
    }

    /* Define ::hyve::io::file::name */
    if (!db_checkState(io_file_name_o, DB_DEFINED)) {
        io_file_name_o->type = db_resolve_ext(io_file_name_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::io::file::name.type");
        io_file_name_o->modifiers = 0x0;
        io_file_name_o->state = 0x6;
        io_file_name_o->weak = FALSE;
        io_file_name_o->id = 0;
        if (db_define(io_file_name_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::name'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::read(::hyve::lang::uint32 bytes) */
    io_file_read_o = db_declare(io_file_o, "read(::hyve::lang::uint32 bytes)", db_typedef(db_method_o));
    if (!io_file_read_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::read(::hyve::lang::uint32 bytes)'.");
        goto error;
    }

    /* Declare ::hyve::io::file::readAll() */
    io_file_readAll_o = db_declare(io_file_o, "readAll()", db_typedef(db_method_o));
    if (!io_file_readAll_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::readAll()'.");
        goto error;
    }

    /* Declare ::hyve::io::file::readLn() */
    io_file_readLn_o = db_declare(io_file_o, "readLn()", db_typedef(db_method_o));
    if (!io_file_readLn_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::readLn()'.");
        goto error;
    }

    /* Define ::hyve::io::file::readLn() */
    if (!db_checkState(io_file_readLn_o, DB_DEFINED)) {
        db_function(io_file_readLn_o)->returnType = db_resolve_ext(io_file_readLn_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::io::file::readLn().returnType");
        io_file_readLn_o->virtual = FALSE;
        
        /* Bind io_file_readLn_o with C-function */
        db_function(io_file_readLn_o)->kind = DB_PROCEDURE_CDECL;
        db_string io_file_readLn(io_file _this);
        db_function(io_file_readLn_o)->impl = (db_word)io_file_readLn;
        if (db_define(io_file_readLn_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::readLn()'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::readText() */
    io_file_readText_o = db_declare(io_file_o, "readText()", db_typedef(db_method_o));
    if (!io_file_readText_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::readText()'.");
        goto error;
    }

    /* Define ::hyve::io::file::readText() */
    if (!db_checkState(io_file_readText_o, DB_DEFINED)) {
        db_function(io_file_readText_o)->returnType = db_resolve_ext(io_file_readText_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::io::file::readText().returnType");
        io_file_readText_o->virtual = FALSE;
        
        /* Bind io_file_readText_o with C-function */
        db_function(io_file_readText_o)->kind = DB_PROCEDURE_CDECL;
        db_string io_file_readText(io_file _this);
        db_function(io_file_readText_o)->impl = (db_word)io_file_readText;
        if (db_define(io_file_readText_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::readText()'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::writeText(::hyve::lang::string txt) */
    io_file_writeText_o = db_declare(io_file_o, "writeText(::hyve::lang::string txt)", db_typedef(db_method_o));
    if (!io_file_writeText_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::writeText(::hyve::lang::string txt)'.");
        goto error;
    }

    /* Define ::hyve::io::file::writeText(::hyve::lang::string txt) */
    if (!db_checkState(io_file_writeText_o, DB_DEFINED)) {
        db_function(io_file_writeText_o)->returnType = db_resolve_ext(io_file_writeText_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::io::file::writeText(::hyve::lang::string txt).returnType");
        io_file_writeText_o->virtual = FALSE;
        
        /* Bind io_file_writeText_o with C-function */
        db_function(io_file_writeText_o)->kind = DB_PROCEDURE_CDECL;
        db_uint32 io_file_writeText(io_file _this, db_string txt);
        db_function(io_file_writeText_o)->impl = (db_word)io_file_writeText;
        if (db_define(io_file_writeText_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::writeText(::hyve::lang::string txt)'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::fileMode */
    io_fileMode_o = db_declare(io_o, "fileMode", db_typedef(db_enum_o));
    if (!io_fileMode_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode'.");
        goto error;
    }

    /* Declare ::hyve::io::fileMode::Append */
    io_fileMode_Append_o = db_declare(io_fileMode_o, "Append", db_typedef(db_constant_o));
    if (!io_fileMode_Append_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode::Append'.");
        goto error;
    }

    /* Define ::hyve::io::fileMode::Append */
    if (!db_checkState(io_fileMode_Append_o, DB_DEFINED)) {
        (*io_fileMode_Append_o) = 2;
        if (db_define(io_fileMode_Append_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode::Append'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::fileMode::Read */
    io_fileMode_Read_o = db_declare(io_fileMode_o, "Read", db_typedef(db_constant_o));
    if (!io_fileMode_Read_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode::Read'.");
        goto error;
    }

    /* Define ::hyve::io::fileMode::Read */
    if (!db_checkState(io_fileMode_Read_o, DB_DEFINED)) {
        (*io_fileMode_Read_o) = 0;
        if (db_define(io_fileMode_Read_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode::Read'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::fileMode::ReadAppend */
    io_fileMode_ReadAppend_o = db_declare(io_fileMode_o, "ReadAppend", db_typedef(db_constant_o));
    if (!io_fileMode_ReadAppend_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode::ReadAppend'.");
        goto error;
    }

    /* Define ::hyve::io::fileMode::ReadAppend */
    if (!db_checkState(io_fileMode_ReadAppend_o, DB_DEFINED)) {
        (*io_fileMode_ReadAppend_o) = 4;
        if (db_define(io_fileMode_ReadAppend_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode::ReadAppend'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::fileMode::ReadWrite */
    io_fileMode_ReadWrite_o = db_declare(io_fileMode_o, "ReadWrite", db_typedef(db_constant_o));
    if (!io_fileMode_ReadWrite_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode::ReadWrite'.");
        goto error;
    }

    /* Define ::hyve::io::fileMode::ReadWrite */
    if (!db_checkState(io_fileMode_ReadWrite_o, DB_DEFINED)) {
        (*io_fileMode_ReadWrite_o) = 3;
        if (db_define(io_fileMode_ReadWrite_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode::ReadWrite'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::fileMode::Write */
    io_fileMode_Write_o = db_declare(io_fileMode_o, "Write", db_typedef(db_constant_o));
    if (!io_fileMode_Write_o) {
        db_error("io_load: failed to declare object '::hyve::io::fileMode::Write'.");
        goto error;
    }

    /* Define ::hyve::io::fileMode::Write */
    if (!db_checkState(io_fileMode_Write_o, DB_DEFINED)) {
        (*io_fileMode_Write_o) = 1;
        if (db_define(io_fileMode_Write_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode::Write'.");
            goto error;
        }
    }
    /* Define ::hyve::io::fileMode */
    if (!db_checkState(io_fileMode_o, DB_DEFINED)) {
        if (db_define(io_fileMode_o)) {
            db_error("io_load: failed to define object '::hyve::io::fileMode'.");
            goto error;
        }
    }
    /* Define ::hyve::io::file::mode */
    if (!db_checkState(io_file_mode_o, DB_DEFINED)) {
        io_file_mode_o->type = db_resolve_ext(io_file_mode_o, NULL, "::hyve::io::fileMode", FALSE, "element ::hyve::io::file::mode.type");
        io_file_mode_o->modifiers = 0x0;
        io_file_mode_o->state = 0x6;
        io_file_mode_o->weak = FALSE;
        io_file_mode_o->id = 1;
        if (db_define(io_file_mode_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::mode'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::print(::hyve::lang::string str) */
    io_print_o = db_declare(io_o, "print(::hyve::lang::string str)", db_typedef(db_function_o));
    if (!io_print_o) {
        db_error("io_load: failed to declare object '::hyve::io::print(::hyve::lang::string str)'.");
        goto error;
    }

    /* Define ::hyve::io::print(::hyve::lang::string str) */
    if (!db_checkState(io_print_o, DB_DEFINED)) {
        io_print_o->returnType = db_resolve_ext(io_print_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::io::print(::hyve::lang::string str).returnType");
        
        /* Bind io_print_o with C-function */
        db_function(io_print_o)->kind = DB_PROCEDURE_CDECL;
        db_void io_print(db_string str);
        db_function(io_print_o)->impl = (db_word)io_print;
        if (db_define(io_print_o)) {
            db_error("io_load: failed to define object '::hyve::io::print(::hyve::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::println(::hyve::lang::string str) */
    io_println_o = db_declare(io_o, "println(::hyve::lang::string str)", db_typedef(db_function_o));
    if (!io_println_o) {
        db_error("io_load: failed to declare object '::hyve::io::println(::hyve::lang::string str)'.");
        goto error;
    }

    /* Define ::hyve::io::println(::hyve::lang::string str) */
    if (!db_checkState(io_println_o, DB_DEFINED)) {
        io_println_o->returnType = db_resolve_ext(io_println_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::io::println(::hyve::lang::string str).returnType");
        
        /* Bind io_println_o with C-function */
        db_function(io_println_o)->kind = DB_PROCEDURE_CDECL;
        db_void io_println(db_string str);
        db_function(io_println_o)->impl = (db_word)io_println;
        if (db_define(io_println_o)) {
            db_error("io_load: failed to define object '::hyve::io::println(::hyve::lang::string str)'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::readln() */
    io_readln_o = db_declare(io_o, "readln()", db_typedef(db_function_o));
    if (!io_readln_o) {
        db_error("io_load: failed to declare object '::hyve::io::readln()'.");
        goto error;
    }

    /* Define ::hyve::io::readln() */
    if (!db_checkState(io_readln_o, DB_DEFINED)) {
        io_readln_o->returnType = db_resolve_ext(io_readln_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::io::readln().returnType");
        
        /* Bind io_readln_o with C-function */
        db_function(io_readln_o)->kind = DB_PROCEDURE_CDECL;
        db_string io_readln(void);
        db_function(io_readln_o)->impl = (db_word)io_readln;
        if (db_define(io_readln_o)) {
            db_error("io_load: failed to define object '::hyve::io::readln()'.");
            goto error;
        }
    }
    /* Define ::hyve::io::file::read(::hyve::lang::uint32 bytes) */
    if (!db_checkState(io_file_read_o, DB_DEFINED)) {
        db_function(io_file_read_o)->returnType = db_resolve_ext(io_file_read_o, NULL, "::hyve::lang::sequence{::hyve::lang::octet,0}", FALSE, "element ::hyve::io::file::read(::hyve::lang::uint32 bytes).returnType");
        io_file_read_o->virtual = FALSE;
        
        /* Bind io_file_read_o with C-function */
        db_function(io_file_read_o)->kind = DB_PROCEDURE_CDECL;
        db_octet_seq io_file_read(io_file _this, db_uint32 bytes);
        db_function(io_file_read_o)->impl = (db_word)io_file_read;
        if (db_define(io_file_read_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::read(::hyve::lang::uint32 bytes)'.");
            goto error;
        }
    }
    /* Define ::hyve::io::file::readAll() */
    if (!db_checkState(io_file_readAll_o, DB_DEFINED)) {
        db_function(io_file_readAll_o)->returnType = db_resolve_ext(io_file_readAll_o, NULL, "::hyve::lang::sequence{::hyve::lang::octet,0}", FALSE, "element ::hyve::io::file::readAll().returnType");
        io_file_readAll_o->virtual = FALSE;
        
        /* Bind io_file_readAll_o with C-function */
        db_function(io_file_readAll_o)->kind = DB_PROCEDURE_CDECL;
        db_octet_seq io_file_readAll(io_file _this);
        db_function(io_file_readAll_o)->impl = (db_word)io_file_readAll;
        if (db_define(io_file_readAll_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::readAll()'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data) */
    io_file_write_o = db_declare(io_file_o, "write(::hyve::lang::sequence{::hyve::lang::octet,0} data)", db_typedef(db_method_o));
    if (!io_file_write_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data)'.");
        goto error;
    }

    /* Define ::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data) */
    if (!db_checkState(io_file_write_o, DB_DEFINED)) {
        db_function(io_file_write_o)->returnType = db_resolve_ext(io_file_write_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data).returnType");
        io_file_write_o->virtual = FALSE;
        
        /* Bind io_file_write_o with C-function */
        db_function(io_file_write_o)->kind = DB_PROCEDURE_CDECL;
        db_uint32 io_file_write(io_file _this, db_octet_seq data);
        db_function(io_file_write_o)->impl = (db_word)io_file_write;
        if (db_define(io_file_write_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::write(::hyve::lang::sequence{::hyve::lang::octet,0} data)'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::construct(::hyve::io::file object) */
    io_file_construct_o = db_declare(io_file_o, "construct(::hyve::io::file object)", db_typedef(db_callback_o));
    if (!io_file_construct_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::construct(::hyve::io::file object)'.");
        goto error;
    }

    /* Define ::hyve::io::file::construct(::hyve::io::file object) */
    if (!db_checkState(io_file_construct_o, DB_DEFINED)) {
        db_function(io_file_construct_o)->returnType = db_resolve_ext(io_file_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::io::file::construct(::hyve::io::file object).returnType");
        io_file_construct_o->delegate = db_resolve_ext(io_file_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::io::file::construct(::hyve::io::file object).delegate");
        
        /* Bind io_file_construct_o with C-function */
        db_function(io_file_construct_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 io_file_construct(io_file object);
        db_function(io_file_construct_o)->impl = (db_word)io_file_construct;
        if (db_define(io_file_construct_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::construct(::hyve::io::file object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::file::destruct(::hyve::io::file object) */
    io_file_destruct_o = db_declare(io_file_o, "destruct(::hyve::io::file object)", db_typedef(db_callback_o));
    if (!io_file_destruct_o) {
        db_error("io_load: failed to declare object '::hyve::io::file::destruct(::hyve::io::file object)'.");
        goto error;
    }

    /* Define ::hyve::io::file::destruct(::hyve::io::file object) */
    if (!db_checkState(io_file_destruct_o, DB_DEFINED)) {
        db_function(io_file_destruct_o)->returnType = db_resolve_ext(io_file_destruct_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::io::file::destruct(::hyve::io::file object).returnType");
        io_file_destruct_o->delegate = db_resolve_ext(io_file_destruct_o, NULL, "::hyve::lang::class::destruct(lang::object object)", FALSE, "element ::hyve::io::file::destruct(::hyve::io::file object).delegate");
        
        /* Bind io_file_destruct_o with C-function */
        db_function(io_file_destruct_o)->kind = DB_PROCEDURE_CDECL;
        db_void io_file_destruct(io_file object);
        db_function(io_file_destruct_o)->impl = (db_word)io_file_destruct;
        if (db_define(io_file_destruct_o)) {
            db_error("io_load: failed to define object '::hyve::io::file::destruct(::hyve::io::file object)'.");
            goto error;
        }
    }
    /* Define ::hyve::io::file */
    if (!db_checkState(io_file_o, DB_DEFINED)) {
        db_type(io_file_o)->defaultType = db_resolve_ext(io_file_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::io::file.defaultType");
        db_type(io_file_o)->parentType = NULL;
        db_type(io_file_o)->parentState = 0x0;
        db_interface(io_file_o)->base = NULL;
        db_struct(io_file_o)->baseAccess = 0x0;
        io_file_o->implements.length = 0;
        io_file_o->implements.buffer = NULL;
        if (db_define(io_file_o)) {
            db_error("io_load: failed to define object '::hyve::io::file'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::err */
    io_err_o = db_declare(io_o, "err", db_typedef(io_file_o));
    if (!io_err_o) {
        db_error("io_load: failed to declare object '::hyve::io::err'.");
        goto error;
    }

    /* Define ::hyve::io::err */
    if (!db_checkState(io_err_o, DB_DEFINED)) {
        io_err_o->name = db_strdup("#err");
        io_err_o->mode = IO_Write;
        io_err_o->binary = FALSE;
        if (db_define(io_err_o)) {
            db_error("io_load: failed to define object '::hyve::io::err'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::in */
    io_in_o = db_declare(io_o, "in", db_typedef(io_file_o));
    if (!io_in_o) {
        db_error("io_load: failed to declare object '::hyve::io::in'.");
        goto error;
    }

    /* Define ::hyve::io::in */
    if (!db_checkState(io_in_o, DB_DEFINED)) {
        io_in_o->name = db_strdup("#in");
        io_in_o->mode = IO_Read;
        io_in_o->binary = FALSE;
        if (db_define(io_in_o)) {
            db_error("io_load: failed to define object '::hyve::io::in'.");
            goto error;
        }
    }
    /* Declare ::hyve::io::out */
    io_out_o = db_declare(io_o, "out", db_typedef(io_file_o));
    if (!io_out_o) {
        db_error("io_load: failed to declare object '::hyve::io::out'.");
        goto error;
    }

    /* Define ::hyve::io::out */
    if (!db_checkState(io_out_o, DB_DEFINED)) {
        io_out_o->name = db_strdup("#out");
        io_out_o->mode = IO_Write;
        io_out_o->binary = FALSE;
        if (db_define(io_out_o)) {
            db_error("io_load: failed to define object '::hyve::io::out'.");
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
