/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usu_Grupo.cpp
 * Author: Aeliner
 * 
 * Created on June 24, 2018, 3:08 PM
 */

#include "Usu_Grupo.h"

Usu_Grupo::Usu_Grupo() 
{
    this->usu = NULL;
    this->fecha_in;
}

Usu_Grupo::Usu_Grupo(Usuario* us, DtFecha* fechita)
{
    this->usu = us;
    this->fecha_in = fechita;
}



Usu_Grupo::~Usu_Grupo() {
}

Usuario* Usu_Grupo::getUsu()
 {
    return this->usu;
 }
 DtFecha* Usu_Grupo::getFecha_in()
 {
     return this->fecha_in;
 }
 
      void Usu_Grupo::setFecha_in(DtFecha* Fecha)
      {
          this->fecha_in=Fecha;
      }
       void Usu_Grupo::setUsu(Usuario* usu)
       {
           this->usu= usu;
       }
