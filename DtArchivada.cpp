/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtArchivada.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 4:20 PM
 */

#include "DtArchivada.h"

DtArchivada::DtArchivada()
{
    this->visto = false;
    this->ident = 0;
    this->cantidad = 0;
}

DtArchivada::DtArchivada(bool visto, int identificador, int cantidad):DtConv(visto, identificador)
{
    this->visto = visto;
    this->ident = ident;
    this->cantidad = cantidad;
}

DtArchivada::DtArchivada(int cant){
    this->cantidad=cant;
}

DtArchivada::DtArchivada(const DtArchivada& orig)
{
    
}

DtArchivada::~DtArchivada()
{
    
}

int DtArchivada::getCant()
{
    return cantidad;
}