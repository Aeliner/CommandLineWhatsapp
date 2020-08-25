/*
 * ListaDicc.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTADICC_H_
#define LISTADICC_H_

#include "NodoDicc.h"
#include "IIterator.h"
#include "ICollectible.h"
#include "IDictionary.h"
#include "ListDiccIterator.h"
#include "ListDiccIteratorObj.h"
#include "ListDiccIteratorKey.h"

class ListDicc: public IDictionary{
	private:
		NodoDicc* primero;
		unsigned int tam;
	public:
		//constructores
		ListDicc();

		//operaciones
		void add(ICollectible* elem,IKey* key);
		bool member(IKey* key);
		ICollectible* removeKey(IKey* key);
		ICollectible* removeObj(ICollectible* obj);
		ICollectible* find(IKey* key);
		ListDiccIteratorObj* getIteratorObj();
		ListDiccIteratorKey* getIteratorKey();
		unsigned int size();

		//destructor
		virtual ~ListDicc();
};

#endif /* LISTADICC_H_ */
