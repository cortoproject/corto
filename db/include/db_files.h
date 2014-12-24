
#ifndef db_files_H
#define db_files_H

#ifdef __cplusplus
extern "C" {
#endif

/* Returns zero if OK, -1 if failed */
int db_mkdir(const char *name);

/* Returns zero if OK, -1 if failed */
int db_cp(const char *source, const char *destination);

#ifdef __cplusplus
}
#endif

#endif
