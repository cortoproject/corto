/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Alias_tc_aliasNonHidden(
    test_Alias this)
{
    corto_struct base = corto_declare(root_o, "base", corto_struct_o);
    test_assert(base != NULL);
    corto_member m = corto_declare(base, "m", corto_member_o);
    test_assert(m != NULL);
        m->type = (corto_type)corto_int32_o;
        test_assert(corto_define(m) == 0);
    test_assert(corto_define(base) == 0);

    corto_struct sub = corto_declare(root_o, "sub", corto_struct_o);
    test_assert(sub != NULL);
    corto_set_ref(&sub->super.base, base);
    corto_alias alias = corto_declare(sub, "m", corto_alias_o);
    test_assert(alias != NULL);
        corto_set_ref(&alias->member, m);
        test_assert(corto_define(alias) == 0);
    test_assert(corto_define(sub) != 0);
    test_assert(ut_catch() != 0);
}

void test_Alias_tc_aliasPrivate(
    test_Alias this)
{
    corto_struct base = corto_declare(root_o, "base", corto_struct_o);
    test_assert(base != NULL);
    corto_member m = corto_declare(base, "m", corto_member_o);
    test_assert(m != NULL);
        m->type = (corto_type)corto_int32_o;
        m->modifiers |= CORTO_PRIVATE | CORTO_HIDDEN;
        test_assert(corto_define(m) == 0);
    test_assert(corto_define(base) == 0);

    corto_struct sub = corto_declare(root_o, "sub", corto_struct_o);
    test_assert(sub != NULL);
    corto_set_ref(&sub->super.base, base);
    corto_alias alias = corto_declare(sub, "m", corto_alias_o);
    test_assert(alias != NULL);
        corto_set_ref(&alias->member, m);
        test_assert(corto_define(alias) == 0);
    test_assert(corto_define(sub) != 0);
    test_assert(ut_catch() != 0);
}

void test_Alias_tc_aliasPrivateBase(
    test_Alias this)
{
    corto_struct base = corto_declare(root_o, "base", corto_struct_o);
    test_assert(base != NULL);
    corto_member m = corto_declare(base, "m", corto_member_o);
    test_assert(m != NULL);
        m->type = (corto_type)corto_int32_o;
        m->modifiers |= CORTO_HIDDEN;
        test_assert(corto_define(m) == 0);
    test_assert(corto_define(base) == 0);

    corto_struct sub = corto_declare(root_o, "sub", corto_struct_o);
    corto_set_ref(&sub->super.base, base);
    sub->base_modifiers = CORTO_PRIVATE;
    test_assert(sub != NULL);
    corto_alias alias = corto_declare(sub, "m", corto_alias_o);
    test_assert(alias != NULL);
        corto_set_ref(&alias->member, m);
        test_assert(corto_define(alias) == 0);
    test_assert(corto_define(sub) != 0);
    test_assert(ut_catch() != 0);
}

void test_Alias_tc_aliasHiddenBase(
    test_Alias this)
{
    corto_struct base = corto_declare(root_o, "base", corto_struct_o);
    test_assert(base != NULL);
    corto_member m = corto_declare(base, "m", corto_member_o);
    test_assert(m != NULL);
        m->type = (corto_type)corto_int32_o;
        test_assert(corto_define(m) == 0);
    test_assert(corto_define(base) == 0);

    corto_struct sub = corto_declare(root_o, "sub", corto_struct_o);
    corto_set_ref(&sub->super.base, base);
    sub->base_modifiers = CORTO_HIDDEN;
    test_assert(sub != NULL);
    corto_alias alias = corto_declare(sub, "m", corto_alias_o);
    test_assert(alias != NULL);
        corto_set_ref(&alias->member, m);
        test_assert(corto_define(alias) == 0);
    test_assert(corto_define(sub) == 0);
}

void test_Alias_tc_aliasHiddenMember(
    test_Alias this)
{
    corto_struct base = corto_declare(root_o, "base", corto_struct_o);
    test_assert(base != NULL);
    corto_member m = corto_declare(base, "m", corto_member_o);
    test_assert(m != NULL);
        m->type = (corto_type)corto_int32_o;
        m->modifiers |= CORTO_HIDDEN;
        test_assert(corto_define(m) == 0);
    test_assert(corto_define(base) == 0);

    corto_struct sub = corto_declare(root_o, "sub", corto_struct_o);
    corto_set_ref(&sub->super.base, base);
    test_assert(sub != NULL);
    corto_alias alias = corto_declare(sub, "m", corto_alias_o);
    test_assert(alias != NULL);
        corto_set_ref(&alias->member, m);
        test_assert(corto_define(alias) == 0);
    test_assert(corto_define(sub) == 0);
}
