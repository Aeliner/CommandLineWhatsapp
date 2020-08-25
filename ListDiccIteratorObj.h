/*
 * ListDiccIteratorObj.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTDICCITERATOROBJ_H_
#define LISTDICCITERATOROBJ_H_

#include "ListDiccIterator.h"
#include "NodoDicc.h"

class ListDiccIteratorObj : public ListDiccIterator{
	public:
		ListDiccIteratorObj(NodoDicc* nodo);
		virtual~ ListDiccIteratorObj();
		ICollectible* getCurrent();
};


#endif /* LISTDICCITERATOROBJ_H_ */
