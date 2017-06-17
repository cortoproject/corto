/* $CORTO_GENERATED
 *
 * SelectSink.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_SelectSink_setup(
    test_SelectSink this)
{
/* $begin(test/SelectSink/setup) */

    /* Register sink mount */
    corto_voidCreateChild_auto(root_o, mount);
    test_SinkMountCreateChild_auto(root_o, sinkMount, mount, NULL, NULL);

    /* Ensure all objects are created with persistency enabled */
    corto_setAttr(CORTO_ATTR_PERSISTENT);

/* $end */
}

void _test_SelectSink_tc_selectLoaderCortoScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderCortoScope) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderCortoSingle(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderCortoSingle) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderCortoTree(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderCortoTree) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderNestedScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderNestedScope) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderNestedSingle(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderNestedSingle) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderNestedTree(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderNestedTree) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderRootScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderRootScope) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderRootSingle(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderRootSingle) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectLoaderRootTree(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectLoaderRootTree) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SelectSink_tc_selectMixedScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScope) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(mount, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(mount, j, 0);

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

/* $end */
}

void _test_SelectSink_tc_selectMixedScopeNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScopeNested1) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(x, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(x, j, 0);

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

/* $end */
}

void _test_SelectSink_tc_selectMixedScopeNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMixedScopeNested2) */
    corto_iter iter;
    corto_result *result;

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");

    /* Create duplicate of object in mount */
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);

    /* Create object that is not in mount (should not show up) */
    corto_int32CreateChild_auto(a, i, 0);

    /* Create float object that is not in mount (should not show up) */
    corto_float32CreateChild_auto(a, j, 0);

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

/* $end */
}

void _test_SelectSink_tc_selectMountInResult(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectMountInResult) */
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

/* $end */
}

void _test_SelectSink_tc_selectScope(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectScope) */
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

/* $end */
}

void _test_SelectSink_tc_selectScopeWithType(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectScopeWithType) */
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };

    test_ObjectMount m1 = test_ObjectMountCreate("*", "/", &r1);
    test_ObjectMount m2 = test_ObjectMountCreate("*", "/root", &r2);

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

/* $end */
}

void _test_SelectSink_tc_selectScopeWithTypeFromTreeMount(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectScopeWithTypeFromTreeMount) */
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };

    test_ObjectMount m1 = test_ObjectMountCreate("//", "/", &r1);
    test_ObjectMount m2 = test_ObjectMountCreate("//", "/root", &r2);

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

/* $end */
}

void _test_SelectSink_tc_selectSingle(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingle) */
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

/* $end */
}

void _test_SelectSink_tc_selectSingleTypeFilter(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleTypeFilter) */
    corto_iter iter;
    corto_result *result;

    // Select single object of the package type
    corto_int16 ret = corto_select("//native*").iter( &iter );
    test_assert(ret == 0);
    test_assertstr(corto_lasterr(), NULL);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "native");
    test_assertstr(result->parent, "/corto");
    test_assertstr(result->type, "/corto/core/package");

/* $end */
}

void _test_SelectSink_tc_selectSingleVirtualNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleVirtualNested1) */
    corto_iter iter;
    corto_result *result;
    corto_int16 ret = corto_select("x/a").from("/mount").iter( &iter );

    test_assert(ret == 0);

    /* Create actual objects */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);
    corto_release(mount);

    test_assert(corto_iter_hasNext(&iter));
    result = corto_iter_next(&iter);
    test_assert(result != NULL);
    test_assert(result->id != NULL);
    test_assertstr(result->id, "a");
    test_assertstr(result->parent, "x");
    test_assertstr(result->type, "int32");

    test_assert(!corto_iter_hasNext(&iter));

/* $end */
}

void _test_SelectSink_tc_selectSingleVirtualNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleVirtualNested2) */
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

/* $end */
}

void _test_SelectSink_tc_selectSingleWithType(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleWithType) */
    corto_result r1 = {
        .id = "a",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };

    /* use root as mount point */
    test_ObjectMount m1 = test_ObjectMountCreate("*", "/", &r1);
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

/* $end */
}

void _test_SelectSink_tc_selectSingleWithTypeFromTreeMount(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectSingleWithTypeFromTreeMount) */
    corto_result r1 = {
        .id = "a",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };

    /* use root as mount point */
    test_ObjectMount m1 = test_ObjectMountCreate("//", "/", &r1);
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

/* $end */
}

void _test_SelectSink_tc_selectTreeWithType(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectTreeWithType) */
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };
    corto_result r3 = {
        .id = "nested",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };

    test_ObjectMount m1 = test_ObjectMountCreate("/", "/", &r1);
    test_ObjectMount m2 = test_ObjectMountCreate("/", "/root", &r2);
    test_ObjectMount m3 = test_ObjectMountCreate("/", "/root/obj", &r3);
    test_ObjectMount m4 = test_ObjectMountCreate("/", "/root/obj/nested", &r2);

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

/* $end */
}

void _test_SelectSink_tc_selectTreeWithTypeFromTreeMount(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectTreeWithTypeFromTreeMount) */
    corto_result r1 = {
        .id = "root",
        .parent = ".",
        .type = "int32",
        .leaf = FALSE
    };
    corto_result r2 = {
        .id = "obj",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };
    corto_result r3 = {
        .id = "nested",
        .parent = ".",
        .type = "float32",
        .leaf = TRUE
    };

    test_ObjectMount m1 = test_ObjectMountCreate("//", "/", &r1);
    test_ObjectMount m2 = test_ObjectMountCreate("//", "/root", &r2);
    test_ObjectMount m3 = test_ObjectMountCreate("//", "/root/obj", &r3);
    test_ObjectMount m4 = test_ObjectMountCreate("//", "/root/obj/nested", &r2);

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

/* $end */
}

void _test_SelectSink_tc_selectVirtualScopeNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeNested1) */
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild(mount, "x", 0);
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

/* $end */
}

void _test_SelectSink_tc_selectVirtualScopeNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeNested2) */
    corto_iter iter;
    corto_result *result;

    /* Create an actual scope */
    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
    corto_int32CreateChild_auto(x, a, 0);
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

/* $end */
}

void _test_SelectSink_tc_selectVirtualScopeVirtualNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeVirtualNested1) */
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

/* $end */
}

void _test_SelectSink_tc_selectVirtualScopeVirtualNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualScopeVirtualNested2) */
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

/* $end */
}

void _test_SelectSink_tc_selectVirtualSingleNested1(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualSingleNested1) */
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
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

/* $end */
}

void _test_SelectSink_tc_selectVirtualSingleNested2(
    test_SelectSink this)
{
/* $begin(test/SelectSink/tc_selectVirtualSingleNested2) */
    corto_iter iter;
    corto_result *result;

    corto_object mount = corto_resolve(root_o, "mount");
    corto_int32CreateChild_auto(mount, x, 0);
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

/* $end */
}

void _test_SelectSink_teardown(
    test_SelectSink this)
{
/* $begin(test/SelectSink/teardown) */

    /* << Insert implementation >> */

/* $end */
}
