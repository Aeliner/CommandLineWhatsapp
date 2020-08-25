/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtVideo.cpp
 * Author: Nuevo
 * 
 * Created on 23 de junio de 2018, 03:23 PM
 */

#include "DtVideo.h"

//DtVideo::DtVideo() {
//}

DtVideo::DtVideo(string url, float dur, int cod, DtFecha* fec, bool vis, Usuario* us): DtMensaje(cod, fec, vis, us)
{
 this->url=url;
 this->duracion=dur;
}

DtVideo::DtVideo(string url, float dur, DtFecha* fec, bool vis): DtMensaje(fec, vis)
{
 this->url=url;
 this->duracion=dur;
}

DtVideo::~DtVideo() {
}

string DtVideo::getUrl()
{
    return url;
}

float DtVideo::getDuracion()
{
    return duracion;
}

