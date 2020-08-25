/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtGrupo.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 4:07 PM
 */

#ifndef DTGRUPO_H
#define DTGRUPO_H

#include "DtConv.h"
#include <iostream>
#include <string>
using namespace std;

class DtGrupo: public DtConv {
public:
    DtGrupo();
    DtGrupo(bool, int, string);
    DtGrupo(string, int);
    string getNombre();
    DtGrupo(const DtGrupo& orig);
    virtual ~DtGrupo();
private:
    string nombre;
};

#endif /* DTGRUPO_H */

