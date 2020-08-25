/*
 * Lista.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "ICollection.h"
#include "Nodo.h"
#include "ListaIterator.h"
#include "ICollectible.h"
class Lista: public ICollection {
private:
  Nodo *first;
  
public:
  Lista();
  ~Lista();

  void add(ICollectible *);
  void remove(ICollectible *);
  bool member(ICollectible *);
  IIterator *iterator();

  bool isEmpty();
};

#endif /* LISTA_H_ */
