/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Video.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 05:13 PM
 */

#ifndef VIDEO_H
#define VIDEO_H
#include "Mensaje.h"
class Video: public Mensaje {
public:
    Video();
    Video(float,string,DtFecha*,bool, Usuario*);
    float getDuracion();
    string getUrl();
    void setDuracion(float);
    void setUrl(string);
    virtual ~Video();
private:
    float duracion;
    string url;
};

#endif /* VIDEO_H */

