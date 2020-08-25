/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtImagen.h
 * Author: nambr
 *
 * Created on 13 de junio de 2018, 08:33 PM
 */
#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

#ifndef DTIMAGEN_H
#define DTIMAGEN_H

class DtImagen:public DtMensaje {
public:
    DtImagen(string, string, float, string,int, DtFecha*, bool, Usuario*);
    DtImagen(string, string, float, string,DtFecha*, bool);
    string getFormato();
    float getTamanio();
    string getTexto();
    string getUrl();
    virtual ~DtImagen();
private:
    string url;
    string formato;
    float tamanio;
    string texto;
};

#endif /* DTIMAGEN_H */

