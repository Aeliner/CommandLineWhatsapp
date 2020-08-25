/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlUsuario.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 03:46 PM
 */

#ifndef CTRLUSUARIO_H
#define CTRLUSUARIO_H
#include <iostream>
#include <string>
#include "iUsuario.h"
#include "IDictionary.h"
#include "Usuario.h"
#include "ctrlFecha.h"

using namespace std;

class ctrlUsuario : public iUsuario {
public:
    bool haySesion();
    static ctrlUsuario* getInstanceU();
    DtControl ingNum(int cel);
    bool esAdmin(int);
     void registrar(string nombre,string imagen, string desc);
     void cancelar();
     DtFecha* mostrarConexion();
     Usuario* traerUsuarioLogueado();
    DtConv** listarConver();
     void cerrarSesion();
    DtUsuario agregarContacto(int cel);
     ICollection* listarContactos();
   void confirmar();
   bool numeroValid(int, ICollection*);
     void cambiarNombre(string nombre);
     void cambiarImagen(string imagen);
     void cambiarDes(string descripcion);
     void setIdentificador(int);
     int  getIdentificador();
     ICollection* listarUsuariosSis();
     bool numeroValid2(int, ICollection*, ICollection*, ICollection*);
        bool existeEnSis(int);
     void setSesion(int);
     ICollection* listarMGrupito(int);
     int getSesion();
     IDictionary* traerUsuarios();
     void Agrega(Usuario*);
     void EliminarUsus();
//     DtControl ingNum(int cel);
//     void registrar(string nombre,string imagen, string desc);
//    void cancelar();
//   DtFecha mostrarConexion();
//     void traerUsuarioLogueado();
//    DtConv** listarConver();
//    void cerrarSesion();
//     DtUsuario agregarContacto(int cel);
//     DtUsuario** listarContactos();
//   void confirmar();
//     void cambiarNombre(string nombre);
//    void cambiarImagen(string img_url);
//     void cambiarDes(string descripcion);
      ~ctrlUsuario();
protected:
 ctrlUsuario();
 static ctrlUsuario* instanceU;  
 IDictionary* Usuarios;
 int identificador;
 int sesion;    
 int celuContacto;
 
};

#endif /* CTRLUSUARIO_H */

