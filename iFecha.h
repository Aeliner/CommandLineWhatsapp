/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iFecha.h
 * Author: nambr
 *
 * Created on 14 de junio de 2018, 04:35 PM
 */

#ifndef IFECHA_H
#define IFECHA_H
#include "DtFecha.h"

class iFecha {
public:
    virtual void modificarFecha(DtFecha*)=0;
    virtual DtFecha* mostrarFecha()=0;
    virtual ~iFecha();
private:

};

#endif /* IFECHA_H */

