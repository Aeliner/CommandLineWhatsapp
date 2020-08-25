/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSimple.h
 * Author: Nuevo
 *
 * Created on 23 de junio de 2018, 03:14 PM
 */

#ifndef DTSIMPLE_H
#define DTSIMPLE_H
#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtSimple: public DtMensaje {
public:
    DtSimple();
    DtSimple(string, int, DtFecha*, bool, Usuario*);
    DtSimple(string,DtFecha*, bool);
    string getTexto();
    virtual ~DtSimple();
private:
    string texto;

};

#endif /* DTSIMPLE_H */

