


#define _test_scope(object, expected) \
{\
   db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, FALSE, TRUE};\
   db_serialize(&serializer, tc_jsonser_number_##object##_o, &userData);\
   if (strcmp(userData.buffer, "{\"scope\":"expected"}")) {\
       result = -1;\
       fprintf(\
           stderr,\
           "tc_jsonser_number: FAIL: expected %s, serialized %s\n",\
           "{\"scope\":"expected"}", userData.buffer);\
   }\
}

int16 test_scope(void) {
    int16 result = 0;

    _test_scope(namesp, 
        "[{\"name\":\"a\","
            "\"type\":\"::hyve::lang::int16\",\""
            "states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\",\""
            "childCount\":0},"
        "{\"name\":\"b\",\""
            "type\":\"::hyve::lang::string\","
            "\"states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\","
            "\"childCount\":0}]"
    );
    return result;
}

#undef _test_scope
