/*
 * tc_stringser.c
 *
 *  Created on: Nov 19, 2013
 *      Author: sander
 */

#include "tc_stringser__type.h"
#include "tc_stringser__meta.h"
#include "tc_stringser__api.h"
#include "cortex.h"

int tc__classPrimitives(void) {
    tc_classPrimitives o1, o2;
    cx_string str1, str2;
    int result = 0;

    /* Create object */
    o1 = tc_classPrimitives__create(TRUE,'a',11,1.1,"String with special characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_BLUE,TC_WALK|TC_FLY);

    /* Serialize to string */
    str1 = cx_str(o1, 0);
    if (!str1) {
        goto ser1_err;
    }

    /* Serialize from string */
    o2 = cx_fromStr(str1);
    if (!o2) {
        goto deser_err;
    }

    /* Serialize back to string */
    str2 = cx_str(o2, 0);
    if (!str2) {
        goto ser2_err;
    }

    /* Compare strings, print error if they do not match */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)o1, str1, (void*)o2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_compare(o1, o2) != CX_EQ ? 1 : result;

    /* Free string */
    cx_dealloc(str1);
    cx_dealloc(str2);

    /* Free objects */
    cx_release(o1);
    cx_release(o2);

    return result;
ser2_err:
    cx_release(o2);
deser_err:
    cx_dealloc(str1);
ser1_err:
    cx_release(o1);
    return 1;
}

int tc__classInherit(void) {
    tc_classInherit o1, o2;
    cx_string str1, str2;
    int result = 0;

    /* Create object */
    o1 = tc_classInherit__create(
            TRUE, 'a',11,1.1,"String with special characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_BLUE,TC_WALK|TC_FLY,
            FALSE,'b',22,2.2,"string with special Characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_RED, TC_SWIM);

    /* Serialize to string */
    str1 = cx_str(o1, 0);
    if (!str1) {
        goto ser1_err;
    }

    /* Serialize from string */
    o2 = cx_fromStr(str1);
    if (!o2) {
        goto deser_err;
    }

    /* Serialize back to string */
    str2 = cx_str(o2, 0);
    if (!str2) {
        goto ser2_err;
    }

    /* Compare strings, print error if they do not match */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)o1, str1, (void*)o2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_compare(o1, o2) != CX_EQ ? 1 : result;

    /* Free string */
    cx_dealloc(str1);
    cx_dealloc(str2);

    /* Free objects */
    cx_release(o1);
    cx_release(o2);

    return result;
ser2_err:
    cx_release(o2);
deser_err:
    cx_dealloc(str1);
ser1_err:
    cx_release(o1);
    return 1;
}

int tc__arrayOfBool(void) {
    tc_arrayOfBool array1 = {TRUE,FALSE,TRUE};
    tc_arrayOfBool array2 = {FALSE,FALSE,FALSE};
    cx_string str1, str2;
    cx_value info1,info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfBool_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfBool_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfBool_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int tc__arrayOfChar(void) {
    tc_arrayOfChar array1 = {'a','b','c'};
    tc_arrayOfChar array2 = {'\0','\0','\0'};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfChar_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfChar_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfChar_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int tc__arrayOfInt(void) {
    tc_arrayOfInt array1 = {1,3,37};
    tc_arrayOfInt array2 = {0,0,0};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfInt_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfInt_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfInt_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int tc__arrayOfFloat(void) {
    tc_arrayOfFloat array1 = {1.1,3.3,37.37};
    tc_arrayOfFloat array2 = {0,0,0};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfFloat_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfFloat_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfFloat_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int tc__arrayOfString(void) {
    tc_arrayOfString array1 = {"abc","def","ghij"};
    tc_arrayOfString array2 = {NULL,NULL,NULL};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfString_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfString_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfString_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    /* Free deserialized array */

    return result;
}

int tc__arrayOfColor(void) {
    tc_arrayOfColor array1 = {TC_RED,TC_YELLOW,TC_BLUE};
    tc_arrayOfColor array2 = {TC_RED,TC_RED,TC_RED};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfColor_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfColor_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfColor_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int tc__arrayOfMoveMode(void) {
    tc_arrayOfMoveMode array1 = {TC_WALK,TC_FLY|TC_WALK,TC_SWIM|TC_FLY};
    tc_arrayOfMoveMode array2 = {TC_SWIM,TC_SWIM,TC_SWIM};
    cx_string str1, str2;
    cx_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    cx_valueValueInit(&info1, NULL, cx_type(tc_arrayOfMoveMode_o), array1);
    str1 = cx_strv(&info1, 0);

    /* Serialize string to array */
    cx_fromStrp(str1, array2, cx_type(tc_arrayOfMoveMode_o));

    /* Serialize 2nd array back to string */
    cx_valueValueInit(&info2, NULL, cx_type(tc_arrayOfMoveMode_o), array2);
    str2 = cx_strv(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = cx_comparev(&info1, &info2) != CX_EQ ? 1 : result;

    /* Free strings */
    cx_dealloc(str1);
    cx_dealloc(str2);

    return result;
}

int main(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    cx_bool result = TRUE;

    /* Start database */
    cx_start();

    /* Load definitions */
    tc_stringser_load();

    if (tc__classPrimitives()) {
        printf("tc_stringser: tc_classPrimitives failed\n");
        result = FALSE;
    }

    if (tc__classInherit()) {
        printf("tc_stringser: tc_classInherit failed\n");
        result = FALSE;
    }

    if (tc__arrayOfBool()) {
        printf("tc_stringser: tc_arrayOfBool failed\n");
        result = FALSE;
    }

    if (tc__arrayOfChar()) {
        printf("tc_stringser: tc_arrayOfChar failed\n");
        result = FALSE;
    }

    if (tc__arrayOfInt()) {
        printf("tc_stringser: tc_arrayOfInt failed\n");
        result = FALSE;
    }

    if (tc__arrayOfFloat()) {
        printf("tc_stringser: tc_arrayOfFloat failed\n");
        result = FALSE;
    }

    if (tc__arrayOfString()) {
        printf("tc_stringser: tc_arrayOfString failed\n");
        result = FALSE;
    }

    if (tc__arrayOfMoveMode()) {
        printf("tc_stringser: tc_arrayOfMoveMode failed\n");
        result = FALSE;
    }

    /* Stop database */
    cx_stop();

    if (result) {
        printf("tc_stringser: OK\n");
    }

    return result;
}
