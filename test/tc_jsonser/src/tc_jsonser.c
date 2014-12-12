#include <string.h>
#include "hyve.h"
#include "json.h"

#include "tc_jsonser__api.h"
#include "tc_jsonser__meta.h"
#include "tc_jsonser__type.h"

#include "tc_jsonser_primitive_value.h"
#include "tc_jsonser_scope.h"

int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    db_bool result = TRUE;
    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    db_start();
    tc_jsonser_load();

    test_primitive_values();
    test_scope();   
 
    db_stop();

    if (result) {
        printf("tc_jsonser: OK\n");
    }

    return result;
}
