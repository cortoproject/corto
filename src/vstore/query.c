/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
uint32_t corto_query_cardinality(
    corto_query* this)
{
    if (!strchr(this->select, '*') || strstr(this->select, "//")) {
        return -1;
    } else {
        return 1;
    }

}

bool corto_query_match(
    corto_query* this,
    corto_record *record)
{
    corto_assert(record->id != NULL, "no id specified in result");
    corto_assert(record->parent != NULL, "no parent specified in result");
    corto_assert(record->type != NULL, "no type specified in result");

    const char *result_type = record->type;
    const char *query_type = record->type;
    if (result_type[0] == '/') result_type ++;
    if (query_type[0] == '/') query_type ++;

    if (this->type && this->type[0] && strcmp(result_type, query_type)) {
        return false;
    }

    if (this->from && this->from[0] && strcmp(this->from, record->parent)) {
        return false;
    }

    if (this->select && !corto_idmatch(this->select, record->id)) {
        return false;
    }

    return true;
}
