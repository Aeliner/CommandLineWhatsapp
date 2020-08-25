/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 04:14 PM
 */

#include "Visto.h"
#include "ctrlFecha.h"

Visto::Visto() {
    this->usuario=NULL;
    this->visto = false;
    this->fecha = NULL;
}

Visto::Visto(bool vis, DtFecha* fec, Usuario* u) {
    this->usuario=u;
    this->visto=vis;
    this->fecha=fec;
}

Visto::Visto(bool vis, Usuario* u){
    this->usuario=u;
    this->visto=vis;
}

Visto::~Visto() {
}

bool Visto::getVisto()
{
    return visto;
}

DtFecha* Visto::getFecha()
{ 
    return fecha;
}

void Visto::setVisto(bool vis)
{
    this->visto = vis;
}

void Visto::setFecha(DtFecha* fec)
{
    this->fecha=fec;
}

Usuario* Visto::getUsu(){
    return usuario;
}

bool Visto::noFueVisto(int usu)
  {
    if( this->usuario->getCel() == usu){
        this->visto=true;
        this->fecha = ctrlFecha::getInstanceF()->mostrarFecha();
         return true;
       }
    return false;
  }

bool Visto::borrar(int cel){
    return this->desvReceptores(cel);
 }
 
 bool Visto::desvReceptores(int cel){
     if(this->usuario->getCel() == cel){
         this->usuario = NULL;
         return true;
     }
     return false;
 }

void Visto::desvin()
{
    this->usuario = NULL;
    
}
