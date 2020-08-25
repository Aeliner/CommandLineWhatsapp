/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlUsuario.cpp
 * Author: nambr
 * 
 * Created on 11 de junio de 2018, 03:46 PM
 */

#include "ctrlUsuario.h"
#include "DtParticipante.h"

ctrlUsuario* ctrlUsuario::instanceU = NULL;

ctrlUsuario::ctrlUsuario() 
{
    this->Usuarios =  new ListDicc();
    this->sesion = 0;
}

 IDictionary* ctrlUsuario::traerUsuarios(){
        return Usuarios;
    }

ICollection* ctrlUsuario::listarUsuariosSis()
{
    ICollection* coleccionsita = new Lista();
        IIterator* it = this->Usuarios->getIteratorObj();
        
        while(it->hasNext())
        {
             Usuario* usu = dynamic_cast <Usuario*> (it->getCurrent());
             Conversacion* conv = dynamic_cast <Conversacion*> (it->getCurrent());
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             Visto* vis = dynamic_cast <Visto*> (it->getCurrent());
                coleccionsita->add(usu->darDato());
            it->next();
            }
        return coleccionsita;
}

bool ctrlUsuario::haySesion()
{
    if (this->sesion == 0)
        return false;
    return true;
}

ctrlUsuario::~ctrlUsuario() {
    ctrlUsuario::EliminarUsus();
    delete this->Usuarios;
    this->instanceU = NULL;
    //delete this->instanceU;
    
}

void ctrlUsuario::Agrega(Usuario* usu){
    this->Usuarios->add(usu, new IntKey(usu->getCel()));
}

void ctrlUsuario::EliminarUsus(){
    
    IIterator *it2 = this->Usuarios->getIteratorObj();
        while(it2->hasNext())
        {
        IIterator *it = this->Usuarios->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
             it->next();
        }
        delete it;
//         if(it2->hasNext())
//         it2->next();
        }
}

    ctrlUsuario* ctrlUsuario::getInstanceU()
{
    if(instanceU == NULL)
     {
         instanceU = new ctrlUsuario();
     }
  return instanceU;
}
    
    bool ctrlUsuario::existeEnSis(int cel)
    {
        bool lol = false;
        ICollection* usus = ctrlUsuario::listarUsuariosSis();
            IIterator *itUs = usus->iterator();
            while (itUs->hasNext())
            {
                DtUsuario* dt = dynamic_cast <DtUsuario*> (itUs->getCurrent());
                if (dt->getCel() == cel)
                {
                    lol = true;
                    break;
                }
                itUs->next();
            }
            return lol;
    }

DtControl ctrlUsuario::ingNum(int cel)
{
    IntKey* llavesita = new IntKey(cel);
    Usuario* usu;
    usu = (Usuario*) (this->Usuarios->find(llavesita));
    if (usu == NULL)
    {
        DtControl noExiste= DtControl(false, false);
        ctrlUsuario::identificador = cel;
        return noExiste;
    }
    
    DtControl Existe= DtControl(usu->existeEnSis(cel), usu->tieneSesion(cel));
    ctrlUsuario::sesion = cel;
    return Existe;
//   return usu->darDatosInicio();
    
}
  
  
  
     void ctrlUsuario::registrar(string nombre,string imagen, string desc)
     {
//         ctrlUsuario* usu = NULL;
//         ctrlFecha* fechita= NULL
         Usuario* aux = new Usuario(ctrlUsuario::identificador, nombre, ctrlFecha::getInstanceF()->mostrarFecha(), imagen, desc, ctrlFecha::getInstanceF()->mostrarFecha());
         IntKey* aux2 = new IntKey(aux->cel);
         ICollectible* colec = (ICollectible*) (aux);
         ctrlUsuario::Usuarios->add(colec, aux2);
         ctrlUsuario::sesion = identificador;
     }
     
    void ctrlUsuario::cancelar()
    {
        this->identificador = 0;    
    }
   DtFecha* ctrlUsuario::mostrarConexion()
   {
//       IntKey* llavesita = new IntKey(this->identificador);
//       Usuario* usu = (Usuario*) (this->Usuarios->find(llavesita));
       Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
       return usu->mostrar();
   }
     Usuario* ctrlUsuario::traerUsuarioLogueado()
     {
       IntKey* llavesita = new IntKey(this->sesion);
       Usuario* usu = (Usuario*) (this->Usuarios->find(llavesita));
       return usu;
     }
    DtConv** ctrlUsuario::listarConver(){}
    
    ICollection* ctrlUsuario::listarMGrupito(int id)
    {
        return ctrlUsuario::getInstanceU()->traerUsuarioLogueado()->listarM(id);
    }
    
    void ctrlUsuario::cerrarSesion()
    {
        //ctrlFecha* fechita;
        Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
        this->identificador = 0;
        this->sesion=0;
        usu->setUltCon(ctrlFecha::getInstanceF()->mostrarFecha());
    }
    
     DtUsuario ctrlUsuario::agregarContacto(int cel)
     {
         IntKey* llavesita = new IntKey(cel);
       Usuario* usu = (Usuario*) (this->Usuarios->find(llavesita));
       DtUsuario xD = DtUsuario(usu->getNombre(), usu->getCel());
       ctrlUsuario::celuContacto = cel;
       return xD;
     }
     ICollection* ctrlUsuario::listarContactos()
     {
         Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
         return usu->ListarC();
     }
     
     bool ctrlUsuario::numeroValid(int numerito, ICollection* contactos)
     {
         IIterator *it = contactos->iterator();
            while(it->hasNext())
            {
                DtUsuario *dt2 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if (dt2->getCel() == numerito)
                {
                    throw invalid_argument ("Este usuario ya esta en su lista de contactos");
                }
                it->next();
            }
         delete it;
         
         if (!this->existeEnSis(numerito))
            {
                throw invalid_argument ("Este usuario no existe en el sistema");
            }
         
         if(numerito == this->sesion)
             throw invalid_argument ("No te puedes agregar a ti mismo como contacto");
         
         return true;
     }
     
   void ctrlUsuario::confirmar()
   {
         Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
         
         IntKey* llavesita = new IntKey(ctrlUsuario::celuContacto);
         usu->contactos->add(ctrlUsuario::Usuarios->find(llavesita), llavesita);
   }
     void ctrlUsuario::cambiarNombre(string nombre)
     {
         Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
         usu->setNombre(nombre);
     }
     
    void ctrlUsuario::cambiarImagen(string url)
    {
        Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
        usu->setImgUrl(url);
    }
     void ctrlUsuario::cambiarDes(string descripcion)
     {
         Usuario* usu = ctrlUsuario::traerUsuarioLogueado();
         usu->setDescripcion(descripcion);
     }
       
     
     
     void ctrlUsuario::setIdentificador(int identi)
     {
         this->identificador=identi;
     }
     
       
       int  ctrlUsuario::getIdentificador()
    {
         return identificador;
     }
 
       void ctrlUsuario::setSesion(int sesion)
       {
           this->sesion = sesion;
       }
       
       int ctrlUsuario::getSesion()
       {
           return sesion;
       }
       
       bool ctrlUsuario::numeroValid2(int numerito, ICollection* contactos, ICollection* participantes, ICollection* miembritos)
     {
           bool valido = false;
         IIterator *it = contactos->iterator();
            while(it->hasNext())
            {
                DtUsuario *dt2 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if (dt2->getCel() == numerito)
                {
                    valido = true;
                    break;
                }
                it->next();
            }
         delete it;
         
         if(!valido)
         {
             throw invalid_argument ("Este usuario no esta en su lista de contactos");
         }
         
         if (!this->existeEnSis(numerito))
            {
                throw invalid_argument ("Este usuario no existe en el sistema");
            }
         
         it = miembritos->iterator();
         while(it->hasNext())
         {
             DtUsuario* part = dynamic_cast <DtUsuario*> (it->getCurrent());
             if(part->getCel() == numerito)
             {
                 throw invalid_argument("Este usuario ya fue seleccionado para ser ingresado al grupo");
             }
             it->next();
         }
         delete it;
         
         it = participantes->iterator();
         while(it->hasNext())
             {
             DtParticipante* part = dynamic_cast <DtParticipante*> (it->getCurrent());
             if(part->getNum() == numerito)
             {
                 throw invalid_argument("Este usuario ya pertenece a este grupo");
             }
             it->next();
             }
         
         delete it;
         return valido;
         
     }
       
        bool ctrlUsuario::esAdmin(int id)
        {
           Usuario* usu = this->getInstanceU()->traerUsuarioLogueado();
           return usu->esAdmin(id);
        }