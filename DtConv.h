/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtConv.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 3:57 PM
 */

#ifndef DTCONV_H
#define DTCONV_H
#include "ICollectible.h"
class DtConv: public ICollectible {
public:
    DtConv();
    DtConv(bool, int);
    virtual bool getVisto();
    virtual int getId();
    DtConv(const DtConv& orig);
    virtual ~DtConv();
protected:
    bool visto;
    int ident;
};

#endif /* DTCONV_H */

