/* $CORTO_GENERATED
 *
 * Application.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
corto_int16 test_Project_cleanEnv(corto_string name);
corto_int16 test_Project_implement(corto_string package);
corto_int16 test_Project_implementNoCorto(
    corto_string name,
    corto_string package,
    corto_bool local);

void test_Project_load(corto_string target, corto_string fullname);
corto_int16 test_Project_use(corto_string target, corto_string fullname, corto_string dependency);
corto_int16 test_Project_useNoCorto(
    corto_string package,
    corto_string include,
    corto_string includeName);

/* $end */

void _test_Application_setup(
    test_Application this)
{
/* $begin(test/Application/setup) */
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

    corto_time timeout = {10, 0};
    test_setTimeout(&timeout);
/* $end */
}

void _test_Application_tc_app(
    test_Application this)
{
/* $begin(test/Application/tc_app) */
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

void _test_Application_tc_appCortoDependencyNoCorto(
    test_Application this)
{
/* $begin(test/Application/tc_appCortoDependencyNoCorto) */
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
            "--notest",
            "--unmanaged",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create application that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "bar",
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

    /* Add function to foo application */
    test_assert(!test_Project_implementNoCorto("foo", "foo", FALSE));
    test_assert(!test_Project_useNoCorto("bar", "foo", "foo"));

/* $end */
}

void _test_Application_tc_appCortoNestedDependencyNoCorto(
    test_Application this)
{
/* $begin(test/Application/tc_appCortoNestedDependencyNoCorto) */
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
            "--unmanaged",
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
            "--unmanaged",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create application that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
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

    /* Add function to foo application */
    test_assert(!test_Project_implementNoCorto("child", "parent/child", FALSE));
    test_assert(!test_Project_useNoCorto("foo", "parent/child", "child"));

/* $end */
}

void _test_Application_tc_appDef(
    test_Application this)
{
/* $begin(test/Application/tc_appDef) */
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

    /* Create definition file */
    FILE *f = fopen("Project/Project.cx", "w");
    fprintf(f, "#package /Project\n\n");
    fprintf(f, "struct Point::\n");
    fprintf(f, "    x, y: int32\n");
    fprintf(f, "    void add(Point p)\n");
    fclose(f);

    pid = corto_procrun(
        "corto",
        (char*[]){"corto", "rebuild", "Project", "--silent", NULL});

    test_assert(pid != 0);
    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project/include"));
    test_assert(corto_fileTest("Project/include/Project.h"));
    test_assert(corto_fileTest("Project/src/Point.c"));

/* $end */
}

void _test_Application_tc_appDependency(
    test_Application this)
{
/* $begin(test/Application/tc_appDependency) */
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
            "--notest",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create application that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "bar",
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

    /* Add function to foo application */
    test_assert(!test_Project_implement("foo"));
    test_assert(!test_Project_use("bar", NULL, "foo"));

/* $end */
}

void _test_Application_tc_appNested(
    test_Application this)
{
/* $begin(test/Application/tc_appNested) */
    corto_int8 ret;
    corto_int16 waitResult;

    corto_pid pid = corto_procrun(
        "corto",
        (char*[]){"corto", "create", "corto/Project", "--silent", NULL});

    test_assert(pid != 0);
    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    test_assert(corto_fileTest("Project"));
    test_assert(corto_fileTest("Project/rakefile"));
    test_assert(corto_fileTest("Project/src"));
    test_assert(corto_fileTest("Project/src/Project.c"));
    test_assert(corto_fileTest("Project/test"));

    pid = corto_procrunRedirect(
        "corto",
        (char*[]){"corto", "run", "Project", NULL},
        stdin, NULL, stderr);

    test_assert(pid != 0);
    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    pid = corto_procrunRedirect(
        "corto",
        (char*[]){"corto", "run", "corto/Project", NULL},
        stdin, NULL, stderr);

    test_assert(pid != 0);
    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

/* $end */
}

void _test_Application_tc_appNestedDependency(
    test_Application this)
{
/* $begin(test/Application/tc_appNestedDependency) */
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

    /* Create application that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
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

    /* Add function to foo application */
    test_assert(!test_Project_implement("child"));
    test_assert(!test_Project_use("foo", NULL, "child"));

/* $end */
}

void _test_Application_tc_appNoCortoDependency(
    test_Application this)
{
/* $begin(test/Application/tc_appNoCortoDependency) */
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
            "--notest",
            "--unmanaged",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create application that will depend on foo */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "bar",
            "--silent",
            "--notest",
            "--unmanaged",
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

    /* Add function to foo application */
    test_assert(!test_Project_implementNoCorto("foo", "foo", FALSE));
    test_assert(!test_Project_useNoCorto("bar", "foo", "foo"));

/* $end */
}

void _test_Application_tc_appNoCortoNestedDependency(
    test_Application this)
{
/* $begin(test/Application/tc_appNoCortoNestedDependency) */
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
            "--unmanaged",
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
            "--unmanaged",
            NULL
        });

    test_assert(pid != 0);

    waitResult = corto_procwait(pid, &ret);
    test_assert(waitResult == 0);
    test_assert(ret == 0);

    /* Create application that will depend on parent/child */
    pid = corto_procrun(
        "corto",
        (char*[]){
            "corto",
            "create",
            "foo",
            "--silent",
            "--notest",
            "--unmanaged",
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

    /* Add function to foo application */
    test_assert(!test_Project_implementNoCorto("child", "parent/child", FALSE));
    test_assert(!test_Project_useNoCorto("foo", "parent/child", "child"));

/* $end */
}

void _test_Application_tc_appNoTest(
    test_Application this)
{
/* $begin(test/Application/tc_appNoTest) */
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

void _test_Application_teardown(
    test_Application this)
{
/* $begin(test/Application/teardown) */
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
