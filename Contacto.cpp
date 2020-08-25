/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 04:41 PM
 */

#include "Contacto.h"

Contacto::Contacto():Mensaje() {
    this->cel = 0;
    this->nombre = "No disponible";
}

Contacto::Contacto(string nombre, int cel,DtFecha* fec, bool vis, Usuario* us): Mensaje(fec, vis, us) {
    this->cel = cel;
    this->nombre = nombre;
}

Contacto::~Contacto() {
}

string Contacto::getNombre()
{
    return nombre;
}

int Contacto::getCel()
{
    return cel;
}