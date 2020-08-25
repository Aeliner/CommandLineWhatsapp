/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtGrupo.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 4:07 PM
 */

#include "DtGrupo.h"

DtGrupo::DtGrupo()
{
    
}



DtGrupo::DtGrupo(bool visto, int identificador, string nombre):DtConv(visto, identificador)
{
    this->visto = visto;
    this->ident = ident;
    this->nombre = nombre;
}

DtGrupo::DtGrupo(string nombre, int identificador){
    this->nombre = nombre;
    this->ident = identificador;
}

DtGrupo::DtGrupo(const DtGrupo& orig)
{
    
}

DtGrupo::~DtGrupo()
{
    
}

string DtGrupo::getNombre()
{
    return nombre;
}

