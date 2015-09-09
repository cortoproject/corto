
#ifndef profile__KEYVALUE_H
#define profile__KEYVALUE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct profile_TlsValue {
    cx_ll ll;
    cx_object topProfile; 
} profile_TlsValue;

#ifdef __cplusplus
}
#endif
#endif
