/*
 * Collection.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef ICOLLECTION_H_
#define ICOLLECTION_H_

#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include <string>

#include "IIterator.h"
#include "ICollectible.h"
using namespace std;

class ICollection {
public:
  virtual void add(ICollectible *o) = 0;
  virtual void remove(ICollectible *o) = 0;
  virtual bool member(ICollectible *o) = 0;
  virtual IIterator *iterator() = 0;
  virtual bool isEmpty() = 0;
};

#endif

#endif /* ICOLLECTION_H_ */
