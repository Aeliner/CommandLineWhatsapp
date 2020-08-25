/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtConv.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 3:57 PM
 */

#include "DtConv.h"

DtConv::DtConv()
{
    
}

DtConv::DtConv(bool visto, int identificador)
{
    this->ident = identificador;
    this->visto = visto;
}

DtConv::DtConv(const DtConv& orig)
{
    
}

DtConv::~DtConv()
{
    
}

bool DtConv::getVisto()
{
    return visto;
}

int DtConv::getId()
{
    return this->ident;
}

