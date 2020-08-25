/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 04:24 PM
 */

#ifndef SIMPLE_H
#define SIMPLE_H
#include <iostream>
#include <string>
#include "Mensaje.h"
using namespace std;

class Simple: public Mensaje{
public:
    Simple();
    Simple(string,DtFecha*, bool, Usuario*);
    string getTexto();
    void setTexto(string);
    virtual ~Simple();
private:
    string texto;
};

#endif /* SIMPLE_H */

