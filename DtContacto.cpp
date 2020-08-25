/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContacto.cpp
 * Author: Nuevo
 * 
 * Created on 23 de junio de 2018, 03:29 PM
 */

#include "DtContacto.h"

//DtContacto::DtContacto() {
//}

DtContacto::DtContacto(string nom, int cel, int cod, DtFecha* fec, bool vis, Usuario* us): DtMensaje(cod, fec, vis, us)
{
    this->nombre=nom;
    this->cel=cel;
}

DtContacto::DtContacto(string nom, int cel, DtFecha* fec, bool vis): DtMensaje(fec, vis)
{
    this->nombre=nom;
    this->cel=cel;
}

DtContacto::~DtContacto() {
}

int DtContacto::getCel()
{
    return cel;
}

string DtContacto::getNombre()
{
    return nombre;
}

