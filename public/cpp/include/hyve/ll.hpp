/*
 * ll.hpp
 *
 *  Created on: Jan 27, 2013
 *      Author: sander
 */

#ifndef LL_HPP_
#define LL_HPP_

#include "def.hpp"
#include "hyve/lang/_type.hpp"
#include "collection.hpp"

namespace hyve {
	typedef void* ll_h;

	/* Linked list implementation */
	class ll {
	public:
		ll();
		ll(ll_h handle);
		~ll();

		class node;

		static ll_h _new();

		/* Walk elements */
		int walk(hyve::walkAction action, void* userData);

		/* Insert element at beginning of list */
		void insert(void* data);

		/* Insert element at end of list */
		void append(void* data);

		/* Remove element */
		void remove(void* data);

		/* Replace element */
		void replace(void* object, void* by);

		/* Take first element */
		void* takeFirst();

		/* Random access read */
		void* get(int index);

		/* Find element */
		void* find(hyve::compareAction compare, void* object);

		/* Check if object is in list */
		hyve::lang::_bool hasObject(void* object);

		/* Last element */
		void* last();

		/* Size of list */
		int size();

		/* Merge with other list */
		void merge(hyve::ll* list);

		/* Get handle */
		void* getHandle();

	private:
		ll_h handle;
		hyve::lang::_bool owned;
	};
}


#endif /* LL_HPP_ */
