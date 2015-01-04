#include "cx_generator.h"
#include "cx_object.h"

typedef struct cx_html_gen {
    const char *path;
    unsigned int level;
    const char *rootFullname;
    cx_generator generator;
} cx_html_gen_t;