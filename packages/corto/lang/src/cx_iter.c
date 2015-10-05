
#include "cx_iter.h"

void cx_iterMoveFirst(cx_iter* iter) {
	iter->moveFirst(iter);
}

void* cx_iterMove(cx_iter* iter, unsigned int index) {
	return iter->move(iter, index);
}

int cx_iterHasNext(cx_iter* iter) {
	return iter->hasNext(iter);
}

void* cx_iterNext(cx_iter* iter) {
	return iter->next(iter);
}

void* cx_iterNextPtr(cx_iter* iter) {
	return iter->nextPtr(iter);
}

void* cx_iterRemove(cx_iter* iter) {
	return iter->remove(iter);
}

void cx_iterInsert(cx_iter* iter, void* o) {
	iter->insert(iter, o);
}

void cx_iterSet(cx_iter* iter, void* o) {
	iter->set(iter, o);
}

