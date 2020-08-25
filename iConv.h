/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iConv.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:34 PM
 */

#ifndef ICONV_H
#define ICONV_H
#include <iostream>
#include <string>
#include "DtMensaje.h"
#include "ICollection.h"
#include "Usuario.h"
#include "Conversacion.h"
using namespace std;

class iConv {
public:
   
    virtual ICollection* listarConv()=0;
    virtual ICollection* listarCA()=0;
    virtual void idValido(int, ICollection*)=0;
    virtual void ingresarId(int id)=0;
    virtual void ingresaArch(int)=0;
    virtual Conversacion* getConvSel()=0;
    virtual ICollection* listarContacto()=0;
    virtual void ingresarIdConvArch(int id)=0;
    virtual void seleccionarContacto(int numero)=0;
    virtual Usuario* seleccionarContactoM(int)=0;
    virtual Usuario* getUsuRecordado() = 0;
    virtual void iniciarConversacion()=0;
    virtual void ingresarTexto(string texto)=0;
    virtual void ingresarImagen(string formato, float tamanio, string texto, string url)=0;
    virtual void ingresarVideo(string url, float duracion)=0;
    virtual void crearMensaje(DtMensaje&)=0;
    virtual ICollection* listarConvArch()=0;
    virtual ICollection* mostrarMnsj()=0;
    virtual bool existeCont(int, ICollection*)=0;
    virtual void actualizarvisto()=0;
    virtual ICollection* seleccionarMens(int cod)=0;
    virtual void archivarConv(int id)=0;
    virtual void seleccionarConv(int id)=0;
    virtual void selecMensaje(int id)=0;
    virtual void eliminar()=0;
    virtual bool existeList(int)=0;
    virtual void setConvRec(Conversacion*)= 0;
    	    virtual bool existeConv(int)=0;
            virtual bool existeListAr(int)=0;

    virtual ICollection* listarPartGrupo(int) = 0;
    virtual ~iConv();
private:

};

#endif /* ICONV_H */

