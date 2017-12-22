/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Container_tc_anonymousContainer(
    test_Container this)
{
    /* Containers are always created as named objects. If using corto_declare
     * an anonymous "named" object is created. */
    test_ContainerNestedLeaf o = corto_declare(NULL, NULL, test_ContainerNestedLeaf_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedLeaf_o));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED) == true);
    test_assertint(corto_scope_size(o), 1);
    test_assert(!corto_check_state(o, CORTO_VALID));

    corto_object leaf = corto_lookup(o, "ChildLeaf");
    test_assert(leaf != NULL);
    test_assert(corto_typeof(leaf) == corto_type(test_ContainerNestedLeaf_ChildLeaf_o));
    test_assertint(corto_scope_size(leaf), 0);
    test_assert(!corto_check_state(o, CORTO_VALID));

    test_assert(corto_define(o) == 0);
    test_assertint(corto_scope_size(o), 1);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_state(leaf, CORTO_VALID));

    test_assert(corto_release(leaf) == 1);
    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_complexContainer(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_Car_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Car_o));
    test_assertint(corto_scope_size(o), 2);

    test_Car car = test_Car(o);
    corto_set_str(&car->license_plate, "abc");
    car->speed = 100;

    corto_object wheel = corto_lookup(car, "Wheel");
    test_assert(wheel != NULL);
    test_assert(corto_typeof(wheel) == corto_type(corto_tableinstance_o));
    test_assert(!corto_check_state(wheel, CORTO_VALID));
    test_assertint(corto_scope_size(wheel), 0);

    corto_object engine = corto_lookup(car, "Engine");
    test_assert(engine != NULL);
    test_assert(corto_typeof(engine) == corto_type(test_Car_Engine_o));
    test_assert(!corto_check_state(engine, CORTO_VALID));
    test_assertint(corto_scope_size(engine), 0);

    test_Car_Wheel wheel1 = corto_declare(wheel, "FrontLeft", test_Car_Wheel_o);
    test_assert(wheel1 != NULL);
    test_assert(corto_typeof(wheel1) == corto_type(test_Car_Wheel_o));
    test_assert(!corto_check_state(wheel1, CORTO_VALID));
    test_assertint(wheel1->location, Test_FrontLeft);
    test_assertint(corto_scope_size(wheel1), 1);

    test_Car_Wheel tire1 = corto_lookup(wheel1, "Tire");
    test_assert(tire1 != NULL);
    test_assert(corto_typeof(tire1) == corto_type(test_Car_Wheel_Tire_o));
    test_assert(!corto_check_state(tire1, CORTO_VALID));
    test_assertint(corto_scope_size(tire1), 0);

    test_assert(corto_define(car) == 0);
    test_assertint(corto_scope_size(o), 2);

    test_assert(corto_check_state(wheel, CORTO_VALID));
    test_assert(corto_check_state(wheel1, CORTO_VALID));
    test_assert(corto_check_state(tire1, CORTO_VALID));
    test_assert(corto_check_state(engine, CORTO_VALID));

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_containerEmpty(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_ContainerEmpty_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerEmpty_o));
    test_assertint(corto_scope_size(o), 0);

    test_ContainerEmpty c = test_ContainerEmpty(o);
    c->id = 10;
    corto_set_str(&c->value, "Foo");
    test_assert(corto_define(c) == 0);
    test_assertint(corto_scope_size(o), 0);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_containerNestedContainer(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_ContainerNestedContainer_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedContainer_o));
    test_assertint(corto_scope_size(o), 1);

    corto_object child = corto_lookup(o, "ChildContainer");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(test_ContainerNestedContainer_ChildContainer_o));
    test_assert(!corto_check_state(child, CORTO_VALID));

    /* Test if members of container are properly generated */
    test_ContainerNestedContainer container = test_ContainerNestedContainer(o);
    container->id = 10;
    corto_set_str(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scope_size(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedContainer_ChildContainer childContainer = 
        test_ContainerNestedContainer_ChildContainer(child);
    childContainer->id = 10;
    corto_set_str(&childContainer->value, "Foo");
    corto_release(child);
    test_assertint(corto_scope_size(o), 1);

    test_assert(corto_check_state(child, CORTO_VALID));

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_containerNestedLeaf(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_ContainerNestedLeaf_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedLeaf_o));
    test_assertint(corto_scope_size(o), 1);

    corto_object child = corto_lookup(o, "ChildLeaf");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(test_ContainerNestedLeaf_ChildLeaf_o));
    test_assert(!corto_check_state(child, CORTO_VALID));

    /* Test if members of container are properly generated */
    test_ContainerNestedLeaf container = test_ContainerNestedLeaf(o);
    container->id = 10;
    corto_set_str(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scope_size(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedLeaf_ChildLeaf childLeaf = 
        test_ContainerNestedLeaf_ChildLeaf(child);
    childLeaf->id = 10;
    corto_set_str(&childLeaf->value, "Foo");
    corto_release(child);
    test_assertint(corto_scope_size(o), 1);

    test_assert(corto_check_state(child, CORTO_VALID));

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_containerNestedTable(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_ContainerNestedTable_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_ContainerNestedTable_o));
    test_assertint(corto_scope_size(o), 1);

    corto_object child = corto_lookup(o, "ChildTable");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == corto_type(corto_tableinstance_o));
    test_assert(!corto_check_state(child, CORTO_VALID));

    corto_tableinstance childTable = corto_tableinstance(child);
    test_assert(childTable->type == corto_struct(test_ContainerNestedTable_ChildTable_o));
    corto_release(child);
    test_assertint(corto_scope_size(o), 1);

    /* Test if members of container are properly generated */
    test_ContainerNestedTable container = test_ContainerNestedTable(o);
    container->id = 10;
    corto_set_str(&container->value, "Foo");
    test_assert(corto_define(container) == 0);
    test_assertint(corto_scope_size(o), 1);

    test_assert(corto_check_state(child, CORTO_VALID));

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_leafRoot(
    test_Container this)
{
    corto_object o = corto_declare(root_o, "o", test_LeafRoot_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_LeafRoot_o));
    test_assertint(corto_scope_size(o), 0);
    
    test_LeafRoot leaf = test_LeafRoot(o);
    leaf->id = 10;
    corto_set_str(&leaf->value, "Foo");
    test_assert(corto_define(leaf) == 0);
    test_assertint(corto_scope_size(o), 0);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableMultiKey(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableMultiKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiKey record = corto_declare(o, "1,2", test_TableMultiKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 0);
    test_assertint(record->id1, 1);
    test_assertint(record->id2, 2);
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 0);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableMultiMixedKey(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableMultiMixedKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiMixedKey record = corto_declare(o, "1,Hello World", test_TableMultiMixedKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 0);
    test_assertint(record->id1, 1);
    test_assertstr(record->id2, "Hello World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 0);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableMultiStringKey(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableMultiStringKey_o);
    test_assert (corto_define(o) == 0);

    test_TableMultiStringKey record = corto_declare(o, "Hello,World", test_TableMultiStringKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 0);
    test_assertstr(record->id1, "Hello");
    test_assertstr(record->id2, "World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 0);

    test_assert(corto_delete(o) == 0);
}

void test_Container_tc_tableNested(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableNested_o);

    test_TableSingleKey record = corto_declare(o, "1", test_TableNested_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 1);
    test_assert(!corto_check_state(record, CORTO_VALID));
    test_assertint(record->id, 1);

    corto_tableinstance nested = corto_lookup(record, "ChildTable");
    test_assert(nested != NULL);
    test_assert(corto_typeof(nested) == corto_type(corto_tableinstance_o));
    test_assert(!corto_check_state(nested, CORTO_VALID));
    test_assertint(corto_scope_size(nested), 0);

    test_assert(corto_define(o) == 0);

    test_assert(corto_check_state(record, CORTO_VALID));
    test_assert(corto_check_state(nested, CORTO_VALID));

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableNestedContainer(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableNestedContainer_o);
    test_assert (corto_define(o) == 0);

    test_TableNestedContainer record = corto_declare(o, "1", test_TableNestedContainer_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 1);
    test_assertint(record->id, 1);

    corto_object child = corto_lookup(record, "ChildContainer");
    test_assert(child != NULL);
    test_assert(!corto_check_state(child, CORTO_VALID));
    test_assert(corto_typeof(child) == corto_type(test_TableNestedContainer_ChildContainer_o));

    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 1);

    test_assert(corto_check_state(child, CORTO_VALID));
    corto_release(child);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableNestedLeafs(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableNestedLeafs_o);
    test_assert (corto_define(o) == 0);

    test_TableNestedLeafs record = corto_declare(o, "1", test_TableNestedLeafs_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 2);
    test_assertint(record->id, 1);

    corto_object child1 = corto_lookup(record, "ChildLeaf1");
    test_assert(child1 != NULL);
    test_assert(!corto_check_state(child1, CORTO_VALID));
    test_assert(corto_typeof(child1) == corto_type(test_TableNestedLeafs_ChildLeaf1_o));

    corto_object child2 = corto_lookup(record, "ChildLeaf2");
    test_assert(child2 != NULL);
    test_assert(!corto_check_state(child2, CORTO_VALID));
    test_assert(corto_typeof(child2) == corto_type(test_TableNestedLeafs_ChildLeaf2_o));

    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 2);

    test_assert(corto_check_state(child1, CORTO_VALID));
    test_assert(corto_check_state(child2, CORTO_VALID));
    corto_release(child1);
    corto_release(child2);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableSingleKey(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableSingleKey_o);
    test_assert (corto_define(o) == 0);

    test_TableSingleKey record = corto_declare(o, "1", test_TableSingleKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 0);
    test_assertint(record->id, 1);
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 0);

    test_assert(corto_delete(o) == 0);

}

void test_Container_tc_tableStringKey(
    test_Container this)
{
    corto_tableinstance o = corto_declare(root_o, "o", corto_tableinstance_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_tableinstance_o));
    test_assertint(corto_scope_size(o), 0);
    corto_set_ref(&o->type, test_TableStringKey_o);
    test_assert (corto_define(o) == 0);

    test_TableStringKey record = corto_declare(o, "Hello World", test_TableStringKey_o);
    test_assert(record != NULL);
    test_assertint(corto_scope_size(record), 0);
    test_assertstr(record->id, "Hello World");
    test_assert(corto_define(record) == 0);
    test_assertint(corto_scope_size(record), 0);

    test_assert(corto_delete(o) == 0);

}

