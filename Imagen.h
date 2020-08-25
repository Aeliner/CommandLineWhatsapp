/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagen.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 04:47 PM
 */

#ifndef IMAGEN_H
#define IMAGEN_H
#include "Mensaje.h"

class Imagen:public Mensaje {
public:
    Imagen();
    Imagen(string,string,float,string,DtFecha*,bool, Usuario*);
    string getFormato();
    string getTexto();
    float getTamanio();
    void setFormato(string);
    void setTexto(string);
    void setTamanio(float);
    string getUrl();
    virtual ~Imagen();
private:
    string formato;
    string texto;
    float tamanio;
    string url;

};

#endif /* IMAGEN_H */

