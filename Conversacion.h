/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 8:19 PM
 */

#ifndef CONVERSACION_H
#define CONVERSACION_H

#include "DtConv.h"
#include "DtMensaje.h"
#include "Est_Conv.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "Mensaje.h"


class Est_Conv;
class Conversacion {
public:
    Conversacion(int);
    Conversacion();
    virtual int getIdentificador();
    void setIdentificador(int);
    void setearEc2(Est_Conv*);
    ICollection* listarUsus();
    virtual DtConv* getDato()=0;
    virtual ICollection* getMensaje()=0;
    bool sosVos(int);
    void archivar(int);
    Conversacion* selecConv();
    void actualizarVisto(int);
    void crearMensaje(DtMensaje&, Usuario*);
    ICollection* selec(int);
    int encontrarMens(int);
    void eliminar(int);
    void desvincular(int);
    virtual ~Conversacion();
    ICollection* listarPart();
    IDictionary* LisMen();
protected:
    int identificador = 0;
    int generador;
    IDictionary* mensaje;
    ICollection* est_conv;
};

#endif /* CONVERSACION_H */

