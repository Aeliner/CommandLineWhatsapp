/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.h
 * Author: nambr
 *
 * Created on 8 de junio de 2018, 04:14 PM
 */

#ifndef VISTO_H
#define VISTO_H
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Usuario.h"
using namespace std;
class Visto: public ICollectible {
public:
    Visto();
    Visto(bool, DtFecha*, Usuario*);
    Visto(bool, Usuario*);
    bool getVisto();
    Usuario* getUsu();
    DtFecha* getFecha();
    void setVisto(bool);
    void setFecha(DtFecha*);
    bool noFueVisto(int);
    void desvin();
    bool desvReceptores(int);
    bool desvinReceptores();
    bool borrar(int);
    
    virtual ~Visto();
private:
    bool visto;
    DtFecha* fecha;
    Usuario* usuario;
};

#endif /* VISTO_H */

