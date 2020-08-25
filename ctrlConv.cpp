/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlConv.cpp
 * Author: nambr
 * 
 * Created on 11 de junio de 2018, 04:16 PM
 */

#include "ctrlConv.h"
#include "privada.h"
#include "iGrupo.h"
#include "DtContacto.h"
#include "DtSimple.h"
#include "DtVideo.h"
#include "DtImagen.h"

ctrlConv* ctrlConv::instanceC = NULL;

ctrlConv::ctrlConv() 
{
    this->arch = NULL;
    this->convSel = NULL;
    this->conver = NULL;
    this->recordado = NULL;
    this->mensCont = NULL;
}



ctrlConv::~ctrlConv() {
    delete this->convSel;
    delete this->conver;
    delete this->recordado;
    delete this->mensCont;
    delete this->arch;
    this->instanceC = NULL;
}

ctrlConv* ctrlConv::getInstanceC(){
 if(instanceC == NULL)
     {
         instanceC = new ctrlConv();
     }
  return instanceC;


}

Conversacion* ctrlConv::getConvSel()
{
    return this->convSel;
}

Conversacion* ctrlConv::getConvRec()
{
    return this->conver;
}

ICollection* ctrlConv::listarConv()
{
    Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
    return usuario->setDtConv();
}

int ctrlConv::getIdM()
{
    return ctrlConv::idM;
}

void ctrlConv::aumentaId()
{
    idM++;
}

int ctrlConv::getxD()
{
    return ctrlConv::xD;
}

void ctrlConv::aumentarxD()
{
    xD++;
}
    void ctrlConv::ingresarId(int id)
     {
         //Conversacion* conv;
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         this->convSel=usuario->selecConv(id);
     }
     
     ICollection* ctrlConv::listarContacto()
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         return usuario->ListarC();
     }
     
     void ctrlConv::ingresarIdConvArch(int id)
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         this->convSel=usuario->selecConvA(id);
     }
     
     void ctrlConv::ingresaArch(int id){
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         this->convSel=usuario->selecArch(id);
     }
     
     void ctrlConv::seleccionarContacto(int numero)
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         Usuario* us=usuario->seleccionarCont(numero);
         this->recordado=us;
     }
     
     void ctrlConv::iniciarConversacion()
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         Privada* conv = new Privada();
         usuario->crearConversacion(this->recordado, conv);
         //this->recordado->crearConv(conv);
         this->convSel=conv;
     }
     void ctrlConv::ingresarTexto(string texto)
     {
         this->texto=texto;
     }
    void ctrlConv::ingresarImagen(string formato, float tamanio, string texto, string url)
    {
        this->formato=formato;
        this->tamanio=tamanio;
        this->textoI=texto;
        this->urlI=url;
    }
     void ctrlConv::ingresarVideo(string url, float duracion)
     {
         this->urlV=url;
         this->duracion=duracion;
     }
     
       Usuario* ctrlConv::seleccionarContactoM(int numero)
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         Usuario* us=usuario->seleccionarCont(numero);
         this->mensCont=us;
         return us;
     }
     
     void ctrlConv::crearMensaje(DtMensaje& dt)
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         this->convSel->crearMensaje(dt, usuario);
     }
     
     Usuario* ctrlConv::getUsuRecordado()
     {
         return this->mensCont;
     }
     
     ICollection* ctrlConv::listarConvArch()
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         return usuario->setDtConvA();
     }
     
     
     ICollection* ctrlConv::mostrarMnsj()
     {
         Usuario* usu = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         return usu->mostrarMens();
     }
     
     
     void ctrlConv::actualizarvisto()
     {
     Usuario* usu = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
     usu->actualizarVisto(this->convSel->getIdentificador());

     }
     
     
     ICollection* ctrlConv::seleccionarMens(int cod)
     {
     Usuario* usu = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         return usu->selecMns(cod);
     }
     
     ICollection* ctrlConv::listarCA()
     {
          Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
          return usuario->Activas();
     }
     
       bool ctrlConv::existeList(int id){
             bool conver = false;
        ICollection* conv = ctrlConv::listarCA();
            IIterator *itC = conv->iterator();
            while (itC->hasNext())
            {
                DtConv* dtC = dynamic_cast <DtConv*> (itC->getCurrent());
                if (dtC->getId()==id)
                {
                    conver = true;
                    break;
                }
                itC->next();
            }
            if(conver==false){
                throw invalid_argument("Esta conversacion no existe para el usuario");
            }
            return conver;
       }
       
    bool ctrlConv::existeConv(int numero){
    bool conver = false;
    ICollection* conv = ctrlConv::listarCA();
    IIterator* itC = conv->iterator();
    ICollection* convA = ctrlConv::listarConvArch();
    IIterator* itA = convA->iterator();
    while(itC->hasNext()){
        DtPrivada* dtP = dynamic_cast <DtPrivada*> (itC->getCurrent());
        if(dtP != NULL)
        {
        if(dtP->getNumero()==numero){
            conver=true;
            throw invalid_argument("Ya tiene una conversacion activa con ese usuario");
            break;
        }
        }
        itC->next();
    }
    
    while(itA->hasNext()){
        DtPrivada* dtPri = dynamic_cast <DtPrivada*> (itA->getCurrent());
        if(dtPri != NULL)
        {
        if(dtPri->getNumero()==numero){
            conver=true;
            throw invalid_argument("Ya tiene una conversacion archivada con ese usuario");
            break;
        }
        }
        itA->next();
    }
 
    return conver;

    }
    
  bool ctrlConv::existeCont(int numero, ICollection* contactos){
    bool existe = false;
    IIterator *it = contactos->iterator();
            while(it->hasNext())
            {
                DtUsuario *dt2 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if (dt2->getCel() == numero)
                {
                    existe=true;
                    return existe;
                }
                it->next();
            }
        if(!existe)
        throw invalid_argument("Este usuario no se encuentra en su lista de contactos");
        }
    
    
    
    
    
    void ctrlConv::setConvRec(Conversacion* Conversacion)
    {
        ctrlConv::conver = Conversacion;
    }
    
    bool ctrlConv::existeListAr(int id){
        bool conver = false;
        ICollection* conv = ctrlConv::listarConvArch();
            IIterator *itC = conv->iterator();
            while (itC->hasNext())
            {
                DtConv* dtC = dynamic_cast <DtConv*> (itC->getCurrent());
                if (dtC->getId()==id)
                {
                    conver = true;
                    break;
                }

                itC->next();
            }
            if(conver==false){
                throw invalid_argument("Esta conversacion no existe para el usuario");
            }
            return conver;
        
        
        
        
    }
     
     ICollection* ctrlConv::listarPartGrupo(int id)
     {
//         ICollection* lol = this->listarCA();
//         IIterator *it = lol->iterator();
//         while(it->hasNext())
//         {
//             DtGrupo* grp = dynamic_cast <DtGrupo*> (it->getCurrent());
//             if(grp!= NULL)
//             {
//                 if(grp->getId() == id)
//                 {
//                     
//                 }
//             }
//         }
     }
     
     void ctrlConv::archivarConv(int id)
     {
         Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
         this->arch->archivar(id);
         this->arch = NULL;
     }
     
    void ctrlConv::seleccionarConv(int id)
    {
        Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
        this->arch=usuario->selecConv(id);
    }
    
     void ctrlConv::selecMensaje(int id)
     {
         Usuario* usu = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
       this->idMensR = (usu->seleccionarMensaje(id));
     }
    
     void ctrlConv::eliminar()
    {
        Usuario* usu = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
          usu->eliminar(this->convSel->getIdentificador(), this->idMensR);
    }
    
    string ctrlConv::getTexto(){
        return texto;
    }
    
    string ctrlConv::getFormato(){
        return formato;
    }
    string ctrlConv::getTextoI(){
        return textoI;
    }
    string ctrlConv::geturlI(){
        return urlI;
    }
    string ctrlConv::geturlV(){
        return urlV;
    }
    
    float ctrlConv::getTamanio(){
        return tamanio;
    }
    
    float ctrlConv::getDuracion(){
        return duracion;
    }
    
    Usuario* ctrlConv::getCont(){
        return mensCont;
    }
    
    void ctrlConv::idValido(int id, ICollection* mensajitos)
    {
        bool xD = false;
        bool xD2 = false;
        IIterator* it = mensajitos->iterator();
        while(it->hasNext())
        {
            DtSimple* dtSim = dynamic_cast <DtSimple*> (it->getCurrent());
            if(dtSim != NULL)
            {
                if(dtSim->getCodigo() == id)
                {
                    xD = true;
                    if(dtSim->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
                        xD2 = true;
                break;
                }
            }
            DtImagen* dtImg = dynamic_cast <DtImagen*> (it->getCurrent());
            if(dtImg != NULL)
            {
                if(dtImg->getCodigo() == id)
                {
                    xD = true;
                    if(dtImg->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
                        xD2 = true;
                break;
                }
            }
            DtVideo* dtVid = dynamic_cast <DtVideo*> (it->getCurrent());
            if(dtVid != NULL)
            {
                if(dtVid->getCodigo() == id)
                {
                    xD = true;
                    if(dtVid->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
                        xD2 = true;
                break;
                }
            }
            DtContacto* dtCon = dynamic_cast <DtContacto*> (it->getCurrent());
            if (dtCon != NULL)
            {
                if(dtCon->getCodigo() == id)
                {
                    xD = true;
                    if(dtCon->getEmisor()->getCel() == ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->getCel())
                        xD2 = true;
                break;
                }
            }
            it->next();
        }
        delete it;
        if(!xD)
            throw invalid_argument("Este id no coincide con ningun mensaje de esta conversacion");
        
        if(!xD2)
            throw invalid_argument("No eres emisor de este mensaje");
    }