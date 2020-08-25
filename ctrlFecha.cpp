/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlFecha.cpp
 * Author: nambr
 * 
 * Created on 14 de junio de 2018, 04:15 PM
 */

#include "ctrlFecha.h"

ctrlFecha* ctrlFecha::instanceF = NULL;

ctrlFecha::ctrlFecha() 
{
    DtFecha* fecha= new DtFecha(1900,1,1,0,0,0);
    this->fecha = fecha;
}
ctrlFecha::~ctrlFecha() {
    this->instanceF = NULL;
}

ctrlFecha* ctrlFecha::getInstanceF(){
     if(instanceF == NULL)
     {
         instanceF = new ctrlFecha();
     }
  return instanceF;
}


void ctrlFecha::modificarFecha(DtFecha* fecha2) {
    this->fecha=fecha2;

}


DtFecha* ctrlFecha::mostrarFecha() {
    return ctrlFecha::fecha;
}
