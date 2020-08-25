/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 5:51 PM
 */

#ifndef USUARIO_H
#define USUARIO_H

#include "DtFecha.h"
#include <iostream>
#include <string>
#include "DtControl.h"
#include "DtUsuario.h"
#include "Conversacion.h"
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "Lista.h"
#include "ListaDicc.h"
#include "IntKey.h"

class Conversacion;
using namespace std;


class Usuario:public ICollectible {
public:
    Usuario();
    Usuario(int,string,DtFecha*,string,string,DtFecha*);
    ICollection* Activas();
    int getCel();
    Conversacion* selecArch(int);
    string getNombre();
    DtFecha* getFechaRe();
    string getImgUrl();
    ICollection* listarG(int);
    ICollection* listarM(int);
    void ingresarGrupo();
    string getDescripcion();
    DtFecha* getUltCon();
    void setCel(int);
    void setNombre(string);
    void setFechaRe(DtFecha*);
    void setImgUrl(string);
    void setDescripcion(string);
    void setUltCon(DtFecha*);
    bool existeEnSis(int);
    bool tieneSesion(int);
    DtControl darDatosInicio();
    DtFecha* mostrar();
    DtUsuario* darDato();
    ICollection* ListarC();
    bool esCont();
    DtUsuario* getCont();
    void crearConversacion(Usuario*, Conversacion*);
    void crearConv(Conversacion*);
    Usuario* darMiembro();
    bool tieneConv();
    ICollection* setDtConv();
    ICollection* setDtConvA();
    Conversacion* selecConv(int);
    Conversacion* selecConvA(int);
    ICollection* mostrarMens();
    void actualizarVisto(int);
    void actualizarDatos(bool, DtFecha*);
    ICollection* selecMns(int);
    void desvinReceptores();
    bool esAdmin(int);
    void eliminar(int, int);
    bool esEmisor(int);
    bool receptor(int);
    void desvincular();
    void crearConversacionGrupo(Usuario*, Conversacion*);
    void crearConvUsuario(Usuario*, Conversacion*);
    void EliminarCont();
    void crearConvUsuarioGrupo(Usuario*, Conversacion*);
    Usuario* seleccionarCont(int);
    Usuario* traerUsuElegido(int);
    int seleccionarMensaje(int);
    Usuario(const Usuario& orig);
    IDictionary* Listacontactos();
    ~Usuario();
private:
    friend class ctrlUsuario;
    int cel;
    string nombre;
    DtFecha* fecha_re;
    string img_url;
    string descripcion;
    DtFecha* ult_con;
    ICollection* est_conv;
    IDictionary* contactos;
    IDictionary* creador;
    IDictionary* administrador;
};

#endif /* USUARIO_H */

