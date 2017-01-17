#include "cortotool_publish.h"
#include "corto/argparse/argparse.h"

corto_int16 cortotool_publish(int argc, char *argv[]) {
    corto_ll silent, mute, notag, dirs, majorarg, minorarg, patcharg;
    corto_uint32 major = 0, minor = 0, patch = 0;

    CORTO_UNUSED(argc);

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'publish' argument */
        {"--silent", &silent, NULL},
        {"--mute", &mute, NULL},
        {"--notag", &notag, NULL},
        {"$?*", &dirs, NULL},
        {"$+major", &majorarg, NULL},
        {"$|minor", &minorarg, NULL},
        {"$|patch", &patcharg, NULL},
        {NULL}
      }
    );

    if (!data) {
        corto_error("corto: %s", corto_lasterr());
        goto error;
    }

    if (dirs) {
        corto_string dir = corto_llGet(dirs, 0);
        if (corto_chdir(dir)) {
            corto_error("corto: %s", corto_lasterr());
            goto error;
        }
    }


    if (!corto_fileTest("./.corto")) {
        corto_error("corto: invalid project directory");
        goto error;
    }

    if (!notag) {
        corto_error(
            "corto: tagging of repository not yet supported "
            "(use --notag to just increase version)");
        goto error;
    }

    corto_string version = corto_fileLoad(".corto/version.txt");

    /* Patch version */
    if (version) {
        char *v = version;

        /* Parse major version */
        char *ptr = strchr(version, '.');
        if (ptr) {
            *ptr = '\0';
            major = atoi(v);
            v = ptr + 1;
        }

        /* Parse minor version */
        ptr = strchr(v, '.');
        if (ptr) {
            *ptr = '\0';
            minor = atoi(v);
            v = ptr + 1;
        }

        /* Parse patch version */
        patch = atoi(v);
    }

    if (majorarg) {
        major++;
    }
    if (minorarg) {
        minor++;
    }
    if (patcharg) {
        patch++;
    }

    FILE *f = fopen(".corto/version.txt", "w");
    if (!f) {
        corto_error("failed to open '.corto/version.txt' (check permissions)");
        goto error;
    }

    fprintf(f, "%u.%u.%u\n", major, minor, patch);
    fclose(f);

    corto_argclean(data);
    corto_dealloc(version);

    if (!silent) {
        corto_info("corto: version updated to %u.%u.%u", major, minor, patch);
    }

    return 0;
error:
    return -1;
}

void cortotool_publishHelp(void) {
    printf("Usage: corto publish [options]\n");
    printf("       corto publish major|minor|patch [options]\n");
    printf("       corto publish <project> [options]\n");
    printf("       corto publish <project> major|minor|patch [options]\n");
    printf("\n");
    printf("Increase version number of project, and create git tag.\n");
    printf("\n");
    printf("Options:\n");
    printf("  --notag: Just update version number, don't create git tag\n");
    printf("\n");
}
