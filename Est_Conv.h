/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Est_Conv.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 8:46 PM
 */

#ifndef EST_CONV_H
#define EST_CONV_H
#include "ICollectible.h"
#include "DtConv.h"
#include "IDictionary.h"
#include "Conversacion.h"
#include "DtArchivada.h"
#include "ICollection.h"
#include<iostream>
class Usuario;
class Conversacion;
using namespace std;
class Est_Conv: public ICollectible {
public:
    Est_Conv();
    Est_Conv(bool,Conversacion*,Usuario*);
    DtArchivada* getArch();
    bool getEstado();
    void setEstado(bool);
    bool esArch();
    DtConv* getDato();
    Conversacion* selecConv(int);
    Usuario* getUsuario();
    void traerConv(int);
    bool esConv(int);
    ICollection* getMens();
    ICollection* selectMns(int);
    int traerMensaje(int);
    void eliminar(int);

    virtual ~Est_Conv();
private:
    
    bool activo;
    Conversacion* conv;
    Usuario* usu;
};

#endif /* EST_CONV_H */

