/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlConv.h
 * Author: nambr
 *
 * Created on 11 de junio de 2018, 04:16 PM
 */

#ifndef CTRLCONV_H
#define CTRLCONV_H
#include <iostream>
#include <string>
#include "iConv.h"
#include "Usuario.h"
#include "ctrlUsuario.h"
class ctrlUsuario;
using namespace std;

class ctrlConv : public iConv {
public:
    static ctrlConv* getInstanceC();
      ICollection* listarConv();
      ICollection* listarCA();
      void ingresaArch(int);
      void ingresarId(int id);
      ICollection* listarContacto();
      void idValido(int, ICollection*);
      void ingresarIdConvArch(int id);
      void seleccionarContacto(int numero);
      void iniciarConversacion();
      void ingresarTexto(string texto);
    void ingresarImagen(string formato, float tamanio, string texto, string url);
      void ingresarVideo(string url, float duracion);
     void crearMensaje(DtMensaje&);
      Usuario* seleccionarContactoM(int);
     ICollection* listarConvArch();
     ICollection* mostrarMnsj();
     bool existeCont(int, ICollection*);
      void actualizarvisto();
      Usuario* getUsuRecordado();
     ICollection* seleccionarMens(int cod);
      void archivarConv(int id);
     void seleccionarConv(int id);
     void selecMensaje(int id);
     Conversacion* getConvSel();
     Conversacion* getConvRec();
     bool esAdmin(int, int);
     void eliminar();
    string getTexto();
    string getFormato();
    string getTextoI();
    string geturlI();
    string geturlV();
    float getTamanio();
    float getDuracion();
    Usuario* getCont();
    ~ctrlConv();
    int getxD();
    void aumentarxD();
    int getIdM();
    bool existeList(int);
    bool existeConv(int);
    void setConvRec(Conversacion*);

    bool existeListAr(int);
  
    ICollection* listarPartGrupo(int);
    void aumentaId();
private:
    Conversacion* convSel;
      ctrlConv();
      int xD = 1;
      int idM = 1;
      static ctrlConv* instanceC;
      Conversacion* conver;
      Usuario* recordado;
      string texto;
      string formato;
      string textoI;
      string urlI;
      string urlV;
      int idMensR;
      float tamanio, duracion;
      Usuario* mensCont;
      Conversacion* arch;
 
};

#endif /* CTRLCONV_H */

