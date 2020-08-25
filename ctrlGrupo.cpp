/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ctrlGrupo.cpp
 * Author: nambr
 * 
 * Created on 11 de junio de 2018, 04:07 PM
 */

#include "ctrlGrupo.h"
#include "ctrlConv.h"
int ctrlGrupo::contG = 1;
ctrlGrupo* ctrlGrupo::instanceG = NULL;

ctrlGrupo::ctrlGrupo()
{
    this->miembros = new ListDicc();
}



ctrlGrupo::~ctrlGrupo() {
   
    ctrlGrupo::vaciarMiembros();
    delete this->miembros;
    this->instanceG = NULL;
}

IDictionary* ctrlGrupo::getMiembros(){
    return miembros;
}


void ctrlGrupo::valido(ICollection* contactos, ICollection* miembros, int celu)
{
    bool valido = false;
    IIterator *it = contactos->iterator();
            while(it->hasNext())
            {
                DtUsuario *dt2 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if (dt2->getCel() == celu)
                {
                    valido = true;
                    break;
                }
                it->next();
            }
    delete it;
    if(!valido)
    {
        throw invalid_argument("Este usuario no se encuentra en su lista de contactos");
    }
    
    it = miembros->iterator();
            
            while(it->hasNext())
            {
                DtUsuario *dt3 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if(dt3->getCel() == celu)
                {
                    delete it;
                    throw invalid_argument("Este usuario ya fue seleccionado para ser ingresado al grupo");
                }
                it->next();
            }
    
}

void ctrlGrupo::valido2(ICollection* grupo, int celu)
{
    bool valido = false;
    IIterator* it = grupo->iterator();
    if (!it->hasNext())
    {
        throw invalid_argument("Debe ingresar algun usuario al grupo antes");
    }
            while(it->hasNext())
            {
                DtUsuario *dt3 = dynamic_cast <DtUsuario*> (it->getCurrent());
                if(dt3->getCel() == celu)
                {
                    valido = true;
                    break;
                }
                it->next();
            }
    delete it;
    if(!valido)
    {
        throw invalid_argument ("Este usuario no esta seleccionado para ser ingresado al grupo");
    }
}

 ctrlGrupo* ctrlGrupo::getInstanceG(){
 

    if(instanceG == NULL)
     {
         instanceG = new ctrlGrupo();
     }
  return instanceG;

}
   ICollection* ctrlGrupo::seleccionarGrupo(int id)
   {
       Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
       return usuario->listarG(id);
   }
   
   void ctrlGrupo::ingresarContactos()
   {
   }
   
    void ctrlGrupo::seleccionarAdmin(string numero){}
    DtGrupo** ctrlGrupo::listarGrupo(){}
    void ctrlGrupo::agregarAdmin(){}
    
ICollection* ctrlGrupo::listarMiembrosGrupo()
{
	ICollection* coleccionsita = new Lista();
	IIterator* it = this->miembros->getIteratorObj();
        ICollectible* col;
	while(it->hasNext())
        {
	    Usuario* miembro= dynamic_cast <Usuario*> (it->getCurrent());
            col = (ICollectible*) miembro->darDato();
            coleccionsita->add(col);
            it->next();
	}
return coleccionsita;
}

ICollection* ctrlGrupo::listarMGrupito(int)
{
    
}
    void ctrlGrupo::elegirContactos(int cel)
    {
        Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
        Usuario* um = usuario->traerUsuElegido(cel);
        IntKey* aux2 = new IntKey(cel);
         this->miembros->add(um, aux2);
    }
    
    void ctrlGrupo::quitarContacto(int cel)
    {
       Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
       IntKey* aux2 = new IntKey(cel);
       this->miembros->removeKey(aux2);
    }
    void ctrlGrupo::cancelar()
    {
        IIterator* it;
        IIterator *it2 = this->miembros->getIteratorObj();
        while(it2->hasNext())
        {
        it = this->miembros->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
            it->next();
        }
        delete it;
        }
    }
    void ctrlGrupo::crearGrupo(string nombre, string img)
    {
        Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
        Grupal *xD = new Grupal(nombre, img, ctrlFecha::getInstanceF()->mostrarFecha(), usuario);
        IIterator *it = this->miembros->getIteratorObj();

        while(it->hasNext())
        {
            Usuario* m = (Usuario*) (it->getCurrent());
            usuario->crearConversacionGrupo(m, xD);
            xD->crearUsuGrupo(m);
            it->next();
        }
        delete it;
        IIterator *it2 = this->miembros->getIteratorObj();
        while(it2->hasNext())
        {
        it = this->miembros->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
            it->next();
        }
        delete it;
        }
        usuario->crearConvUsuarioGrupo(usuario, xD);
        xD->crearUsuGrupUsuario(usuario);  
    }
    
    Conversacion* ctrlGrupo::getConvG(){
        return grup;
    }
    
    void ctrlGrupo::ingresarGrupo()
    {
        Usuario* usuario = ctrlUsuario::getInstanceU()->traerUsuarioLogueado();
        IIterator *it = this->miembros->getIteratorObj();
        Grupal* xD = (Grupal*) ctrlConv::getInstanceC()->getConvRec();
        while(it->hasNext())
        {
            Usuario* m = (Usuario*) (it->getCurrent());
            usuario->crearConversacionGrupo(m, xD);
            xD->crearUsuGrupo(m);
            it->next();
        }
        delete it;
        IIterator *it2 = this->miembros->getIteratorObj();
        while(it2->hasNext())
        {
        it = this->miembros->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
            it->next();
        }
        delete it;
        }
    }
    void ctrlGrupo::agregar(){}
    void ctrlGrupo::seleccionarParticipante(string numero){}
    void ctrlGrupo::eliminarParticipantes(){}
    
    void ctrlGrupo::vaciarMiembros()
    {
        IIterator* it;
    IIterator *it2 = this->miembros->getIteratorObj();
        while(it2->hasNext())
        {
        it = this->miembros->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
            it->next();
        }
        delete it;
        }
    }