/* $CORTO_GENERATED
 *
 * map.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

int16_t _corto_map_construct(
    corto_map this)
{
/* $begin(corto/lang/map/construct) */
    corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    corto_type(this)->size = sizeof(corto_map);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_map);
    corto_collection(this)->elementType = this->elementType;
    corto_claim(this->elementType);
    corto_collection(this)->max = this->max;
    return corto_type_construct(corto_type(this));
/* $end */
}

int16_t _corto_map_init(
    corto_map this)
{
/* $begin(corto/lang/map/init) */
    corto_collection(this)->kind = CORTO_MAP;
    return corto_collection_init(corto_collection(this));
/* $end */
}
