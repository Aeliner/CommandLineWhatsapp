/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversacion.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 8:19 PM
 */

#include "Conversacion.h"
#include "Simple.h"
#include "Video.h"
#include "Imagen.h"
#include "Contacto.h"
#include "ctrlConv.h"
#include "DtSimple.h"
#include "DtImagen.h"
#include "DtVideo.h"
#include "DtContacto.h"
#include "ListaDicc.h"
#include "IntKey.h"
#include "Grupal.h"
#include "DtParticipante.h"
Conversacion::Conversacion()
{
    this->identificador = ctrlConv::getInstanceC()->getxD();
    this->est_conv = new Lista();
    this->mensaje = new ListDicc();
    ctrlConv::getInstanceC()->aumentarxD();
}

Conversacion::Conversacion(int ident)
{
    this->identificador = ctrlConv::getInstanceC()->getxD();
    this->est_conv = new Lista();
    this->mensaje = new ListDicc();
    ctrlConv::getInstanceC()->aumentarxD();
}

Conversacion::~Conversacion()
{
    delete this->est_conv;
    delete this->mensaje;
}

IDictionary* Conversacion::LisMen(){
    return mensaje;
}

int Conversacion::getIdentificador()
{
    return identificador;
}

void Conversacion::setIdentificador(int ident)
{
    this->identificador = ident;
}
void Conversacion::setearEc2(Est_Conv * xd)
{
         this->est_conv->add(xd);
         
}

bool Conversacion::sosVos(int id)
{
    return (this->identificador==id);
}

Conversacion* Conversacion::selecConv(){
    return this;
}

void Conversacion::crearMensaje(DtMensaje& mens, Usuario* usu)
 {
    Mensaje* mensaj;
     DtSimple* sim = dynamic_cast <DtSimple*> (&mens);
     if(sim != NULL){
         mensaj = new Simple(ctrlConv::getInstanceC()->getTexto(), ctrlFecha::getInstanceF()->mostrarFecha(), false, usu);
              
     }
     else{
         DtImagen* img=dynamic_cast <DtImagen*> (&mens);
         if(img != NULL){
            mensaj=new Imagen(ctrlConv::getInstanceC()->getFormato(), ctrlConv::getInstanceC()->getTextoI(), ctrlConv::getInstanceC()->getTamanio(), ctrlConv::getInstanceC()->geturlI(), ctrlFecha::getInstanceF()->mostrarFecha(), false, usu);
         }
         else {
             DtVideo* vid=dynamic_cast<DtVideo*> (&mens);
             if(vid!=NULL){
               mensaj=new Video(ctrlConv::getInstanceC()->getDuracion(), ctrlConv::getInstanceC()->geturlV(), ctrlFecha::getInstanceF()->mostrarFecha(), false, usu); 
             }
             else{
                 DtContacto* cont=dynamic_cast<DtContacto*>(&mens);
                 if(cont!=NULL){
                 mensaj=new Contacto(ctrlConv::getInstanceC()->getUsuRecordado()->getNombre(), ctrlConv::getInstanceC()->getUsuRecordado()->getCel(), ctrlFecha::getInstanceF()->mostrarFecha(), false, usu);
                 }
             }
             
         }
     }
     
       IntKey* llavesita = new IntKey(mensaj->getCodigo());
         this->mensaje->add(mensaj, llavesita);
                
         IIterator* it=this->est_conv->iterator();
             while(it->hasNext()){
                Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
                Usuario* us=est->getUsuario();
                if(us->getCel() != ctrlUsuario::getInstanceU()->getSesion())
                mensaj->setearReceptores(us);
                it->next();
     }
         delete it;

 }


void Conversacion::archivar(int id){
    IIterator* it = this->est_conv->iterator();
        Conversacion* conv;
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==true&& ctrlUsuario::getInstanceU()->traerUsuarioLogueado() == est->getUsuario()){
                conv=est->selecConv(id);
                if(conv != NULL)
                est->setEstado(false);
             }
             it->next();
        }
    }

ICollection* Conversacion::selec(int cod)
{
    IIterator* it = this->mensaje->getIteratorObj();
         while(it->hasNext())
        {
             Mensaje* menso1 = dynamic_cast <Mensaje*> (it->getCurrent());
             bool ok = menso1->tenesDatos(cod);
             if(ok)
             {
                 return menso1->darDato();
             }
             it->next(); 
        }
    
}

void Conversacion::actualizarVisto(int idconv)
{
         IIterator* it = this->mensaje->getIteratorObj();
         while(it->hasNext())
        {
             Mensaje* menso = dynamic_cast <Mensaje*> (it->getCurrent());
             menso->fueLeido();
             it->next(); 
        }
         delete it;
}


ICollection* Conversacion::listarPart()
{
    ICollection* coleccionsita = new Lista();
    Grupal* grup = dynamic_cast <Grupal*> (this);
    IIterator* it = this->est_conv->iterator();
    while(it->hasNext())
    {
        Est_Conv* est = (Est_Conv*) it->getCurrent();
        Usuario* us =est->getUsuario();
        if(grup->esAdmin(us))
        {
            coleccionsita->add(new DtParticipante(us->getNombre(),us->getCel(), grup->getFechitaIng(us), true));
        }
        else
        {
            cout<<us->getNombre()<<endl;
            
            cout<<us->getCel();
            coleccionsita->add(new DtParticipante(us->getNombre(),us->getCel(), grup->getFechitaIng(us), false));
        }
        it->next();
    }
    return coleccionsita;
}

ICollection* Conversacion::listarUsus()
{
    ICollection* coleccionsita = new Lista();
    IIterator* it = this->est_conv->iterator();
    while(it->hasNext())
    {
        Est_Conv* est = (Est_Conv*) it->getCurrent();
        Usuario* us = est->getUsuario();
        coleccionsita->add(us);
        it->next();
    }
    return coleccionsita;
}

int Conversacion::encontrarMens(int idMenso)
 {
    IntKey* llavesita = new IntKey(idMenso);
    Mensaje* m = (Mensaje*) this->mensaje->find(llavesita);
    return m->getCodigo();
 }

void Conversacion::eliminar(int id)
{
    IntKey* llave = new IntKey(id);
    Mensaje* lol = (Mensaje*) this->mensaje->find(llave);
    Usuario* us = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
    if(lol->borrarvinculoEmisor(us->getCel(), this))
    {
        ICollectible* c = this->mensaje->removeKey(llave);
        delete c;
    }
    else
        lol->borrarVinculoReceptor(us->getCel());
}

void Conversacion::desvincular(int id)
{
    IntKey* llavesita = new IntKey(id);
    this->mensaje->removeKey(llavesita);
}