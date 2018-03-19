/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_SelectSink_setup(
    test_SelectSink this)
{

    /* Register sink mount */
    corto_void__create_auto(root_o, mount);
    test_SinkMount__create_auto(root_o, sinkMount, mount, NULL, NULL);

    /* Ensure all objects are created with persistency enabled */
    corto_set_attr(CORTO_ATTR_PERSISTENT);
}

void test_SelectSink_tc_selectLoaderCortoScope(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("/").from("corto").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "lang");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "secure");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "vstore");
    test_assertstr(r->parent, ".");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderCortoSingle(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("r").from("corto").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, ".");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderCortoTree(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("//").from("corto").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "u");
    test_assertstr(r->parent, "r");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "lang");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "secure");
    test_assertstr(r->parent, ".");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "vstore");
    test_assertstr(r->parent, ".");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);

}

void test_SelectSink_tc_selectLoaderNestedScope(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("corto/").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "lang");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "secure");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "vstore");
    test_assertstr(r->parent, "/corto");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderNestedSingle(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("corto/native").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, "/corto");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderNestedSingleVirtual(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("corto/r").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, "/corto");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderNestedTree(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("corto//").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "u");
    test_assertstr(r->parent, "/corto/r");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "lang");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "secure");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "vstore");
    test_assertstr(r->parent, "/corto");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderRootScope(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("/").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "p");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "v");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderRootSingle(
    test_SelectSink this)
{

    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("p").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "p");
    test_assertstr(r->parent, "");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderRootTree(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_iter it;
    test_assert(corto_select("//").type("package").iter(&it) == 0);

    corto_result *r;
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "corto");
    test_assertstr(r->parent, "");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "lang");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "native");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "secure");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "vstore");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "r");
    test_assertstr(r->parent, "/corto");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "u");
    test_assertstr(r->parent, "/corto/r");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "p");
    test_assertstr(r->parent, "");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "q");
    test_assertstr(r->parent, "/p");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "s");
    test_assertstr(r->parent, "/p/q");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "v");
    test_assertstr(r->parent, "");

    test_assert(!corto_iter_hasNext(&it));

    test_assert(corto_delete(m) == 0);
}

void test_SelectSink_tc_selectLoaderLookupFromUnknown(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_object p = corto_declare(root_o, "p", corto_unknown_o);
    test_assert(p != NULL);

    corto_object q = corto_lookup(NULL, "p/q");
    test_assert(q != NULL);

    /* Ensure that 'p' hasn't been resumed */
    /* test_assert(corto_parentof(q) == p); - TODO: not yet implemented */

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(q) == 0);
}

void test_SelectSink_tc_selectLoaderLookupNestedInitialSlash(
    test_SelectSink this)
{
    /* Disable package loader to ensure test results are predictable */
    corto_enable_load(false);

    /* Create loader simulator mount */
    test_LoaderSimulatorMount m = test_LoaderSimulatorMount__create(NULL, NULL);

    corto_object q = corto_lookup(NULL, "/p/q");
    test_assert(q != NULL);

    corto_object s = corto_lookup(NULL, "/p/q/s");
    test_assert(s != NULL);

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(q) == 0);
}

void test_SelectSink_tc_selectMixedScope(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32__create_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32__create_auto(mount, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32__create_auto(mount, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "y"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "z"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectSink_tc_selectMixedScopeNested1(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32__create_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32__create_auto(x, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32__create_auto(x, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("x/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "b"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "c"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectMixedScopeNested2(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32__create_auto(mount, x, 0);
    corto_int32__create_auto(x, a, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32__create_auto(a, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32__create_auto(a, j, 0);

    corto_release(mount);

    corto_int16 ret = corto_select("x/a/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectMountInResult(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x").from("/mount").iter( &iter );
    test_assert(ret == 0);

    corto_object mount = corto_lookup(NULL, "sinkMount");
    test_assert(mount != NULL);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "x");
    test_assertstr(result->parent, ".");
    test_assertstr(result->type, "int32");
    test_assert(result->owner == mount);

    test_assert(!corto_iter_hasNext(&iter));
    corto_release(mount);

}

void test_SelectSink_tc_selectScope(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "y"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "z"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectScopeWithType(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .flags = 0
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "*", "/", &r1);
    test_ObjectMount m2 = test_ObjectMount__create(NULL, NULL, "*", "/root", &r2);
    corto_iter it;
    corto_select("root/obj").type("float32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root");
    test_assertstr(r->type, "float32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
    test_assert(corto_delete(m2) == 0);
}

void test_SelectSink_tc_selectScopeWithTypeFromTreeMount(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .flags = 0
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "//", "/", &r1);
    test_ObjectMount m2 = test_ObjectMount__create(NULL, NULL, "//", "/root", &r2);
    corto_iter it;
    corto_select("root/obj").type("float32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root");
    test_assertstr(r->type, "float32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
    test_assert(corto_delete(m2) == 0);
}

void test_SelectSink_tc_selectSingle(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "x"));
    test_assert(!strcmp(result->parent, "."));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectSingleTypeFilter(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    // Select single object of the package type
    corto_int16 ret = corto_select("//native*").iter( &iter );
    test_assert(ret == 0);
    test_assert(!corto_catch());

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "native");
    test_assertstr(result->parent, "/corto");
    test_assertstr(result->type, "package");

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectSink_tc_selectSingleVirtualNested1(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x/a").from("/mount").iter( &iter );

    test_assert(ret == 0);

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32__create_auto(mount, x, 0);
    corto_int32__create_auto(x, a, 0);
    corto_release(mount);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "int32");

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectSingleVirtualNested2(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x/a/k").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectSingleWithType(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "a",
        .parent = ".",
        .type = "int32",
        .flags = CORTO_RESULT_LEAF
    };
    /* use root as mount point */
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "*", "/", &r1);
    test_assert(m1 != NULL);
    corto_iter it;
    corto_select("a").type("int32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "int32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
}

void test_SelectSink_tc_selectSingleWithTypeFromTreeMount(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "a",
        .parent = ".",
        .type = "int32",
        .flags = 0
    };
    /* use root as mount point */
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "//", "/", &r1);
    test_assert(m1 != NULL);
    corto_iter it;
    corto_select("a").type("int32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "int32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
}

void test_SelectSink_tc_selectTreeWithType(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .flags = 0
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    corto_result r3 = {
        .id = "nested",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "/", "/", &r1);
    test_ObjectMount m2 = test_ObjectMount__create(NULL, NULL, "/", "/root", &r2);
    test_ObjectMount m3 = test_ObjectMount__create(NULL, NULL, "/", "/root/obj", &r3);
    test_ObjectMount m4 = test_ObjectMount__create(NULL, NULL, "/", "/root/obj/nested", &r2);
    corto_iter it;
    corto_select("//obj").type("float32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root");
    test_assertstr(r->type, "float32");
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root/obj/nested");
    test_assertstr(r->type, "float32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
    test_assert(corto_delete(m2) == 0);
    test_assert(corto_delete(m3) == 0);
    test_assert(corto_delete(m4) == 0);
}

void test_SelectSink_tc_selectTreeWithTypeFromTreeMount(
    test_SelectSink this)
{
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .flags = 0
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    corto_result r3 = {
        .id = "nested",
        .parent = ".",
        .type = "float32",
        .flags = CORTO_RESULT_LEAF
    };
    test_ObjectMount m1 = test_ObjectMount__create(NULL, NULL, "//", "/", &r1);
    test_ObjectMount m2 = test_ObjectMount__create(NULL, NULL, "//", "/root", &r2);
    test_ObjectMount m3 = test_ObjectMount__create(NULL, NULL, "//", "/root/obj", &r3);
    test_ObjectMount m4 = test_ObjectMount__create(NULL, NULL, "//", "/root/obj/nested", &r2);
    corto_iter it;
    corto_select("//obj").type("float32").iter(&it);
    test_assert(corto_iter_hasNext(&it));
    corto_result *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root");
    test_assertstr(r->type, "float32");
    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "obj");
    test_assertstr(r->parent, "/root/obj/nested");
    test_assertstr(r->type, "float32");
    test_assert(!corto_iter_hasNext(&it));
    test_assert(corto_delete(m1) == 0);
    test_assert(corto_delete(m2) == 0);
    test_assert(corto_delete(m3) == 0);
    test_assert(corto_delete(m4) == 0);
}

void test_SelectSink_tc_selectVirtualScopeNested1(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32__create(mount, "x", 0);
    corto_release(mount);

    corto_int16 ret = corto_select("x/a/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectVirtualScopeNested2(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32__create_auto(mount, x, 0);
    corto_int32__create_auto(x, a, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("x/a/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectVirtualScopeVirtualNested1(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x/a/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "l"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "m"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectVirtualScopeVirtualNested2(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x/a/k/*").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "n"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "o"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "p"));
    test_assert(!strcmp(result->parent, "x/a/k"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectVirtualSingleNested1(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32__create_auto(mount, x, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("x/a").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "a"));
    test_assert(!strcmp(result->parent, "x"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_SelectSink_tc_selectVirtualSingleNested2(
    test_SelectSink this)
{
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32__create_auto(mount, x, 0);
    corto_release(mount);

    corto_int16 ret = corto_select("x/a/k").from("/mount").iter( &iter );

    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assert(!strcmp(result->id, "k"));
    test_assert(!strcmp(result->parent, "x/a"));
    test_assert(!strcmp(result->type, "int32"));

    test_assert(!corto_iter_hasNext(&iter));
}

void test_SelectSink_tc_selectObjectFromVstore(
    test_SelectSink this)
{
    corto_mountPolicy p = {
        .mask = CORTO_MOUNT_QUERY,
        .ownership = CORTO_LOCAL_SOURCE
    };

    corto_mount m =
        corto_subscribe("*")
            .from("data")
            .contentType("text/corto")
            .mount(test_SimpleMount_o, &p, NULL);
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(test_SimpleMount_o));
    test_assert(corto_check_state(m, CORTO_VALID) == true);

    corto_iter it;
    test_assert(corto_select("*").from("data").iter_objects(&it) == 0);

    test_assert(corto_iter_hasNext(&it) == true);
    corto_object r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(corto_idof(r), "foo");
    test_assertstr(corto_idof(corto_parentof(r)), "data");
    test_assert(corto_typeof(r) == corto_type(corto_int32_o));
    test_assert(corto_check_state(r, CORTO_VALID));
    test_assertint(*(int32_t*)r, 10);

    test_assert(corto_iter_hasNext(&it) == false);
}

void test_SelectSink_tc_selectObjectFromVstore_w_InvalidObjectInStore(
    test_SelectSink this)
{
    corto_mountPolicy p = {
        .mask = CORTO_MOUNT_QUERY,
        .ownership = CORTO_LOCAL_SOURCE
    };

    corto_mount m =
        corto_subscribe("*")
            .from("data")
            .contentType("text/corto")
            .mount(test_SimpleMount_o, &p, NULL);
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(test_SimpleMount_o));
    test_assert(corto_check_state(m, CORTO_VALID) == true);

    /* Declare object */
    corto_object o = corto_declare(root_o, "data/foo", corto_int32_o);

    corto_iter it;
    test_assert(corto_select("*").from("data").iter_objects(&it) == 0);

    test_assert(corto_iter_hasNext(&it) == true);
    corto_object r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assert(o == r);
    test_assertstr(corto_idof(r), "foo");
    test_assertstr(corto_idof(corto_parentof(r)), "data");
    test_assert(corto_typeof(r) == corto_type(corto_int32_o));
    test_assert(corto_check_state(r, CORTO_VALID));
    test_assertint(*(int32_t*)r, 10);

    test_assert(corto_iter_hasNext(&it) == false);
}

void test_SelectSink_tc_selectObjectFromVstore_w_ValidObjectInStore(
    test_SelectSink this)
{
    corto_mountPolicy p = {
        .mask = CORTO_MOUNT_QUERY,
        .ownership = CORTO_LOCAL_SOURCE
    };

    corto_mount m =
        corto_subscribe("*")
            .from("data")
            .contentType("text/corto")
            .mount(test_SimpleMount_o, &p, NULL);
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(test_SimpleMount_o));
    test_assert(corto_check_state(m, CORTO_VALID) == true);

    /* Declare & define object BEFORE creation of mount */
    int32_t *o = corto_create(root_o, "data/foo", corto_int32_o);
    test_assert(corto_define(o) == 0);
    test_assert(corto_check_state(o, CORTO_VALID));

    /* Change object value */
    *o = 20;

    corto_iter it;
    test_assert(corto_select("*").from("data").iter_objects(&it) == 0);

    test_assert(corto_iter_hasNext(&it) == true);
    corto_object r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assert(o == r);
    test_assertstr(corto_idof(r), "foo");
    test_assertstr(corto_idof(corto_parentof(r)), "data");
    test_assert(corto_typeof(r) == corto_type(corto_int32_o));
    test_assert(corto_check_state(r, CORTO_VALID));
    test_assertint(*(int32_t*)r, 20); /* Value should not be overwritten */

    test_assert(corto_iter_hasNext(&it) == false);
}

void test_SelectSink_teardown(
    test_SelectSink this)
{

    /* << Insert implementation >> */

}
