/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtPrivada.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 4:15 PM
 */

#include "DtPrivada.h"

DtPrivada::DtPrivada()
{
    this->visto = false;
    this->ident = 0;
    this->nombre = "No disponible";
    this->numero = 0;
}

DtPrivada::DtPrivada(bool visto, int identificador, string nombre, int numero):DtConv(visto, identificador)
{
    this->visto = visto;
    this->ident = identificador;
    this->nombre = nombre;
    this->numero = numero;
}

DtPrivada::DtPrivada(string nom, int cel, int numerito){
    this->nombre=nom;
    this->numero=cel;
    this->ident = numerito;
}

DtPrivada::DtPrivada(const DtPrivada& orig)
{
    
}

DtPrivada::~DtPrivada()
{
    
}

string DtPrivada::getNombre()
{
    return nombre;
}

int DtPrivada::getNumero()
{
    return numero;
}


