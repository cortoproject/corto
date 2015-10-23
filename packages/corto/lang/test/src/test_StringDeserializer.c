/* test_StringDeserializer.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::StringDeserializer::setup() */
corto_void _test_StringDeserializer_setup(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::setup) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolFalse() */
corto_void _test_StringDeserializer_tc_deserBoolFalse(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolFalse) */

    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "bool{false}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*(corto_bool*)o == FALSE);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolInvalid() */
corto_void _test_StringDeserializer_tc_deserBoolInvalid(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolInvalid) */

    corto_string err;
    corto_object o = corto_boolCreate(TRUE); 
    corto_int16 ret = corto_fromStr(&o, "bool{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "'bar' is not a valid boolean value"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserBoolTrue() */
corto_void _test_StringDeserializer_tc_deserBoolTrue(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserBoolTrue) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*(corto_bool*)o == TRUE);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserChar() */
corto_void _test_StringDeserializer_tc_deserChar(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserChar) */

    corto_object p = NULL; 
    corto_int16 ret = corto_fromStr(&p, "char{a}");
    test_assert(p != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(p) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)p == 'a');
    corto_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharEscape() */
corto_void _test_StringDeserializer_tc_deserCharEscape(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharEscape) */

    corto_object p = NULL; 
    corto_int16 ret = corto_fromStr(&p, "char{\\}");
    test_assert(p != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(p) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)p == '\\');
    corto_delete(p);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharEscapeQuoted() */
corto_void _test_StringDeserializer_tc_deserCharEscapeQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharEscapeQuoted) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "char{'\\'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == '\\');
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharNull() */
corto_void _test_StringDeserializer_tc_deserCharNull(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharNull) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "char{\0}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == '\0');
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharNullQuoted() */
corto_void _test_StringDeserializer_tc_deserCharNullQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharNullQuoted) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "char{'\0'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == '\0');
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCharQuoted() */
corto_void _test_StringDeserializer_tc_deserCharQuoted(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCharQuoted) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "char{'a'}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_char_o);
    test_assert(*(corto_char*)o == 'a');
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCollection() */
corto_void _test_StringDeserializer_tc_deserCollection(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCollection) */

    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test::PrimitiveCollection{{0, 1, 2, 3}}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_PrimitiveCollection_o);
    
    test_PrimitiveCollection *c = test_PrimitiveCollection(o);
    test_assert(c != NULL);
    test_assert(c->ints != NULL);
    test_assert(corto_llSize(c->ints) == 4);

    test_assert((corto_uint32)(corto_word)corto_llGet(c->ints, 0) == 0);
    test_assert((corto_uint32)(corto_word)corto_llGet(c->ints, 1) == 1);
    test_assert((corto_uint32)(corto_word)corto_llGet(c->ints, 2) == 2);
    test_assert((corto_uint32)(corto_word)corto_llGet(c->ints, 3) == 3);

    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCollectionComplex() */
corto_void _test_StringDeserializer_tc_deserCollectionComplex(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCollectionComplex) */

    corto_object *o = NULL;
    corto_int16 ret = corto_fromStr(&o, "test::CompositeCollection{{{0, 1}, {2, 3}, {4, 5}}}");

    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_CompositeCollection_o);
    
    test_CompositeCollection *c = test_CompositeCollection(o);
    test_assert(c != NULL);
    test_assert(c->points != NULL);
    test_assert(corto_llSize(c->points) == 3);

    test_Point *p = corto_llGet(c->points, 0);
    test_assert(p != NULL);
    test_assert(p->x == 0);
    test_assert(p->y == 1);

    p = corto_llGet(c->points, 1);
    test_assert(p != NULL);
    test_assert(p->x == 2);
    test_assert(p->y == 3);

    p = corto_llGet(c->points, 2);
    test_assert(p != NULL);
    test_assert(p->x == 4);
    test_assert(p->y == 5);

    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserComposite() */
corto_void _test_StringDeserializer_tc_deserComposite(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserComposite) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point{10,20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeMembers() */
corto_void _test_StringDeserializer_tc_deserCompositeMembers(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeMembers) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point{ y=20, x = 10 }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeMixed() */
corto_void _test_StringDeserializer_tc_deserCompositeMixed(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeMixed) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point{ x=10, 20 }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);
    
/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeNested() */
corto_void _test_StringDeserializer_tc_deserCompositeNested(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeNested) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Line{{10, 20}, {30, 40}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 10);
    test_assert(l->start.y == 20);
    test_assert(l->stop.x == 30);
    test_assert(l->stop.y == 40);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeNestedMembers() */
corto_void _test_StringDeserializer_tc_deserCompositeNestedMembers(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeNestedMembers) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Line{stop={y=40, x=30}, start={x=10, y=20}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 10);
    test_assert(l->start.y == 20);
    test_assert(l->stop.x == 30);
    test_assert(l->stop.y == 40);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeNestedMixed() */
corto_void _test_StringDeserializer_tc_deserCompositeNestedMixed(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeNestedMixed) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Line{start={x=40, 30}, {x=10, 20}}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Line_o);
    test_Line *l = o;
    test_assert(l->start.x == 40);
    test_assert(l->start.y == 30);
    test_assert(l->stop.x == 10);
    test_assert(l->stop.y == 20);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeNoType() */
corto_void _test_StringDeserializer_tc_deserCompositeNoType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeNoType) */

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

/* $end */
}

/* ::test::StringDeserializer::tc_deserCompositeWhitespace() */
corto_void _test_StringDeserializer_tc_deserCompositeWhitespace(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserCompositeWhitespace) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point  {   10 ,   20\n}  ");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);
    test_Point *p = o;
    test_assert(p->x == 10);
    test_assert(p->y == 20);
    corto_delete(o);
    
/* $end */
}

/* ::test::StringDeserializer::tc_deserExisting() */
corto_void _test_StringDeserializer_tc_deserExisting(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserExisting) */

    corto_bool *o = corto_boolCreate(FALSE);
    test_assert(o != NULL);
    test_assert(*o == FALSE);
    corto_int16 ret = corto_fromStr(&o, "true");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*o == TRUE);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserExisting_w_type() */
corto_void _test_StringDeserializer_tc_deserExisting_w_type(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserExisting_w_type) */

    corto_bool *o = corto_boolCreate(FALSE);
    test_assert(o != NULL);
    test_assert(*o == FALSE); 
    corto_int16 ret = corto_fromStr(&o, "bool{true}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_bool_o);
    test_assert(*o == TRUE);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInheritance() */
corto_void _test_StringDeserializer_tc_deserInheritance(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInheritance) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point3D{10,20,30}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInheritanceMembers() */
corto_void _test_StringDeserializer_tc_deserInheritanceMembers(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInheritanceMembers) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point3D{z=30,x=10,y=20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInheritanceMixed() */
corto_void _test_StringDeserializer_tc_deserInheritanceMixed(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInheritanceMixed) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point3D{z=30,x=10,20}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)test_Point3D_o);
    test_Point3D *p = o;
    test_assert(test_Point(p)->x == 10);
    test_assert(test_Point(p)->y == 20);
    test_assert(p->z == 30);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16() */
corto_void _test_StringDeserializer_tc_deserInt16(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int16{32767}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == 32767);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16Minus() */
corto_void _test_StringDeserializer_tc_deserInt16Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16Minus) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int16{-32768}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == -32768);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt16Overflow() */
corto_void _test_StringDeserializer_tc_deserInt16Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt16Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int16{32768}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int16_o);
    test_assert(*(corto_int16*)o == -32768);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32() */
corto_void _test_StringDeserializer_tc_deserInt32(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int32{2147483647}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == 2147483647);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32Minus() */
corto_void _test_StringDeserializer_tc_deserInt32Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32Minus) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int32{-2147483648}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == -2147483648);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt32Overflow() */
corto_void _test_StringDeserializer_tc_deserInt32Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt32Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int32{2147483648}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(*(corto_int32*)o == -2147483648);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt64() */
corto_void _test_StringDeserializer_tc_deserInt64(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt64) */
    
    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int64{9223372036854775807}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int64_o);
    test_assert(*(corto_int64*)o == 9223372036854775807);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt64Minus() */
corto_void _test_StringDeserializer_tc_deserInt64Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt64Minus) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int64{-9223372036854775808");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int64_o);
    test_assert(*(corto_int64*)o == (-9223372036854775807 - 1)); /* C doesn't allow -9223372036854775808 */
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8() */
corto_void _test_StringDeserializer_tc_deserInt8(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int8{127}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == 127);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Minus() */
corto_void _test_StringDeserializer_tc_deserInt8Minus(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Minus) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int8{-128}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == -128);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserInt8Overflow() */
corto_void _test_StringDeserializer_tc_deserInt8Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserInt8Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "int8{128}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_int8_o);
    test_assert(*(corto_int8*)o == -128);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserString() */
corto_void _test_StringDeserializer_tc_deserString(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserString) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{Hello World}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringEscape() */
corto_void _test_StringDeserializer_tc_deserStringEscape(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringEscape) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{\"\\\"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "\\"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringQuotes() */
corto_void _test_StringDeserializer_tc_deserStringQuotes(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringQuotes) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{\"Hello World\"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringQuotesWhitespaces() */
corto_void _test_StringDeserializer_tc_deserStringQuotesWhitespaces(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringQuotesWhitespaces) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{\"  Hello World   \"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "  Hello World   "));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringWhitespace() */
corto_void _test_StringDeserializer_tc_deserStringWhitespace(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringWhitespace) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{\"   \n\n\n  \t\t \"}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "   \n\n\n  \t\t "));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringWhitespaceTrailing() */
corto_void _test_StringDeserializer_tc_deserStringWhitespaceTrailing(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringWhitespaceTrailing) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "string{  Hello World   }");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserStringWhitespaceTrailingNoType() */
corto_void _test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserStringWhitespaceTrailingNoType) */

    corto_string *o = corto_stringCreate(NULL);
    test_assert(o != NULL); 
    test_assert(*o == NULL); 
    corto_int16 ret = corto_fromStr(&o, "  Hello World   ");
    test_assert(ret == 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);
    test_assert(!strcmp(*(corto_string*)o, "Hello World"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint16() */
corto_void _test_StringDeserializer_tc_deserUint16(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint16) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint16{65535}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint16_o);
    test_assert(*(corto_uint16*)o == 65535);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint16Overflow() */
corto_void _test_StringDeserializer_tc_deserUint16Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint16Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint16{65536}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint16_o);
    test_assert(*(corto_uint16*)o == 0);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint32() */
corto_void _test_StringDeserializer_tc_deserUint32(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint32) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint32{4294967295}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint32_o);
    test_assert(*(corto_uint32*)o == 4294967295);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint32Overflow() */
corto_void _test_StringDeserializer_tc_deserUint32Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint32Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint32{4294967296}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint32_o);
    test_assert(*(corto_uint32*)o == 0);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint64() */
corto_void _test_StringDeserializer_tc_deserUint64(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint64) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint64{18446744073709551615}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint64_o);
    test_assert(*(corto_uint64*)o == 18446744073709551615u);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint8() */
corto_void _test_StringDeserializer_tc_deserUint8(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint8) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint8{255}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint8_o);
    test_assert(*(corto_uint8*)o == 255);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_deserUint8Overflow() */
corto_void _test_StringDeserializer_tc_deserUint8Overflow(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_deserUint8Overflow) */

    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "uint8{256}");
    test_assert(o != NULL);
    test_assert(ret == 0);
    test_assert(corto_typeof(o) == (corto_type)corto_uint8_o);
    test_assert(*(corto_uint8*)o == 0);
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_errExcessElements() */
corto_void _test_StringDeserializer_tc_errExcessElements(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errExcessElements) */

    corto_string err;
    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point{10, 20, 30}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "excess elements in string"));

/* $end */
}

/* ::test::StringDeserializer::tc_errMissingType() */
corto_void _test_StringDeserializer_tc_errMissingType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errMissingType) */

    corto_string err;
    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "{foo}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "no type provided for '{foo}'"));

/* $end */
}

/* ::test::StringDeserializer::tc_errNotAType() */
corto_void _test_StringDeserializer_tc_errNotAType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errNotAType) */

    corto_string err;
    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "lang{foo}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "'lang' is not a type"));

/* $end */
}

/* ::test::StringDeserializer::tc_errTypeMismatch() */
corto_void _test_StringDeserializer_tc_errTypeMismatch(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errTypeMismatch) */

    corto_string err;
    corto_object o = corto_boolCreate(TRUE); 
    corto_int16 ret = corto_fromStr(&o, "string{bar}");
    test_assert(o != NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "type of object ('::corto::lang::bool') does not match string ('::corto::lang::string')"));
    corto_delete(o);

/* $end */
}

/* ::test::StringDeserializer::tc_errUnresolvedMember() */
corto_void _test_StringDeserializer_tc_errUnresolvedMember(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errUnresolvedMember) */

    corto_string err;
    corto_object o = NULL; 
    corto_int16 ret = corto_fromStr(&o, "test::Point{a = 10}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "member 'a' not found"));

/* $end */
}

/* ::test::StringDeserializer::tc_errUnresolvedType() */
corto_void _test_StringDeserializer_tc_errUnresolvedType(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::tc_errUnresolvedType) */

    corto_string err;
    corto_object o = NULL;
    corto_int16 ret = corto_fromStr(&o, "foo{bar}");
    test_assert(o == NULL);
    test_assert(ret != 0);
    test_assert((err = corto_lasterr()) != NULL);
    test_assert(!strcmp(err, "unknown type 'foo'"));

/* $end */
}

/* ::test::StringDeserializer::teardown() */
corto_void _test_StringDeserializer_teardown(test_StringDeserializer this) {
/* $begin(::test::StringDeserializer::teardown) */

    /* << Insert implementation >> */

/* $end */
}
