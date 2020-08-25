/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grupal.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 8:29 PM
 */

#ifndef GRUPAL_H
#define GRUPAL_H

#include "Conversacion.h"
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "DtGrupo.h"
#include "Usu_Grupo.h"
#include "ctrlFecha.h"
using namespace std;

class Grupal:public Conversacion {
public:
    Grupal();
    Grupal( string, string, DtFecha*, Usuario*);
    string getNombre();
    string getImg();
    DtFecha* getFecha();
    Usuario* getAdmin();
    void setNombre(string);
    void setImg(string);
    void setFecha(DtFecha*);
        void crearUsuGrupo(Usuario*);
    void crearUsuGrupUsuario(Usuario*);
    bool esAdmin(Usuario*);
    DtFecha* getFechitaIng(Usuario*);
    DtGrupo* getDato();
    ICollection* getMensaje();
 virtual ~Grupal();
private:
    string nombre;
    string img;
    DtFecha* fecha_c;
    IDictionary* administrador;
    Usuario* creador;
    ICollection* Usu_grupo;
};

#endif /* GRUPAL_H */

