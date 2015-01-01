/*
 * tc_call.c
 *
 *  Created on: Oct 16, 2012
 *      Author: sander
 */

#include "tc_call__type.h"
#include "tc_call__meta.h"
#include "tc_call__api.h"
#include "tc_Animal.h"
#include "cortex.h"

/* Call non-virtual function */
int tc_call_01(void) {
	tc_Animal animal;
	tc_AnimalKind kind;
	cx_method m_getKind;

	kind = 0;

	/* Create reptile animal */
	animal = tc_Animal__create(TC_REPTILE);

	/* Resolve Animal::getKind */
	m_getKind = cx_interface_resolveMethod(cx_interface(tc_Animal_o), "getKind");

	/* Call method */
	cx_call(cx_function(m_getKind), &kind, animal);

	/* Free object */
	cx_free(animal);

	/* Test succeeded if kind == TC_REPTILE */
	return !(kind == TC_REPTILE);
}

/* Call virtual function */
int tc_call_02(void) {
	tc_Mammal m1, m2, m3;
	int result;

	result = 0;

	/* Create two mammals */
	m1 = tc_Mammal__create(TC_PRIMATE);
	m2 = tc_Mammal__create(TC_RODENTIA);
	m3 = tc_Mammal__create(TC_RODENTIA);

	/* Call method (uses generated virtual method to C mapping) */
	if (tc_Animal_matesWith(tc_Animal(m1), tc_Animal(m2))) {
		result = -1;
	}

	if (!tc_Animal_matesWith(tc_Animal(m2), tc_Animal(m3))) {
		result = -1;
	}

	cx_free(m1);
	cx_free(m2);
	cx_free(m3);

	return result;
}

/* Call functions with complex parameters */
int tc_call_03(void) {
	tc_Mammal m;
	tc_MammalProps props, result;
	cx_method m_setProps, m_getProps;
	int ret;

	/* memset, so padding bytes are also zero'd */
	memset(&props, 0, sizeof(tc_MammalProps));

	/* Create mammal */
	m = tc_Mammal__create(TC_CARNIVORA);

	/* Resolve methods */
	m_setProps = cx_interface_resolveMethod(cx_interface(tc_Mammal_o), "setProps");
	m_getProps = cx_interface_resolveMethod(cx_interface(tc_Mammal_o), "getProps");

	/* Set props */
	props.habitat = TC_AIR;
	props.legs = 10;
	props.speed = 20.64;
	cx_call(cx_function(m_setProps), NULL, m, props);

	/* Get props */
	cx_call(cx_function(m_getProps), &result, m, 42);

	cx_free(m);

	/* Compare props */
	ret = memcmp(&props, &result, sizeof(tc_MammalProps));

	/* If failed, print details */
	if (ret) {
	    printf("expected props = legs(%d), habitat(%d), speed(%f).\n", props.legs, props.habitat, props.speed);
	    printf("got      props = legs(%d), habitat(%d), speed(%f).\n", result.legs, result.habitat, result.speed);
	}

	return ret;
}

/* Call functions with double argument and returnvalue */
int tc_call_04(void) {
	tc_Mammal m;
	cx_method m_setSpeed, m_getSpeed;
	cx_float64 speed, result;

	m = tc_Mammal__create(TC_CHIROPTERA);

	/* Resolve methods */
	m_setSpeed = cx_interface_resolveMethod(cx_interface(tc_Mammal_o), "setSpeed");
	m_getSpeed = cx_interface_resolveMethod(cx_interface(tc_Mammal_o), "getSpeed");

	/* Set speed */
	speed = 10.1;
	cx_call(cx_function(m_setSpeed), NULL, m, speed);

	/* Get speed */
	cx_call(cx_function(m_getSpeed), &result, m);

	cx_free(m);

	return memcmp(&speed, &result, sizeof(cx_float64));
}

/* Test call-functionality */
int main(int argc, char* argv[]) {
	int result;
    DB_UNUSED(argc);
    DB_UNUSED(argv);

    result = 0;

    /* Start database */
    cx_start();

    /* Load testcase-types */
    tc_call_load();

    /* Test 1, call non-virtual function */
    if (tc_call_01()) {
        printf("tc_call_01 failed.\n");
    	result = -1;
    }

    /* Test 2, call virtual functions */
    if (tc_call_02()) {
        printf("tc_call_02 failed.\n");
    	result = -1;
    }

    /* Test 3, complex types in argument-list or as returnType */
    if (tc_call_03()) {
        printf("tc_call_03 failed.\n");
    	result = -1;
    }

    /* Test 4, double types in argument-list or as returnType */
    if (tc_call_04()) {
        printf("tc_call_04 failed.\n");
    	result = -1;
    }

    if (!result) {
        printf("tc_call success.\n");
    }

    /* Stop database */
    cx_stop();

    return result;
}
