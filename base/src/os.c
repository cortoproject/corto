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

#include <include/base.h>

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
int corto_proccmd(char* cmd, int8_t *rc) {
    int pid;
    char *args[CORTO_MAX_CMD_ARGS];
    char buffer[CORTO_MAX_CMD];
    strcpy(buffer, cmd);

    corto_debug("cmd: %s", cmd);

    /* Split up commands */
    char ch, *ptr;
    uint8_t argCount = 0;
    bool newArg = FALSE;
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

int16_t corto_setenv(const char *varname, const char *value, ...) {
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
