/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Args_tc_matchAddNoProject(
    test_Args this)
{
    char *argv[] = {"add", "::corto::test", "--silent", NULL};
    corto_ll project, packages, silent;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL},
        {"--silent", &silent, NULL},
        {"$?*", &project, NULL},
        {"$+*", &packages, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(silent != NULL);
    test_assert(project == NULL);
    test_assert(packages != NULL);

    test_assert(corto_ll_size(silent) == 1);
    test_assert(corto_ll_size(packages) == 1);

    test_assertstr(corto_ll_get(silent, 0), "--silent");
    test_assertstr(corto_ll_get(packages, 0), "::corto::test");

    corto_argclean(data);

}

void test_Args_tc_matchAll(
    test_Args this)
{
    char *argv[] = {"abc", "def", "-g", "--hi", NULL};
    corto_ll args;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"*", &args, NULL},
        {"-*", &args, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);
    test_assert(args != NULL);
    test_assert(corto_ll_size(args) == 4);
    test_assert(!strcmp(corto_ll_get(args, 0), "abc"));
    test_assert(!strcmp(corto_ll_get(args, 1), "def"));
    test_assert(!strcmp(corto_ll_get(args, 2), "-g"));
    test_assert(!strcmp(corto_ll_get(args, 3), "--hi"));

    corto_argclean(data);

}

void test_Args_tc_matchCreate(
    test_Args this)
{
    char *argv[] = {"create", "MyApp", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(app != NULL);
    test_assert(corto_ll_size(app) == 1);
    test_assert(!strcmp(corto_ll_get(app, 0), "MyApp"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreateApp(
    test_Args this)
{
    char *argv[] = {"create", "app", "MyApp", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(app != NULL);
    test_assert(corto_ll_size(app) == 1);
    test_assert(!strcmp(corto_ll_get(app, 0), "MyApp"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreateMultiple(
    test_Args this)
{
    char *argv[] = {"create", "app", "MyApp1", "MyApp2", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(app != NULL);
    test_assert(corto_ll_size(app) == 2);
    test_assert(!strcmp(corto_ll_get(app, 0), "MyApp1"));
    test_assert(!strcmp(corto_ll_get(app, 1), "MyApp2"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreatePackage(
    test_Args this)
{
    char *argv[] = {"create", "package", "myPackage", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(package != NULL);
    test_assert(corto_ll_size(package) == 1);
    test_assert(!strcmp(corto_ll_get(package, 0), "myPackage"));

    test_assert(app == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreatePackageAndApp(
    test_Args this)
{
    char *argv[] = {"create", "package", "myPackage", "app", "MyApp", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(package != NULL);
    test_assert(corto_ll_size(package) == 1);
    test_assert(!strcmp(corto_ll_get(package, 0), "myPackage"));

    test_assert(app != NULL);
    test_assert(corto_ll_size(app) == 1);
    test_assert(!strcmp(corto_ll_get(app, 0), "MyApp"));

    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreatePackageAndAppEscaped(
    test_Args this)
{
    char *argv[] = {"create", "package", "package", "app", "app", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(package != NULL);
    test_assert(corto_ll_size(package) == 1);
    test_assert(!strcmp(corto_ll_get(package, 0), "package"));

    test_assert(app != NULL);
    test_assert(corto_ll_size(app) == 1);
    test_assert(!strcmp(corto_ll_get(app, 0), "app"));

    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchCreatePackageOptions(
    test_Args this)
{
    char *argv[] = {"create", "package", "myPackage", "--silent", "--notest", "--local", NULL};
    corto_ll app, package, component, silent, notest, local;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"app", NULL, &app},
        {"package", NULL, &package},
        {"component", NULL, &component},
        {"--silent", &silent, NULL},
        {"--notest", &notest, NULL},
        {"--local", &local, NULL},
        {"*", &app, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(package != NULL);
    test_assert(corto_ll_size(package) == 1);
    test_assert(!strcmp(corto_ll_get(package, 0), "myPackage"));

    test_assert(silent != NULL);
    test_assert(corto_ll_size(silent) == 1);
    test_assert(!strcmp(corto_ll_get(silent, 0), "--silent"));

    test_assert(notest != NULL);
    test_assert(corto_ll_size(notest) == 1);
    test_assert(!strcmp(corto_ll_get(notest, 0), "--notest"));

    test_assert(local != NULL);
    test_assert(corto_ll_size(local) == 1);
    test_assert(!strcmp(corto_ll_get(local, 0), "--local"));

    test_assert(app == NULL);
    test_assert(component == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchDuplicate(
    test_Args this)
{
    char *argv[] = {"abc", "def", "abc", "def", NULL};
    corto_ll abc, def;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"abc", &abc, NULL},
        {"def", &def, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(abc != NULL);
    test_assert(corto_ll_size(abc) == 2);

    test_assert(def != NULL);
    test_assert(corto_ll_size(def) == 2);

    test_assert(!strcmp(corto_ll_get(abc, 0), "abc"));
    test_assert(!strcmp(corto_ll_get(abc, 1), "abc"));
    test_assert(!strcmp(corto_ll_get(def, 0), "def"));
    test_assert(!strcmp(corto_ll_get(def, 1), "def"));

    corto_argclean(data);

}

void test_Args_tc_matchDuplicateArg(
    test_Args this)
{
    char *argv[] = {"--option1", "arg1", "--option1", "arg2", "--option2", "arg3", NULL};
    corto_ll option1, option2, args1, args2;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"--option1", &option1, &args1},
        {"--option2", &option2, &args2},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(option1 != NULL);
    test_assert(corto_ll_size(option1) == 2);

    test_assert(option2 != NULL);
    test_assert(corto_ll_size(option2) == 1);

    test_assert(!strcmp(corto_ll_get(option1, 0), "--option1"));
    test_assert(!strcmp(corto_ll_get(option1, 1), "--option1"));
    test_assert(!strcmp(corto_ll_get(option2, 0), "--option2"));

    test_assert(args1 != NULL);
    test_assert(corto_ll_size(args1) == 2);

    test_assert(args2 != NULL);
    test_assert(corto_ll_size(args2) == 1);

    test_assert(!strcmp(corto_ll_get(args1, 0), "arg1"));
    test_assert(!strcmp(corto_ll_get(args1, 1), "arg2"));
    test_assert(!strcmp(corto_ll_get(args2, 0), "arg3"));

    corto_argclean(data);

}

void test_Args_tc_matchErr(
    test_Args this)
{
    char *argv[] = {"abc", "def", NULL};
    corto_ll args;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"efg", &args, NULL},
        {NULL}
      }
    );

    test_assert(data == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "unknown option 'abc'"));

}

void test_Args_tc_matchFixed(
    test_Args this)
{
    char *argv[] = {"a", "b", "c", "d", NULL};
    corto_ll a, b, c, d;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", &a, NULL},
        {"$1", &b, NULL},
        {"$2", &c, NULL},
        {"$3", &d, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(a != NULL);
    test_assert(corto_ll_size(a) == 1);

    test_assert(b != NULL);
    test_assert(corto_ll_size(b) == 1);

    test_assert(c != NULL);
    test_assert(corto_ll_size(c) == 1);

    test_assert(d != NULL);
    test_assert(corto_ll_size(d) == 1);

    test_assert(!strcmp(corto_ll_get(a, 0), "a"));
    test_assert(!strcmp(corto_ll_get(b, 0), "b"));
    test_assert(!strcmp(corto_ll_get(c, 0), "c"));
    test_assert(!strcmp(corto_ll_get(d, 0), "d"));

    corto_argclean(data);

}

void test_Args_tc_matchMultiple(
    test_Args this)
{
    char *argv[] = {"abc", "def", NULL};
    corto_ll abc, def;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"abc", &abc, NULL},
        {"def", &def, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(abc != NULL);
    test_assert(corto_ll_size(abc) == 1);

    test_assert(def != NULL);
    test_assert(corto_ll_size(def) == 1);

    test_assert(!strcmp(corto_ll_get(abc, 0), "abc"));
    test_assert(!strcmp(corto_ll_get(def, 0), "def"));

    corto_argclean(data);

}

void test_Args_tc_matchMultipleArg(
    test_Args this)
{
    char *argv[] = {"--option1", "arg1", "--option2", "arg2", NULL};
    corto_ll option1, option2, args1, args2;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"--option1", &option1, &args1},
        {"--option2", &option2, &args2},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(option1 != NULL);
    test_assert(corto_ll_size(option1) == 1);

    test_assert(option2 != NULL);
    test_assert(corto_ll_size(option2) == 1);

    test_assert(!strcmp(corto_ll_get(option1, 0), "--option1"));
    test_assert(!strcmp(corto_ll_get(option2, 0), "--option2"));

    test_assert(args1 != NULL);
    test_assert(corto_ll_size(args1) == 1);

    test_assert(args2 != NULL);
    test_assert(corto_ll_size(args2) == 1);

    test_assert(!strcmp(corto_ll_get(args1, 0), "arg1"));
    test_assert(!strcmp(corto_ll_get(args2, 0), "arg2"));

    corto_argclean(data);

}

void test_Args_tc_matchNone(
    test_Args this)
{
    char *argv[] = {"abc", "def", NULL};

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"abc", NULL, NULL},
        {"def", NULL, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);
    test_assert(corto_lasterr() == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchOptional(
    test_Args this)
{
    char *argv[] = {"ab", "cd", "ef", NULL};
    corto_ll atMostOnce, atLeastOnce;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$?*", &atMostOnce, NULL},
        {"$+*", &atLeastOnce, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(atMostOnce != NULL);
    test_assert(corto_ll_size(atMostOnce) == 1);

    test_assert(atLeastOnce != NULL);
    test_assert(corto_ll_size(atLeastOnce) == 2);

    test_assert(!strcmp(corto_ll_get(atMostOnce, 0), "ab"));
    test_assert(!strcmp(corto_ll_get(atLeastOnce, 0), "cd"));
    test_assert(!strcmp(corto_ll_get(atLeastOnce, 1), "ef"));

    corto_argclean(data);

}

void test_Args_tc_matchOptionalOneArg(
    test_Args this)
{
    char *argv[] = {"ab", NULL};
    corto_ll atMostOnce, atLeastOnce;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$?*", &atMostOnce, NULL},
        {"$+*", &atLeastOnce, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(atMostOnce == NULL);
    test_assert(atLeastOnce != NULL);
    test_assert(corto_ll_size(atLeastOnce) == 1);

    test_assert(!strcmp(corto_ll_get(atLeastOnce, 0), "ab"));

    corto_argclean(data);

}

void test_Args_tc_matchOptionalWithOtherArgs(
    test_Args this)
{
    char *argv[] = {"ab", "other", NULL};
    corto_ll atMostOnce, atLeastOnce, other;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"other", &other, NULL},
        {"$?*", &atMostOnce, NULL},
        {"$+*", &atLeastOnce, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(other != NULL);
    test_assert(atMostOnce == NULL);
    test_assert(atLeastOnce != NULL);

    test_assert(corto_ll_size(other) == 1);
    test_assert(corto_ll_size(atLeastOnce) == 1);

    test_assert(!strcmp(corto_ll_get(other, 0), "other"));
    test_assert(!strcmp(corto_ll_get(atLeastOnce, 0), "ab"));

    corto_argclean(data);

}

void test_Args_tc_matchPattern(
    test_Args this)
{
    char *argv[] = {"abcd", "bacd", NULL};
    corto_ll args;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"*cd", &args, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(args != NULL);
    test_assert(corto_ll_size(args) == 2);

    test_assert(!strcmp(corto_ll_get(args, 0), "abcd"));
    test_assert(!strcmp(corto_ll_get(args, 1), "bacd"));

    corto_argclean(data);

}

void test_Args_tc_matchPublish(
    test_Args this)
{
    char *argv[] = {"publish", "MyApp", "major", "--notag", NULL};
    corto_ll notag, dirs, majorarg, minorarg, patcharg;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'publish' argument */
        {"--notag", &notag, NULL},
        {"$?*", &dirs, NULL},
        {"$+major", &majorarg, NULL},
        {"$|minor", &minorarg, NULL},
        {"$|patch", &patcharg, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(notag != NULL);
    test_assert(majorarg != NULL);
    test_assert(minorarg == NULL);
    test_assert(patcharg == NULL);

    test_assert(dirs != NULL);
    test_assert(!strcmp(corto_ll_get(dirs, 0), "MyApp"));

    corto_argclean(data);

}

void test_Args_tc_matchPublishNoProject(
    test_Args this)
{
    char *argv[] = {"publish", "major", "--notag", NULL};
    corto_ll notag, dirs, majorarg, minorarg, patcharg;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'publish' argument */
        {"--notag", &notag, NULL},
        {"$?*", &dirs, NULL},
        {"$+major", &majorarg, NULL},
        {"$|minor", &minorarg, NULL},
        {"$|patch", &patcharg, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(notag != NULL);
    test_assert(majorarg != NULL);
    test_assert(minorarg == NULL);
    test_assert(patcharg == NULL);
    test_assert(dirs == NULL);

    corto_argclean(data);

}

void test_Args_tc_matchShell(
    test_Args this)
{
    char *argv[] = {"shell", "-p", "corto/idl", "test.cx", "-d", "test2.cx", NULL};
    corto_ll pp, d, load;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore first argument */
        {"-p", NULL, &pp},
        {"-d", &d, NULL},
        {"*", &load, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(pp != NULL);
    test_assert(corto_ll_size(pp) == 1);
    test_assert(!strcmp(corto_ll_get(pp, 0), "corto/idl"));

    test_assert(d != NULL);
    test_assert(corto_ll_size(d) == 1);
    test_assert(!strcmp(corto_ll_get(d, 0), "-d"));

    test_assert(load != NULL);
    test_assert(corto_ll_size(load) == 2);
    test_assert(!strcmp(corto_ll_get(load, 0), "test.cx"));
    test_assert(!strcmp(corto_ll_get(load, 1), "test2.cx"));

    corto_argclean(data);

}

void test_Args_tc_matchSingle(
    test_Args this)
{
    char *argv[] = {"abc", NULL};
    corto_ll abc;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"abc", &abc, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(abc != NULL);
    test_assert(corto_ll_size(abc) == 1);

    test_assert(!strcmp(corto_ll_get(abc, 0), "abc"));

    corto_argclean(data);

}

void test_Args_tc_matchSingleArg(
    test_Args this)
{
    char *argv[] = {"--option", "arg", NULL};
    corto_ll options, args;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"--option", &options, &args},
        {NULL}
      }
    );

    test_assert(data != NULL);

    test_assert(options != NULL);
    test_assert(corto_ll_size(options) == 1);

    test_assert(args != NULL);
    test_assert(corto_ll_size(args) == 1);

    test_assert(!strcmp(corto_ll_get(options, 0), "--option"));
    test_assert(!strcmp(corto_ll_get(args, 0), "arg"));

    corto_argclean(data);

}

