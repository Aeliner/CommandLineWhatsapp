/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Privada.cpp
 * Author: nambr
 * 
 * Created on 8 de junio de 2018, 04:00 PM
 */

#include "Privada.h"
#include "Mensaje.h"
#include "Simple.h"
#include "Imagen.h"
#include "DtImagen.h"
#include "Video.h"
#include "DtVideo.h"
#include "Contacto.h"
#include "DtContacto.h"
#include "ctrlUsuario.h"
#include "DtSimple.h"

Privada::Privada(): Conversacion() {
    
}
Privada::Privada(int id): Conversacion (id) {
    //this->identificador = id;
}

DtPrivada* Privada::getDato(){
    
    IIterator* it = this->mensaje->getIteratorObj();
    
    if(!it->hasNext())
    {
        IIterator* it2 = this->est_conv->iterator();
        while(it2->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it2->getCurrent();
            if(est->getUsuario()->getCel() != ctrlUsuario::getInstanceU()->getSesion())
            {
                DtPrivada* priv2 = new DtPrivada(est->getUsuario()->getNombre(), est->getUsuario()->getCel(), this->identificador);
            return priv2;
            }
            it2->next();
        }
    }
    
    while(it->hasNext())
    {
        Mensaje* mens = dynamic_cast <Mensaje*> (it->getCurrent());
        if (mens->getOtros() != NULL)
        {
            Usuario* usua = mens->getOtros()->getUsu();
            DtPrivada* priv=new DtPrivada(usua->getNombre(), usua->getCel(), this->identificador );
            return priv;
        }
        else
        {
            Usuario* us = mens->getEmisor();
            DtPrivada* pri = new DtPrivada(us->getNombre(), us->getCel(), this->identificador);
            return pri;
        }
        it->next();
    }

//    DtPrivada* priv = new DtPrivada(mens-
    
}

    ICollection* Privada::getMensaje() {
       ICollection* CoMens = new Lista();
    IIterator* it = this->mensaje->getIteratorObj();
    while(it->hasNext()){
    Mensaje* mensa = dynamic_cast <Mensaje*> (it->getCurrent());
    if(mensa->getOtros2() != NULL || mensa->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
    {
    Simple* mens = dynamic_cast<Simple*> (it->getCurrent());
    if (mens != NULL) {

        CoMens->add(new DtSimple(mens->getTexto(), mens->getCodigo(), mens->getFecha(), mens->getVisto(), mens->getEmisor()));
        
    } else {
        Imagen* img = dynamic_cast<Imagen*> (it->getCurrent());
        if (img != NULL) {

           CoMens->add(new DtImagen(img->getUrl(), img->getFormato(), img->getTamanio(), img->getTexto(), img->getCodigo(), img->getFecha(), img->getVisto(), img->getEmisor()));
        } else {
            Video* vid = dynamic_cast<Video*> (it->getCurrent());
            if (vid != NULL) {

                CoMens->add(new DtVideo(vid->getUrl(), vid->getDuracion(),vid->getCodigo(), vid->getFecha(), vid->getVisto(), vid->getEmisor()));
            
            }
            else {
                Contacto* conto = dynamic_cast<Contacto*> (it->getCurrent());
                if (conto != NULL) {

                   CoMens->add(new DtContacto(conto->getNombre(), conto->getCel(),conto->getCodigo(), conto->getFecha(), conto->getVisto(), conto->getEmisor()));
                    
                }
            }
        }
    }
    }
        it->next();
    }
    return CoMens;
 }

Privada::~Privada() {
}

