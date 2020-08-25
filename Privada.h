/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Privada.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 04:00 PM
 */

#ifndef PRIVADA_H
#define PRIVADA_H
#include "Conversacion.h"
#include "DtPrivada.h"

class Privada: public Conversacion {
public:
    Privada();
    Privada(int );
    DtPrivada* getDato();
    ICollection* getMensaje();
    ~Privada();
private:
        
};

#endif /* PRIVADA_H */

