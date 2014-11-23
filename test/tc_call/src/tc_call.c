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
#include "hyve.h"

/* Call non-virtual function */
int tc_call_01(void) {
	tc_Animal animal;
	tc_AnimalKind kind;
	db_method m_getKind;

	kind = 0;

	/* Create reptile animal */
	animal = tc_Animal__create(TC_REPTILE);

	/* Resolve Animal::getKind */
	m_getKind = db_interface_resolveMethod(db_interface(tc_Animal_o), "getKind");

	/* Call method */
	db_call(db_function(m_getKind), &kind, animal);

	/* Free object */
	db_free(animal);

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

	db_free(m1);
	db_free(m2);
	db_free(m3);

	return result;
}

/* Call functions with complex parameters */
int tc_call_03(void) {
	tc_Mammal m;
	tc_MammalProps props, result;
	db_method m_setProps, m_getProps;
	int ret;

	/* memset, so padding bytes are also zero'd */
	memset(&props, 0, sizeof(tc_MammalProps));

	/* Create mammal */
	m = tc_Mammal__create(TC_CARNIVORA);

	/* Resolve methods */
	m_setProps = db_interface_resolveMethod(db_interface(tc_Mammal_o), "setProps");
	m_getProps = db_interface_resolveMethod(db_interface(tc_Mammal_o), "getProps");

	/* Set props */
	props.habitat = TC_AIR;
	props.legs = 10;
	props.speed = 20.64;
	db_call(db_function(m_setProps), NULL, m, props);

	/* Get props */
	db_call(db_function(m_getProps), &result, m, 42);

	db_free(m);

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
	db_method m_setSpeed, m_getSpeed;
	db_float64 speed, result;

	m = tc_Mammal__create(TC_CHIROPTERA);

	/* Resolve methods */
	m_setSpeed = db_interface_resolveMethod(db_interface(tc_Mammal_o), "setSpeed");
	m_getSpeed = db_interface_resolveMethod(db_interface(tc_Mammal_o), "getSpeed");

	/* Set speed */
	speed = 10.1;
	db_call(db_function(m_setSpeed), NULL, m, speed);

	/* Get speed */
	db_call(db_function(m_getSpeed), &result, m);

	db_free(m);

	return memcmp(&speed, &result, sizeof(db_float64));
}

/* Test call-functionality */
int main(int argc, char* argv[]) {
	int result;
    DB_UNUSED(argc);
    DB_UNUSED(argv);

    result = 0;

    /* Start database */
    db_start();

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
    db_stop();

    return result;
}
