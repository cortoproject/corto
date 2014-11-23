/*
 * tc_stringser.c
 *
 *  Created on: Nov 19, 2013
 *      Author: sander
 */

#include "tc_stringser__type.h"
#include "tc_stringser__meta.h"
#include "tc_stringser__api.h"
#include "hyve.h"

int tc__classPrimitives(void) {
    tc_classPrimitives o1, o2;
    db_string str1, str2;
    int result = 0;

    /* Create object */
    o1 = tc_classPrimitives__create(TRUE,'a',11,1.1,"String with special characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_BLUE,TC_WALK|TC_FLY);

    /* Serialize to string */
    str1 = db_toString(o1, 0);
    if (!str1) {
        goto ser1_err;
    }

    /* Serialize from string */
    o2 = db_fromString(str1);
    if (!o2) {
        goto deser_err;
    }

    /* Serialize back to string */
    str2 = db_toString(o2, 0);
    if (!str2) {
        goto ser2_err;
    }

    /* Compare strings, print error if they do not match */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)o1, str1, (void*)o2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_compare(o1, o2) != DB_EQ ? 1 : result;

    /* Free string */
    db_dealloc(str1);
    db_dealloc(str2);

    /* Free objects */
    db_free(o1);
    db_free(o2);

    return result;
ser2_err:
    db_free(o2);
deser_err:
    db_dealloc(str1);
ser1_err:
    db_free(o1);
    return 1;
}

int tc__classInherit(void) {
    tc_classInherit o1, o2;
    db_string str1, str2;
    int result = 0;

    /* Create object */
    o1 = tc_classInherit__create(
            TRUE, 'a',11,1.1,"String with special characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_BLUE,TC_WALK|TC_FLY,
            FALSE,'b',22,2.2,"string with special Characters ~`!@#$%^&*()_-+=\"{}[]|\\:;'<>,.?/",TC_RED, TC_SWIM);

    /* Serialize to string */
    str1 = db_toString(o1, 0);
    if (!str1) {
        goto ser1_err;
    }

    /* Serialize from string */
    o2 = db_fromString(str1);
    if (!o2) {
        goto deser_err;
    }

    /* Serialize back to string */
    str2 = db_toString(o2, 0);
    if (!str2) {
        goto ser2_err;
    }

    /* Compare strings, print error if they do not match */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)o1, str1, (void*)o2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_compare(o1, o2) != DB_EQ ? 1 : result;

    /* Free string */
    db_dealloc(str1);
    db_dealloc(str2);

    /* Free objects */
    db_free(o1);
    db_free(o2);

    return result;
ser2_err:
    db_free(o2);
deser_err:
    db_dealloc(str1);
ser1_err:
    db_free(o1);
    return 1;
}

int tc__arrayOfBool(void) {
    tc_arrayOfBool array1 = {TRUE,FALSE,TRUE};
    tc_arrayOfBool array2 = {FALSE,FALSE,FALSE};
    db_string str1, str2;
    db_value info1,info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfBool_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfBool_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfBool_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int tc__arrayOfChar(void) {
    tc_arrayOfChar array1 = {'a','b','c'};
    tc_arrayOfChar array2 = {'\0','\0','\0'};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfChar_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfChar_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfChar_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int tc__arrayOfInt(void) {
    tc_arrayOfInt array1 = {1,3,37};
    tc_arrayOfInt array2 = {0,0,0};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfInt_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfInt_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfInt_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int tc__arrayOfFloat(void) {
    tc_arrayOfFloat array1 = {1.1,3.3,37.37};
    tc_arrayOfFloat array2 = {0,0,0};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfFloat_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfFloat_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfFloat_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int tc__arrayOfString(void) {
    tc_arrayOfString array1 = {"abc","def","ghij"};
    tc_arrayOfString array2 = {NULL,NULL,NULL};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfString_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfString_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfString_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    /* Free deserialized array */

    return result;
}

int tc__arrayOfColor(void) {
    tc_arrayOfColor array1 = {TC_RED,TC_YELLOW,TC_BLUE};
    tc_arrayOfColor array2 = {TC_RED,TC_RED,TC_RED};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfColor_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfColor_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfColor_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int tc__arrayOfMoveMode(void) {
    tc_arrayOfMoveMode array1 = {TC_WALK,TC_FLY|TC_WALK,TC_SWIM|TC_FLY};
    tc_arrayOfMoveMode array2 = {TC_SWIM,TC_SWIM,TC_SWIM};
    db_string str1, str2;
    db_value info1, info2;
    int result = 0;

    /* Serialize array to string */
    db_valueValueInit(&info1, NULL, db_typedef(tc_arrayOfMoveMode_o), array1);
    str1 = db_valueToString(&info1, 0);

    /* Serialize string to array */
    db_valueFromString(str1, array2, db_typedef(tc_arrayOfMoveMode_o));

    /* Serialize 2nd array back to string */
    db_valueValueInit(&info2, NULL, db_typedef(tc_arrayOfMoveMode_o), array2);
    str2 = db_valueToString(&info2, 0);

    /* Compare the two strings */
    if (strcmp(str1, str2)) {
        printf("asymetrical serializer\\deserializer:\n [%p] %s\n [%p] %s\n", (void*)array1, str1, (void*)array2, str2);
        result = 1;
    }

    /* Compare objects */
    result = db_valueCompare(&info1, &info2) != DB_EQ ? 1 : result;

    /* Free strings */
    db_dealloc(str1);
    db_dealloc(str2);

    return result;
}

int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    db_bool result = TRUE;

    /* Start database */
    db_start();

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
    db_stop();

    if (result) {
        printf("tc_stringser: OK\n");
    }

    return result;
}
