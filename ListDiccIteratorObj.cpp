/*
 * ListDiccIteratorObj.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListDiccIteratorObj.h"
#include "Par.h"

ListDiccIteratorObj::ListDiccIteratorObj(NodoDicc* nodo): ListDiccIterator(nodo)
{
    
}

ListDiccIteratorObj::~ListDiccIteratorObj(){}

ICollectible* ListDiccIteratorObj::getCurrent(){
	Par* p=(Par*)ListDiccIterator::getCurrent();
	return(p->getObject());
}


