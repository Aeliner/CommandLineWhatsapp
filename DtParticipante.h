/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtParticipante.h
 * Author: Aeliner
 *
 * Created on June 25, 2018, 10:26 PM
 */

#ifndef DTPARTICIPANTE_H
#define DTPARTICIPANTE_H

#include "ICollectible.h"
#include "DtFecha.h"

class DtParticipante:public ICollectible {
public:
    DtParticipante();
    DtParticipante(string, int, DtFecha*, bool);
    string getNombre();
    int getNum();
    DtFecha* getFecha();
    bool getAdmin();
    
    virtual ~DtParticipante();
private:
    string nombre;
    int numero;
    DtFecha* fecha;
    bool admin;
};

#endif /* DTPARTICIPANTE_H */

