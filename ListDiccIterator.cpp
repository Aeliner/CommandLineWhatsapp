/*
 * ListDiccIterator.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListDiccIterator.h"
#include "stdio.h"

//constructores
ListDiccIterator::ListDiccIterator(){}
ListDiccIterator::ListDiccIterator(NodoDicc* current){
    this->current=current;
}
//operaciones
ICollectible* ListDiccIterator::getCurrent(){
	return(this->current->getNext()->getPar());
}

bool ListDiccIterator::hasNext(){
   return(this->current->hasNext());
}

ICollectible *ListDiccIterator::next(){
	ICollectible *res = this->getCurrent() ;
	current = current->getNext();
	return res;
}

//destructor
ListDiccIterator::~ListDiccIterator(){
	this->current=NULL;
}

void ListDiccIterator::remove() {
  NodoDicc *temp = current->getNext();
  if (temp->hasNext()) {
	  current->setNext(temp->getNext());
  }
  else {
	  current->setNext(NULL);
  }
  temp->setNext(NULL);
  delete temp;
}
