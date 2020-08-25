/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FechaHora.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 2:31 PM
 */

#include "DtFecha.h"
#include <stdexcept>
DtFecha::DtFecha()
{
    this->anio = 1900;
    this->mes = 1;
    this->dia = 1;
    this-> hora = 0;
    this-> min = 0;
    this-> seg = 0;
}
DtFecha::DtFecha(int anio, int mes, int dia, int hora, int min, int seg)
{
    if(anio < 1900 || dia > 31 ||dia < 1 || hora > 23 || hora < 0|| min > 59 ||min < 0|| seg > 59 ||seg < 0|| mes > 12 || mes < 1)
    {
        throw std::invalid_argument("Fecha invalida");
    }
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
}

DtFecha::~DtFecha()
{
    
}

int DtFecha::getAnio()
{
    return anio;
}

int DtFecha::getMes()
{
    return mes;
}

int DtFecha::getDia()
{
    return dia;
}

int DtFecha::getHora()
{
    return hora;
}

int DtFecha::getMin()
{
    return min;
}

int DtFecha::getSeg()
{
    return seg;
}

ostream& operator<<(ostream& os, const DtFecha &fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio<< "  " << fecha.hora<< ":" <<fecha.min<< ":" <<fecha.seg;
    return os;
}


