/*
 * NodoDicc.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "NodoDicc.h"
#include "stdio.h"

//constructores
NodoDicc::NodoDicc(){
	this->par=NULL;
	this->next=NULL;
}

NodoDicc::NodoDicc(NodoDicc* next, Par* par){
	this->par=par;
	this->next=next;
}

//operaciones
void NodoDicc::setNext(NodoDicc* next){
	this->next=next;
}

bool NodoDicc:: hasNext(){
	return(this->next!=NULL);
}

NodoDicc* NodoDicc:: getNext(){
	return(this->next);
}

Par* NodoDicc::getPar(){
	return(this->par);
}

void NodoDicc::setPar(Par* par){
	this->par=par;
}

//destructor
NodoDicc:: ~NodoDicc(){
	if(this->par!=NULL)
		delete(par);
	if(this->hasNext())
		delete(this->next);
}


