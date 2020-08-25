/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtDatoM.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 3:27 PM
 */

#ifndef DTDATOM_H
#define DTDATOM_H
#include "DtFecha.h"
#include <iostream>
#include <string>
#include "ICollectible.h"
using namespace std;
class DtDatoM:public ICollectible {
public:
    DtDatoM(int, string, DtFecha*);
    DtDatoM();
    int getNumRecept();
    string getNomRecept();
    DtFecha* getFecha();
    DtDatoM(const DtDatoM& orig);
    virtual ~DtDatoM();
private:
    int num_recept;
    string nom_recept;
    DtFecha* fec_visto;
};

#endif /* DTDATOM_H */

