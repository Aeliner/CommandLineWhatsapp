/*
 * ListaDicc.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListaDicc.h"
#include "ListDiccIteratorObj.h"
#include <string>
using namespace std;

//constructor
ListDicc::ListDicc(){
	this->primero= new NodoDicc();
	this->tam=0;
}

//operaciones
void ListDicc:: add(ICollectible* elem,IKey* key){
	Par* p= new Par(elem,key);
	NodoDicc* aux= new NodoDicc(this->primero->getNext(),p);
	this->tam++;
	this->primero->setNext(aux);
}

bool ListDicc:: member(IKey* key){
	NodoDicc* nodo_aux= this->primero;
	while((nodo_aux->hasNext())&&(!(nodo_aux->getNext()->getPar()->getKey()->equals(key)))){
		nodo_aux=nodo_aux->getNext();
	}
	if(nodo_aux->hasNext()){
		return(true);
	}else{
		return(false);
	}
}

ICollectible* ListDicc::removeKey(IKey* key){
	NodoDicc* aux=this->primero;
	while ((aux->hasNext())&&(!(aux->getNext()->getPar()->getKey()->equals(key))))
		aux=aux->getNext();
	if (aux->hasNext()){
		NodoDicc* temp=aux->getNext();
		aux->setNext(aux->getNext()->getNext());
		temp->setNext(NULL);
		Par* p=temp->getPar();
		ICollectible* objeto= p->getObject();
		this->tam--;
		delete(temp);
		return(objeto);
	}
	return NULL;
}

ICollectible* ListDicc::removeObj(ICollectible* obj){
	NodoDicc* aux=this->primero;
	while ((aux->hasNext())&&(aux->getNext()->getPar()->getObject()!=obj))
		aux=aux->getNext();
	if (aux->hasNext()){
		NodoDicc* temp=aux->getNext();
		aux->setNext(aux->getNext()->getNext());
		temp->setNext(NULL);
		Par* p=temp->getPar();
		ICollectible* objeto= p->getObject();
		this->tam--;
		delete(temp);
		return(objeto);
	}
	return NULL;
}

ICollectible* ListDicc:: find(IKey* key){
	NodoDicc* aux= this->primero;
	while ((aux->hasNext())&&(!(aux->getNext()->getPar()->getKey()->equals(key))))
		aux=aux->getNext();
	if (aux->hasNext())
		return(aux->getNext()->getPar()->getObject());
	return NULL;
}

ListDiccIteratorObj* ListDicc::getIteratorObj(){
	return(new ListDiccIteratorObj(this->primero));
}


ListDiccIteratorKey* ListDicc:: getIteratorKey(){
	return(new ListDiccIteratorKey(this->primero));
}


unsigned int ListDicc:: size(){
	return(this->tam);
}

//destructor
ListDicc:: ~ListDicc(){
	delete(this->primero);
}


