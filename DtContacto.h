/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtContacto.h
 * Author: Nuevo
 *
 * Created on 23 de junio de 2018, 03:29 PM
 */

#ifndef DTCONTACTO_H
#define DTCONTACTO_H
#include "DtMensaje.h"

using namespace std;
class DtContacto: public DtMensaje {
public:
    DtContacto();
    DtContacto(string, int, int, DtFecha*, bool, Usuario*);
    DtContacto(string, int, DtFecha*, bool);
    string getNombre();
    int getCel();
    virtual ~DtContacto();
private:

    string nombre;
    int cel;
};

#endif /* DTCONTACTO_H */

