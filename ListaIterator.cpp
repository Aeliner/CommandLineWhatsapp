/*
 * ListaIterator.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListaIterator.h"
#include "stdio.h"

ListaIterator::ListaIterator(Nodo *nodo)
  :actual(nodo) {
}

bool ListaIterator::hasNext() {
  return actual->hasNext();
}

ICollectible *ListaIterator::next() {
  ICollectible *res = getCurrent();
  actual = actual->getNext();
  return res;
}

ICollectible *ListaIterator::getCurrent() {
  return actual->getNext()->getICollectible();
}

void ListaIterator::remove() {
  Nodo *temp = actual->getNext();
  if (temp->hasNext()) {
    actual->setNext(temp->getNext());
  }
  else {
    actual->setNext(NULL);
  }
  temp->setNext(NULL);
  delete temp;
}



