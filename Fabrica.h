

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:41 PM
 */

#ifndef FABRICA_H
#define FABRICA_H
#include "iConv.h"
#include "iGrupo.h"
#include "iUsuario.h"
#include "iFecha.h"
#include "ctrlFecha.h"
#include "ctrlConv.h"
#include "ctrlUsuario.h"
#include "ctrlGrupo.h"
class Fabrica {
public:
    Fabrica();
    iUsuario* getIusuario();
    iConv* getiConversacion();
    iGrupo* getiGrupo();
    iFecha* getiFecha();
    void cargarDatos();
    virtual ~Fabrica();
private:
    iUsuario* usuario;
    iConv* conversacion;
    iGrupo* grupo;
    iFecha* fechas;
          
};

#endif /* FABRICA_H */

