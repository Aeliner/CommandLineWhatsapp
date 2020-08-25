/*
 * Nodo.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "Nodo.h"
#include "stdio.h"

Nodo::Nodo()
  :next(NULL), elem(NULL) {
}

Nodo::Nodo(Nodo *next, ICollectible *ICollectible)
  :next(next), elem(ICollectible) {
}

Nodo::~Nodo() {
  if (next != NULL) {
    delete next;
  }
  elem = NULL;
}


void Nodo::setNext(Nodo *next) {
  this->next = next;
}

Nodo *Nodo::getNext() {
  return next;
}

bool Nodo::hasNext() {
  return next != NULL;
}

ICollectible *Nodo::getICollectible() {
  return elem;
}

void Nodo::setICollectible(ICollectible *ICollectible) {
  this->elem = ICollectible;
}



