/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 04:41 PM
 */

#ifndef CONTACTO_H
#define CONTACTO_H
#include "Mensaje.h"
class Contacto: public Mensaje{
public:
    Contacto();
    Contacto(string,int,DtFecha*, bool, Usuario*);
    string getNombre();
    int getCel();
    virtual ~Contacto();
private:
    string nombre;
    int cel;
};

#endif /* CONTACTO_H */

