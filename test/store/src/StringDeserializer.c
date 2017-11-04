/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_StringDeserializer_setup(
    test_StringDeserializer this)
{

    corto_setAttr(CORTO_ATTR_PERSISTENT);

    corto_enableload(FALSE);

}

void test_StringDeserializer_tc_deserAnonymousComplex(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/ReferenceMember{m="
            "<0>"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_ReferenceMember_o, o));
    test_ReferenceMember *t = test_ReferenceMember(o);
    test_assert(t != NULL);
    test_assert(t->m != NULL);
    test_assert(t->m == t);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousComplexString(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/CompositeWithString{"
            "a=10,"
            "b=\"Hello\","
            "c=\"World\","
            "d=20"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_CompositeWithString_o, o));
    test_CompositeWithString *t = test_CompositeWithString(o);
    test_assert(t != NULL);
    test_assertint(t->a, 10);
    test_assertstr(t->b, "Hello");
    test_assertstr(t->c, "World");
    test_assertint(t->d, 20);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousComplexStringEsc(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/CompositeWithString{"
            "a=10,"
            "b=\"\\\"Hello\\\"\","
            "c=\"\\\"World\\\"\","
            "d=20"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_CompositeWithString_o, o));
    test_CompositeWithString *t = test_CompositeWithString(o);
    test_assert(t != NULL);
    test_assertint(t->a, 10);
    test_assertstr(t->b, "\"Hello\"");
    test_assertstr(t->c, "\"World\"");
    test_assertint(t->d, 20);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousCycle(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/ReferenceMember{m="
            "<0>"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_ReferenceMember_o, o));
    test_ReferenceMember *t = test_ReferenceMember(o);
    test_assert(t != NULL);
    test_assert(t->m != NULL);
    test_assert(t->m == t);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousMultiple(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/AnonymousTest{{"
            "<1>int32{10},"
            "<2>int32{20},"
            "<3>int32{30}"
        "}}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_AnonymousTest_o, o));
    test_AnonymousTest t = test_AnonymousTest(o);
    test_assert(t != NULL);
    test_assert(t->objects != NULL);
    test_assert(corto_ll_size(t->objects) == 3);
    corto_object e1 = corto_ll_get(t->objects, 0);
    corto_object e2 = corto_ll_get(t->objects, 1);
    corto_object e3 = corto_ll_get(t->objects, 2);
    test_assert(corto_instanceof(corto_int32_o, e1));
    test_assert(corto_instanceof(corto_int32_o, e2));
    test_assert(corto_instanceof(corto_int32_o, e3));
    test_assert(e1 != e2);
    test_assert(e1 != e3);
    test_assert(e2 != e3);
    test_assert(*(corto_int32*)e1 == 10);
    test_assert(*(corto_int32*)e2 == 20);
    test_assert(*(corto_int32*)e3 == 30);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousNested(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/AnonymousTest{{"
            "<1>int32{10},"
            "<2>test/AnonymousTest{{"
                "<3>int32{20},"
                "<4>test/Point{10, 20},"
                "<5>test/AnonymousTest{{"
                    "<6>test/Point{30, 40},"
                    "<7>int32{30}"
                "}}"
            "}}"
        "}}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_AnonymousTest_o, o));
    test_AnonymousTest top = test_AnonymousTest(o);
    test_assert(top != NULL);
    test_assert(top->objects != NULL);
    test_assert(corto_ll_size(top->objects) == 2);

    corto_object e1 = corto_ll_get(top->objects, 0);
    corto_object e2 = corto_ll_get(top->objects, 1);
    test_assert(corto_instanceof(corto_int32_o, e1));
    test_assert(corto_instanceof(test_AnonymousTest_o, e2));
    test_assert(*(corto_int32*)e1 == 10);
    test_AnonymousTest t2 = test_AnonymousTest(e2);
    test_assert(t2 != NULL);
    test_assert(corto_ll_size(t2->objects) == 3);

    corto_object e3 = corto_ll_get(t2->objects, 0);
    corto_object e4 = corto_ll_get(t2->objects, 1);
    corto_object e5 = corto_ll_get(t2->objects, 2);
    test_assert(corto_instanceof(corto_int32_o, e3));
    test_assert(corto_instanceof(test_Point_o, e4));
    test_assert(corto_instanceof(test_AnonymousTest_o, e5));
    test_assert(*(corto_int32*)e3 == 20);
    test_Point *t4 = test_Point(e4);
    test_assert(t4 != NULL);
    test_assert(t4->x == 10);
    test_assert(t4->y == 20);
    test_AnonymousTest t5 = test_AnonymousTest(e5);
    test_assert(t5 != NULL);
    test_assert(corto_ll_size(t5->objects) == 2);

    corto_object e6 = corto_ll_get(t5->objects, 0);
    corto_object e7 = corto_ll_get(t5->objects, 1);
    test_assert(corto_instanceof(test_Point_o, e6));
    test_assert(corto_instanceof(corto_int32_o, e7));
    test_Point *t6 = test_Point(e6);
    test_assert(t6 != NULL);
    test_assert(t6->x == 30);
    test_assert(t6->y == 40);
    test_assert(*(corto_int32*)e7 == 30);

}

void test_StringDeserializer_tc_deserAnonymousReuse(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/AnonymousTest{{"
            "/corto/lang/type,"
            "<1>int32{10},"
            "<2>int32{20},"
            "<3>int32{30},"
            "<1>,"
            "<2>,"
            "<3>"
        "}}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_AnonymousTest_o, o));
    test_AnonymousTest t = test_AnonymousTest(o);
    test_assert(t != NULL);
    test_assert(t->objects != NULL);
    test_assert(corto_ll_size(t->objects) == 7);
    corto_object e1 = corto_ll_get(t->objects, 0);
    corto_object e2 = corto_ll_get(t->objects, 1);
    corto_object e3 = corto_ll_get(t->objects, 2);
    corto_object e4 = corto_ll_get(t->objects, 3);
    corto_object e5 = corto_ll_get(t->objects, 4);
    corto_object e6 = corto_ll_get(t->objects, 5);
    corto_object e7 = corto_ll_get(t->objects, 6);
    test_assert(corto_instanceof(corto_class_o, e1));
    test_assert(corto_instanceof(corto_int32_o, e2));
    test_assert(corto_instanceof(corto_int32_o, e3));
    test_assert(corto_instanceof(corto_int32_o, e4));
    test_assert(e2 != e3);
    test_assert(e2 != e4);
    test_assert(e3 != e4);
    test_assert(e2 == e5);
    test_assert(e3 == e6);
    test_assert(e4 == e7);
    test_assert(e1 == corto_type_o);
    test_assert(*(corto_int32*)e2 == 10);
    test_assert(*(corto_int32*)e3 == 20);
    test_assert(*(corto_int32*)e4 == 30);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousReuseNested(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/AnonymousTest{{"
            "<1>int32{10},"
            "<2>test/AnonymousTest{{"
                "<3>int32{20},"
                "<4>test/Point{10, 20},"
                "<5>test/AnonymousTest{{"
                    "<6>test/Point{30, 40},"
                    "<7>int32{30}"
                "}}"
            "}},"
            "<1>,<2>,<3>,<4>,<5>,<6>,<7>"
        "}}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_AnonymousTest_o, o));
    test_AnonymousTest top = test_AnonymousTest(o);
    test_assert(top != NULL);
    test_assert(top->objects != NULL);
    test_assert(corto_ll_size(top->objects) == 9);

    corto_object e1 = corto_ll_get(top->objects, 0);
    corto_object e2 = corto_ll_get(top->objects, 1);
    test_assert(corto_instanceof(corto_int32_o, e1));
    test_assert(corto_instanceof(test_AnonymousTest_o, e2));
    test_assert(*(corto_int32*)e1 == 10);
    test_AnonymousTest t2 = test_AnonymousTest(e2);
    test_assert(t2 != NULL);
    test_assert(corto_ll_size(t2->objects) == 3);

    corto_object e3 = corto_ll_get(t2->objects, 0);
    corto_object e4 = corto_ll_get(t2->objects, 1);
    corto_object e5 = corto_ll_get(t2->objects, 2);
    test_assert(corto_instanceof(corto_int32_o, e3));
    test_assert(corto_instanceof(test_Point_o, e4));
    test_assert(corto_instanceof(test_AnonymousTest_o, e5));
    test_assert(*(corto_int32*)e3 == 20);
    test_Point *t4 = test_Point(e4);
    test_assert(t4 != NULL);
    test_assert(t4->x == 10);
    test_assert(t4->y == 20);
    test_AnonymousTest t5 = test_AnonymousTest(e5);
    test_assert(t5 != NULL);
    test_assert(corto_ll_size(t5->objects) == 2);

    corto_object e6 = corto_ll_get(t5->objects, 0);
    corto_object e7 = corto_ll_get(t5->objects, 1);
    test_assert(corto_instanceof(test_Point_o, e6));
    test_assert(corto_instanceof(corto_int32_o, e7));
    test_Point *t6 = test_Point(e6);
    test_assert(t6 != NULL);
    test_assert(t6->x == 30);
    test_assert(t6->y == 40);
    test_assert(*(corto_int32*)e7 == 30);

}

void test_StringDeserializer_tc_deserAnonymousSimple(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/AnonymousTest{{"
            "<1>int32{10}"
        "}}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_AnonymousTest_o, o));
    test_AnonymousTest t = test_AnonymousTest(o);
    test_assert(t != NULL);
    test_assert(t->objects != NULL);
    test_assert(corto_ll_size(t->objects) == 1);
    corto_object e1 = corto_ll_get(t->objects, 0);
    test_assert(corto_instanceof(corto_int32_o, e1));
    test_assertint(*(corto_int32*)e1, 10);
    corto_release(o);

}

void test_StringDeserializer_tc_deserAnonymousTwice(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
        "test/ReferenceMember{m="
            "int32{10}"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_instanceof(test_ReferenceMember_o, o));
    test_ReferenceMember *t = test_ReferenceMember(o);
    test_assert(t != NULL);
    test_assert(t->m != NULL);
    test_assert(corto_typeof(t->m) == corto_type(corto_int32_o));
    test_assertint(*(corto_int32*)t->m, 10);

    /* Temporarily store anonymous object, check if object is still the same
     * when deserialized a second time */
    corto_object tmp_o = o;
    corto_object tmp_m = t->m;

    corto_fromStr(&o,
        "test/ReferenceMember{m="
            "int32{20}"
        "}");

    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(o == tmp_o);
    t = test_ReferenceMember(o);
    test_assert(t != NULL);
    test_assert(t->m != NULL);
    test_assert(t->m == tmp_m);
    test_assertint(*(corto_int32*)t->m, 20);

    corto_release(o);

}

void test_StringDeserializer_tc_deserArray(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/IntArray{0, 1, 2, 3}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_IntArray_o);

    corto_int32 *c = test_IntArray(o);
    test_assert(c != NULL);

    test_assert(c[0] == 0);
    test_assert(c[1] == 1);
    test_assert(c[2] == 2);
    test_assert(c[3] == 3);

    corto_delete(o);
}

void test_StringDeserializer_tc_deserArrayComplex(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
      "test/CompositeArray{{10, 20}, {30, 40}, {50, 60}, {70, 80}}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeArray_o);

    test_Point *c = test_CompositeArray(o);
    test_assert(c != NULL);

    test_assert(c[0].x == 10);
    test_assert(c[0].y == 20);
    test_assert(c[1].x == 30);
    test_assert(c[1].y == 40);
    test_assert(c[2].x == 50);
    test_assert(c[2].y == 60);
    test_assert(c[3].x == 70);
    test_assert(c[3].y == 80);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserArrayReference(
    test_StringDeserializer this)
{
    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/ObjectArray{lang, corto, bool, any}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ObjectArray_o);

    corto_object *c = test_ObjectArray(o);
    test_assert(c != NULL);

    test_assert(c[0] == corto_lang_o);
    test_assert(c[1] == corto_o);
    test_assert(c[2] == corto_bool_o);
    test_assert(c[3] == corto_any_o);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserBoolFalse(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "bool{false}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*(corto_bool*)o == FALSE);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserBoolInvalid(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = corto_boolCreate(TRUE);
    corto_int16 ret = corto_fromStr(&o, "bool{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "failed to deserialize 'bool{bar}': 'bar' is not a valid boolean value"));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserBoolTrue(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*(corto_bool*)o == TRUE);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserChar(
    test_StringDeserializer this)
{

    corto_object p = NULL;
    corto_int16 ret = corto_fromStr(&p, "char{a}");
    test_assert(p != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(p) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)p == 'a');
    corto_delete(p);

}

void test_StringDeserializer_tc_deserCharEscape(
    test_StringDeserializer this)
{

    corto_object p = NULL;
    corto_int16 ret = corto_fromStr(&p, "char{\\}");
    test_assert(p != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(p) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)p == '\\');
    corto_delete(p);

}

void test_StringDeserializer_tc_deserCharEscapeQuoted(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "char{'\\\\'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assertint(*(corto_char*)o, '\\');
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCharNull(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "char{\0}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == '\0');
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCharNullQuoted(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "char{'\\0'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assertint(*(corto_char*)o, '\0');
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCharQuoted(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "char{'a'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == 'a');
    corto_delete(o);

}

void test_StringDeserializer_tc_deserComposite(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point{10,20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeMembers(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point{ y=20, x = 10 }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeMixed(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point{ x=10, 20 }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeNested(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Line{{10, 20}, {30, 40}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 10);
    test_assert(l->start.y == 20);
    test_assert(l->stop.x == 30);
    test_assert(l->stop.y == 40);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeNestedMembers(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Line{stop={y=40, x=30}, start={x=10, y=20}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 10);
    test_assert(l->start.y == 20);
    test_assert(l->stop.x == 30);
    test_assert(l->stop.y == 40);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeNestedMixed(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Line{start={x=40, 30}, {x=10, 20}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 40);
    test_assert(l->start.y == 30);
    test_assert(l->stop.x == 10);
    test_assert(l->stop.y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeNoType(
    test_StringDeserializer this)
{

    test_Point *o = test_PointCreate(0, 0);
    test_assert(o != NULL);
    test_assert(o->x == 0);
    test_assert(o->y == 0);
    corto_int16 ret = corto_fromStr(&o, "{10,20}");
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_assert(o->x == 10);
    test_assert(o->y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserCompositeWhitespace(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point  {   10 ,   20\n}  ");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserExisting(
    test_StringDeserializer this)
{

    corto_bool *o = corto_boolCreate(FALSE);
    test_assert(o != NULL);
    test_assert(*o == FALSE);
    corto_int16 ret = corto_fromStr(&o, "true");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*o == TRUE);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserExisting_w_scopedType(
    test_StringDeserializer this)
{

    corto_int32 *o = corto_int32Create(0);
    corto_int32 *p = o;
    test_assert(o != NULL);
    test_assert(*o == 0);
    corto_int16 ret = corto_fromStr(&o, "corto/lang/int32{10}");
    test_assert(o != NULL);
    test_assert(o == p);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*o == 10);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserExisting_w_type(
    test_StringDeserializer this)
{

    corto_bool *o = corto_boolCreate(FALSE);
    corto_bool *p = o;
    test_assert(o != NULL);
    test_assert(*o == FALSE);
    corto_int16 ret = corto_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(o == p);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*o == TRUE);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInheritance(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point3D{10,20,30}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInheritanceMembers(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point3D{z=30,x=10,y=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInheritanceMixed(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point3D{z=30,x=10,20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt16(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int16{32767}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == 32767);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt16Minus(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int16{-32768}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == -32768);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt16Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int16{32768}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == -32768);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt32(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int32{2147483647}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == 2147483647);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt32Minus(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int32{-2147483648}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == -2147483648);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt32Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int32{2147483648}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == -2147483648);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt64(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int64{9223372036854775807}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int64_o);
    test_assert(*(corto_int64*)o == 9223372036854775807);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt64Minus(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int64{-9223372036854775808");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int64_o);
    test_assert(*(corto_int64*)o == (-9223372036854775807 - 1)); /* C doesn't allow -9223372036854775808 */
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt8(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int8{127}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == 127);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt8Minus(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int8{-128}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == -128);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserInt8Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "int8{128}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == -128);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserList(
    test_StringDeserializer this)
{
    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/IntList{0, 1, 2, 3}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_IntList_o);

    test_IntList *c = test_IntList(o);
    test_assert(c != NULL);
    test_assert(corto_ll_size(*c) == 4);

    test_assert((corto_uint32)(corto_word)corto_ll_get(*c, 0) == 0);
    test_assert((corto_uint32)(corto_word)corto_ll_get(*c, 1) == 1);
    test_assert((corto_uint32)(corto_word)corto_ll_get(*c, 2) == 2);
    test_assert((corto_uint32)(corto_word)corto_ll_get(*c, 3) == 3);

    corto_delete(o);
}

void test_StringDeserializer_tc_deserListComplex(
    test_StringDeserializer this)
{
    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/CompositeList{{0, 1}, {2, 3}, {4, 5}}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeList_o);

    test_CompositeList *c = test_CompositeList(o);
    test_assert(c != NULL);
    test_assert(corto_ll_size(*c) == 3);

    test_Point *p = corto_ll_get(*c, 0);
    test_assert(p != NULL);
    test_assert(p->x == 0);
    test_assert(p->y == 1);

    p = corto_ll_get(*c, 1);
    test_assert(p != NULL);
    test_assert(p->x == 2);
    test_assert(p->y == 3);

    p = corto_ll_get(*c, 2);
    test_assert(p != NULL);
    test_assert(p->x == 4);
    test_assert(p->y == 5);

    corto_delete(o);
}

void test_StringDeserializer_tc_deserListReference(
    test_StringDeserializer this)
{
    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/ObjectList{lang, corto, bool, any}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ObjectList_o);

    test_IntList *c = test_ObjectList(o);
    test_assert(c != NULL);
    test_assert(corto_ll_size(*c) == 4);

    test_assert(corto_ll_get(*c, 0) == corto_lang_o);
    test_assert(corto_ll_get(*c, 1) == corto_o);
    test_assert(corto_ll_get(*c, 2) == corto_bool_o);
    test_assert(corto_ll_get(*c, 3) == corto_any_o);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserSequence(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/IntSequence{0, 1, 2, 3}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_IntSequence_o);

    test_IntSequence *c = test_IntSequence(o);
    test_assert(c != NULL);
    test_assert(c->length == 4);
    test_assert(c->buffer != NULL);

    test_assert(c->buffer[0] == 0);
    test_assert(c->buffer[1] == 1);
    test_assert(c->buffer[2] == 2);
    test_assert(c->buffer[3] == 3);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserSequenceComplex(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o,
      "test/CompositeSequence{{10, 20}, {30, 40}, {50, 60}, {70, 80}}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeSequence_o);

    test_CompositeSequence *c = test_CompositeSequence(o);
    test_assert(c != NULL);
    test_assert(c->buffer != NULL);
    test_assert(c->length == 4);

    test_assert(c->buffer[0].x == 10);
    test_assert(c->buffer[0].y == 20);
    test_assert(c->buffer[1].x == 30);
    test_assert(c->buffer[1].y == 40);
    test_assert(c->buffer[2].x == 50);
    test_assert(c->buffer[2].y == 60);
    test_assert(c->buffer[3].x == 70);
    test_assert(c->buffer[3].y == 80);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserSequenceReference(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/ObjectSequence{lang, corto, bool, any}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ObjectSequence_o);

    test_ObjectSequence *c = test_ObjectSequence(o);
    test_assert(c != NULL);
    test_assert(c->buffer != NULL);
    test_assert(c->length == 4);

    test_assert(c->buffer[0] == corto_lang_o);
    test_assert(c->buffer[1] == corto_o);
    test_assert(c->buffer[2] == corto_bool_o);
    test_assert(c->buffer[3] == corto_any_o);

    corto_delete(o);

}

void test_StringDeserializer_tc_deserString(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{Hello World}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringEscape(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{\\}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assertstr(*(corto_string*)o, "\\");
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringEscapeQuotes(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{\"\\\\\"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assertstr(*(corto_string*)o, "\\");
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringMember(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/CompositeWithString{10, \"Hello World\", \"Foo Bar\", 20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeWithString_o);
    test_assertint(test_CompositeWithString(o)->a, 10);
    test_assertstr(test_CompositeWithString(o)->b, "Hello World");
    test_assertstr(test_CompositeWithString(o)->c, "Foo Bar");
    test_assertint(test_CompositeWithString(o)->d, 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringMemberEscape(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/CompositeWithString{10, \"Hello World\\n\", \"Foo Bar\\n\", 20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeWithString_o);
    test_assertint(test_CompositeWithString(o)->a, 10);
    test_assertstr(test_CompositeWithString(o)->b, "Hello World\n");
    test_assertstr(test_CompositeWithString(o)->c, "Foo Bar\n");
    test_assertint(test_CompositeWithString(o)->d, 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringMemberEscapeNoQuotes(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/CompositeWithString{10, Hello\nWorld, Foo\nBar, 20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeWithString_o);
    test_assertint(test_CompositeWithString(o)->a, 10);
    test_assertstr(test_CompositeWithString(o)->b, "Hello\nWorld");
    test_assertstr(test_CompositeWithString(o)->c, "Foo\nBar");
    test_assertint(test_CompositeWithString(o)->d, 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringMemberNoQuotes(
    test_StringDeserializer this)
{
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/CompositeWithString{10, Hello World, Foo Bar, 20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeWithString_o);
    test_assertint(test_CompositeWithString(o)->a, 10);
    test_assertstr(test_CompositeWithString(o)->b, "Hello World");
    test_assertstr(test_CompositeWithString(o)->c, "Foo Bar");
    test_assertint(test_CompositeWithString(o)->d, 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringQuotes(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{\"Hello World\"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringQuotesWhitespaces(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{\"  Hello World   \"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "  Hello World   "));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringWhitespace(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{\"   \n\n\n  \t\t \"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "   \n\n\n  \t\t "));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringWhitespaceTrailing(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "string{  Hello World   }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType(
    test_StringDeserializer this)
{

    corto_string *o = corto_stringCreate(NULL);
    test_assert(o != NULL);
    test_assert(*o == NULL);
    corto_int16 ret = corto_fromStr(&o, "  Hello World   ");
    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

}

void test_StringDeserializer_tc_deserTargetAnonymousNotOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_setOwner(owner);
    test_ReferenceMember *o = corto_createChild(NULL, "o", test_ReferenceMember_o);
    test_assert(o != NULL);

    /* Deserializer can't assign anonymous object because member 'm' won't be
     * owned by thread */
    o->m = corto_create(test_TargetActual_o);

    corto_setOwner(NULL);
    corto_int16 ret = corto_fromStr(&o, "{m=<1>/test/TargetActual{target=10, actual=20},n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 0);
    test_assert(o->m != NULL);
    test_assert(corto_typeof(o->m) == (corto_type)test_TargetActual_o);
    test_TargetActual m = o->m;

    /* Deserializer should not touch anonymous object because member 'm' is not
     * owned by the thread */
    test_assertint(m->target, 0);
    test_assertint(m->actual, 0);


    corto_setOwner(owner);
    corto_delete(o);
    corto_setOwner(NULL);

    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetAnonymousOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_setOwner(owner);
    test_ReferenceMember *o = corto_createChild(NULL, "o", test_ReferenceMember_o);
    test_assert(o != NULL);

    corto_int16 ret = corto_fromStr(&o, "{m=<1>/test/TargetActual{target=10, actual=20}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 10);
    test_assert(corto_typeof(o->m) == (corto_type)test_TargetActual_o);
    test_TargetActual m = o->m;
    test_assertint(m->target, 0);
    test_assertint(m->actual, 20);

    corto_delete(o);
    corto_setOwner(NULL);

    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetMemberNotOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_setOwner(owner);
    test_TargetActualMember *o = corto_createChild(NULL, "o", test_TargetActualMember_o);

    corto_setOwner(NULL);
    corto_int16 ret = corto_fromStr(&o, "{m={target=10, actual=20}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActualMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 0);
    test_assertint(o->m->actual, 0);
    test_assertint(o->m->target, 10);

    corto_setOwner(owner);
    corto_delete(o);
    corto_setOwner(NULL);

    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetMemberOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_setOwner(owner);
    test_TargetActualMember *o = corto_createChild(NULL, "o", test_TargetActualMember_o);

    corto_int16 ret = corto_fromStr(&o, "{m={target=10, actual=20}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActualMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 10);
    test_assert(o->m->target == 0);
    test_assert(o->m->actual == 20);

    corto_setOwner(owner);
    corto_delete(o);
    corto_setOwner(NULL);

    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetNotOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_setOwner(owner);
    test_TargetActual o = corto_createChild(NULL, "o", test_TargetActual_o);

    corto_setOwner(NULL);
    corto_int16 ret = corto_fromStr(&o, "{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(corto_ownerof(o) == owner);
    test_assert(o->target == 10);
    test_assert(o->actual == 0);

    corto_setOwner(owner);
    corto_delete(o);
    corto_setOwner(NULL);

    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetNotOwnedMount(
    test_StringDeserializer this)
{
    test_TargetActual o = corto_create(test_TargetActual_o);
    corto_object owner = corto_create(corto_mount_o);

    corto_setOwner(owner);
    corto_int16 ret = corto_fromStr(&o, "{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(corto_ownerof(o) == NULL);
    test_assert(o->target == 10);
    test_assert(o->actual == 0);
    corto_setOwner(NULL);

    corto_delete(o);
    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetNotOwnedObj(
    test_StringDeserializer this)
{
    test_TargetActual o = corto_create(test_TargetActual_o);
    corto_object owner = corto_create(corto_void_o);

    corto_setOwner(owner);
    corto_int16 ret = corto_fromStr(&o, "{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(corto_ownerof(o) == NULL);
    test_assert(o->target == 0);
    test_assert(o->actual == 20);
    corto_setOwner(NULL);

    corto_delete(o);
    corto_delete(owner);

}

void test_StringDeserializer_tc_deserTargetOwned(
    test_StringDeserializer this)
{
    test_TargetActual o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/TargetActual{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(o->target == 0);
    test_assert(o->actual == 20);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserTargetOwnedMount(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);

    corto_setOwner(owner);
    test_TargetActual o = corto_createChild(NULL, "o", test_TargetActual_o);

    corto_int16 ret = corto_fromStr(&o, "{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(corto_ownerof(o) == owner);
    test_assert(o->target == 0);
    test_assert(o->actual == 20);

    ret = corto_delete(o);
    test_assert(ret == 0);

    corto_setOwner(NULL);
    ret = corto_delete(owner);
    test_assert(ret == 0);

}

void test_StringDeserializer_tc_deserTargetOwnedObj(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_void_o);

    corto_setOwner(owner);
    test_TargetActual o = corto_createChild(NULL, "o", test_TargetActual_o);
    corto_int16 ret = corto_fromStr(&o, "test/TargetActual{target=10, actual=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_TargetActual_o);
    test_assert(corto_ownerof(o) == owner);
    test_assert(o->target == 0);
    test_assert(o->actual == 20);
    test_assert(corto_delete(o) == 0);

    corto_setOwner(NULL);
    test_assert(corto_delete(owner) == 0);

}

void test_StringDeserializer_tc_deserTargetRefAnonymousMemberNotOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);

    corto_setOwner(owner);
    test_ReferenceTargetMember *o = corto_createChild(NULL, "o", test_ReferenceTargetMember_o);

    corto_setOwner(NULL);
    corto_int16 ret = corto_fromStr(&o, "{m={target=int32{10}, actual=int32{20}}, 10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceTargetMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 0);
    test_assert(o->m->target != NULL);
    test_assert(corto_typeof(o->m->target) == corto_type(corto_int32_o));
    test_assertint(*(corto_int32*)o->m->target, 10);
    test_assert(o->m->actual == NULL);

    corto_setOwner(owner);
    test_assert(corto_delete(o) == 0);

    corto_setOwner(NULL);
    test_assert(corto_delete(owner) == 0);

}

void test_StringDeserializer_tc_deserTargetRefAnonymousMemberOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);

    corto_setOwner(owner);
    test_ReferenceTargetMember *o = corto_createChild(NULL, "o", test_ReferenceTargetMember_o);

    corto_int16 ret = corto_fromStr(&o, "{m={target=int32{10}, actual=int32{20}}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceTargetMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 10);
    test_assert(o->m->actual != NULL);
    test_assert(corto_typeof(o->m->actual) == corto_type(corto_int32_o));
    test_assertint(*(corto_int32*)o->m->actual, 20);
    test_assert(o->m->target == NULL);

    test_assert(corto_delete(o) == 0);

    corto_setOwner(NULL);
    test_assert(corto_delete(owner) == 0);

}

void test_StringDeserializer_tc_deserTargetRefMemberNotOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_object a = corto_createChild(NULL, "a", corto_int32_o);
    corto_object b = corto_createChild(NULL, "b", corto_int32_o);

    corto_setOwner(owner);
    test_ReferenceTargetMember *o = corto_createChild(NULL, "o", test_ReferenceTargetMember_o);

    corto_setOwner(NULL);
    corto_int16 ret = corto_fromStr(&o, "{m={target=/a, actual=/b}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceTargetMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 0);
    test_assert(o->m->target == a);
    test_assert(o->m->actual == NULL);

    corto_setOwner(owner);
    test_assert(corto_delete(o) == 0);

    corto_setOwner(NULL);
    test_assert(corto_delete(owner) == 0);
    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(b) == 0);

}

void test_StringDeserializer_tc_deserTargetRefMemberOwned(
    test_StringDeserializer this)
{
    corto_object owner = corto_create(corto_mount_o);
    corto_object a = corto_createChild(NULL, "a", corto_int32_o);
    corto_object b = corto_createChild(NULL, "b", corto_int32_o);

    corto_setOwner(owner);
    test_ReferenceTargetMember *o = corto_createChild(NULL, "o", test_ReferenceTargetMember_o);

    corto_int16 ret = corto_fromStr(&o, "{m={target=/a, actual=/b}, n=10}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_ReferenceTargetMember_o);
    test_assert(corto_ownerof(o) == owner);
    test_assertint(o->n, 10);
    test_assert(o->m->target == NULL);
    test_assert(o->m->actual == b);
    test_assert(corto_delete(o) == 0);

    corto_setOwner(NULL);
    test_assert(corto_delete(owner) == 0);
    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(b) == 0);

}

void test_StringDeserializer_tc_deserUint16(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint16{65535}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint16_o);
    test_assert(*(corto_uint16*)o == 65535);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint16Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint16{65536}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint16_o);
    test_assert(*(corto_uint16*)o == 0);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint32(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint32{4294967295}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint32_o);
    test_assert(*(corto_uint32*)o == 4294967295);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint32Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint32{4294967296}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint32_o);
    test_assert(*(corto_uint32*)o == 0);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint64(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint64{18446744073709551615}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint64_o);
    test_assert(*(corto_uint64*)o == 18446744073709551615u);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint8(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint8{255}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint8_o);
    test_assert(*(corto_uint8*)o == 255);
    corto_delete(o);

}

void test_StringDeserializer_tc_deserUint8Overflow(
    test_StringDeserializer this)
{

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "uint8{256}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint8_o);
    test_assert(*(corto_uint8*)o == 0);
    corto_delete(o);

}

void test_StringDeserializer_tc_errExcessElements(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point{10, 20, 30}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "failed to deserialize 'test/Point{10, 20, 30}': excess elements in string"));

}

void test_StringDeserializer_tc_errMissingType(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "{foo}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "no type provided for '{foo}'"));

}

void test_StringDeserializer_tc_errNotAType(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "lang{foo}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "'lang' is not a type"));

}

void test_StringDeserializer_tc_errTypeMismatch(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = corto_boolCreate(TRUE);
    corto_int16 ret = corto_fromStr(&o, "string{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "type of object ('bool') does not match string ('string')"));
    corto_delete(o);

}

void test_StringDeserializer_tc_errUnresolvedMember(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test/Point{a = 10}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "failed to deserialize 'test/Point{a = 10}': member 'a' not found in type '/test/Point'"));

}

void test_StringDeserializer_tc_errUnresolvedType(
    test_StringDeserializer this)
{

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "foo{bar}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "unknown type 'foo'"));

}

void test_StringDeserializer_teardown(
    test_StringDeserializer this)
{

    /* << Insert implementation >> */

}

