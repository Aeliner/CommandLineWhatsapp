/*
 * Lista.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "Lista.h"
#include <string.h>

Lista::Lista() {
  //first = NULL;
  first = new Nodo();
}

Lista::~Lista() {
	//if (first!=NULL) delete first;
	delete first;
}

void Lista::add(ICollectible *o) {
  Nodo *nuevo = new Nodo(first->getNext(), o);
  first->setNext(nuevo);
}

void Lista::remove(ICollectible *o) {
  IIterator *iter = iterator();
  bool fin = false;
  while (iter->hasNext() && !fin) {
    if (o == iter->getCurrent()) {
      iter->remove();
      fin = true;
    }
    else {
      iter->next();
    }
  }
  delete iter;
}

bool Lista::member(ICollectible *o) {
  IIterator *iter = iterator();
  bool encontre = false;

  while (iter->hasNext() && !encontre) {
    if (o == iter->next()) {
      encontre = true;
    }
  }

  delete iter;
  return encontre;
}


IIterator *Lista::iterator() {
  return new ListaIterator(first);
}

bool Lista::isEmpty() {
  return !first->hasNext();
}





