/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: Aeliner
 * 
 * Created on June 7, 2018, 5:51 PM
 */

#include "Usuario.h"
#include "ctrlUsuario.h"
#include "ICollection.h"
#include "Usu_Grupo.h"
#include "ctrlConv.h"
#include "ctrlGrupo.h"

Usuario::Usuario()
{
    this->cel = 0;
    this->contactos = new ListDicc();
    this->descripcion = "";
    this->fecha_re = NULL;
    this->img_url = "";
    this->nombre = "";
    this->ult_con = NULL;
    this->est_conv = new Lista();
}
Usuario::Usuario(int celular, string nombre, DtFecha* fecha_re, string img_url, string descripcion, DtFecha* ult_con)
{
    this->cel = celular;
    this->nombre = nombre;
    this->fecha_re = fecha_re;
    this->img_url = img_url;
    this->descripcion = descripcion;
    this->ult_con = ult_con;
    this->contactos = new ListDicc();
    this->est_conv = new Lista();
    this->administrador = new ListDicc();
    this->creador = new ListDicc();
}

Usuario::~Usuario()
{
    this->EliminarCont();
    delete this->administrador;
    delete this->contactos;
    delete this->creador;
    delete this->est_conv;
}

void Usuario::EliminarCont(){
    IIterator *it2 = this->contactos->getIteratorObj();
        while(it2->hasNext())
        {
        IIterator *it = this->contactos->getIteratorObj();
        while(it->hasNext())
        {
            it->remove();
            if(it->hasNext())
             it->next();
        }
        delete it;
        }
}

IDictionary* Usuario::Listacontactos(){
    return contactos;
}

int Usuario::getCel()
{
    return this->cel;
}

string Usuario::getNombre()
{
    return this->nombre;
}

DtFecha* Usuario::getFechaRe()
{
    return this->fecha_re;
}

string Usuario::getDescripcion()
{
   return this->descripcion; 
}

string Usuario::getImgUrl()
{
    return img_url;
}

DtFecha* Usuario::getUltCon()
{
    return ult_con;
}

void Usuario::setCel(int cel)
{
    this->cel = cel;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Usuario::setFechaRe(DtFecha* fecha_re)
{
    this->fecha_re = fecha_re;
}

void Usuario::setImgUrl(string img_url)
{
    this->img_url = img_url;
}

void Usuario::setUltCon(DtFecha* ult_con)
{
    this->ult_con = ult_con;
}

bool Usuario::existeEnSis(int cel) {
    if (ctrlUsuario::getInstanceU()->getIdentificador() != cel)
        return false;
    return true;
}

    bool Usuario::tieneSesion(int cel){
        //ctrlUsuario* u;
            if(ctrlUsuario::getInstanceU()->getSesion() == cel)
                return true;
           return false;
}

DtControl Usuario::darDatosInicio() {
   // DtControl aux;
    DtControl aux(this->existeEnSis(this->cel),this->tieneSesion(this->cel));
    return aux;
    
    
//        aux->getExiste()=true;
//        aux->getSesion()=true;
          //    aux.getExiste() = existe;
//    aux.getSesion() = this->tieneSesion(cel);
    
}

    
    
    DtFecha* Usuario::mostrar()
    {
        return this->ult_con;
    }
    
    DtUsuario* Usuario::darDato()
    {
       DtUsuario *xD= new DtUsuario(this->nombre, this->cel);
       return xD;
    }
    ICollection* Usuario::ListarC()
    {
        ICollection* coleccionsita = new Lista();
        IIterator* it = this->contactos->getIteratorObj();
        
        while(it->hasNext())
        {
             Usuario* usu = dynamic_cast <Usuario*> (it->getCurrent());
                coleccionsita->add(usu->getCont());
            it->next();
            }
        delete it;
        return coleccionsita;
    }
    
    Usuario* Usuario::traerUsuElegido(int cel)
    {
        IntKey* llavesita = new IntKey(cel);
       Usuario* usu = (Usuario*) (this->contactos->find(llavesita));
       return usu;
    }
    
    bool Usuario::esCont(){}
    DtUsuario* Usuario::getCont()
    {
        DtUsuario *xD = new DtUsuario(this->getNombre(),this->getCel());
        return xD;
    }
    void Usuario::crearConversacion(Usuario* us, Conversacion* conversacionsita )
    {
         Est_Conv* xD = new Est_Conv(true, conversacionsita, this );
         conversacionsita->setearEc2(xD);
        
         this->est_conv->add(xD);
         us->crearConv(conversacionsita);
         
    }
    
void Usuario::crearConversacionGrupo(Usuario* us, Conversacion*conver) 
{
//   Est_Conv* xD = new Est_Conv(true, conver, this );
//         conver->setearEc2(xD);
//        
//         this->est_conv->add(xD);
         us->crearConv(conver);
}


void Usuario::crearConvUsuarioGrupo(Usuario* us, Conversacion* xD)
{
        us->crearConv(xD);
//        Est_Conv* xD2 = new Est_Conv(true, xD, this);
//       xD->setearEc2(xD2);
}


   
    void Usuario::crearConv(Conversacion* conver)
    {
        Est_Conv* xD = new Est_Conv(true, conver, this);
        conver->setearEc2(xD);
        this->est_conv->add(xD);
        
    }   
    Usuario* Usuario::darMiembro()
    {
        Usuario* xD;
        return xD;
    }
    bool Usuario::tieneConv(){}
    
    ICollection* Usuario::setDtConv()
    {
        DtArchivada* archi;
        int a = 0;
        IIterator* it = this->est_conv->iterator();
        ICollection* coleccionsita = new Lista();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==true){
             coleccionsita->add(est->getDato());
             }
             else 
                 a++;
             it->next();
            }
        coleccionsita->add(archi=new DtArchivada(a));
        return coleccionsita;
    }
    
    ICollection* Usuario::Activas(){
        IIterator* it = this->est_conv->iterator();
        ICollection* coleccionsita = new Lista();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==true){
             coleccionsita->add(est->getDato());
             }
            it->next(); 
        }
        return coleccionsita;
    }
    
    Conversacion* Usuario::selecConv(int id)
    {
        IIterator* it = this->est_conv->iterator();
        Conversacion* conv;
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==true){
                conv=est->selecConv(id);
                if(conv != NULL)
                    break;
             }
             it->next();
        }
        delete it;
        return conv;
    }
    
    Conversacion* Usuario::selecConvA(int id){
        IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==false){
                 Conversacion* conv=est->selecConv(id);
                 est->setEstado(true);
                 return conv;
             }
             it->next();
        }
        return NULL;
    }
    
    Conversacion* Usuario::selecArch(int id){
        IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==false){
                 Conversacion* conv=est->selecConv(id);
                 return conv;
             }
             it->next();
        }
        return NULL;
    }
    
    ICollection* Usuario::setDtConvA(){
        IIterator* it = this->est_conv->iterator();
        ICollection* coleccionsita = new Lista();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->getEstado()==false)
             {
             coleccionsita->add(est->getDato());
             }
             it->next();
        }
        return coleccionsita;
    }
    
    void Usuario::crearConvUsuario(Usuario* us, Conversacion* xD)
    {
        us->crearConv(xD);
        Est_Conv* xD2 = new Est_Conv(true, xD, this);
       xD->setearEc2(xD2);
    }
    
    Usuario* Usuario::seleccionarCont(int cel){
       IntKey* llavesita = new IntKey(cel);
       Usuario* usu = (Usuario*) (this->contactos->find(llavesita));
       return usu;
    }
    
    ICollection* Usuario::mostrarMens()
    {
IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             if(est->selecConv(ctrlConv::getInstanceC()->getConvSel()->getIdentificador())!=NULL){
            // coleccionsita->add(est->getMens());
            return est->getMens();
                    
             }
            it->next(); 
        }

    }
    
    void Usuario::actualizarVisto(int idconv)
    {
         IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             bool es = est->esConv(idconv);
             if(es)
             {
              Conversacion* con = est->selecConv(idconv); 
              con->actualizarVisto(idconv);
              break;
             }
            it->next(); 
        }
         delete it;
    }
    
    ICollection* Usuario::selecMns(int cod)
    {
//        ctrlConv* as;
       
         IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
             Est_Conv* est = dynamic_cast <Est_Conv*> (it->getCurrent());
             bool es = est->esConv( ctrlConv::getInstanceC()->getConvSel()->getIdentificador());
             if(es)
             {
                 return est->selectMns(cod);
             }
            it->next(); 
        }   
    }
    
    void Usuario::actualizarDatos(bool visto, DtFecha* fecha)
    {
       
    }
    
    void Usuario::desvinReceptores(){}
    void Usuario::eliminar(int idConv, int idMens)
    {
        IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it->getCurrent();
               bool es = est->esConv(idConv);
                if(es)
                {
                     est->eliminar(idMens);
                    break;
                }
            it->next();
            }
        delete it;
    }
    bool Usuario::esEmisor(int){}
    bool Usuario::receptor(int){}
    void Usuario::desvincular(){}
    
    ICollection* Usuario::listarG(int id)
    {
        IIterator* it = this->est_conv->iterator();
        
        while(it->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it->getCurrent();
            if (est->selecConv(id) != NULL)
            {
                Conversacion* conver = est->selecConv(id);
                ctrlConv::getInstanceC()->setConvRec(conver);
                return conver->listarPart();
            }
            it->next();
            }
        delete it;
    }
    
    void Usuario::ingresarGrupo()
    {
        
    }
    
    ICollection* Usuario::listarM(int id)
    {
        IIterator *it = this->est_conv->iterator();
        while(it->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it->getCurrent();
            if(est->selecConv(id) != NULL)
            {
                Conversacion* conver = est->selecConv(id);
                return conver->listarUsus();
            }
        }
    }

    bool Usuario::esAdmin(int id)
    {
        IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it->getCurrent();
            if(est->selecConv(id) != NULL)
            {
                Conversacion* conver = est->selecConv(id);
                Grupal* grup = dynamic_cast <Grupal*> (conver);
                if(grup->getAdmin()->getCel() == this->cel)
                    return true;
                return false;
            }
            it->next();
        }
    }
    
    int Usuario::seleccionarMensaje(int idMenso)
    {
        IIterator* it = this->est_conv->iterator();
        while(it->hasNext())
        {
            Est_Conv* est = (Est_Conv*) it->getCurrent();
               bool es = est->esConv(ctrlConv::getInstanceC()->getConvSel()->getIdentificador());
                if(es)
                {
                     return est->traerMensaje(idMenso);
                    break;
                }
            it->next();
            }
        delete it;
    }