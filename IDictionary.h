/*
 * IDictionary.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef IDICTIONARY_H_
#define IDICTIONARY_H_

#include "ICollectible.h"
#include "IKey.h"
#include "IIterator.h"

class IDictionary{
	public:
		virtual void add(ICollectible* elem, IKey* key)=0;
		virtual bool member(IKey* key)=0;
		virtual ICollectible* removeKey(IKey* key)=0;
		virtual ICollectible* removeObj(ICollectible* obj)=0;
		virtual ICollectible* find(IKey* key)=0;
		virtual IIterator* getIteratorObj()=0;
		virtual IIterator* getIteratorKey()=0;
		virtual unsigned int size()=0;
		virtual ~IDictionary();
};

#endif /* IDICTIONARY_H_ */
