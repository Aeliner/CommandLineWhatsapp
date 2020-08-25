/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 2:27 PM
 */

#include "Mensaje.h"
#include "ctrlUsuario.h"
#include "ctrlConv.h"

Mensaje::Mensaje()
{
    this->codigo=ctrlConv::getInstanceC()->getIdM();
    this->fecha_env;
    this->visto=false;
    this->vistos = new Lista();
    this->emisor = NULL;
    ctrlConv::getInstanceC()->aumentaId();
}

Mensaje::Mensaje(DtFecha* fec,bool vis, Usuario* emis)
{
    this->codigo=ctrlConv::getInstanceC()->getIdM();
    this->fecha_env=fec;
    this->visto=vis;
    this->vistos = new Lista();
    this->emisor = emis;
    ctrlConv::getInstanceC()->aumentaId();
}

Mensaje::~Mensaje()
{
    delete this->emisor;
    delete this->vistos;
}

int Mensaje::getCodigo()
{
return codigo;
}

DtFecha* Mensaje::getFecha()
{
    return fecha_env;
}

bool Mensaje::getVisto()
{
    return visto;
}

void Mensaje::setCodigo(int cod)
{
    this->codigo=cod;
}

void Mensaje::setFecha(DtFecha* fec)
{
    this->fecha_env=fec;

}

void Mensaje::setVisto(bool vis){
    this->visto=vis;
}

Visto* Mensaje::getOtros(){
    IIterator* it = this->vistos->iterator();
    while(it->hasNext()){
    Visto* vis = dynamic_cast <Visto*> (it->getCurrent());
    if(vis->getUsu()->getCel() != ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel()){
         return vis;
    }
    it->next();
    }
    return NULL;
}

Visto* Mensaje::getOtros2()
{
    IIterator* it = this->vistos->iterator();
    while(it->hasNext()){
    Visto* vis = dynamic_cast <Visto*> (it->getCurrent());
    if(vis->getUsu()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel()){
         return vis;
    }
    it->next();
    }
    return NULL;
}

Usuario* Mensaje::getEmisor(){
    return emisor;
}

void Mensaje::setearReceptores(Usuario* usu){
    Visto* vis= new Visto(false, usu);
    this->vistos->add(vis);
}

void Mensaje::setVistos(Usuario* usu){
    Visto* vis= new Visto(true, ctrlFecha::getInstanceF()->mostrarFecha(), usu);
    this->vistos->add(vis);
}

void Mensaje::fueLeido()
{
   IIterator* it = this->vistos->iterator();
         while(it->hasNext())
        {
             Visto* viso = dynamic_cast <Visto*> (it->getCurrent());
             bool ok = viso->noFueVisto(ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel());
             if(ok) 
                 break;
             it->next(); 
        }
   delete it;
   
   bool valido = true;
   it = this->vistos->iterator();
   while(it->hasNext())
   {
       Visto* vis = dynamic_cast <Visto*> (it->getCurrent());
       if(vis->getVisto() != true)
       {
           valido = false;
           break;
       }
       it->next();
   }
   delete it;
   if(valido)
       this->visto = true;
}

bool Mensaje::tenesDatos(int id)
{
    if (this->codigo == id)
        return true;
    return false;
}

ICollection* Mensaje::darDato()
{
    ICollection* coleccionsita = new Lista();
    if(this->emisor != ctrlUsuario::getInstanceU()->traerUsuarioLogueado())
        return coleccionsita;
    IIterator *it = this->vistos->iterator();
    while(it->hasNext())
    {
        DtDatoM * xd;
        Visto* vistito = dynamic_cast <Visto*> (it->getCurrent());
        Usuario* us = vistito->getUsu();
        if(vistito->getVisto()==true)
        coleccionsita->add(xd = new DtDatoM(us->getCel(), us->getNombre(), vistito->getFecha()));
        it->next();
    }
    delete it;
    return coleccionsita;
}

Usuario* Mensaje::esEmisor()
{
    return this->emisor;
}

bool Mensaje::borrarvinculoEmisor(int cel, Conversacion* converK)
{
    if (this->emisor->getCel() == cel)
    {
        this->desv(cel);
     converK->desvincular(this->codigo);
     IIterator* it = this->vistos->iterator();
     while(it->hasNext())
     {
         Visto* v = (Visto*) it->getCurrent();
         v->desvin();
         it->next();
     }
     delete it;
     IIterator *it2 = this->vistos->iterator();
        while(it2->hasNext())
        {
        it = this->vistos->iterator();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
            it->next();
        }
        delete it;
        }
     delete it2;
     delete this->vistos;   
     return true;
    }
    return false;
}

bool Mensaje::borrarVinculoReceptor(int cel) {

    if (this->emisor->getCel() != cel) {
        IIterator* it = this->vistos->iterator();
        while (it->hasNext()) {
            Visto* vis = dynamic_cast<Visto*> (it->getCurrent());
            if (vis->borrar(cel)) {
                it->remove();
                break;
            }
            it->next();
        }
        delete it;
        return true;
    }
    return false;
}

void Mensaje::desv(int cel)
 {
     this->emisor = NULL;
 }