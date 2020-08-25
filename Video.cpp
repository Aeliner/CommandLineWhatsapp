/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Video.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 05:13 PM
 */

#include "Video.h"

Video::Video(): Mensaje() {
    this->duracion=0;
    this->url="No disponible";
//    this->codigo=0;
//    this->fecha_env;
//    this->visto=false;
    
}

Video::Video(float dura,string url, DtFecha* fec,bool vis, Usuario* us): Mensaje(fec,vis, us) {
    this->duracion=dura;
    this->url=url;
//    this->codigo=cod;
//    this->fecha_env=fec;
//    this->visto=vis;
//    this->emisor=us;
    
    
}

Video::~Video() {
}

float Video::getDuracion(){
return duracion;
}

string Video::getUrl(){
    return url;
}

void Video::setDuracion(float dura) {
    this->duracion=dura;
}

void Video::setUrl(string url) {
    this->url=url;
}