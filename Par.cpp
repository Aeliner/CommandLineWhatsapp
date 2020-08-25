/*
 * Par.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */
#include "Par.h"
#include <stdlib.h>

Par::Par(){
}

Par::Par(ICollectible* object, IKey* key){
	this->object=object;
	this->key=key;
}

IKey* Par:: getKey(){
	return(this->key);
}

ICollectible* Par::getObject(){
	return(this->object);
}

Par:: ~Par(){
	delete this->key;
}



