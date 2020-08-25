/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DtMensaje.h"
#include "ctrlConv.h"


DtMensaje::DtMensaje(int cod, DtFecha* fecha, bool visto, Usuario* emis)
{
    this->codigo = cod;
    this->fecha_env = fecha;
    this->visto = visto;
    this->emisor = emis;
}

DtMensaje::DtMensaje(DtFecha* fecha, bool visto)
{
    this->fecha_env = fecha;
    this->visto = visto;
}


DtMensaje::~DtMensaje()
{
    
}

int DtMensaje::getCodigo()
{
    return codigo;
}

DtFecha* DtMensaje::getFecha()
{
    return fecha_env;
}

bool DtMensaje::getVisto()
{
    return visto;
}

Usuario* DtMensaje::getEmisor()
{
    return emisor;
}

