/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtUsuario.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 3:53 PM
 */

#include "DtUsuario.h"

DtUsuario::DtUsuario()
{
    this->cel = 0;
    this->nombre = '0';
}

DtUsuario::DtUsuario(string nombre, int cel)
{
    this->cel = cel;
    this->nombre = nombre;
}

DtUsuario::DtUsuario(const DtUsuario& orig)
{
    
}

DtUsuario::~DtUsuario()
{
    
}

int DtUsuario::getCel()
{
    return cel;
}

string DtUsuario::getNombre()
{
    return nombre;
}

