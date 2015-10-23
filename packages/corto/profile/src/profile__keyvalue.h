
#ifndef profile__KEYVALUE_H
#define profile__KEYVALUE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct profile_TlsValue {
    corto_ll ll;
    corto_object topProfile; 
} profile_TlsValue;

#ifdef __cplusplus
}
#endif
#endif
