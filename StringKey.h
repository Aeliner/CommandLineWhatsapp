/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringKey.h
 * Author: nambr
 *
 * Created on 12 de junio de 2018, 03:58 PM
 */

#ifndef STRINGKEY_H
#define STRINGKEY_H
#include <iostream>
#include "string.h"
using namespace std;
#include "IKey.h"
class StringKey:public IKey {
public:
    StringKey(string);
    bool equals(IKey*);
    virtual ~StringKey();
private:
    string llave;
};

#endif /* STRINGKEY_H */

