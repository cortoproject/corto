/* $CORTO_GENERATED
 *
 * Project.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

/* $header() */
corto_int16 test_Project_cleanEnv(corto_string name) {
    char *env;

    env = corto_envparse(
      "$HOME/.corto/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, name);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/lib/corto/<version>/<project>");
        goto error;
    }
    corto_rmtree(env);
    corto_dealloc(env);

    env = corto_envparse(
      "$HOME/.corto/include/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, name);
    if (!env) {
        test_fail(
          "failed to clean $HOME/.corto/include/corto/<version>/<project>");
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
            "--nocoverage",
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
    corto_string package,
    corto_bool local)
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
    if (!local) {
        fprintf(f, "#include \"%s/%s.h\"\n", package, name);
    } else {
        fprintf(f, "#include \"%s.h\"\n", name);
    }
    fprintf(f, "void foo(void) {}\n\n");
    fclose(f);

    sprintf(cfile, "%s/include/%s.h", name, name);
    f = fopen(cfile, "w");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "\nvoid foo(void);\n\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            name,
            "--silent",
            "--nocoverage",
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

void test_Project_load(corto_string target, corto_string fullname) {
    corto_int8 ret;
    corto_int16 waitResult;

    if (fullname) {
       corto_string location = corto_locate(fullname, CORTO_LOCATION_LIB);
       test_assert(location != NULL);

       /* If target is a library, load library with Corto to ensure that all
        * symbols can be resolved */
       corto_pid pid = corto_procrun(
           "corto",
           (char*[]){
               "corto",
               location,
                NULL
            });

            test_assert(pid != 0);

        waitResult = corto_procwait(pid, &ret);
        test_assert(waitResult == 0);
        test_assert(ret == 0);
    }
}

corto_int16 test_Project_use(corto_string target, corto_string fullname, corto_string dependency) {
    corto_id cfile;
    corto_int8 ret;
    corto_int16 waitResult;

    sprintf(cfile, "%s/src/%s.c", target, target);
    FILE *f = fopen(cfile, "a");
    if (!f) {
        goto error;
    }

    /* Add function and rebuild */
    fprintf(f, "\n\nvoid bar(void) {\n    %s_foo();\n}\n\n", dependency);
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            target,
            "--silent",
            "--nocoverage",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

     test_Project_load(target, fullname);

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
    fprintf(f, "\n\nvoid bar(void) {\n    foo();\n}\n\n");
    fclose(f);

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            package,
            "--silent",
            "--nocoverage",
             NULL
         });

     test_assert(pid != 0);

     waitResult = corto_procwait(pid, &ret);
     test_assert(waitResult == 0);
     test_assert(ret == 0);

     test_Project_load(package, include);

    return 0;
error:
    return -1;
}
/* $end */

corto_void _test_Project_setup(
    test_Project this)
{
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

    corto_time timeout = {20, 0};
    test_setTimeout(&timeout);
/* $end */
}

corto_void _test_Project_tc_packageCortoDependencyNoCorto(
    test_Project this)
{
/* $begin(test/Project/tc_packageCortoDependencyNoCorto) */
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_implementNoCorto("foo", "foo", FALSE));
    test_assert(!test_Project_useNoCorto("bar", "/bar", "foo"));

/* $end */
}

corto_void _test_Project_tc_packageCortoNestedDependencyNoCorto(
    test_Project this)
{
/* $begin(test/Project/tc_packageCortoNestedDependencyNoCorto) */
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_implementNoCorto("child", "parent/child", FALSE));
    test_assert(!test_Project_useNoCorto("foo", "parent/child", "child"));

/* $end */
}

corto_void _test_Project_tc_packageDependency(
    test_Project this)
{
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
            "--nocoverage",
            "--notest",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("bar", "/bar", "foo"));

/* $end */
}

corto_void _test_Project_tc_packageDependencyColons(
    test_Project this)
{
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
            "--nocoverage",
            "--notest",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("bar", "/bar", "foo"));
/* $end */
}

corto_void _test_Project_tc_packageNested(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedColons(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedDependency(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("foo", "/foo", "child"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyColons(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("foo", "/foo", "child"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyFullyScoped(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("foo", "/foo", "child"));

/* $end */
}

corto_void _test_Project_tc_packageNestedDependencyFullyScopedColons(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_use("foo", "/foo", "child"));

/* $end */
}

corto_void _test_Project_tc_packageNestedFullyScoped(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNestedFullyScopedColons(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Project_tc_packageNoCorto(
    test_Project this)
{
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
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(!corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/doc"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
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
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Validate that library is present */
    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoDependency(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_implementNoCorto("foo", "foo", FALSE));

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

corto_void _test_Project_tc_packageNoCortoLocal(
    test_Project this)
{
/* $begin(test/Project/tc_packageNoCortoLocal) */
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
            "--nocoverage",
            "--nocorto",
            "--local",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Implement before adding the package. If there's no implementation, there
     * is nothing to be built */
    test_assert(!test_Project_implementNoCorto("foo", "foo", TRUE));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoNested(
    test_Project this)
{
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
            "--nocoverage",
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
    test_assert(corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(!corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/doc"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/corto/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/corto/Project/libProject.so",
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
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Validate that library is present */
    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/corto/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/corto/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNoCortoNestedDependency(
    test_Project this)
{
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
            "--nocoverage",
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
            "--nocoverage",
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
            "--nocoverage",
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
    test_assert(!test_Project_implementNoCorto("child", "parent/child", FALSE));

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

corto_void _test_Project_tc_packageNodef(
    test_Project this)
{
/* $begin(test/Project/tc_packageNodef) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--nodef",
            "--silent",
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(!corto_fileTest("Project/Project.md"));
    test_assert(!corto_fileTest("Project/Project.cx"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));

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

    test_assert(!corto_fileTest("Project/doc"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNodefC4cpp(
    test_Project this)
{
/* $begin(test/Project/tc_packageNodefC4cpp) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--nodef",
            "--silent",
            "--nocoverage",
            "--lang",
            "c4cpp",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(!corto_fileTest("Project/Project.md"));
    test_assert(!corto_fileTest("Project/Project.cx"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.cpp"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));

    test_assert(corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/test/test"));
    test_assert(corto_fileTest("Project/test/rakefile"));
    test_assert(corto_fileTest("Project/test/test.cx"));
    test_assert(corto_fileTest("Project/test/src"));
    test_assert(corto_fileTest("Project/test/src/test.cpp"));
    test_assert(corto_fileTest("Project/test/src/MySuite.cpp"));
    test_assert(corto_fileTest("Project/test/include"));
    test_assert(corto_fileTest("Project/test/include/test.h"));
    test_assert(corto_fileTest("Project/test/include/MySuite.h"));
    test_assert(corto_fileTest("Project/test/include/_api.h"));
    test_assert(corto_fileTest("Project/test/include/_interface.h"));
    test_assert(corto_fileTest("Project/test/include/_meta.h"));
    test_assert(corto_fileTest("Project/test/include/_type.h"));

    test_assert(corto_fileTest("Project/.corto"));
    test_assert(!corto_fileTest("Project/.corto/libProject.so"));

    test_assert(!corto_fileTest("Project/doc"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNodefLocal(
    test_Project this)
{
/* $begin(test/Project/tc_packageNodefLocal) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--nodef",
            "--local",
            "--silent",
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(!corto_fileTest("Project/Project.md"));
    test_assert(!corto_fileTest("Project/Project.cx"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));

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
    test_assert(corto_fileTest("Project/.corto/libProject.so"));

    test_assert(!corto_fileTest("Project/doc"));

    test_assert(!corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packageNodefLocalC4cpp(
    test_Project this)
{
/* $begin(test/Project/tc_packageNodefLocalC4cpp) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--nodef",
            "--local",
            "--silent",
            "--nocoverage",
            "--lang",
            "c4cpp",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(!corto_fileTest("Project/Project.md"));
    test_assert(!corto_fileTest("Project/Project.cx"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.cpp"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));

    test_assert(corto_fileTest("Project/test"));
    test_assert(!corto_fileTest("Project/test/test"));
    test_assert(corto_fileTest("Project/test/rakefile"));
    test_assert(corto_fileTest("Project/test/test.cx"));
    test_assert(corto_fileTest("Project/test/src"));
    test_assert(corto_fileTest("Project/test/src/test.cpp"));
    test_assert(corto_fileTest("Project/test/src/MySuite.cpp"));
    test_assert(corto_fileTest("Project/test/include"));
    test_assert(corto_fileTest("Project/test/include/test.h"));
    test_assert(corto_fileTest("Project/test/include/MySuite.h"));
    test_assert(corto_fileTest("Project/test/include/_api.h"));
    test_assert(corto_fileTest("Project/test/include/_interface.h"));
    test_assert(corto_fileTest("Project/test/include/_meta.h"));
    test_assert(corto_fileTest("Project/test/include/_type.h"));

    test_assert(corto_fileTest("Project/.corto"));
    test_assert(corto_fileTest("Project/.corto/libProject.so"));

    test_assert(!corto_fileTest("Project/doc"));

    test_assert(!corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(!corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_packagePublicHeaderRemoval(
    test_Project this)
{
/* $begin(test/Project/tc_packagePublicHeaderRemoval) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "package",
            "Project",
            "--nocorto",
            "--silent",
            "--nocoverage",
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));

    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));

    test_assert(corto_fileTest(
        "$HOME/.corto/lib/corto/%s.%s/Project",
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/lib/corto/%s.%s/Project/libProject.so",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/Project.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    /* Create new include file */
    FILE *include = fopen("Project/include/MyInclude.h", "w");
    test_assert(include != NULL);
    fclose(include);

    /* Rebuild project */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            "Project",
            "--silent",
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Test if header is installed */
    test_assert(corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/MyInclude.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

    /* Remove header from project */
    ret = corto_rm("Project/include/MyInclude.h");
    test_assert(ret == 0);

    /* Rebuild project */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "rebuild",
            "Project",
            "--silent",
            "--nocoverage",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Verify header file is no longer installed in environment */
    test_assert(!corto_fileTest(
      "$HOME/.corto/include/corto/%s.%s/Project/MyInclude.h",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR));

/* $end */
}

corto_void _test_Project_tc_publishNotag(
    test_Project this)
{
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
            "--nocoverage",
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

corto_void _test_Project_teardown(
    test_Project this)
{
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
