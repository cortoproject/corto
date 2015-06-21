
#ifndef profiling__KEYVALUE_H
#define profiling__KEYVALUE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct profiling_TlsValue {
    cx_ll ll;
    cx_object topProfile; 
} profiling_TlsValue;

#ifdef __cplusplus
}
#endif
#endif
