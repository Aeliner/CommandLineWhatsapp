/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iUsuario.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:37 PM
 */

#ifndef IUSUARIO_H
#define IUSUARIO_H
#include <iostream>
#include <string>
#include "DtControl.h"
#include "DtFecha.h"
#include "DtConv.h"
#include "DtUsuario.h"
#include "Usuario.h"
using namespace std;
class iUsuario {
public:
    virtual DtControl ingNum(int cel)=0;
    virtual void EliminarUsus()=0;
    virtual void Agrega(Usuario*)=0;
    virtual bool haySesion() = 0;
    virtual bool esAdmin(int) = 0;
    virtual IDictionary* traerUsuarios()=0;
    virtual void registrar(string nombre,string imagen, string desc)=0;
    virtual void cancelar()=0;
    virtual DtFecha* mostrarConexion()=0;
    virtual Usuario* traerUsuarioLogueado()=0;
    virtual DtConv** listarConver()=0;
    virtual void cerrarSesion()=0;
    virtual DtUsuario agregarContacto(int cel)=0;
    virtual ICollection* listarContactos()=0;
   virtual void confirmar()=0;
   virtual bool numeroValid(int, ICollection*) = 0;
   virtual bool numeroValid2(int, ICollection*, ICollection*, ICollection*) = 0;
   virtual ICollection* listarMGrupito(int) = 0;
    virtual void cambiarNombre(string nombre)=0;
    virtual void cambiarImagen(string imagen)=0;
    virtual void cambiarDes(string descripcion)=0;
    virtual int  getIdentificador()= 0;
     virtual int getSesion()= 0;
     virtual ICollection* listarUsuariosSis()=0;
     virtual bool existeEnSis(int) = 0;
     virtual void setSesion(int) = 0;
    virtual ~iUsuario();
private:

};

#endif /* IUSUARIO_H */

