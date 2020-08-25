/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.cpp
 * Author: nambr
 * 
 * Created on 11 de junio de 2018, 04:41 PM
 */

#include "Fabrica.h"
#include "ctrlUsuario.h"
#include "DtSimple.h"
#include "DtContacto.h"
#include "Simple.h"
#include "Privada.h"
#include "Contacto.h"
#include "Video.h"

//iUsuario* Fabrica::usuario = NULL;
//Fabrica* Fabrica::conversacion = NULL;
//Fabrica* Fabrica::grupo = NULL;
//Fabrica* Fabrica::fechas = NULL;

Fabrica::Fabrica()
{
    this->conversacion = NULL;
    this->usuario = NULL;
    this->grupo = NULL;
    this->fechas = NULL;
}


Fabrica::~Fabrica()
{
    
}

iUsuario* Fabrica::getIusuario()
{
//    ctrlUsuario* usu = NULL;
//    if (this->usuario == NULL)
    usuario=ctrlUsuario::getInstanceU();
    return usuario;

}
iConv* Fabrica::getiConversacion()
{
   conversacion=ctrlConv::getInstanceC();
   return conversacion;
    
}
iGrupo* Fabrica::getiGrupo()
{
    grupo=ctrlGrupo::getInstanceG();
    return grupo;
}

iFecha* Fabrica::getiFecha(){
    fechas=ctrlFecha::getInstanceF();
    return fechas;
}


        
void Fabrica::cargarDatos()
{
    delete usuario;
    delete conversacion;
    delete grupo;
    delete fechas;
    
    usuario=NULL;
    conversacion=NULL;
    grupo=NULL;
    fechas=NULL;
    
    usuario=this->getIusuario();
    conversacion=this->getiConversacion();
    grupo=this->getiGrupo();
    fechas=this->getiFecha();
    
//    DtFecha* fec;

    Usuario* u1 = new Usuario(90123654, "Juan Perez", new DtFecha(), "home/img/perfil/juan.png", "Como andan?", new DtFecha());
    Usuario* u2 = new Usuario(90765432, "Maria Fernandez", new DtFecha(), "home/img/perfil/maria.png", "Disponible", new DtFecha());
    Usuario* u3 = new Usuario(90246810, "Pablo Iglesias", new  DtFecha(), "home/img/perfil/pablo.png", "En el Gym", new DtFecha());
    Usuario* u4 = new Usuario(90666777, "Sara Ruiz",  new DtFecha(), "home/img/perfil/sara.png", "Estoy usando TeleTIP", new DtFecha());
//    
    usuario->Agrega(u1);
    usuario->Agrega(u2);
    usuario->Agrega(u3);
    usuario->Agrega(u4);
//    getIusuario()->traerUsuarios()->add(u1, new IntKey(u1->getCel()));
//    getIusuario()->traerUsuarios()->add(u2, new IntKey(u2->getCel()));
//    getIusuario()->traerUsuarios()->add(u3, new IntKey(u3->getCel()));
//    getIusuario()->traerUsuarios()->add(u4, new IntKey(u4->getCel()));
    
    //Agrega contactos de u1
    
    u1->Listacontactos()->add(u2, new IntKey(u2->getCel()));
    u1->Listacontactos()->add(u3, new IntKey(u3->getCel()));
    u1->Listacontactos()->add(u4, new IntKey(u4->getCel()));
    
    //Agrega contactos de u2
    u2->Listacontactos()->add(u1, new IntKey(u1->getCel()));
    u2->Listacontactos()->add(u3, new IntKey(u3->getCel()));
    
    //Agregar contactos de u3
    u3->Listacontactos()->add(u1, new IntKey(u1->getCel()));
    u3->Listacontactos()->add(u2, new IntKey(u2->getCel()));
    u3->Listacontactos()->add(u4, new IntKey(u4->getCel()));
    
    //Agregar contactos u4
    u4->Listacontactos()->add(u1, new IntKey(u1->getCel()));
    u4->Listacontactos()->add(u3, new IntKey(u4->getCel()));
   
    //Conversacion defensa
//    Privada* prueba = new Privada();
//    u3->crearConversacion(u1, prueba);

    
    //Crea conversacion CS2
    usuario->setSesion(90765432);
//    conversacion->seleccionarContacto(90123654);
//    conversacion->iniciarConversacion();
    Privada* pri = new Privada();
    u2->crearConversacion(u1, pri);
    
//    conversacion->getConvSel()->
    //Crea mensaje M5
//    fec = DtFecha(2018, 05, 23, 12, 23, 00);
//    fechas->modificarFecha(fec);
    Simple* sim = new Simple("Hola, me pasas el contacto de Sara que no lo tengo", new DtFecha(2018, 05, 23, 12, 23, 00), false, u2);
    pri->LisMen()->add(sim, new IntKey(sim->getCodigo()));
    sim->setVistos(u1);
    
    
    //Crea mensaje M6
//    fec = DtFecha(2018, 05, 23, 12, 25, 00);
//    fechas->modificarFecha(fec);
    usuario->setSesion(90123654);
    Contacto* cont=new Contacto(u4->getNombre(), u4->getCel(), new DtFecha(2018, 05, 23, 12, 25, 00), false, u1);
    pri->LisMen()->add(cont, new IntKey(cont->getCodigo()));
    cont->setVistos(u2);
    
    //Crear mensaje M7
//    fec = DtFecha(2018, 05, 23, 12, 26, 00);
//    fechas->modificarFecha(fec);
     usuario->setSesion(90765432);
    Simple* simp = new Simple("Gracias", new DtFecha(2018, 05, 23, 12, 26, 00), false, u2);
    pri->LisMen()->add(simp, new IntKey(simp->getCodigo()));
    simp->setVistos(u1);
    
    
    //Crear conversacion CS3
    usuario->setSesion(90666777);
//    conversacion->seleccionarContacto(90246810);
//    conversacion->iniciarConversacion();
    Privada* priv = new Privada();
    u4->crearConversacion(u3, priv);
    
    
    //Crear mensaje M8
//    fec = DtFecha(2018, 05, 23, 18, 30, 00);
//    fechas->modificarFecha(fec);
    Simple* simpl = new Simple("Hola Pablo, como estas?",new DtFecha(2018, 05, 23, 18, 30, 00), false, u4);
    priv->LisMen()->add(simpl, new IntKey(simpl->getCodigo()));
    simpl->setVistos(u3);
    
    
    
    //Crear grupo G1
    usuario->setSesion(90123654);
//    grupo->getMiembros()->add(u2, new IntKey(u2->getCel()));
//    grupo->getMiembros()->add(u3, new IntKey(u3->getCel()));
//    grupo->getMiembros()->add(u4, new IntKey(u4->getCel()));
//    DtFecha* fec = new DtFecha(2017, 05, 22, 15, 35, 00);
//    fechas->modificarFecha(fec);
//    grupo->ingresarGrupo();
//    grupo->crearGrupo("Amigos", "home/img/amigos.png");
//    fec = new DtFecha(2017, 05, 22, 15, 35, 00);
//    fechas->modificarFecha(fec);
    //usuario->setSesion(90123654);
    Grupal* grup = new Grupal("Amigos", "home/img/amigos.png", new DtFecha(2017, 05, 22, 15, 35, 00), u1);
    u1->crearConversacionGrupo(u2, grup);
    grup->crearUsuGrupo(u2);
    u1->crearConversacionGrupo(u3, grup);
    grup->crearUsuGrupo(u3);
    u1->crearConversacionGrupo(u4, grup);
    grup->crearUsuGrupo(u4);
    
    u1->crearConvUsuarioGrupo(u1, grup);
    grup->crearUsuGrupUsuario(u1);
    
    
    //Crear M1
//    fec = new DtFecha(2017, 05, 22, 18, 04, 00);
//    fechas->modificarFecha(fec);
    usuario->setSesion(90666777);
    Simple* simple = new Simple("Miren que bueno este video!", new DtFecha(2017, 05, 22, 18, 04, 00), false, u4);
    grup->LisMen()->add(simple, new IntKey(simple->getCodigo()));
    simple->setVistos(u3);
    simple->setearReceptores(u2);
    simple->setVistos(u1);
    
    //Crear M2
//    fec = new DtFecha(2017, 05, 22, 18, 05, 00);
//    fechas->modificarFecha(fec);
    Video* vid=new Video(5, "home/video/perfil/video", new DtFecha(2017, 05, 22, 18, 05, 00), false, u4);
    grup->LisMen()->add(vid, new IntKey(vid->getCodigo()));
    vid->setVistos(u3);
    vid->setearReceptores(u2);
    vid->setVistos(u1);
    
    
    //Crear M3
//    fec = new DtFecha(2017, 05, 22, 18, 12, 00);
//    fechas->modificarFecha(fec);
    usuario->setSesion(90123654);
    Simple* s = new Simple("Muy gracioso!", new DtFecha(2017, 05, 22, 18, 12, 00), false, u1);
    grup->LisMen()->add(s, new IntKey(s->getCodigo()));
    s->setVistos(u3);
    s->setearReceptores(u2);
    s->setVistos(u4);
    
    //Crear M4
//    fec = new DtFecha(2017, 05, 22, 18, 13, 00);
//    fechas->modificarFecha(fec);
    usuario->setSesion(90246810);
    Simple* si = new Simple("Excelente!", new DtFecha(2017, 05, 22, 18, 13, 00), false, u3);
    grup->LisMen()->add(si, new IntKey(si->getCodigo()));
    si->setVistos(u1);
    si->setearReceptores(u2);
    si->setVistos(u4);
    

}