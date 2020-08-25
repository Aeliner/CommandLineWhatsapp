/*
 * ListaIterator.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */
#ifndef _ListaIterator_H_
#define _ListaIterator_H_

#include "IIterator.h"
#include "Nodo.h"

class ListaIterator: public IIterator {
private:
  Nodo *actual;

public:
  ListaIterator(Nodo *);

  bool hasNext();
  ICollectible *next();
  ICollectible *getCurrent();
  void remove();
};

#endif /* LISTAITERATOR_H_ */
