/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>

/*
 * Receives:
 * - the error code
 * - an initial message
 * The name for the error code will be appended.
 */
static void printError(int e, const char *ctx) {
    corto_seterr("%s '%s'", strerror(e), ctx);
}

int corto_touch(const char *file) {
    FILE* touch = NULL;

    if (file) {
        touch = fopen(file, "ab");
        if (touch) {
            fclose(touch);
        }
    }

    return touch ? 0 : -1;
}

int corto_chdir(const char *dir) {
    if (chdir(dir)) {
        corto_seterr("%s '%s'", strerror(errno), dir);
        return -1;
    }
    return 0;
}

char* corto_cwd(void) {
    corto_id cwd;
    if (getcwd(cwd, sizeof(cwd))) {
        return corto_setThreadString(cwd);
    } else {
        corto_seterr("%s", strerror(errno));
        return NULL;
    }
}

int corto_mkdir(const char *fmt, ...) {
    int _errno = 0;
    char msg[PATH_MAX];
    
    va_list args;
    va_start(args, fmt);
    char *name = corto_venvparse(fmt, args);
    va_end(args);
    if (!name) {
        goto error_name;
    }

    if (mkdir(name, 0755)) {
        _errno = errno;

        /* If error is ENOENT an element in the prefix of the name
         * doesn't exist. Recursively create pathname, and retry. */
        if (errno == ENOENT) {
            /* Allocate so as to not run out of stackspace in recursive call */
            char *prefix = corto_strdup(name);
            char *ptr = &prefix[strlen(prefix)-1], ch;
            while ((ch = *ptr) && (ptr >= prefix)) {
                if (ch == '/') {
                    *ptr = '\0';
                    break;
                }
                ptr--;
            }
            if (ch == '/') {
                if (!corto_mkdir(prefix)) {
                    /* Retry current directory */
                    if (!mkdir(name, 0755)) {
                        _errno = 0;
                    } else {
                        _errno = errno;
                    }
                } else {
                    goto error;
                }
            } else {
                goto error; /* If no prefix is found, report error */
            }
            corto_dealloc(prefix);
        }

        /* Post condition for function is that directory exists so don't
         * report an error if it already did. */
        if (_errno && (_errno != EEXIST)) {
            goto error;
        }
    }

    corto_dealloc(name);

    return 0;
error:
    sprintf(msg, "%s", name);
    printError(errno, msg);
    corto_dealloc(name);
error_name:
    return -1;
}

int corto_cp(const char *sourcePath, const char *destinationPath) {
    int _errno = 0;
    char msg[PATH_MAX];
    FILE *destinationFile;
    FILE *sourceFile;

    if (!(sourceFile = fopen(sourcePath, "rb"))) {
        _errno = errno;
        sprintf(msg, "cannot open sourcefile '%s'", sourcePath);
        goto error;
    }

    if (!(destinationFile = fopen(destinationPath, "wb"))) {
        /* If destination is a directory, append filename to directory and try
         * again */
        if (errno == EISDIR) {
            corto_id fileName, dest;
            strcpy(fileName, sourcePath);
            corto_nameFromFullname(fileName);
            sprintf(dest, "%s/%s", destinationPath, fileName);
            if (!(destinationFile = fopen(dest, "wb"))) {
                _errno = errno;
                sprintf(msg, "cannot open destinationfile '%s'", dest);
                fclose(sourceFile);
                goto error;
            }
        } else {
            _errno = errno;
            sprintf(msg, "cannot open destinationfile '%s'", destinationPath);
            fclose(sourceFile);
            goto error;
        }
    }

    /* "no real standard portability"
     * http://www.cplusplus.com/reference/cstdio/fseek/ */
    if (fseek(sourceFile, 0, SEEK_END)) {
        _errno = errno;
        sprintf(msg, "cannot traverse file '%s'", sourcePath);
        goto error_CloseFiles;
    }

    long fileSizeResult;
    size_t fileSize;
    fileSizeResult = ftell(sourceFile);
    if (fileSizeResult == -1) {
        sprintf(msg, "cannot obtain filesize from file %s", sourcePath);
        goto error_CloseFiles;
    }
    /* Now we can be sure that fileSizeResult doesn't contain a
     * negative value */
    fileSize = fileSizeResult;

    rewind(sourceFile);

    char *buffer = corto_alloc(fileSize);
    if (!buffer) {
        _errno = 0;
        sprintf(msg, "cannot allocate buffer for copying files");
        goto error_CloseFiles;
    }

    if (fread(buffer, 1, fileSize, sourceFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "cannot read the file %s", sourcePath);
        goto error_CloseFiles_FreeBuffer;
    }

    if (fwrite(buffer, 1, fileSize, destinationFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "cannot write to the file %s", destinationPath);
        goto error_CloseFiles_FreeBuffer;
    }

    corto_dealloc(buffer);
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;

error_CloseFiles_FreeBuffer:
    free(buffer);
error_CloseFiles:
    fclose(sourceFile);
    fclose(destinationFile);
error:
    printError(_errno, msg);
    return -1;
}

/* Test if name is a directory */
int corto_isdir(const char *path) {
    struct stat buff;
    if (stat(path, &buff) != 0) {
        return 0;
    }
    return S_ISDIR(buff.st_mode);
}

int corto_rename(const char *oldName, const char *newName) {
    if (rename(oldName, newName)) {
        corto_seterr(strerror(errno));
        goto error;
    }
    return 0;
error:
    return -1;
}

/* Remove a file. Returns 0 if OK, -1 if failed */
int corto_rm(const char *name) {
    int result = 0;

    if (corto_isdir(name)) {
        return corto_rmtree(name);
    } else if (remove(name)) {
        /* Don't care if file didn't exist since the postcondition
         * is that file doesn't exist. */
        if (errno != EEXIST) {
            result = -1;
            corto_seterr(strerror(errno));
        }
    }

    return result;
}

static int corto_rmtreeCallback(
  const char *path,
  const struct stat *sb,
  int typeflag,
  struct FTW *ftwbuf)
{
    CORTO_UNUSED(sb);
    CORTO_UNUSED(typeflag);
    CORTO_UNUSED(ftwbuf);
    if (remove(path)) {
        corto_seterr(strerror(errno));
        goto error;
    }
    return 0;
error:
    return -1;
}

/* Recursively remove a directory */
int corto_rmtree(const char *name) {
    return nftw(name, corto_rmtreeCallback, 20, FTW_DEPTH);
}

/* Read the contents of a directory */
corto_ll corto_opendir(const char *name) {
    DIR *dp;
    struct dirent *ep;
    corto_ll result = NULL;

    dp = opendir (name);

    if (dp != NULL) {
        result = corto_ll_new();
        while ((ep = readdir (dp))) {
            if (*ep->d_name != '.') {
                corto_ll_append(result, corto_strdup(ep->d_name));
            }
        }
        closedir (dp);
    }

    return result;
}

void corto_closedir(corto_ll dir) {
    corto_iter iter = corto_ll_iter(dir);

    while(corto_iter_hasNext(&iter)) {
        corto_dealloc(corto_iter_next(&iter));
    }
    corto_ll_free(dir);
}

corto_pid corto_procrun(const char* exec, char *argv[]) {
    pid_t pid = fork();


    if (pid == 0) {

        /* Child process */
        if (execvp(exec, argv)) {
            corto_error("failed to start process '%s'\n  cwd='%s'\n  err='%s'",
              exec,
              corto_cwd(),
              strerror(errno));
            abort();
        }
    } else if (pid > 0) {
        /* Parent process */
    } else {
        /* Failure */
    }

    return pid;
}

#include "unistd.h"
#include <fcntl.h>

corto_pid corto_procrunRedirect(
    const char* exec, char *argv[], FILE *in, FILE *out, FILE *err)
{
    pid_t pid = fork();

    if (pid == 0) {
        FILE *devnull = NULL;
        if (!out || !err) {
            devnull = fopen("/dev/null", "w");
            if (!devnull) {
                corto_error("failed to open /dev/null");
                abort();
            }
        }

        if (dup2(fileno(out ? out : devnull), STDOUT_FILENO) < 0) {
            corto_error("failed to redirect stdout for '%s': %s", exec, strerror(errno));
            abort();
        }
        if (out && (err != stdout)) fclose(out);

        if (dup2(fileno(err ? err : devnull), STDERR_FILENO) < 0) {
            corto_error("failed to redirect stderr for '%s': %s", exec, strerror(errno));
            abort();
        }

        if (err && (err != stderr)) fclose(err);
        if (devnull) fclose(devnull);

        if (dup2(fileno(in), STDIN_FILENO) < 0) {
            corto_error("failed to redirect stdin for '%s': %s", exec, strerror(errno));
            abort();
        }
        if (in && (in != stdin)) fclose(in);

        /* Child process */
        if (execvp(exec, argv)) {
            corto_error("failed to start process '%s'", exec);
            abort();
        }
    } else if (pid > 0) {
        /* Parent process */
    } else {
        /* Failure */
    }

    return pid;
}

int corto_prockill(corto_pid pid, corto_procsignal sig) {
    return kill(pid, sig);
}

int corto_procwait(corto_pid pid, int8_t *rc) {
    int status = 0;
    int result = 0;

    if (waitpid(pid, &status, 0) != pid) {
        corto_seterr("wait for %d failed: %s", pid, strerror(errno));
        return -1;
    }

    if (WIFSIGNALED(status)) {
        result = WTERMSIG(status);
    } else {
        if (rc) {
            *rc = WEXITSTATUS(status);
        }
    }

    return result;
}

/* Simple blocking function to create and wait for a process */
int corto_proccmd(corto_string cmd, int8_t *rc) {
    int pid;
    char *args[CORTO_MAX_CMD_ARGS];
    char buffer[CORTO_MAX_CMD];
    strcpy(buffer, cmd);

    corto_debug("cmd: %s", cmd);

    /* Split up commands */
    char ch, *ptr;
    corto_uint8 argCount = 0;
    corto_bool newArg = FALSE;
    args[argCount] = buffer;
    for (ptr = buffer; (ch = *ptr); ptr++) {
        if (isspace(ch)) {
            *ptr = '\0';
            newArg = TRUE;
        } else if (newArg) {
            args[++argCount] = ptr;
            newArg = FALSE;
        }
    }
    args[argCount + 1] = NULL;

    if (!(pid = corto_procrun(args[0], args))) {
        goto error;
    }

    return corto_procwait(pid, rc);
error:
    return -1;
}

int corto_proccheck(corto_pid pid, int8_t *rc) {
    int status = 0;
    int result = 0;

    result = waitpid(pid, &status, WNOHANG);
    if (!result) {
        /* Process did not change state, still running */
    } else if (WIFSIGNALED(status)) {
        /* Process exited with a signal */
        result = WTERMSIG(status);
    } else {
        /* Process exited normally */
        if (rc) {
            *rc = WEXITSTATUS(status);
        }
        result = -1;
    }

    return result;
}

/* Check whether process is being debugged */
#ifdef __MACH__
#ifndef NDEBUG
typedef unsigned long u_long;
typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned char u_char;
#include <sys/sysctl.h>
#endif
#endif

int corto_beingTraced(void) {
/* Some of these APIs might be unstable. Only use in debug builds. */
#ifndef NDEBUG
#ifdef __MACH__
    int                 junk;
    int                 mib[4];
    struct kinfo_proc   info;
    size_t              size;

    // Initialize the flags so that, if sysctl fails for some bizarre
    // reason, we get a predictable result.
    info.kp_proc.p_flag = 0;

    // Initialize mib, which tells sysctl the info we want, in this case
    // we're looking for information about a specific process ID.
    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PID;
    mib[3] = getpid();

    // Call sysctl.
    size = sizeof(info);
    junk = sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, NULL, 0);
    assert(junk == 0);

    // We're being debugged if the P_TRACED flag is set.
    return ( (info.kp_proc.p_flag & P_TRACED) != 0 );
#else
    return ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1;
#endif
#else
    return 0;
#endif
}

char* corto_hostname(void) {
    corto_id buff;
    gethostname(buff, sizeof(buff));
    return corto_setThreadString(buff);
}

corto_pid _corto_pid(void) {
    return getpid();
}

corto_int16 corto_setenv(const char *varname, const char *value, ...) {
    if (value) {
        va_list arglist;
        char *buff;
        va_start(arglist, value);
        buff = corto_venvparse(value, arglist);
        if (!buff) {
            va_end(arglist);
            goto error;
        }
        va_end(arglist);
        setenv(varname, buff, 1);
        corto_dealloc(buff);
    } else {
        unsetenv(varname);
    }
    return 0;
error:
    return -1;
}

char* corto_getenv(const char *varname) {
    return getenv(varname);
}

static char* corto_growBuffer(char **buffer, char *ptr, int *size, int length) {
    int pos = ptr - *buffer;

    if ((pos + length) >= *size) {
        *size = ((pos + length) < 256) ? 256 : pos + length + 1;
        *buffer = corto_realloc(*buffer, *size);
        ptr = &(*buffer)[pos];
    }

    return ptr;
}

static int corto_venvparseFlush(char* var, char** varptrptr, char** bptrptr, char** resultptr, int size, char ch) {
    char *val;
    int len;
    **varptrptr = '\0';
    val = corto_getenv(var);
    if (!val) {
        corto_seterr("environment variable '%s' doesn't exist", var);
        goto error;
    }
    len = strlen(val);
    *bptrptr = corto_growBuffer(resultptr, *bptrptr, &size, len + 1);
    memcpy(*bptrptr, val, len);
    *bptrptr += len;
    *varptrptr = var;
    **bptrptr = ch;
    (*bptrptr)++;
    return 0;
error:
    return -1;
}

char* corto_venvparse(const char* input, va_list arglist) {
    int size = 256;
    char *result = corto_alloc(size);
    const char *ptr;
    char *bptr, *str = NULL;
    char var[256], *varptr; /* buffer for name of environment variable */
    char ch;

    str = corto_vasprintf(input, arglist);

    ptr = str;
    bptr = result;
    varptr = var;

    while ((ch = *ptr)) {
        if (ch == '$') {
            ptr++;
            varptr = var;
            *varptr = *ptr;
            varptr++;
        } else if (ch == '~') {
            char *val = corto_getenv("HOME");
            if (!val) {
                corto_seterr("$HOME environment variable (~) not found in string '%s'", str);
                goto error;
            }
            int len = strlen(val);
            bptr = corto_growBuffer(&result, bptr, &size, len);
            memcpy(bptr, val, len);
            bptr += len;
        } else {
            /* decide if we buffer a variable name or copy chars directly */
            if (varptr != var) {
                if (isalpha(ch) || (ch == '_')) {
                    /* copy variable name into var */
                    *varptr = ch;
                    varptr++;
                } else {
                    /* copy the value of the variable */
                    if (corto_venvparseFlush(var, &varptr, &bptr, &result, size, ch)) {
                        goto error;
                    }
                }
            } else {
                bptr = corto_growBuffer(&result, bptr, &size, 1);
                *bptr = ch;
                bptr++;
            }
        }
        ptr++;
    }
    if (varptr != var) {
        if (corto_venvparseFlush(var, &varptr, &bptr, &result, size, ch)) {
            goto error;
        }
    }

    bptr = corto_growBuffer(&result, bptr, &size, 1);
    *bptr = '\0';

    corto_dealloc(str);

    return result;
error:
    if (str) corto_dealloc(str);
    return NULL;
}

char* corto_envparse(const char* str, ...) {
    va_list arglist;
    char *result;

    va_start(arglist, str);
    result = corto_venvparse(str, arglist);
    va_end(arglist);
    return result;
}
