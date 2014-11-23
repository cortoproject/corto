/*
 * collection.hpp
 *
 *  Created on: Jan 27, 2013
 *      Author: sander
 */

#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_

namespace hyve {
	typedef int (*compareAction)(void* o1, void* o2);
	typedef int (*walkAction)(void* o, void* userData);

	class ll;
	class rbtree;
}

#endif /* COLLECTION_HPP_ */
