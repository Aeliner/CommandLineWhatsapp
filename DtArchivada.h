/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtArchivada.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 4:20 PM
 */

#ifndef DTARCHIVADA_H
#define DTARCHIVADA_H
#include <iostream>
#include <string>
#include "DtConv.h"
using namespace std;

class DtArchivada:public DtConv{
public:
    DtArchivada();
    DtArchivada(bool, int, int);
    DtArchivada(int);
    int getCant();
    DtArchivada(const DtArchivada& orig);
    virtual ~DtArchivada();
private:
    int cantidad;
};

#endif /* DTARCHIVADA_H */

