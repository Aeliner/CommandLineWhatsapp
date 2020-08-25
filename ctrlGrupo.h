/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlGrupo.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:07 PM
 */

#ifndef CTRLGRUPO_H
#define CTRLGRUPO_H
#include <iostream>
#include <string>
#include "iGrupo.h"
#include "ctrlUsuario.h"
#include "ICollection.h"
#include "Grupal.h"
using namespace std;
class ctrlGrupo: public iGrupo {
public:
static ctrlGrupo* getInstanceG();
    ICollection* seleccionarGrupo(int);
    void seleccionarAdmin(string numero);
    DtGrupo** listarGrupo();
    void agregarAdmin();
    void vaciarMiembros();
    IDictionary* getMiembros();
    ICollection* listarMiembrosGrupo();
    void elegirContactos(int cel);
    void quitarContacto(int cel);
    void cancelar();
    void crearGrupo(string, string);
    void agregar();
    void ingresarGrupo();
        void ingresarContactos();
    ICollection* listarMGrupito(int);
    void seleccionarParticipante(string numero);
    void eliminarParticipantes();
    void valido(ICollection*, ICollection*, int);
    void valido2(ICollection*, int);
    Conversacion* getConvG();
    ~ctrlGrupo();
private:
        ctrlGrupo();
    static ctrlGrupo* instanceG;
    IDictionary* miembros;
    static int contG;
    Conversacion* grup;
};

#endif /* CTRLGRUPO_H */

