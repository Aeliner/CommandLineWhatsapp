/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usu_Grupo.h
 * Author: Aeliner
 *
 * Created on June 24, 2018, 3:07 PM
 */

#ifndef USU_GRUPO_H
#define USU_GRUPO_H

#include "DtFecha.h"
#include "Usuario.h"
#include "ICollectible.h"

class Usu_Grupo:public ICollectible {
public:
       DtFecha* getFecha_in();
       Usuario* getUsu();
       Usu_Grupo();
       Usu_Grupo(Usuario*, DtFecha*);
       void setFecha_in(DtFecha*);
       void setUsu(Usuario*);
       virtual ~Usu_Grupo();
private:
    DtFecha* fecha_in;
    Usuario* usu;
};

#endif /* USU_GRUPO_H */

