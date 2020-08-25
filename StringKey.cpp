/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringKey.cpp
 * Author: nambr
 * 
 * Created on 12 de junio de 2018, 03:58 PM
 */

#include "StringKey.h"
#include <string.h>
#include <stdio.h>

StringKey::StringKey(string llave)
{
    this->llave = llave;
}

bool StringKey::equals(IKey* llavesita)
{
    
 StringKey* llavesota = (StringKey*) (llavesita);
    if (this->llave.compare(llavesota->llave)==0)
  return true;
   return false;
 
 //    int ret= strcmp(this->llave, llavesota->llave) ;
//    if (ret == 0)
//    return true;
//    else return false;
}

StringKey::~StringKey() {
}

