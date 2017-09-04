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

static int runCommand(char *cmd, int argc, char *argv[]) {
    /* If a command is found, run the command with remaining args */
    corto_id package;
    sprintf(package, "driver/tool/%s", cmd);
    return corto_run(package, argc, argv);    
}

static int loadArguments(int argc, char* argv[]) {
    int i;
    for (i = 0; i < argc; i++) {
        if (corto_load(argv[i], 0, NULL)) {
            return i + 1;
        }
    }
    return 0;
}

static void printLogo(void) {
    char *color1 = CORTO_GREEN, *color2 = CORTO_CYAN;
    printf("\n");
    printf("            %s##########%s\n", color1, CORTO_NORMAL);
    printf("          %s##########%s ####%s\n", color1, color2, CORTO_NORMAL);
    printf("        %s##########%s ########%s\n", color1, color2, CORTO_NORMAL);
    printf("      %s##########%s   ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("    %s##########%s       ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("  %s##########%s           ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("   %s##########%s         ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("     %s##########%s     ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("       %s##########%s ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("         %s######%s ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("           %s##%s ##########%s\n", color1, color2, CORTO_NORMAL);
    printf("\n");
}

static void printUsage(void) {
    printf("Usage: corto [options] <command> [arguments]\n");
    printf("\n");
    printf("Options:\n");
    printf("  -h,--help                  Display this usage information\n");
    printf("\n");
    printf("  version and logo:\n");
    printf("  --patch                    Display major.minor.patch version\n");    
    printf("  --minor                    Display major.minor version\n");
    printf("  --major                    Display major version\n");
    printf("  -v                         Same as --patch\n");    
    printf("  --version                  Display current version and build\n");
    printf("  --logo                     Display logo\n");
    printf("\n");
    printf("  loading packages & files:\n");
    printf("  -l,--load [file/package]   Pass all subsequent arguments to specified file/package\n");
    printf("  -a,--keep-alive            Keep corto running after command is executed\n");
    printf("\n");
    printf("  tracing:\n");
    printf("  --debug                    Set verbosity to DEBUG\n");
    printf("  --trace                    Set verbosity to TRACE\n");
    printf("  --ok                       Set verbosity to OK\n");
    printf("  --log                      Set verbosity to LOG\n");
    printf("  --info                     Set verbosity to INFO\n");
    printf("  --warning                  Set verbosity to WARNING\n");
    printf("  --error                    Set verbosity to ERROR\n");
    printf("  --mute                     Mute errors from loaded packages\n");
    printf("  --backtrace                Enable backtraces for tracing\n");
    printf("  --trace-object [id]        Trace operations for specified object\n");
}

#define PARSE_OPTION(short, long, action)\
    if (argv[i][0] == '-') {\
        if (argv[i][1] == '-') {\
            if (long && !strcmp(&argv[i][2], long ? long : "")) {\
                action;\
                parsed = true;\
            }\
        } else {\
            if (short && argv[i][1] == short) {\
                action;\
                parsed = true;\
            }\
        }\
    }

/* Global options */
static bool load = false;
static bool keep_alive = false;
static bool mute = false;

static void printVersion(bool minor, bool patch) {
    if (patch) {
        printf("%s.%s.%s\n", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, CORTO_VERSION_PATCH);    
    } else
    if (minor) {
        printf("%s.%s\n", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);        
    } else {
        printf("%s\n", CORTO_VERSION_MAJOR);                
    }
}

static void printLongVersion(void) {
    printf("corto version %s (%s)\n  library: %s (%s)\n",
        CORTO_VERSION,
        CORTO_PLATFORM_STRING,
        corto_getLibrary(),
        corto_getBuild());
}

static int parseGenericArgs(int argc, char *argv[]) {
    int i;
    bool parsed;

    for(i = 0; i < argc; i++) {
        parsed = false;
        if (argv[i][0] == '-') {
            PARSE_OPTION('l', "load", load = true; i ++; break);
            PARSE_OPTION('a', "keep-alive", keep_alive = true);
            PARSE_OPTION('v', NULL, printVersion(true, true));
            PARSE_OPTION(0, "patch", printVersion(true, true));
            PARSE_OPTION(0, "minor", printVersion(true, false));
            PARSE_OPTION(0, "major", printVersion(false, false));
            PARSE_OPTION(0, "version", printLongVersion());
            PARSE_OPTION('h', "help", printUsage());
            PARSE_OPTION(0, "logo", printLogo());
            PARSE_OPTION(0, "debug", corto_verbosity(CORTO_DEBUG));
            PARSE_OPTION(0, "trace", corto_verbosity(CORTO_TRACE));
            PARSE_OPTION(0, "ok", corto_verbosity(CORTO_OK));
            PARSE_OPTION(0, "info", corto_verbosity(CORTO_INFO));
            PARSE_OPTION(0, "warning", corto_verbosity(CORTO_WARNING));
            PARSE_OPTION(0, "error", corto_verbosity(CORTO_ERROR));
            PARSE_OPTION(0, "mute", mute = true);
            PARSE_OPTION(0, "backtrace", CORTO_BACKTRACE_ENABLED = true);
            PARSE_OPTION(0, "trace-object", CORTO_TRACE_OBJECT = argv[i + 1]; i ++);
            
            if (!parsed) {
                fprintf(stderr, "unknown option '%s' (use corto --help to see available options)\n", argv[i]);
                return -1;
            }
        } else {
            break;
        }
    }

    return i + 1;
}

int main(int argc, char *argv[]) {
    int result = 0;

    /* Parse arguments before first command. Any arguments after the first
     * command or file are passed to that file or command. */
    int last_parsed = parseGenericArgs(argc - 1, &argv[1]);

    /* If arguments are invalid, don't bother starting corto */
    if (last_parsed != -1) {
        char *cmd = "unknown";

        /* Start corto */
        corto_start(argv[0]);

        /* If there are more arguments than that have been parsed so far, there must
         * be a command or file to be loaded */
        if (argc > last_parsed) {
            char **cur_args = &argv[last_parsed];
            int cur_count = argc - last_parsed;

            /* If load is set, only load a single package/file, and pass all
             * remaining arguments to this file */
            if (load) {
                result = corto_load(cur_args[0], cur_count, cur_args);
            } else {
                /* Test if current argument is a command */
                corto_id package;
                sprintf(package, "driver/tool/%s", cur_args[0]);
                char *lib;
                cmd = cur_args[0];
                if ((lib = corto_locate(package, NULL, CORTO_LOCATION_LIB))) {
                    result = runCommand(cur_args[0], cur_count, cur_args);
                    free(lib);
                } else {
                    /* If not a command, load subsequent arguments */
                    result = loadArguments(cur_count, cur_args);
                    if (result) {
                        cmd = cur_args[result - 1];
                    }
                }
            }
        } else if (argc == 1) {
            /* Run default command */
            if ((result = runCommand("default", 0, NULL))) {
                corto_lasterr();
                corto_seterr("no default command configured");
            }
        }

        if (result) {
            if (!mute && (!corto_lasterr() || corto_lasterr()[0])) {
                corto_error("%s: %s", cmd, corto_lasterr() ? corto_lasterr() : "undefined error");
            } else {
                corto_lasterr();
            }
        }        

        if (keep_alive) {
            while (true) {
                corto_sleep(1, 0);
            }
        }

        /* Stop corto */
        corto_stop();
    } else {
        result = -1;
    }

    return result;    
}
