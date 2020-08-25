/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagen.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 04:47 PM
 */

#include "Imagen.h"

Imagen::Imagen(): Mensaje() {
    this->formato="No disponible";
    this->texto="No disponible";
    this->tamanio=0;
    this->url="No disponible";
//    this->codigo=0;
//    this->fecha_env;
//    this->visto=false;
}

Imagen::Imagen(string form,string tex,float tam,string url,DtFecha* fec, bool vis, Usuario* us): Mensaje(fec,vis, us) {
    this->formato=form;
    this->texto=tex;
    this->tamanio=tam;
    this->url=url;
//    this->codigo=cod;
//    this->fecha_env=fec;
//    this->visto=vis;
//    this->emisor=us;
}

Imagen::~Imagen() {
}

string Imagen::getFormato()
{
    return formato;
}

string Imagen::getTexto(){
    return texto;
}

float Imagen::getTamanio(){
    return tamanio;
}

void Imagen::setFormato(string form){
    this->formato=form;
}

void Imagen::setTexto(string tex){
    this->texto=tex;
}

void Imagen::setTamanio(float tam){
    this->tamanio=tam;
}

string Imagen::getUrl()
{
    return url;
}