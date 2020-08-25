/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtImagen.cpp
 * Author: nambr
 * 
 * Created on 13 de junio de 2018, 08:33 PM
 */

#include "DtImagen.h"

DtImagen::DtImagen(string url, string formato, float tamanio, string texto, int cod, DtFecha* fec, bool visto, Usuario* us): DtMensaje(cod, fec, visto, us) {
    this->url=url;
    this->formato=formato;
    this->tamanio=tamanio;
    this->texto=texto;
}

DtImagen::DtImagen(string url, string formato, float tamanio, string texto, DtFecha* fec, bool visto): DtMensaje(fec, visto) {
    this->url=url;
    this->formato=formato;
    this->tamanio=tamanio;
    this->texto=texto;
}

string DtImagen::getFormato(){
    return formato;
}

float DtImagen::getTamanio(){
    return tamanio;
}

string DtImagen::getUrl()
{
    return url;
}

string DtImagen::getTexto(){
    return texto;
}

DtImagen::~DtImagen() {
}

