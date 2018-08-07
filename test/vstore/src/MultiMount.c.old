/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MultiMount_setup(
    test_MultiMount this)
{
    test_SparseMount red = (test_SparseMount)corto_subscribe("//")
        .from("/data")
        .named(root_o, "config/red")
        .mount(test_SparseMount_o, NULL, NULL);

    test_SparseMount blue = (test_SparseMount)corto_subscribe("//")
        .from("/data")
        .named(root_o, "config/blue")
        .mount(test_SparseMount_o, NULL, NULL);

    test_SparseMount green = (test_SparseMount)corto_subscribe("/")
        .from("/data/B")
        .named(root_o, "config/green")
        .mount(test_SparseMount_o, NULL, NULL);

    /* Populate red mount */
    test_SparseMount_add_object(red, "E", "B", "int32", 0);
    test_SparseMount_add_object(red, "G", "B/E", "int32", CORTO_RESULT_LEAF);
    test_SparseMount_add_object(red, "I", "B/E/G", "int32", 0); /* should never be returned because parent is leaf */
    test_SparseMount_add_object(red, "I", "B/E/H", "int32", 0);
    test_SparseMount_add_object(red, "G", "B/F", "int32", 0);

    test_SparseMount_add_object(red, "C", ".", "int32", 0);
    test_SparseMount_add_object(red, "G", "C/E", "int32", 0);
    test_SparseMount_add_object(red, "I", "C/E/H", "int32", 0);
    test_SparseMount_add_object(red, "G", "C/F", "int32", 0);

    test_SparseMount_add_object(red, "F", "D", "int32", 0);
    test_SparseMount_add_object(red, "G", "D/F", "int32", 0);
    test_SparseMount_add_object(red, "I", "D/F/G", "int32", 0);
    test_SparseMount_add_object(red, "G", "D/E", "int32", 0);

    /* Populate blue mount */
    test_SparseMount_add_object(blue, "B", ".", "int32", 0);
    test_SparseMount_add_object(blue, "H", "B/E", "int32", 0);
    test_SparseMount_add_object(blue, "H", "B/F", "int32", 0);

    test_SparseMount_add_object(blue, "E", "C", "int32", 0);
    test_SparseMount_add_object(blue, "I", "C/E/G", "int32", 0);
    test_SparseMount_add_object(blue, "H", "C/E", "int32", CORTO_RESULT_HIDDEN);
    test_SparseMount_add_object(blue, "I", "C/E/H", "int32", 0);
    test_SparseMount_add_object(blue, "H", "C/F", "int32", 0);

    test_SparseMount_add_object(blue, "E", "D", "int32", 0);
    test_SparseMount_add_object(blue, "H", "D/E", "int32", 0);
    test_SparseMount_add_object(blue, "H", "D/F", "int32", 0);

    /* Populate green mount */
    test_SparseMount_add_object(green, "F", ".", "int32", 0);
}
