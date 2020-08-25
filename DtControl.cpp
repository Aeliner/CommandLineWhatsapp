/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtControl.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 3:51 PM
 */

#include "DtControl.h"

DtControl::DtControl()
{
    
}

DtControl::DtControl(bool existe, bool sesion)
{
    this->existe = existe;
    this->sesion = sesion;
}

DtControl::~DtControl()
{
    
}

bool DtControl::getExiste()
{
    return existe;
}

bool DtControl::getSesion()
{
    return sesion;
}

void DtControl::setExiste(bool ex)
{
    this->existe = ex;
}

void DtControl::setSesion(bool se)
{
    this->sesion = se;
}

