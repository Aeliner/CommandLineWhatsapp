/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtUsuario.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 3:53 PM
 */

#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>
#include <iostream>
#include "ICollectible.h"
using namespace std;

class DtUsuario:public ICollectible {
public:
    DtUsuario(string, int);
    DtUsuario();
    string getNombre();
    int getCel();
    DtUsuario(const DtUsuario& orig);
    virtual ~DtUsuario();
private:
    string nombre;
    int cel;
};

#endif /* DTUSUARIO_H */

