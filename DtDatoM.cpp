/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtDatoM.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 3:27 PM
 */

#include "DtDatoM.h"

DtDatoM::DtDatoM(int numRecept, string nomRecept, DtFecha* fecha){
    this->num_recept = numRecept;
    this->nom_recept = nomRecept;
    this->fec_visto = fecha;
}

DtDatoM::DtDatoM(const DtDatoM& orig)
{
    
}

DtDatoM::~DtDatoM()
{
    
}

int DtDatoM::getNumRecept()
{
    return num_recept;
}

string DtDatoM::getNomRecept()
{
    return nom_recept;
}

DtFecha* DtDatoM::getFecha()
{
    return fec_visto;
}
