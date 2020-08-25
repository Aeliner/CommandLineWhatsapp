/*
 * Nodo.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef NODO_H_
#define NODO_H_

#include "ICollectible.h"

class Nodo {
private:
  Nodo *next;
  ICollectible *elem;

public:
  Nodo();
  Nodo(Nodo *, ICollectible *);
  virtual ~Nodo();

  virtual void setNext(Nodo *);
  virtual Nodo *getNext();
  virtual bool hasNext();

  virtual ICollectible *getICollectible();
  virtual void setICollectible(ICollectible *);
};

#endif /* NODO_H_ */
