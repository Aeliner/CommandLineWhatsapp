/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSimple.cpp
 * Author: Nuevo
 * 
 * Created on 23 de junio de 2018, 03:14 PM
 */

#include "DtSimple.h"
//
//DtSimple::DtSimple(){
//    this->texto=" ";
//}

DtSimple::DtSimple(string texto, int cod, DtFecha* fec, bool vis, Usuario* us): DtMensaje(cod, fec, vis, us) {
    this->texto=texto;
}

DtSimple::DtSimple(string texto,DtFecha* fec, bool vis): DtMensaje(fec, vis) {
    this->texto=texto;
}

DtSimple::~DtSimple() {
}

string DtSimple::getTexto()
{
   return texto; 
}

