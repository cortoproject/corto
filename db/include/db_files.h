
#ifndef cx_files_H
#define cx_files_H

#ifdef __cplusplus
extern "C" {
#endif

/* Returns zero if OK, -1 if failed */
int cx_mkdir(const char *name);

/* Returns zero if OK, -1 if failed */
int cx_cp(const char *source, const char *destination);

#ifdef __cplusplus
}
#endif

#endif
