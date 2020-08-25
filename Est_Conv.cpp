/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Est_Conv.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 8:46 PM
 */

#include "Est_Conv.h"
#include "Grupal.h"
#include "Privada.h"

Est_Conv::Est_Conv()
{
    
}

Est_Conv::Est_Conv(bool estadito,Conversacion* conv, Usuario* usu)
{
    this->activo = estadito;
    this->conv = conv;
    this->usu = usu;
}

Est_Conv::~Est_Conv()
{
    
}

bool Est_Conv::getEstado()
{
    return activo;
}

void Est_Conv::setEstado(bool estadito)
{
    this->activo = estadito;
}

bool Est_Conv::esArch()
{
    return this->activo;
}

DtConv* Est_Conv::getDato(){
    DtConv* con;
     Privada* pri = dynamic_cast<Privada*> (this->conv);
            if (pri != NULL){
                con = pri->getDato();
            }
            else 
            {
                Grupal* en = dynamic_cast<Grupal*>(this->conv);
                con = en->getDato();
                
            }
     return con;
}

Conversacion* Est_Conv::selecConv(int id){
   
    if(this->conv->sosVos(id) == true){
         Conversacion* conver=this->conv->selecConv();
         return conver;
    }
    
    return NULL;
}

Usuario* Est_Conv::getUsuario(){
    return usu;
}

bool Est_Conv::esConv(int idconv)
 {
     if((this->conv->sosVos(idconv)== true))
        return true;
     
     return false;
 
 }

ICollection* Est_Conv::selectMns(int cod)
 {
     return this->conv->selec(cod);
 }

ICollection* Est_Conv::getMens()
{
DtMensaje* men;
DtConv* con;

         Privada* pri = dynamic_cast<Privada*> (this->conv);
            if (pri != NULL){
            return  pri->getMensaje();           
        
            }
            else 
            {
                Grupal* gru = dynamic_cast<Grupal*>(this->conv);    
                return gru->getMensaje();
            }
   }

int Est_Conv::traerMensaje(int id)
{
    return this->conv->encontrarMens(id);
}

void Est_Conv::eliminar(int id)
{
    this->conv->eliminar(id);
}