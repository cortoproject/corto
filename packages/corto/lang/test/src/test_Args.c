/* $CORTO_GENERATED
 *
 * test_Args.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Args_tc_matchAll(test_Args this) {
/* $begin(test/Args/tc_matchAll) */
    char *argv[] = {"abc", "def", "-g", "--hi", NULL};
    corto_ll args;

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"*", &args, NULL},
        {NULL}
      }
    );

    test_assert(data != NULL);
    test_assert(args != NULL);
    test_assert(corto_llSize(args) == 4);
    test_assert(!strcmp(corto_llGet(args, 0), "abc"));
    test_assert(!strcmp(corto_llGet(args, 1), "def"));
    test_assert(!strcmp(corto_llGet(args, 2), "-g"));
    test_assert(!strcmp(corto_llGet(args, 3), "--hi"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreate(test_Args this) {
/* $begin(test/Args/tc_matchCreate) */
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
    test_assert(corto_llSize(app) == 1);
    test_assert(!strcmp(corto_llGet(app, 0), "MyApp"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreateApp(test_Args this) {
/* $begin(test/Args/tc_matchCreateApp) */
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
    test_assert(corto_llSize(app) == 1);
    test_assert(!strcmp(corto_llGet(app, 0), "MyApp"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreateMultiple(test_Args this) {
/* $begin(test/Args/tc_matchCreateMultiple) */
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
    test_assert(corto_llSize(app) == 2);
    test_assert(!strcmp(corto_llGet(app, 0), "MyApp1"));
    test_assert(!strcmp(corto_llGet(app, 1), "MyApp2"));

    test_assert(package == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreatePackage(test_Args this) {
/* $begin(test/Args/tc_matchCreatePackage) */
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
    test_assert(corto_llSize(package) == 1);
    test_assert(!strcmp(corto_llGet(package, 0), "myPackage"));

    test_assert(app == NULL);
    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreatePackageAndApp(test_Args this) {
/* $begin(test/Args/tc_matchCreatePackageAndApp) */
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
    test_assert(corto_llSize(package) == 1);
    test_assert(!strcmp(corto_llGet(package, 0), "myPackage"));

    test_assert(app != NULL);
    test_assert(corto_llSize(app) == 1);
    test_assert(!strcmp(corto_llGet(app, 0), "MyApp"));

    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreatePackageAndAppEscaped(test_Args this) {
/* $begin(test/Args/tc_matchCreatePackageAndAppEscaped) */
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
    test_assert(corto_llSize(package) == 1);
    test_assert(!strcmp(corto_llGet(package, 0), "package"));

    test_assert(app != NULL);
    test_assert(corto_llSize(app) == 1);
    test_assert(!strcmp(corto_llGet(app, 0), "app"));

    test_assert(component == NULL);
    test_assert(silent == NULL);
    test_assert(notest == NULL);
    test_assert(local == NULL);

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchCreatePackageOptions(test_Args this) {
/* $begin(test/Args/tc_matchCreatePackageOptions) */
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
    test_assert(corto_llSize(package) == 1);
    test_assert(!strcmp(corto_llGet(package, 0), "myPackage"));

    test_assert(silent != NULL);
    test_assert(corto_llSize(silent) == 1);
    test_assert(!strcmp(corto_llGet(silent, 0), "--silent"));

    test_assert(notest != NULL);
    test_assert(corto_llSize(notest) == 1);
    test_assert(!strcmp(corto_llGet(notest, 0), "--notest"));

    test_assert(local != NULL);
    test_assert(corto_llSize(local) == 1);
    test_assert(!strcmp(corto_llGet(local, 0), "--local"));

    test_assert(app == NULL);
    test_assert(component == NULL);
    
    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchDuplicate(test_Args this) {
/* $begin(test/Args/tc_matchDuplicate) */
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
    test_assert(corto_llSize(abc) == 2);

    test_assert(def != NULL);
    test_assert(corto_llSize(def) == 2);

    test_assert(!strcmp(corto_llGet(abc, 0), "abc"));
    test_assert(!strcmp(corto_llGet(abc, 1), "abc"));
    test_assert(!strcmp(corto_llGet(def, 0), "def"));
    test_assert(!strcmp(corto_llGet(def, 1), "def"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchDuplicateArg(test_Args this) {
/* $begin(test/Args/tc_matchDuplicateArg) */
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
    test_assert(corto_llSize(option1) == 2);

    test_assert(option2 != NULL);
    test_assert(corto_llSize(option2) == 1);

    test_assert(!strcmp(corto_llGet(option1, 0), "--option1"));
    test_assert(!strcmp(corto_llGet(option1, 1), "--option1"));
    test_assert(!strcmp(corto_llGet(option2, 0), "--option2"));

    test_assert(args1 != NULL);
    test_assert(corto_llSize(args1) == 2);

    test_assert(args2 != NULL);
    test_assert(corto_llSize(args2) == 1);

    test_assert(!strcmp(corto_llGet(args1, 0), "arg1"));
    test_assert(!strcmp(corto_llGet(args1, 1), "arg2"));
    test_assert(!strcmp(corto_llGet(args2, 0), "arg3"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchErr(test_Args this) {
/* $begin(test/Args/tc_matchErr) */
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

/* $end */
}

corto_void _test_Args_tc_matchFixed(test_Args this) {
/* $begin(test/Args/tc_matchFixed) */
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
    test_assert(corto_llSize(a) == 1);

    test_assert(b != NULL);
    test_assert(corto_llSize(b) == 1);

    test_assert(c != NULL);
    test_assert(corto_llSize(c) == 1);

    test_assert(d != NULL);
    test_assert(corto_llSize(d) == 1);

    test_assert(!strcmp(corto_llGet(a, 0), "a"));
    test_assert(!strcmp(corto_llGet(b, 0), "b"));
    test_assert(!strcmp(corto_llGet(c, 0), "c"));
    test_assert(!strcmp(corto_llGet(d, 0), "d"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchMultiple(test_Args this) {
/* $begin(test/Args/tc_matchMultiple) */
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
    test_assert(corto_llSize(abc) == 1);

    test_assert(def != NULL);
    test_assert(corto_llSize(def) == 1);

    test_assert(!strcmp(corto_llGet(abc, 0), "abc"));
    test_assert(!strcmp(corto_llGet(def, 0), "def"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchMultipleArg(test_Args this) {
/* $begin(test/Args/tc_matchMultipleArg) */
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
    test_assert(corto_llSize(option1) == 1);

    test_assert(option2 != NULL);
    test_assert(corto_llSize(option2) == 1);

    test_assert(!strcmp(corto_llGet(option1, 0), "--option1"));
    test_assert(!strcmp(corto_llGet(option2, 0), "--option2"));

    test_assert(args1 != NULL);
    test_assert(corto_llSize(args1) == 1);

    test_assert(args2 != NULL);
    test_assert(corto_llSize(args2) == 1);

    test_assert(!strcmp(corto_llGet(args1, 0), "arg1"));
    test_assert(!strcmp(corto_llGet(args2, 0), "arg2"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchNone(test_Args this) {
/* $begin(test/Args/tc_matchNone) */
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

/* $end */
}

corto_void _test_Args_tc_matchPattern(test_Args this) {
/* $begin(test/Args/tc_matchPattern) */
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
    test_assert(corto_llSize(args) == 2);

    test_assert(!strcmp(corto_llGet(args, 0), "abcd"));
    test_assert(!strcmp(corto_llGet(args, 1), "bacd"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchShell(test_Args this) {
/* $begin(test/Args/tc_matchShell) */
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
    test_assert(corto_llSize(pp) == 1);
    test_assert(!strcmp(corto_llGet(pp, 0), "corto/idl"));

    test_assert(d != NULL);
    test_assert(corto_llSize(d) == 1);
    test_assert(!strcmp(corto_llGet(d, 0), "-d"));

    test_assert(load != NULL);
    test_assert(corto_llSize(load) == 2);
    test_assert(!strcmp(corto_llGet(load, 0), "test.cx"));
    test_assert(!strcmp(corto_llGet(load, 1), "test2.cx"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchSingle(test_Args this) {
/* $begin(test/Args/tc_matchSingle) */
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
    test_assert(corto_llSize(abc) == 1);

    test_assert(!strcmp(corto_llGet(abc, 0), "abc"));

    corto_argclean(data);

/* $end */
}

corto_void _test_Args_tc_matchSingleArg(test_Args this) {
/* $begin(test/Args/tc_matchSingleArg) */
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
    test_assert(corto_llSize(options) == 1);

    test_assert(args != NULL);
    test_assert(corto_llSize(args) == 1);

    test_assert(!strcmp(corto_llGet(options, 0), "--option"));
    test_assert(!strcmp(corto_llGet(args, 0), "arg"));

    corto_argclean(data);

/* $end */
}
