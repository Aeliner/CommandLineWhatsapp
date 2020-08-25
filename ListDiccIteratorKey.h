/*
 * ListDiccIteratorKey.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTDICCITERATORKEY_H_
#define LISTDICCITERATORKEY_H_


#include "ListDiccIterator.h"
#include "NodoDicc.h"
#include "ICollectible.h"

class ListDiccIteratorKey: public ListDiccIterator{
	public:
		ListDiccIteratorKey(NodoDicc* nodo);
		virtual~ ListDiccIteratorKey();
		ICollectible* getCurrent();
};

#endif /* LISTDICCITERATORKEY_H_ */
