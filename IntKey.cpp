/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntKey.cpp
 * Author: nambr
 * 
 * Created on 12 de junio de 2018, 04:23 PM
 */

#include "IntKey.h"

IntKey::IntKey(int llave)
{
    this->llave = llave;
}


IntKey::~IntKey() {
}

bool IntKey::equals(IKey* llavesita)
{
    IntKey* llavesota = (IntKey*) (llavesita);
    return (this->llave == llavesota->llave);
}