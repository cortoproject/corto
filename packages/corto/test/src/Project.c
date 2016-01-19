/* $CORTO_GENERATED
 *
 * Project.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

/* $header() */
corto_int16 test_Project_cleanEnv(corto_string name) {
    char *env;

    env = corto_envparse(
      "$HOME/.corto/lib/corto/%s.%s/packages/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, name);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/lib/corto/<version>/packages/<project>");
        goto error;
    }
    corto_rmtree(env);
    corto_dealloc(env);

    env = corto_envparse(
      "$HOME/.corto/include/corto/%s.%s/packages/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, name);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/include/corto/<version>/packages/<project>");
        goto error;
    }
    corto_rmtree(env);
    corto_dealloc(env);

    return 0;
error:
    return -1;
}

corto_int16 test_Project_implement(corto_string package) {
    corto_id cxfile;
    corto_int8 ret;
    corto_int16 waitResult;

    sprintf(cxfile, "%s/%s.cx", package, package);
    FILE *f = fopen(cxfile, "a");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "void foo()\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            package,
            "--silent",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

    return 0;
error:
    return -1;
}

corto_int16 test_Project_implementNoCorto(
    corto_string name,
    corto_string package)
{
    corto_id cfile;
    corto_int8 ret;
    corto_int16 waitResult;

    sprintf(cfile, "%s/src/%s.c", name, name);
    FILE *f = fopen(cfile, "w");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "#include \"%s/%s.h\"\n", package, name);
    fprintf(f, "void foo() {}\n\n");
    fclose(f);

    sprintf(cfile, "%s/include/%s.h", name, name);
    f = fopen(cfile, "w");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "\nvoid foo();\n\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            name,
            "--silent",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

    return 0;
error:
    return -1;
}

corto_int16 test_Project_use(corto_string package) {
    corto_id cfile;
    corto_int8 ret;
    corto_int16 waitResult;

    sprintf(cfile, "%s/src/%s.c", package, package);
    FILE *f = fopen(cfile, "a");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "\n\nvoid bar() {\n    foo();\n}\n\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            package,
            "--silent",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

    return 0;
error:
    return -1;
}

corto_int16 test_Project_useNoCorto(
    corto_string package,
    corto_string include,
    corto_string includeName)
{
    corto_id cfile;
    corto_int8 ret;
    corto_int16 waitResult;

    sprintf(cfile, "%s/src/%s.c", package, package);
    FILE *f = fopen(cfile, "a");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "#include \"%s/%s.h\"\n", include, includeName);
    fprintf(f, "\n\nvoid bar() {\n    foo();\n}\n\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            package,
            "--silent",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

    return 0;
error:
    return -1;
}
/* $end */

corto_void _test_Project_setup(test_Project this) {
/* $begin(test/Project/setup) */
    test_Project_cleanEnv("Project");
    test_Project_cleanEnv("corto/Project");
    test_Project_cleanEnv("foo");
    test_Project_cleanEnv("bar");
    test_Project_cleanEnv("parent/child");
    test_Project_cleanEnv("parent");

    corto_rmtree("Project");
    corto_rmtree("foo");
    corto_rmtree("bar");
    corto_rmtree("parent");
    corto_rmtree("child");
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
            "--panda",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(corto_fileTest("Project/Project.md"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/src/RedPanda.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));
    test_assert(corto_fileTest("Project/include/RedPanda.h"));
    test_assert(corto_fileTest("Project/include/_api.h"));
    test_assert(corto_fileTest("Project/include/_interface.h"));
    test_assert(corto_fileTest("Project/include/_meta.h"));
    test_assert(corto_fileTest("Project/include/_type.h"));

    test_assert(corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/test/test"));
    test_assert(corto_fileTest("Project/test/rakefile"));
    test_assert(corto_fileTest("Project/test/test.cx"));
    test_assert(corto_fileTest("Project/test/src"));
    test_assert(corto_fileTest("Project/test/src/test.c"));
    test_assert(corto_fileTest("Project/test/src/MySuite.c"));
    test_assert(corto_fileTest("Project/test/include"));
    test_assert(corto_fileTest("Project/test/include/test.h"));
    test_assert(corto_fileTest("Project/test/include/MySuite.h"));
    test_assert(corto_fileTest("Project/test/include/_api.h"));
    test_assert(corto_fileTest("Project/test/include/_interface.h"));
    test_assert(corto_fileTest("Project/test/include/_meta.h"));
    test_assert(corto_fileTest("Project/test/include/_type.h"));

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

corto_void _test_Project_tc_packageDependency(test_Project this) {
/* $begin(test/Project/tc_packageDependency) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create package that will be depended on */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "bar",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "bar",
            "/foo",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("bar/.corto/packages.txt"));
    corto_string str = corto_fileLoad("bar/.corto/packages.txt");
    test_assert(!strcmp(str, "/foo\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("foo"));
    test_assert(!test_Project_use("bar"));

/* $end */
}

corto_void _test_Project_tc_packageDependencyColons(test_Project this) {
/* $begin(test/Project/tc_packageDependencyColons) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create package that will be depended on */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "bar",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "bar",
            "::foo",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("bar/.corto/packages.txt"));
    corto_string str = corto_fileLoad("bar/.corto/packages.txt");
    test_assert(!strcmp(str, "/foo\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("foo"));
    test_assert(!test_Project_use("bar"));
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
            "--panda",
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
    test_assert(!corto_fileTest("Project/Project.md"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/src/RedPanda.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));
    test_assert(corto_fileTest("Project/include/RedPanda.h"));
    test_assert(corto_fileTest("Project/include/_api.h"));
    test_assert(corto_fileTest("Project/include/_interface.h"));
    test_assert(corto_fileTest("Project/include/_meta.h"));
    test_assert(corto_fileTest("Project/include/_type.h"));

    test_assert(!corto_fileTest("Project/test"));

    test_assert(corto_fileTest("Project/.corto"));
    test_assert(corto_fileTest("Project/.corto/libProject.so"));

    test_assert(!corto_fileTest("Project/doc"));

/* $end */
}

corto_void _test_Project_tc_packageNested(test_Project this) {
/* $begin(test/Project/tc_packageNested) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedColons(test_Project this) {
/* $begin(test/Project/tc_packageNestedColons) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent::child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedDependency(test_Project this) {
/* $begin(test/Project/tc_packageNestedDependency) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "foo",
            "parent/child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("foo/.corto/packages.txt"));
    corto_string str = corto_fileLoad("foo/.corto/packages.txt");
    test_assert(!strcmp(str, "/parent/child\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("child"));
    test_assert(!test_Project_use("foo"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyColons(test_Project this) {
/* $begin(test/Project/tc_packageNestedDependencyColons) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "foo",
            "parent::child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("foo/.corto/packages.txt"));
    corto_string str = corto_fileLoad("foo/.corto/packages.txt");
    test_assert(!strcmp(str, "/parent/child\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("child"));
    test_assert(!test_Project_use("foo"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyFullyScoped(test_Project this) {
/* $begin(test/Project/tc_packageNestedDependencyFullyScoped) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "foo",
            "/parent/child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("foo/.corto/packages.txt"));
    corto_string str = corto_fileLoad("foo/.corto/packages.txt");
    test_assert(!strcmp(str, "/parent/child\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("child"));
    test_assert(!test_Project_use("foo"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyFullyScopedColons(test_Project this) {
/* $begin(test/Project/tc_packageNestedDependencyFullyScopedColons) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "foo",
            "::parent::child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("foo/.corto/packages.txt"));
    corto_string str = corto_fileLoad("foo/.corto/packages.txt");
    test_assert(!strcmp(str, "/parent/child\n"));
    corto_dealloc(str);

    /* Add function to foo package */
    test_assert(!test_Project_implement("child"));
    test_assert(!test_Project_use("foo"));

/* $end */
}

corto_void _test_Project_tc_packageNestedFullyScoped(test_Project this) {
/* $begin(test/Project/tc_packageNestedFullyScoped) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "/parent",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "/parent/child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedFullyScopedColons(test_Project this) {
/* $begin(test/Project/tc_packageNestedFullyScopedColons) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "::parent",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "::parent::child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNoCorto(test_Project this) {
/* $begin(test/Project/tc_packageNoCorto) */
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
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(!corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(!corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/doc"));

    test_assert(!corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/packages/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/packages/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    /* Create a source file */
    FILE *f = fopen("Project/src/Project.c", "w");
    fprintf(f, "\nvoid foo(void) {}\n\n");
    fclose(f);

    /* Rebuild project */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "build",
            "Project",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Validate that library is present */
    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/packages/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/packages/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoDependency(test_Project this) {
/* $begin(test/Project/tc_packageNoCortoDependency) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "bar",
            "--silent",
            "--notest",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Implement before adding the package. If there's no implementation, there
     * is nothing to be built */
    test_assert(!test_Project_implementNoCorto("foo", "foo"));

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "bar",
            "foo",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("bar/.corto/packages.txt"));
    corto_string str = corto_fileLoad("bar/.corto/packages.txt");
    test_assert(!strcmp(str, "/foo\n"));
    corto_dealloc(str);

    /* Add implementation */
    test_assert(!test_Project_useNoCorto("bar", "foo", "foo"));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoNested(test_Project this) {
/* $begin(test/Project/tc_packageNoCortoNested) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create package in /corto */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "corto::Project",
            "--silent",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(!corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(!corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/doc"));

    test_assert(!corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/packages/corto/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/packages/corto/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    /* Create a source file */
    FILE *f = fopen("Project/src/Project.c", "w");
    fprintf(f, "\nvoid foo(void) {}\n\n");
    fclose(f);

    /* Rebuild project */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "build",
            "Project",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Validate that library is present */
    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/packages/corto/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/packages/corto/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoNestedDependency(test_Project this) {
/* $begin(test/Project/tc_packageNoCortoNestedDependency) */
    corto_int8 ret;
    corto_int16 waitResult;

    /* Create nested package */
    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent",
            "--silent",
            "--notest",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "parent/child",
            "--silent",
            "--notest",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create package that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "foo",
            "--silent",
            "--notest",
            "--nocorto",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Implement before adding the package. If there's no implementation, there
     * is nothing to be built */
    test_assert(!test_Project_implementNoCorto("child", "parent/child"));

    /* Add package dependency */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "add",
            "foo",
            "parent/child",
            "--silent",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* If test is still running, it means the package builds */

    /* Test package.txt */
    test_assert(corto_fileTest("foo/.corto/packages.txt"));
    corto_string str = corto_fileLoad("foo/.corto/packages.txt");
    test_assert(!strcmp(str, "/parent/child\n"));
    corto_dealloc(str);

    /* Add implementation */
    test_assert(!test_Project_useNoCorto("foo", "parent/child", "child"));

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
    test_Project_cleanEnv("Project");
    test_Project_cleanEnv("corto/Project");
    test_Project_cleanEnv("foo");
    test_Project_cleanEnv("bar");
    test_Project_cleanEnv("parent/child");
    test_Project_cleanEnv("parent");

    corto_rmtree("Project");
    corto_rmtree("foo");
    corto_rmtree("bar");
    corto_rmtree("parent");
    corto_rmtree("child");
/* $end */
}
