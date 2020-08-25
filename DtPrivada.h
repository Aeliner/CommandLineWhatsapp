/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtPrivada.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 4:15 PM
 */

#ifndef DTPRIVADA_H
#define DTPRIVADA_H

#include "DtConv.h"
#include <iostream>
#include <string>
using namespace std;

class DtPrivada:public DtConv {
public:
    DtPrivada();
    DtPrivada(string, int, int);
    DtPrivada(bool, int, string, int);
    string getNombre();
    int getNumero();
    DtPrivada(const DtPrivada& orig);
    virtual ~DtPrivada();
private:
    string nombre;
    int numero;
};

#endif /* DTPRIVADA_H */

