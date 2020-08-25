/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtVideo.h
 * Author: Nuevo
 *
 * Created on 23 de junio de 2018, 03:23 PM
 */

#ifndef DTVIDEO_H
#define DTVIDEO_H
#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtVideo: public DtMensaje {
public:
    DtVideo();
    DtVideo(string, float, int, DtFecha*, bool, Usuario*);
    DtVideo(string, float, DtFecha*, bool);
    string getUrl();
    float getDuracion();
    virtual ~DtVideo();
private:
    string url;
    float duracion;
};

#endif /* DTVIDEO_H */

