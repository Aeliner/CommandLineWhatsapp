/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlFecha.h
 * Author: nambr
 *
 * Created on 14 de junio de 2018, 04:15 PM
 */

#ifndef CTRLFECHA_H
#define CTRLFECHA_H
#include <iostream>
#include "DtFecha.h"
#include "iFecha.h"
using namespace std;
class ctrlFecha: public iFecha {
public:
    static ctrlFecha* getInstanceF();
    ~ctrlFecha();
    void modificarFecha(DtFecha*);
    DtFecha* mostrarFecha();
private:
    DtFecha* fecha;
    ctrlFecha();
    static ctrlFecha* instanceF; 
};

#endif /* CTRLFECHA_H */

