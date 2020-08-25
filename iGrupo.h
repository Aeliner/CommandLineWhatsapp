/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iGrupo.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:29 PM
 */

#ifndef IGRUPO_H
#define IGRUPO_H
#include <iostream>
#include <string>
#include "DtUsuario.h"
#include "DtGrupo.h"
#include "ICollection.h"
#include "IDictionary.h"
#include "Conversacion.h"
using namespace std;
class iGrupo {
public:
  
    virtual ICollection* seleccionarGrupo(int)=0;
    virtual void seleccionarAdmin(string numero)=0;
    virtual DtGrupo** listarGrupo()=0;
    virtual void agregarAdmin()=0;
    virtual Conversacion* getConvG() = 0;
    virtual ICollection* listarMiembrosGrupo()=0;
    virtual void elegirContactos(int cel)=0;
    virtual void quitarContacto(int cel)=0;
    virtual void cancelar()=0;
    virtual IDictionary* getMiembros()=0;
    virtual void vaciarMiembros()=0;
    virtual void crearGrupo(string, string)=0;
    virtual void ingresarGrupo() = 0;
    virtual void agregar()=0;
    virtual void ingresarContactos() =0;
    virtual void valido2(ICollection*, int) = 0;
    virtual void valido(ICollection*, ICollection*, int) = 0;
    virtual ICollection* listarMGrupito(int)=0;
   virtual void seleccionarParticipante(string numero)=0;
    virtual void eliminarParticipantes()=0;
    virtual ~iGrupo();
private:

};

#endif /* IGRUPO_H */

