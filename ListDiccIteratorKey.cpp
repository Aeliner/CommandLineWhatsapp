/*
 * ListDiccIteratorKey.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListDiccIteratorKey.h"

ListDiccIteratorKey::ListDiccIteratorKey(NodoDicc* nodo): ListDiccIterator(nodo){}

ListDiccIteratorKey::~ListDiccIteratorKey(){}

ICollectible* ListDiccIteratorKey:: getCurrent(){
	Par* p=(Par*)ListDiccIterator::getCurrent();
	return(p->getKey());
}
