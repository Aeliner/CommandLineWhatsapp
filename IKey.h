/*
 * IKey.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef IKEY_H_
#define IKEY_H_

#include "ICollectible.h"

class IKey: public ICollectible{
	public:
		virtual bool equals(IKey* key)=0;
		virtual ~IKey();
};

#endif /* IKEY_H_ */
