/*
 * IIterator.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef IIterator_H_
#define IIterator_H_

#include "ICollectible.h"

class IIterator {
public:
  virtual bool hasNext() = 0;
  virtual ICollectible *next() = 0;
  virtual ICollectible *getCurrent() = 0;
  virtual void remove() = 0;
};

#endif /* IIterator_H_ */
