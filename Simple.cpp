/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simple.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 04:24 PM
 */

#include "Simple.h"
#include "Simple.h"

Simple::Simple(): Mensaje() {
//    this->codigo=0;
//    this->fecha_env;
//    this->visto=false;
    this->texto="No disponible";
    
}

Simple::Simple(string tex, DtFecha* fec, bool vis, Usuario* emisor): Mensaje(fec,vis,emisor) {
    this->texto=tex;
//    this->codigo=ide;
//    this->fecha_env=fec;
//    this->visto=vis;
//    this->emisor=emisor;
}

Simple::~Simple() {
}

string Simple::getTexto(){
    return texto;
}

void Simple::setTexto(string tex)
{
    this->texto=tex;

}