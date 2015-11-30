/* $CORTO_GENERATED
 *
 * test_Project.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Project_setup(test_Project this) {
/* $begin(test/Project/setup) */
    char *env;

    env = corto_envparse(
      "$HOME/.corto/lib/corto/%s.%s/packages/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/lib/corto/<version>/packages/Project");
    }
    corto_rmtree(env);
    corto_dealloc(env);

    env = corto_envparse(
      "$HOME/.corto/include/corto/%s.%s/packages/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/lib/corto/<version>/packages/Project");
    }
    corto_rmtree(env);
    corto_dealloc(env);

    corto_rmtree("Project");

/* $end */
}

corto_void _test_Project_tc_app(test_Project this) {
/* $begin(test/Project/tc_app) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){"corto", "create", "Project", "--silent", NULL});

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/test"));

/* $end */
}

corto_void _test_Project_tc_appNoTest(test_Project this) {
/* $begin(test/Project/tc_appNoTest) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){"corto", "create", "Project", "--silent", "--notest", NULL});

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(!corto_fileTest("Project/test"));

/* $end */
}

corto_void _test_Project_tc_package(test_Project this) {
/* $begin(test/Project/tc_package) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(corto_fileTest("Project/README.md"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/src/Project_RedPanda.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));
    test_assert(corto_fileTest("Project/include/Project_RedPanda.h"));
    test_assert(corto_fileTest("Project/include/Project__api.h"));
    test_assert(corto_fileTest("Project/include/Project__interface.h"));
    test_assert(corto_fileTest("Project/include/Project__meta.h"));
    test_assert(corto_fileTest("Project/include/Project__type.h"));

    test_assert(corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/test/test"));
    test_assert(corto_fileTest("Project/test/rakefile"));
    test_assert(corto_fileTest("Project/test/test.cx"));
    test_assert(corto_fileTest("Project/test/src"));
    test_assert(corto_fileTest("Project/test/src/test.c"));
    test_assert(corto_fileTest("Project/test/src/test_MySuite.c"));
    test_assert(corto_fileTest("Project/test/include"));
    test_assert(corto_fileTest("Project/test/include/test.h"));
    test_assert(corto_fileTest("Project/test/include/test_MySuite.h"));
    test_assert(corto_fileTest("Project/test/include/test__api.h"));
    test_assert(corto_fileTest("Project/test/include/test__interface.h"));
    test_assert(corto_fileTest("Project/test/include/test__meta.h"));
    test_assert(corto_fileTest("Project/test/include/test__type.h"));

    test_assert(corto_fileTest("Project/.corto"));
    test_assert(!corto_fileTest("Project/.corto/libProject.so"));

    test_assert(corto_fileTest("Project/doc"));
    test_assert(corto_fileTest("Project/doc/Project.html"));
    test_assert(corto_fileTest("Project/doc/Project"));
    test_assert(corto_fileTest("Project/doc/Project/RedPanda.html"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/packages/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/packages/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/packages/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/packages/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageLocal(test_Project this) {
/* $begin(test/Project/tc_packageLocal) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--silent",
            "--local",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(!corto_fileTest("Project/README.md"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/src/Project_RedPanda.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));
    test_assert(corto_fileTest("Project/include/Project_RedPanda.h"));
    test_assert(corto_fileTest("Project/include/Project__api.h"));
    test_assert(corto_fileTest("Project/include/Project__interface.h"));
    test_assert(corto_fileTest("Project/include/Project__meta.h"));
    test_assert(corto_fileTest("Project/include/Project__type.h"));

    test_assert(!corto_fileTest("Project/test"));

    test_assert(corto_fileTest("Project/.corto"));
    test_assert(corto_fileTest("Project/.corto/libProject.so"));

    test_assert(!corto_fileTest("Project/doc"));

/* $end */
}

corto_void _test_Project_tc_publishNotag(test_Project this) {
/* $begin(test/Project/tc_publishNotag) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--silent",
            "--local",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/.corto/version.txt"));

    corto_string v = corto_fileLoad("Project/.corto/version.txt");
    test_assert(v != NULL);
    test_assert(!strcmp(v, "0.0.0\n"));
    corto_dealloc(v);

    /* Test patch version increase */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "publish",
            "Project",
            "patch",
            "--silent",
            "--notag",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project/.corto/version.txt"));

    v = corto_fileLoad("Project/.corto/version.txt");
    test_assert(v != NULL);
    test_assert(!strcmp(v, "0.0.1\n"));
    corto_dealloc(v);

    /* Test minor version increase */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "publish",
            "Project",
            "minor",
            "--silent",
            "--notag",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project/.corto/version.txt"));

    v = corto_fileLoad("Project/.corto/version.txt");
    test_assert(v != NULL);
    test_assert(!strcmp(v, "0.1.1\n"));
    corto_dealloc(v);

    /* Test major version increase */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "publish",
            "Project",
            "major",
            "--silent",
            "--notag",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project/.corto/version.txt"));

    v = corto_fileLoad("Project/.corto/version.txt");
    test_assert(!strcmp(v, "1.1.1\n"));
    corto_dealloc(v);

/* $end */
}

corto_void _test_Project_teardown(test_Project this) {
/* $begin(test/Project/teardown) */
    char *env = corto_envparse(
      "$HOME/.corto/lib/corto/%s.%s/packages/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);

    corto_rmtree(env);
    corto_dealloc(env);
    corto_rmtree("Project");

/* $end */
}
