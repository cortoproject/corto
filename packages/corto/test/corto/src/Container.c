/* $CORTO_GENERATED
 *
 * Container.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Container_tc_complexContainer(
    test_Container this)
{
/* $begin(test/Container/tc_complexContainer) */
    corto_object o = corto_declareChild(root_o, "o", test_Car_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Car_o));
    test_assertint(corto_scopeSize(o), 2);

    test_Car car = test_Car(o);
    corto_setstr(&car->license_plate, "abc");
    car->speed = 100;

    corto_object wheel = corto_lookup(car, "Wheel");
    test_assert(wheel != NULL);
    test_assert(corto_typeof(wheel) == corto_type(corto_tablescope_o));
    test_assert(!corto_checkState(wheel, CORTO_DEFINED));
    test_assertint(corto_scopeSize(wheel), 0);

    corto_object engine = corto_lookup(car, "Engine");
    test_assert(engine != NULL);
    test_assert(corto_typeof(engine) == corto_type(test_Car_Engine_o));
    test_assert(!corto_checkState(engine, CORTO_DEFINED));
    test_assertint(corto_scopeSize(engine), 0);

    test_Car_Wheel wheel1 = corto_declareChild(wheel, "FrontLeft", test_Car_Wheel_o);
    test_assert(wheel1 != NULL);
    test_assert(corto_typeof(wheel1) == corto_type(test_Car_Wheel_o));
    test_assert(!corto_checkState(wheel1, CORTO_DEFINED));
    test_assertint(wheel1->location, Test_FrontLeft);
    test_assertint(corto_scopeSize(wheel1), 1);

    test_Car_Wheel tire1 = corto_lookup(wheel1, "Tire");
    test_assert(tire1 != NULL);
    test_assert(corto_typeof(tire1) == corto_type(test_Car_Wheel_Tire_o));
    test_assert(!corto_checkState(tire1, CORTO_DEFINED));
    test_assertint(corto_scopeSize(tire1), 0);

    test_assert(corto_define(car) == 0);
    test_assertint(corto_scopeSize(o), 2);

    test_assert(corto_checkState(wheel, CORTO_DEFINED));
    test_assert(corto_checkState(wheel1, CORTO_DEFINED));
    test_assert(corto_checkState(tire1, CORTO_DEFINED));
    test_assert(corto_checkState(engine, CORTO_DEFINED));

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_containerEmpty(
    test_Container this)
{
/* $begin(test/Container/tc_containerEmpty) */
    corto_object o = corto_declareChild(root_o, "o", test_ContainerEmpty_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerEmpty_o));
    test_assertint(corto_scopeSize(o), 0);

    test_ContainerEmpty c = test_ContainerEmpty(o);
    c->id = 10;
    corto_setstr(&c->value, "Foo");
    test_assert(corto_define(c) == 0);
    test_assertint(corto_scopeSize(o), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_containerNestedContainer(
    test_Container this)
{
/* $begin(test/Container/tc_containerNestedContainer) */
    corto_object o = corto_declareChild(root_o, "o", test_ContainerNestedContainer_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedContainer_o));
    test_assertint(corto_scopeSize(o), 1);

    corto_object child = corto_lookup(o, "ChildContainer");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(test_ContainerNestedContainer_ChildContainer_o));
    test_assert(!corto_checkState(child, CORTO_DEFINED));

    /* Test if members of container are properly generated */
    test_ContainerNestedContainer container = test_ContainerNestedContainer(o);
    container->id = 10;
    corto_setstr(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scopeSize(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedContainer_ChildContainer childContainer = 
        test_ContainerNestedContainer_ChildContainer(child);
    childContainer->id = 10;
    corto_setstr(&childContainer->value, "Foo");
    corto_release(child);
    test_assertint(corto_scopeSize(o), 1);

    test_assert(corto_checkState(child, CORTO_DEFINED));

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_containerNestedLeaf(
    test_Container this)
{
/* $begin(test/Container/tc_containerNestedLeaf) */
    corto_object o = corto_declareChild(root_o, "o", test_ContainerNestedLeaf_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedLeaf_o));
    test_assertint(corto_scopeSize(o), 1);

    corto_object child = corto_lookup(o, "ChildLeaf");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(test_ContainerNestedLeaf_ChildLeaf_o));
    test_assert(!corto_checkState(child, CORTO_DEFINED));

    /* Test if members of container are properly generated */
    test_ContainerNestedLeaf container = test_ContainerNestedLeaf(o);
    container->id = 10;
    corto_setstr(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scopeSize(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedLeaf_ChildLeaf childLeaf = 
        test_ContainerNestedLeaf_ChildLeaf(child);
    childLeaf->id = 10;
    corto_setstr(&childLeaf->value, "Foo");
    corto_release(child);
    test_assertint(corto_scopeSize(o), 1);

    test_assert(corto_checkState(child, CORTO_DEFINED));

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_containerNestedTable(
    test_Container this)
{
/* $begin(test/Container/tc_containerNestedTable) */
    corto_object o = corto_declareChild(root_o, "o", test_ContainerNestedTable_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedTable_o));
    test_assertint(corto_scopeSize(o), 1);

    corto_object child = corto_lookup(o, "ChildTable");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(corto_tablescope_o));
    test_assert(!corto_checkState(child, CORTO_DEFINED));

    corto_tablescope childTable = corto_tablescope(child);
    test_assert(childTable->type == corto_struct(test_ContainerNestedTable_ChildTable_o));
    corto_release(child);
    test_assertint(corto_scopeSize(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedTable container = test_ContainerNestedTable(o);
    container->id = 10;
    corto_setstr(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scopeSize(o), 1);

    test_assert(corto_checkState(child, CORTO_DEFINED));

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_leafRoot(
    test_Container this)
{
/* $begin(test/Container/tc_leafRoot) */
    corto_object o = corto_declareChild(root_o, "o", test_LeafRoot_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_LeafRoot_o));
    test_assertint(corto_scopeSize(o), 0);
    
    test_LeafRoot leaf = test_LeafRoot(o);
    leaf->id = 10;
    corto_setstr(&leaf->value, "Foo");
    test_assert(corto_define(leaf) == 0);
    test_assertint(corto_scopeSize(o), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableMultiKey(
    test_Container this)
{
/* $begin(test/Container/tc_tableMultiKey) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableMultiKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiKey record = corto_declareChild(o, "1,2", test_TableMultiKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 0);
    test_assertint(record->id1, 1);
    test_assertint(record->id2, 2);
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableMultiMixedKey(
    test_Container this)
{
/* $begin(test/Container/tc_tableMultiMixedKey) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableMultiMixedKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiMixedKey record = corto_declareChild(o, "1,Hello World", test_TableMultiMixedKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 0);
    test_assertint(record->id1, 1);
    test_assertstr(record->id2, "Hello World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableMultiStringKey(
    test_Container this)
{
/* $begin(test/Container/tc_tableMultiStringKey) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableMultiStringKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiStringKey record = corto_declareChild(o, "Hello,World", test_TableMultiStringKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 0);
    test_assertstr(record->id1, "Hello");
    test_assertstr(record->id2, "World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 0);

    test_assert(corto_delete(o) == 0);
/* $end */
}

corto_void _test_Container_tc_tableNested(
    test_Container this)
{
/* $begin(test/Container/tc_tableNested) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableNested_o);

    test_TableSingleKey record = corto_declareChild(o, "1", test_TableNested_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 1);
    test_assert(!corto_checkState(record, CORTO_DEFINED));
    test_assertint(record->id, 1);

    corto_tablescope nested = corto_lookup(record, "ChildTable");
    test_assert(nested != NULL);
    test_assert(corto_typeof(nested) == corto_type(corto_tablescope_o));
    test_assert(!corto_checkState(nested, CORTO_DEFINED));
    test_assertint(corto_scopeSize(nested), 0);

    test_assert(corto_define(o) == 0);

    test_assert(corto_checkState(record, CORTO_DEFINED));
    test_assert(corto_checkState(nested, CORTO_DEFINED));

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableNestedContainer(
    test_Container this)
{
/* $begin(test/Container/tc_tableNestedContainer) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableNestedContainer_o);
    test_assert (corto_define(o) == 0);

    test_TableNestedContainer record = corto_declareChild(o, "1", test_TableNestedContainer_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 1);
    test_assertint(record->id, 1);

    corto_object child = corto_lookup(record, "ChildContainer");
    test_assert(child != NULL);
    test_assert(!corto_checkState(child, CORTO_DEFINED));
    test_assert(corto_typeof(child) == corto_type(test_TableNestedContainer_ChildContainer_o));

    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 1);

    test_assert(corto_checkState(child, CORTO_DEFINED));
    corto_release(child);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableNestedLeafs(
    test_Container this)
{
/* $begin(test/Container/tc_tableNestedLeafs) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableNestedLeafs_o);
    test_assert (corto_define(o) == 0);

    test_TableNestedLeafs record = corto_declareChild(o, "1", test_TableNestedLeafs_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 2);
    test_assertint(record->id, 1);

    corto_object child1 = corto_lookup(record, "ChildLeaf1");
    test_assert(child1 != NULL);
    test_assert(!corto_checkState(child1, CORTO_DEFINED));
    test_assert(corto_typeof(child1) == corto_type(test_TableNestedLeafs_ChildLeaf1_o));

    corto_object child2 = corto_lookup(record, "ChildLeaf2");
    test_assert(child2 != NULL);
    test_assert(!corto_checkState(child2, CORTO_DEFINED));
    test_assert(corto_typeof(child2) == corto_type(test_TableNestedLeafs_ChildLeaf2_o));

    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 2);

    test_assert(corto_checkState(child1, CORTO_DEFINED));
    test_assert(corto_checkState(child2, CORTO_DEFINED));
    corto_release(child1);
    corto_release(child2);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableSingleKey(
    test_Container this)
{
/* $begin(test/Container/tc_tableSingleKey) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableSingleKey_o);
    test_assert (corto_define(o) == 0);

    test_TableSingleKey record = corto_declareChild(o, "1", test_TableSingleKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 0);
    test_assertint(record->id, 1);
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}

corto_void _test_Container_tc_tableStringKey(
    test_Container this)
{
/* $begin(test/Container/tc_tableStringKey) */
    corto_tablescope o = corto_declareChild(root_o, "o", corto_tablescope_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tablescope_o));
    test_assertint(corto_scopeSize(o), 0);
    corto_setref(&o->type, test_TableStringKey_o);
    test_assert (corto_define(o) == 0);

    test_TableStringKey record = corto_declareChild(o, "Hello World", test_TableStringKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scopeSize(record), 0);
    test_assertstr(record->id, "Hello World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scopeSize(record), 0);

    test_assert(corto_delete(o) == 0);

/* $end */
}
