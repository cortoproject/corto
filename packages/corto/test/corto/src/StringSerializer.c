/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_StringSerializer_tc_serAnonymous(
    test_StringSerializer this)
{
    corto_object anonymous = corto_int32Create(10);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>int32{10}}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serAnonymousComplex(
    test_StringSerializer this)
{
    test_Point *anonymous = corto_create(test_Point_o);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    anonymous->x = 10;
    anonymous->y = 20;

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>/test/Point{10,20}}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serAnonymousComplexString(
    test_StringSerializer this)
{
    test_CompositeWithString *anonymous = corto_create(test_CompositeWithString_o);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    anonymous->a = 10;
    anonymous->b = "Hello";
    anonymous->c = "World";
    anonymous->d = 20;

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>/test/CompositeWithString{10,\"Hello\",\"World\",20}}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serAnonymousComplexStringEsc(
    test_StringSerializer this)
{
    test_CompositeWithString *anonymous = corto_create(test_CompositeWithString_o);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    anonymous->a = 10;
    anonymous->b = "\"Hello\"";
    anonymous->c = "\"World\"";
    anonymous->d = 20;

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>/test/CompositeWithString{10,\"\\\"Hello\\\"\",\"\\\"World\\\"\",20}}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serArray(
    test_StringSerializer this)
{
    corto_array t = corto_arrayCreate(corto_int32_o, 3);
    test_assert(t != NULL);
    corto_string result;

    corto_int32 v[] = {10, 20, 30};

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_delete(t);

}

void test_StringSerializer_tc_serArrayComplex(
    test_StringSerializer this)
{
    corto_array t = corto_arrayCreate(test_Point_o, 3);
    test_assert(t != NULL);
    corto_string result;

    test_Point v[] = {{10, 20}, {30, 40}, {50, 60}};

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_delete(t);

}

void test_StringSerializer_tc_serBoolFalse(
    test_StringSerializer this)
{
    corto_bool v = FALSE;
    corto_string result = NULL;

    result = corto_ptr_str(&v, corto_bool_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "false"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serBoolTrue(
    test_StringSerializer this)
{
    corto_bool v = TRUE;
    corto_string result = NULL;

    result = corto_ptr_str(&v, corto_bool_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "true"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serChar(
    test_StringSerializer this)
{
    corto_char v = 'a';
    corto_string result = NULL;

    result = corto_ptr_str(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "'a'"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serCharEscape(
    test_StringSerializer this)
{
    corto_char v = '\n';
    corto_string result = NULL;

    result = corto_ptr_str(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "'\n'"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serCharNull(
    test_StringSerializer this)
{
    corto_char v = '\0';
    corto_string result = NULL;

    result = corto_ptr_str(&v, corto_char_o, 0);

    test_assert(result != NULL);
    test_assert(!strcmp(result, "''"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serComposite(
    test_StringSerializer this)
{
    test_Point v = {10, 20};
    corto_string result;

    result = corto_ptr_str(&v, test_Point_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20}"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serCompositeNested(
    test_StringSerializer this)
{
    test_Line v = {{10, 20}, {30, 40}};
    corto_string result;

    result = corto_ptr_str(&v, test_Line_o, 0);
    test_assert(result != NULL);
    test_assertstr(result, "{{10,20},{30,40}}");

    corto_dealloc(result);

}

void test_StringSerializer_tc_serCycle(
    test_StringSerializer this)
{
    corto_string result;
    test_ReferenceMember *o = corto_create(test_ReferenceMember_o);
    test_assert(o != NULL);

    corto_ptr_setref(&o->m, o);
    result = corto_str(o, 0);
    test_assertstr(result, "{<0>,0}");

}

void test_StringSerializer_tc_serInheritance(
    test_StringSerializer this)
{
    test_Point3D v = {{10, 20}, 30};
    corto_string result;

    result = corto_ptr_str(&v, test_Point3D_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt16(
    test_StringSerializer this)
{
    corto_int16 v = 32767;
    corto_string result;

    result = corto_ptr_str(&v, corto_int16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "32767"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt16Minus(
    test_StringSerializer this)
{
    corto_int16 v = -32768;
    corto_string result;

    result = corto_ptr_str(&v, corto_int16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-32768"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt32(
    test_StringSerializer this)
{
    corto_int32 v = 2147483647;
    corto_string result;

    result = corto_ptr_str(&v, corto_int32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "2147483647"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt32Minus(
    test_StringSerializer this)
{
    corto_int32 v = -2147483648;
    corto_string result;

    result = corto_ptr_str(&v, corto_int32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-2147483648"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt64(
    test_StringSerializer this)
{
    corto_int64 v = 9223372036854775807;
    corto_string result;

    result = corto_ptr_str(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "9223372036854775807"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt64Minus(
    test_StringSerializer this)
{
    corto_int64 v = -9223372036854775807 - 1;
    corto_string result;

    result = corto_ptr_str(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-9223372036854775808"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt8(
    test_StringSerializer this)
{
    corto_int64 v = 127;
    corto_string result;

    result = corto_ptr_str(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "127"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serInt8Minus(
    test_StringSerializer this)
{
    corto_int64 v = -128;
    corto_string result;

    result = corto_ptr_str(&v, corto_int64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "-128"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serList(
    test_StringSerializer this)
{
    corto_list t = corto_listCreate(corto_int32_o, 0);
    corto_ll v = corto_ll_new();
    corto_string result;

    corto_ll_append(v, (void*)10);
    corto_ll_append(v, (void*)20);
    corto_ll_append(v, (void*)30);

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_ll_free(v);
    corto_release(t);

}

void test_StringSerializer_tc_serListComplex(
    test_StringSerializer this)
{
    corto_list t = corto_listCreate(test_Point_o, 0);
    corto_ll v = corto_ll_new();
    test_Point e1 = {10, 20}, e2 = {30, 40}, e3 = {50, 60};
    corto_string result;

    corto_ll_append(v, &e1);
    corto_ll_append(v, &e2);
    corto_ll_append(v, &e3);

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_ll_free(v);
    corto_release(t);

}

void test_StringSerializer_tc_serLongAnonymous(
    test_StringSerializer this)
{
    corto_object anonymous = corto_int32Create(10);
    corto_objectList objList = corto_ll_new();
    corto_uint32 i;
    for (i = 0; i < 300; i++) {
        corto_ll_append(objList, anonymous);
    }
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>int32{10},<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>,<1>}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);
}

void test_StringSerializer_tc_serSameAnonymous(
    test_StringSerializer this)
{
    corto_object anonymous = corto_int32Create(10);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous);
    corto_ll_append(objList, anonymous);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>int32{10},<1>}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serSequence(
    test_StringSerializer this)
{
    corto_sequence t = corto_sequenceCreate(corto_int32_o, 0);
    CORTO_SEQUENCE(seqType, corto_int32,);
    corto_int32 elements[] = {10, 20, 30};
    seqType v = {3, elements};
    corto_string result;

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{10,20,30}"));

    corto_dealloc(result);
    corto_release(t);

}

void test_StringSerializer_tc_serSequenceComplex(
    test_StringSerializer this)
{
    corto_sequence t = corto_sequenceCreate(test_Point_o, 0);
    CORTO_SEQUENCE(seqType, test_Point,);
    test_Point elements[] = {{10, 20}, {30, 40}, {50, 60}};
    seqType v = {3, elements};
    corto_string result;

    result = corto_ptr_str(&v, t, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "{{10,20},{30,40},{50,60}}"));

    corto_dealloc(result);
    corto_release(t);

}

void test_StringSerializer_tc_serString(
    test_StringSerializer this)
{
    corto_string v = "Hello World";
    corto_string result;

    result = corto_ptr_str(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "\"Hello World\""));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serStringEscape(
    test_StringSerializer this)
{
    corto_string v = "Hello World\n";
    corto_string result;

    result = corto_ptr_str(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assertstr(result, "\"Hello World\\n\"");

    corto_dealloc(result);

}

void test_StringSerializer_tc_serStringNull(
    test_StringSerializer this)
{
    corto_string v = NULL;
    corto_string result;

    result = corto_ptr_str(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "null"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serStringWhitespace(
    test_StringSerializer this)
{
    corto_string v = "  Hello World   ";
    corto_string result;

    result = corto_ptr_str(&v, corto_string_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "\"  Hello World   \""));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serStructArrayInt(
    test_StringSerializer this)
{
    test_struct_arrayInt v = {{10, 20, 30}};

    char *str = corto_ptr_str(&v, test_struct_arrayInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

}

void test_StringSerializer_tc_serStructArrayReference(
    test_StringSerializer this)
{
    test_struct_arrayReference v = {{corto_o, corto_lang_o, corto_class_o}};

    char *str = corto_ptr_str(&v, test_struct_arrayReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{/corto,/corto/lang,class}}");
    corto_dealloc(str);

}

void test_StringSerializer_tc_serStructArrayString(
    test_StringSerializer this)
{
    test_struct_arrayString v = {{"Hello", "World", "Foo"}};

    char *str = corto_ptr_str(&v, test_struct_arrayString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{\"Hello\",\"World\",\"Foo\"}}");
    corto_dealloc(str);

}

void test_StringSerializer_tc_serStructArrayStruct(
    test_StringSerializer this)
{
    test_struct_arrayStruct v = {{{10, 20}, {30, 40}, {50, 60}}};

    char *str = corto_ptr_str(&v, test_struct_arrayStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20},{30,40},{50,60}}}");
    corto_dealloc(str);
    
}

void test_StringSerializer_tc_serStructInherit(
    test_StringSerializer this)
{
    test_struct_inherit v = {{10, 20}, 30, 40};

    char *str = corto_ptr_str(&v, test_struct_inherit_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{10,20,30,40}");
    corto_dealloc(str);

}

void test_StringSerializer_tc_serStructListInt(
    test_StringSerializer this)
{
    test_struct_listInt v;

    corto_ptr_init(&v, test_struct_listInt_o);
    test_IntListAppend(v.m, 10);
    test_IntListAppend(v.m, 20);
    test_IntListAppend(v.m, 30);

    char *str = corto_ptr_str(&v, test_struct_listInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_listInt_o);

}

void test_StringSerializer_tc_serStructListReference(
    test_StringSerializer this)
{
    test_struct_listInt v;

    corto_ptr_init(&v, test_struct_listReference_o);
    test_ReferenceListAppend(v.m, corto_o);
    test_ReferenceListAppend(v.m, corto_lang_o);
    test_ReferenceListAppend(v.m, corto_class_o);

    char *str = corto_ptr_str(&v, test_struct_listReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{/corto,/corto/lang,class}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_listReference_o);

}

void test_StringSerializer_tc_serStructListString(
    test_StringSerializer this)
{
    test_struct_listInt v;

    corto_ptr_init(&v, test_struct_listInt_o);
    test_StringListAppend(v.m, "Hello");
    test_StringListAppend(v.m, "World");
    test_StringListAppend(v.m, "Foo");

    char *str = corto_ptr_str(&v, test_struct_listString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{\"Hello\",\"World\",\"Foo\"}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_listString_o);

}

void test_StringSerializer_tc_serStructListStruct(
    test_StringSerializer this)
{
    test_struct_listInt v;
    test_Point 
        p = {10, 20},
        q = {30, 40},
        r = {50, 60};

    corto_ptr_init(&v, test_struct_listStruct_o);
    test_PointListAppend(v.m, &p);
    test_PointListAppend(v.m, &q);
    test_PointListAppend(v.m, &r);

    char *str = corto_ptr_str(&v, test_struct_listStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20},{30,40},{50,60}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_listStruct_o);

}

void test_StringSerializer_tc_serStructObservableArray(
    test_StringSerializer this)
{
    test_struct_observableArray v;

    corto_ptr_init(&v, test_struct_observableArray_o);
    (*v.m)[0] = 10;
    (*v.m)[1] = 20;
    (*v.m)[2] = 30;
    (*v.m)[3] = 40;

    char *str = corto_ptr_str(&v, test_struct_observableArray_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30,40}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableArray_o);

}

void test_StringSerializer_tc_serStructObservableInt(
    test_StringSerializer this)
{
    test_struct_observableInt v;

    corto_ptr_init(&v, test_struct_observableInt_o);
    *v.m = 10;

    char *str = corto_ptr_str(&v, test_struct_observableInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{10}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableInt_o);
}

void test_StringSerializer_tc_serStructObservableList(
    test_StringSerializer this)
{
    test_struct_observableList v;

    corto_ptr_init(&v, test_struct_observableList_o);
    test_IntListAppend(*v.m, 10);
    test_IntListAppend(*v.m, 20);
    test_IntListAppend(*v.m, 30);

    char *str = corto_ptr_str(&v, test_struct_observableList_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableList_o);

}

void test_StringSerializer_tc_serStructObservableReference(
    test_StringSerializer this)
{
    test_struct_observableReference v;

    corto_ptr_init(&v, test_struct_observableReference_o);
    corto_ptr_setref(v.m, corto_class_o);

    char *str = corto_ptr_str(&v, test_struct_observableReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{class}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableReference_o);

}

void test_StringSerializer_tc_serStructObservableSequence(
    test_StringSerializer this)
{
    test_struct_observableSequence v;

    corto_ptr_init(&v, test_struct_observableSequence_o);
    test_IntSequenceSize(v.m, 3);
    v.m->buffer[0] = 10;
    v.m->buffer[1] = 20;
    v.m->buffer[2] = 30;

    char *str = corto_ptr_str(&v, test_struct_observableSequence_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableSequence_o);

}

void test_StringSerializer_tc_serStructObservableString(
    test_StringSerializer this)
{
    test_struct_observableString v;

    corto_ptr_init(&v, test_struct_observableString_o);
    corto_ptr_setstr(v.m, "Hello World");

    char *str = corto_ptr_str(&v, test_struct_observableString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{\"Hello World\"}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableString_o);

}

void test_StringSerializer_tc_serStructObservableStruct(
    test_StringSerializer this)
{
    test_struct_observableStruct v;

    corto_ptr_init(&v, test_struct_observableStruct_o);
    v.m->x = 10;
    v.m->y = 20;

    char *str = corto_ptr_str(&v, test_struct_observableStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_observableStruct_o);

}

void test_StringSerializer_tc_serStructOptionalArray(
    test_StringSerializer this)
{
    test_struct_optionalArray v;

    corto_ptr_init(&v, test_struct_optionalArray_o);

    int32_t array[] = {10, 20, 30, 40};
    test_IntArraySet(v.m, 4, array);

    char *str = corto_ptr_str(&v, test_struct_optionalArray_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30,40}}");
    corto_dealloc(str);

    test_IntArrayUnset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalArray_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalArray_o);

}

void test_StringSerializer_tc_serStructOptionalInt(
    test_StringSerializer this)
{
    test_struct_optionalInt v;

    corto_ptr_init(&v, test_struct_optionalInt_o);

    corto_int32Set(v.m, 10);

    char *str = corto_ptr_str(&v, test_struct_optionalInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{10}");
    corto_dealloc(str);

    corto_int32Unset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalInt_o);

}

void test_StringSerializer_tc_serStructOptionalList(
    test_StringSerializer this)
{
    test_struct_optionalList v;

    corto_ptr_init(&v, test_struct_optionalList_o);

    int32_t array[] = {10, 20, 30, 40};
    test_IntListSet(v.m, 4, array);

    char *str = corto_ptr_str(&v, test_struct_optionalList_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30,40}}");
    corto_dealloc(str);

    test_IntArrayUnset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalList_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalList_o);

}

void test_StringSerializer_tc_serStructOptionalReference(
    test_StringSerializer this)
{
    test_struct_optionalReference v;

    corto_ptr_init(&v, test_struct_optionalReference_o);

    v.m = corto_ptr_new(corto_object_o);
    corto_ptr_setref(v.m, corto_class_o);

    char *str = corto_ptr_str(&v, test_struct_optionalReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{class}");
    corto_dealloc(str);

    corto_ptr_free(v.m, corto_object_o);
    v.m = NULL;

    str = corto_ptr_str(&v, test_struct_optionalReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalReference_o);

}

void test_StringSerializer_tc_serStructOptionalSequence(
    test_StringSerializer this)
{
    test_struct_optionalSequence v;

    corto_ptr_init(&v, test_struct_optionalSequence_o);

    int32_t array[] = {10, 20, 30, 40};
    test_IntSequenceSet(v.m, 4, array);

    char *str = corto_ptr_str(&v, test_struct_optionalSequence_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30,40}}");
    corto_dealloc(str);

    test_IntArrayUnset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalSequence_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalSequence_o);

}

void test_StringSerializer_tc_serStructOptionalString(
    test_StringSerializer this)
{
    test_struct_optionalString v;

    corto_ptr_init(&v, test_struct_optionalString_o);

    corto_stringSet(v.m, "Hello World");

    char *str = corto_ptr_str(&v, test_struct_optionalString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{\"Hello World\"}");
    corto_dealloc(str);

    corto_stringUnset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalString_o);

}

void test_StringSerializer_tc_serStructOptionalStruct(
    test_StringSerializer this)
{
    test_struct_optionalStruct v;

    corto_ptr_init(&v, test_struct_optionalStruct_o);

    test_PointSet(v.m, 10, 20);

    char *str = corto_ptr_str(&v, test_struct_optionalStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20}}");
    corto_dealloc(str);

    test_PointUnset(v.m);

    str = corto_ptr_str(&v, test_struct_optionalStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_optionalStruct_o);

}

void test_StringSerializer_tc_serStructPrimitive(
    test_StringSerializer this)
{
    test_struct_base v;

    corto_ptr_init(&v, test_struct_base_o);

    v.x = 10;
    v.y = 20;

    char *str = corto_ptr_str(&v, test_struct_base_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{10,20}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_base_o);

}

void test_StringSerializer_tc_serStructSequenceInt(
    test_StringSerializer this)
{
    test_struct_sequenceInt v;

    corto_ptr_init(&v, test_struct_sequenceInt_o);

    corto_ptr_size(&v.m, test_IntSequence_o, 3);
    v.m.buffer[0] = 10;
    v.m.buffer[1] = 20;
    v.m.buffer[2] = 30;

    char *str = corto_ptr_str(&v, test_struct_sequenceInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_sequenceInt_o);

}

void test_StringSerializer_tc_serStructSequenceReference(
    test_StringSerializer this)
{
    test_struct_sequenceReference v;

    corto_ptr_init(&v, test_struct_sequenceReference_o);

    corto_ptr_size(&v.m, test_ReferenceSequence_o, 3);
    corto_ptr_setref(&v.m.buffer[0], corto_o);
    corto_ptr_setref(&v.m.buffer[1], corto_lang_o);
    corto_ptr_setref(&v.m.buffer[2], corto_class_o);

    char *str = corto_ptr_str(&v, test_struct_sequenceReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{/corto,/corto/lang,class}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_sequenceReference_o);

}

void test_StringSerializer_tc_serStructSequenceString(
    test_StringSerializer this)
{
    test_struct_sequenceString v;

    corto_ptr_init(&v, test_struct_sequenceString_o);

    corto_ptr_size(&v.m, test_StringSequence_o, 3);
    corto_ptr_setstr(&v.m.buffer[0], "Hello");
    corto_ptr_setstr(&v.m.buffer[1], "World");
    corto_ptr_setstr(&v.m.buffer[2], "Foo");

    char *str = corto_ptr_str(&v, test_struct_sequenceString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{\"Hello\",\"World\",\"Foo\"}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_sequenceString_o);

}

void test_StringSerializer_tc_serStructSequenceStruct(
    test_StringSerializer this)
{
    test_struct_sequenceStruct v;

    corto_ptr_init(&v, test_struct_sequenceStruct_o);

    corto_ptr_size(&v.m, test_CompositeSequence_o, 3);
    v.m.buffer[0] = (test_Point){10, 20};
    v.m.buffer[1] = (test_Point){30, 40};
    v.m.buffer[2] = (test_Point){50, 60};

    char *str = corto_ptr_str(&v, test_struct_sequenceStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20},{30,40},{50,60}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_sequenceStruct_o);

}

void test_StringSerializer_tc_serStructString(
    test_StringSerializer this)
{
    test_struct_string v;

    corto_ptr_init(&v, test_struct_string_o);

    corto_ptr_setstr(&v.m, "Hello World");

    char *str = corto_ptr_str(&v, test_struct_string_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{\"Hello World\"}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_string_o);

}

void test_StringSerializer_tc_serStructTargetArray(
    test_StringSerializer this)
{
    test_struct_targetArray v;

    corto_ptr_init(&v, test_struct_targetArray_o);

    v.m->actual[0] = 10;
    v.m->actual[1] = 20;
    v.m->actual[2] = 30;
    v.m->actual[3] = 40;
    v.m->target[0] = 50;
    v.m->target[1] = 60;
    v.m->target[2] = 70;
    v.m->target[3] = 80;
    v.m->objective[0] = 90;
    v.m->objective[1] = 100;
    v.m->objective[2] = 110;
    v.m->objective[3] = 120;

    char *str = corto_ptr_str(&v, test_struct_targetArray_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20,30,40},{50,60,70,80},{90,100,110,120}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetArray_o);

}

void test_StringSerializer_tc_serStructTargetInt(
    test_StringSerializer this)
{
    test_struct_targetInt v;

    corto_ptr_init(&v, test_struct_targetInt_o);

    v.m->actual = 10;
    v.m->target = 20;
    v.m->objective = 30;

    char *str = corto_ptr_str(&v, test_struct_targetInt_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{10,20,30}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetInt_o);

}

void test_StringSerializer_tc_serStructTargetList(
    test_StringSerializer this)
{
    test_struct_targetList v;

    corto_ptr_init(&v, test_struct_targetList_o);

    test_IntListAppend(v.m->actual, 10);
    test_IntListAppend(v.m->actual, 20);
    test_IntListAppend(v.m->actual, 30);
    test_IntListAppend(v.m->actual, 40);
    test_IntListAppend(v.m->target, 50);
    test_IntListAppend(v.m->target, 60);
    test_IntListAppend(v.m->target, 70);
    test_IntListAppend(v.m->target, 80);
    test_IntListAppend(v.m->objective, 90);
    test_IntListAppend(v.m->objective, 100);
    test_IntListAppend(v.m->objective, 110);
    test_IntListAppend(v.m->objective, 120);

    char *str = corto_ptr_str(&v, test_struct_targetList_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20,30,40},{50,60,70,80},{90,100,110,120}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetList_o);

}

void test_StringSerializer_tc_serStructTargetReference(
    test_StringSerializer this)
{
    test_struct_targetReference v;

    corto_ptr_init(&v, test_struct_targetReference_o);

    corto_ptr_setref(&v.m->actual, corto_o);
    corto_ptr_setref(&v.m->target, corto_lang_o);
    corto_ptr_setref(&v.m->objective, corto_class_o);

    char *str = corto_ptr_str(&v, test_struct_targetReference_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{/corto,/corto/lang,class}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetReference_o);

}

void test_StringSerializer_tc_serStructTargetSequence(
    test_StringSerializer this)
{
    test_struct_targetSequence v;

    corto_ptr_init(&v, test_struct_targetSequence_o);

    corto_ptr_size(&v.m->actual, test_IntSequence_o, 4);
    v.m->actual.buffer[0] = 10;
    v.m->actual.buffer[1] = 20;
    v.m->actual.buffer[2] = 30;
    v.m->actual.buffer[3] = 40;

    corto_ptr_size(&v.m->target, test_IntSequence_o, 4);
    v.m->target.buffer[0] = 50;
    v.m->target.buffer[1] = 60;
    v.m->target.buffer[2] = 70;
    v.m->target.buffer[3] = 80;

    corto_ptr_size(&v.m->objective, test_IntSequence_o, 4);
    v.m->objective.buffer[0] = 90;
    v.m->objective.buffer[1] = 100;
    v.m->objective.buffer[2] = 110;
    v.m->objective.buffer[3] = 120;

    char *str = corto_ptr_str(&v, test_struct_targetSequence_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20,30,40},{50,60,70,80},{90,100,110,120}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetSequence_o);

}

void test_StringSerializer_tc_serStructTargetString(
    test_StringSerializer this)
{
    test_struct_targetString v;

    corto_ptr_init(&v, test_struct_targetString_o);

    corto_ptr_setstr(&v.m->actual, "Hello");
    corto_ptr_setstr(&v.m->target, "World");
    corto_ptr_setstr(&v.m->objective, "Foo");

    char *str = corto_ptr_str(&v, test_struct_targetString_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{\"Hello\",\"World\",\"Foo\"}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetString_o);

}

void test_StringSerializer_tc_serStructTargetStruct(
    test_StringSerializer this)
{
    test_struct_targetStruct v;

    corto_ptr_init(&v, test_struct_targetStruct_o);

    v.m->actual = (test_Point){10, 20};
    v.m->target = (test_Point){30, 40};
    v.m->objective = (test_Point){50, 60};

    char *str = corto_ptr_str(&v, test_struct_targetStruct_o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{{10,20},{30,40},{50,60}}}");
    corto_dealloc(str);

    corto_ptr_deinit(&v, test_struct_targetStruct_o);

}

void test_StringSerializer_tc_serTwoAnonymous(
    test_StringSerializer this)
{
    corto_object anonymous1 = corto_int32Create(10);
    corto_object anonymous2 = corto_int32Create(20);
    corto_objectList objList = corto_ll_new();
    corto_ll_append(objList, anonymous1);
    corto_ll_append(objList, anonymous2);
    test_AnonymousTest o = test_AnonymousTestCreate(objList);
    test_assert(o != NULL);

    corto_string str = corto_str(o, 0);
    test_assert(str != NULL);
    test_assertstr(str, "{{<1>int32{10},<2>int32{20}}}");

    corto_delete(o);
    corto_dealloc(str);
    corto_ll_free(objList);

}

void test_StringSerializer_tc_serUint16(
    test_StringSerializer this)
{
    corto_uint16 v = 65535;
    corto_string result;

    result = corto_ptr_str(&v, corto_uint16_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "65535"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serUint32(
    test_StringSerializer this)
{
    corto_uint32 v = 4294967295;
    corto_string result;

    result = corto_ptr_str(&v, corto_uint32_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "4294967295"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serUint64(
    test_StringSerializer this)
{
    corto_uint64 v = 18446744073709551615u;
    corto_string result;

    result = corto_ptr_str(&v, corto_uint64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "18446744073709551615"));

    corto_dealloc(result);

}

void test_StringSerializer_tc_serUint8(
    test_StringSerializer this)
{
    corto_uint64 v = 255;
    corto_string result;

    result = corto_ptr_str(&v, corto_uint64_o, 0);
    test_assert(result != NULL);
    test_assert(!strcmp(result, "255"));

    corto_dealloc(result);

}

