/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntKey.h
 * Author: nambr
 *
 * Created on 12 de junio de 2018, 04:23 PM
 */

#ifndef INTKEY_H
#define INTKEY_H
#include "IKey.h"
class IntKey:public IKey {
public:
    IntKey(int);
    bool equals(IKey*);
    virtual ~IntKey();
private:
    int llave;
};

#endif /* INTKEY_H */

