/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grupal.cpp
 * Author: 
 * 
 * Created on June 7, 2018, 8:29 PM
 */

#include "Grupal.h"
#include "ctrlUsuario.h"
#include "Contacto.h"
#include "Simple.h"
#include "Video.h"
#include "Imagen.h"
#include "DtVideo.h"
#include "DtImagen.h"
#include "DtContacto.h"
#include "DtSimple.h"

Grupal::Grupal():Conversacion()
{
    this->identificador = 0;
    this->nombre ="No";
    this->img = "No";
    this->fecha_c = NULL;
    this->creador = NULL;
    this->administrador = new ListDicc();
    this->Usu_grupo = new Lista();
//    this->mensaje = new ListDicc();
}

Grupal::Grupal( string nombre, string imagen, DtFecha* fecha, Usuario* creador): Conversacion(identificador)
{
    this->nombre = nombre;
    this->img = imagen;
    this->fecha_c = fecha;
    this->creador = creador;
    this->administrador = new ListDicc();
    this->Usu_grupo = new Lista();
//    this->mensaje = new ListDicc()
    IntKey* llave = new IntKey(creador->getCel());
    this->administrador->add(creador, llave);
}

Usuario* Grupal::getAdmin()
{
    IIterator* it = this->administrador->getIteratorObj();
    while(it->hasNext())
    {
        Usuario* us = (Usuario*) it->getCurrent();
        return us;
    }
}


Grupal::~Grupal(){}

string Grupal::getNombre()
{
    return nombre;
}

string Grupal::getImg()
{
    return img;
}

DtFecha* Grupal::getFecha()
{
    return fecha_c;
}

void Grupal::setFecha(DtFecha* fechita)
{
    this->fecha_c = fechita;
}

void Grupal::setImg(string imagensita)
{
    this->img = imagensita;
}

void Grupal::setNombre(string nombresito)
{
    this->nombre = nombresito;
}

DtGrupo* Grupal::getDato()
{
    DtGrupo* grup = new DtGrupo(this->getNombre(), this->getIdentificador());
    return grup;
}



void Grupal::crearUsuGrupo(Usuario* us)
{
Usu_Grupo* xD = new Usu_Grupo(us, ctrlFecha::getInstanceF()->mostrarFecha());
        this->Usu_grupo->add(xD);
}

void Grupal::crearUsuGrupUsuario(Usuario* us)
{
    Usu_Grupo* xD = new Usu_Grupo(us, ctrlFecha::getInstanceF()->mostrarFecha());
    this->Usu_grupo->add(xD);
}

bool Grupal::esAdmin(Usuario* usu)
{
    IIterator* it = this->administrador->getIteratorObj();
    while(it->hasNext())
    {
        Usuario* us = (Usuario*) it->getCurrent();
        if(us->getCel() == usu->getCel())
            return true;
        it->next();
    }
    return false;
}

DtFecha* Grupal::getFechitaIng(Usuario* usu)
{
    IIterator* it = this->Usu_grupo->iterator();
    while(it->hasNext())
    {
        Usu_Grupo* fa = (Usu_Grupo*) it->getCurrent();
        if(fa->getUsu()->getCel() == usu->getCel())
            return fa->getFecha_in();
        it->next();
    }
}

ICollection* Grupal::getMensaje()
{
       
Usu_Grupo* ug;
    IIterator* it = this->mensaje->getIteratorObj();
        IIterator* it2 = this->Usu_grupo->iterator();
        while(it2->hasNext())
        {
            ug = dynamic_cast <Usu_Grupo*> (it2->getCurrent());
           if(ug->getUsu()==ctrlUsuario::getInstanceU()->traerUsuarioLogueado())
               break;
           it2->next();
        }
        ICollection* CoGru = new Lista();
   
    while(it->hasNext())
    {
    Mensaje* mensa = dynamic_cast <Mensaje*> (it->getCurrent());
    if(mensa->getOtros2() != NULL || mensa->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
    {
    Simple* mens = dynamic_cast<Simple*> (it->getCurrent());
    if (mens != NULL) {
        if (ug->getUsu() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()) {
            if (ug->getFecha_in()->getAnio() <= mens->getFecha()->getAnio()) {
                if (ug->getFecha_in()->getMes() <= mens->getFecha()->getMes()) {
                    if(ug->getFecha_in()->getDia() <= mens->getFecha()->getMes()){
                    if (ug->getFecha_in()->getHora() <= mens->getFecha()->getHora()) {
                        if (ug->getFecha_in()->getMin() <= mens->getFecha()->getMin()) {
                            if (ug->getFecha_in()->getSeg() <= mens->getFecha()->getSeg()) {

                              CoGru->add(new DtSimple(mens->getTexto(),mens->getCodigo(), mens->getFecha(), mens->getVisto(), mens->getEmisor()));
                               

                            }
                        }
                    }
                }
            }
        }
        }


    } else {
        Imagen* img = dynamic_cast<Imagen*> (it->getCurrent());
        if (img != NULL) {
            if (ug->getUsu() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()) {
                if (ug->getFecha_in()->getAnio() <= img->getFecha()->getAnio()) {
                    if (ug->getFecha_in()->getMes() <= img->getFecha()->getMes()) {
                        if(ug->getFecha_in()->getDia() <= img->getFecha()->getDia()){
                            if (ug->getFecha_in()->getHora() <= img->getFecha()->getHora()) {
                                if (ug->getFecha_in()->getMin() <= img->getFecha()->getMin()) {
                                    if (ug->getFecha_in()->getSeg() <= img->getFecha()->getSeg()) {

                                    CoGru->add(new DtImagen(img->getUrl(), img->getFormato(), img->getTamanio(), img->getTexto(),img->getCodigo(), img->getFecha(), img->getVisto(), img->getEmisor()));
                                    

                                }
                            }
                        }
                    }
                }
            }
        }
        } else {
            Video* vid = dynamic_cast<Video*> (it->getCurrent());
            if (vid != NULL) {
                if (ug->getUsu() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()) {
                    if (ug->getFecha_in()->getAnio() <= vid->getFecha()->getAnio()) {
                        if (ug->getFecha_in()->getMes() <= vid->getFecha()->getMes()) {
                            if(ug->getFecha_in()->getDia() <= vid->getFecha()->getDia()){
                            if (ug->getFecha_in()->getHora() <= vid->getFecha()->getHora()) {
                                if (ug->getFecha_in()->getMin() <= vid->getFecha()->getMin()) {
                                    if (ug->getFecha_in()->getSeg() <= vid->getFecha()->getSeg()) {

                                        CoGru->add(new DtVideo(vid->getUrl(), vid->getDuracion(),vid->getCodigo(),vid->getFecha(), vid->getVisto(), vid->getEmisor()));
                                      

                                    }
                                }
                            }
                        }
                    }
                }
            }
            } else {
                Contacto* conto = dynamic_cast<Contacto*> (it->getCurrent());
                if (conto != NULL) {
                    if (ug->getUsu() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()) {
                        if (ug->getFecha_in()->getAnio() <= conto->getFecha()->getAnio()) {
                            if (ug->getFecha_in()->getMes() <= conto->getFecha()->getMes()) {
                                if(ug->getFecha_in()->getDia() <= conto->getFecha()->getMes()){
                                if (ug->getFecha_in()->getHora() <= conto->getFecha()->getHora()) {
                                    if (ug->getFecha_in()->getMin() <= conto->getFecha()->getMin()) {
                                        if (ug->getFecha_in()->getSeg() <= conto->getFecha()->getSeg()) {

                                          CoGru->add(new DtContacto(conto->getNombre(), conto->getCel(), conto->getCodigo(), conto->getFecha(), conto->getVisto(), conto->getEmisor()));
                                          
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
}
    }
    it->next();
}
    return CoGru;
}