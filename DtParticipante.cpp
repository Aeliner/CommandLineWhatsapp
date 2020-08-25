/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtParticipante.cpp
 * Author: Aeliner
 * 
 * Created on June 25, 2018, 10:26 PM
 */

#include "DtParticipante.h"

DtParticipante::DtParticipante()
{
    this->admin = false;
    this->fecha;
    this->nombre = "No disponible";
    this->numero = 0;
}

DtParticipante::DtParticipante(string nombre, int numero, DtFecha* fecha, bool admin)
{
    this->nombre = nombre;
    this->fecha = fecha;
    this->numero = numero;
    this->admin = admin;
}

DtParticipante::~DtParticipante() 
{
    
}

string DtParticipante::getNombre()
{
    return this->nombre;
}

int DtParticipante::getNum()
{
    return this->numero;
}

DtFecha* DtParticipante::getFecha()
{
    return this->fecha;
}

bool DtParticipante::getAdmin()
{
    return this->admin;
}
