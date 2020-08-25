


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Aeliner
 *
 * Created on June 7, 2018, 2:18 PM
 */

#include <cstdlib>
#include <string.h>
#include "DtControl.h"
#include "Usuario.h"
#include "ctrlUsuario.h"
#include "iUsuario.h"
#include "iFecha.h"
#include "ctrlFecha.h"
#include "Fabrica.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "IDictionary.h"
#include "IIterator.h"
#include "IKey.h"
#include "Contacto.h"
#include "Conversacion.h"
#include "DtPrivada.h"
#include "DtArchivada.h"
#include "DtGrupo.h"
#include "DtSimple.h"
#include "DtVideo.h"
#include "DtContacto.h"
#include "DtImagen.h"
#include "DtParticipante.h"

using namespace std;

/* Punteritos*/

/*Variables Globales*/
int celu;
bool datosP;
DtControl controlUsu;
Fabrica* fab;
iUsuario* usu1;
iGrupo* gru1;
iFecha* fec;
iConv* conv;
DtFecha fechita;

int main(int argc, char** argv)
{
        fab = new Fabrica();
    usu1 = fab->getIusuario();
    gru1 = fab->getiGrupo();
    fec= fab->getiFecha();
    conv= fab->getiConversacion();
    datosP=false;
    int opcion, opcFecha, subOp, celu2, tamanio, opcion2;
    int dia, anio, mes, hora, min, seg=0, id;
    char respuesta;
    string nombre, desc, img, texto, formato, respuestal, respuestita;
    string url, quiere;
    
    do{
        system("cls");
    cout<<"------Guasap TIP------"<<endl;
    
    if(usu1->getSesion() != 0)
    {
        cout<<"Usuario: "<<usu1->traerUsuarioLogueado()->getNombre()<<endl;
        cout<<"Celular: "<<usu1->traerUsuarioLogueado()->getCel()<<endl;
        DtFecha* fec2 = fec->mostrarFecha();
        cout<<"Hora actual del sistema: "<<fec2->getDia()<<"/"<<fec2->getMes()<<"/"<<fec2->getAnio()<<"   "<<fec2->getHora()<<":"<<fec2->getMin()<<":"<<fec2->getSeg()<<endl;
    }
    cout<<endl<<endl<<endl;
    cout<<"1.- Abrir TeleTIP"<<endl;
    cout<<"2.- Cerrar TeleTIP"<<endl;
    cout<<"3.- Agregar contactos"<<endl;
    cout<<"4.- Alta grupo"<<endl;
    cout<<"5.- Enviar mensaje"<<endl;
    cout<<"6.- Ver mensajes"<<endl;
    cout<<"7.- Archivar conversaciones"<<endl;
    cout<<"8.- Modificar usuario"<<endl;
    cout<<"9.- Eliminar mensajes"<<endl;
    cout<<"10.- Agregar paticipantes a un grupo"<<endl;
    cout<<"11.- Hora del sistema"<<endl;
    cout<<"12.- Cargar datos de prueba"<<endl;
    cout<<"0.- Cerrar"<<endl;
    cout<<"Ingrese una opcion:   "<<endl;
    cin>>opcion2;
    system("cls");
    switch(opcion2){
        case 1:
        {
            if(usu1->haySesion())
                cout<<"Se ha iniciado sesion: "<<usu1->getSesion()<<"nombre: "<<usu1->traerUsuarioLogueado()->getNombre()<<endl<<endl;
            else
                cout<<"No hay sesion abierta"<<endl<<endl;
            
             do
            {
            cout<<"---Abrir TeleTIP---"<<endl<<endl;

            cout<<"Ingrese su numero de celular: ";
            cin>>celu;
            if(celu <= 0){
                cout<<"Numero invalido"<<endl;
                break;
            }
            
              if (usu1->haySesion() && usu1->getSesion() != celu )
           {  
                    cout<<"Ya hay una sesion abierta, desea cerrarla? s/n : ";
                            cin>>respuesta;
                            if(respuesta == 's'){
                            usu1->cerrarSesion();
                            cout<<endl<<"Sesion cerrada"<<endl;
                            system("pause");
                            }
                            else{
                                break;
                            }      
           }
            
            controlUsu = usu1->ingNum(celu);
           if(!usu1->existeEnSis(celu))
           {
     
               cout<<"Este usuario no existe en el sistema"<<endl;
               cout<<"Desea darse de alta? s/n: "<<endl;
               cin>>respuesta;
               cout<<endl;
               if (respuesta =='s')
               {
                   cin.ignore();
                   cout<<"Ingrese nombre"<<endl;
                   getline(cin, nombre);
                   cout<<"Ingrese descripcion"<<endl;
                   getline(cin, desc);
                   cout<<"Ingrese url de imagen"<<endl;
                   getline(cin, img);
                   usu1->registrar(nombre, desc, img);
                     controlUsu.setSesion(true);
                     DtFecha* fec = usu1->mostrarConexion();
                   cout<<fec->getDia()<<"/"<<fec->getMes()<<"/"<<fec->getAnio()<<"   "<<fec->getHora()<<":"<<fec->getMin()<<":"<<fec->getSeg()<<endl;
                   cout<<endl<<"Bienvenido a TeleTIP "<<usu1->traerUsuarioLogueado()->getNombre()<<endl;
               }
               
               else
               {
                   usu1->cancelar();
               }
               
           }
            
           else
           {
               usu1->setSesion(celu);
               cout<<"Se ha iniciado una sesion con el usuario "<<usu1->getSesion()<<" satisfactoriamente"<<endl;
           }
           
                break;
           
           }while(controlUsu.getExiste()==false || controlUsu.getSesion()==true);

           system("pause");
           break;
        }  
        case 2:
        {
            if(usu1->getSesion() != 0)
            {
           usu1->cerrarSesion();
            cout<<"Sesion cerrada"<<endl;
            system("pause");
            break;
            }
                cout<<"No hay una sesion abierta"<<endl;
            system("pause");
            break;
        }
        case 3:
		{
			if(usu1->getSesion() == 0)
			{
				cout<<"No hay una sesion activa en el sistema"<<endl;
				system("pause");
				break;
			}
			
			do{
				system("cls");
				cout<<"---Agregar Contactos---"<<endl<<endl;
				cout<<"Lista de Contactos: "<<endl;
				ICollection* cont = usu1->listarContactos();
				IIterator *itCont = cont->iterator();
				
				if (!itCont->hasNext())
				{
					cout<<"No tienes contactos"<<endl;
				}
				
				int numerito = 1;
				while(itCont->hasNext())
				{
					DtUsuario* dt = dynamic_cast <DtUsuario*> (itCont->getCurrent());
					cout<<"Contacto "<<numerito<<": "<<endl;
					cout<<"Nombre: "<<dt->getNombre()<<endl;
					cout<<"Celular: "<<dt->getCel()<<endl;
					cout<<"------------------------------"<<endl;
					numerito++;
					itCont->next();
				}
				cout<<"1.- Ingresar nuevo contacto"<<endl;
                                cout<<"2.- Regresar"<<endl;
                                cin>>opcion;
                                
                                if(opcion == 1)
                                {
				cout<<"Ingrese el celular de su nuevo contacto: ";
				cin>>celu;
				bool valido;
				try{
					valido = usu1->numeroValid(celu, cont);
				}catch(const invalid_argument &e){
					cout<<"Error: "<<e.what()<<endl;
					valido = false;
					system("pause");
				}
				
				if(valido)
				{
					DtUsuario datos = usu1->agregarContacto(celu);
					cout<<"Nombre: "<<datos.getNombre()<<endl;
					cout<<"Celular: "<<datos.getCel()<<endl;
					cout<<"Desea agregar a este usuario a su lista de contactos? s/n: ";
					cin>>respuesta;
					if(respuesta=='s')
					{
						usu1->confirmar();
					}
					else
					{
						break;
					}
					
					
					cout<<"Desea seguir agregando usuarios a su lista de contactos? s/n: ";
					cin>>respuesta;
				}
                                }
                                if(opcion == 2)
                                    break;
			}while(respuesta != 'n');
			break;
		}
        case 4:
            {
                bool validon = true;
			if(usu1->getSesion() == 0)
			{
				cout<<"No hay una sesion activa en el sistema"<<endl;
				system("pause");
				break;
			}
			
			
			do{
				system("cls");
				
				cout<<"---Alta Grupo---"<<endl;
				ICollection* grup = gru1->listarMiembrosGrupo();
				IIterator *itM = grup->iterator();
				if(!itM->hasNext())
				{
					cout<<"No hay contactos seleccionados aun"<<endl;
				}
				
				else{
					int numeritoC = 1;
					cout<<"---Lista de contactos a formar parte del grupo---"<<endl;
					while(itM->hasNext())
					{
						DtUsuario* dt = dynamic_cast <DtUsuario*> (itM->getCurrent());
						cout<<"Contacto "<<numeritoC<<": "<<endl;
						cout<<"Nombre: "<<dt->getNombre()<<endl;
						cout<<"Celular: "<<dt->getCel()<<endl;
						cout<<"------------------------------"<<endl;
                                                numeritoC++;
						itM->next();
					}
					
                                    }   
				ICollection* cont = usu1->listarContactos();
				IIterator *itC = cont->iterator();
				cout<<"---Lista de Contactos---"<<endl;
				if (!itC->hasNext())
				{
					cout<<"No tienes contactos"<<endl;
					system("pause");
                                        validon = false;
					break;
				}
				
				int numerito = 1;
				while(itC->hasNext())
				{
					DtUsuario* dt = dynamic_cast <DtUsuario*> (itC->getCurrent());
					cout<<"Contacto "<<numerito<<": "<<endl;
					cout<<"Nombre: "<<dt->getNombre()<<endl;
					cout<<"Celular: "<<dt->getCel()<<endl;
					cout<<"------------------------------"<<endl;
                                        numerito++;
					itC->next();
				}
				int respuestota;
				cout<<"1.- Ingresar un nuevo usuario al grupo"<<endl;
				cout<<"2.- Quitar un contacto del grupo"<<endl;
				cout<<"3.- Confirmar creacion del grupo"<<endl;
                                cout<<"4.- Regresar"<<endl;
				cout<<"Seleccione una opcion: ";
				cin>>respuestota;
				
				if(respuestota == 1)
				{
					cout<<"Ingrese el numero de celular del usuario a ingresar al grupo: ";
					cin>>celu;
					bool valido = true;
					if(!usu1->existeEnSis(celu))
					{
						cout<<"Este usuario no existe en el sistema"<<endl;
						valido = false;
						system("pause");
					}   
					if(valido)
					{
						try{
							gru1->valido(cont, grup, celu);
						}catch(const invalid_argument &e){
							cout<<"Error: "<<e.what()<<endl;
							system("pause");
							valido = false;
						}
						
						if(valido)
						{
							
							gru1->elegirContactos(celu);
                                                        cout<<"El usuario "<<celu<<" ha sido agregado"<<endl;
                                                        system("pause");
						}
					}
					
					
				}
				
				if(respuestota == 2)
				{
					cout<<"Ingrese el numero de celular del usuario a quitar del grupo: ";
					cin>>celu;
					bool valido = true;
					if(!usu1->existeEnSis(celu))
					{
						cout<<"Este usuario no existe en el sistema"<<endl;
						valido = false;
						system("pause");
					}
					
					if(valido)
					{
						try{
							gru1->valido2(grup, celu);
						}catch(const invalid_argument &e){
							cout<<"Error: "<<e.what()<<endl;
							system("pause");
							valido = false;
						}
						
						if(valido)
						{
							
							gru1->quitarContacto(celu);
                                                        cout<<"El usuario "<<celu<<" ha sido quitado"<<endl;
                                                        system("pause");
						}
					} 
				}
				
				
				if (respuestota == 3)
				{
					IIterator* it = grup->iterator();
					if(!it->hasNext())
					{
						cout<<"Debe ingresar al menos 1 usuario al grupo"<<endl;
						cout<<"Desea ingresar algun usuario al grupo? s/n:";
						cin>>respuestal;
						if(respuestal == "n")
						{
							gru1->cancelar();
                                                        validon = false;
							break;
						}
					}
					else
					{
						respuestita = "n";  
					}
				}
                                
                                if(respuestota == 4)
                                {
                                    gru1->cancelar();
                                    validon = false;
                                    break;
                                }
				
			}while(respuestita != "n");
                        if(validon)
                        {
                            cin.ignore();
			cout<<"Ingrese el nombre del grupo: ";
			getline(cin, nombre);
			cout<<"Ingrese la url de la imagen del grupo: ";
			getline(cin, img);
			
			gru1->crearGrupo(nombre, img);
                        cout<<"El grupo "<<nombre<<" se ha creado de manera satisfactoria"<<endl;
                        system("pause");
			break;
			}
                break;
		}
        case 5:
        {
        if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            cout<<"---------------------------------"<<endl;
            cout<<"-----------Enviar Mensaje--------"<<endl;
            cout<<"---------------------------------"<<endl<<endl<<endl;
        
            ICollection* convs = conv->listarConv();
            IIterator *itConv = convs->iterator();
            ICollection* convsArch = conv->listarConvArch();
            IIterator *itConvArch = convsArch->iterator();
            ICollection* cont = conv->listarContacto();
            
            

               while(itConv->hasNext())
            {
                
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConv->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConv->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"Id: "<<dtGrp->getId()<<endl;
                }
                 
                     

                  DtArchivada* arch = dynamic_cast <DtArchivada*> (itConv->getCurrent());
                
                  if(arch!=NULL){
                 cout<<"-------------ARCHIVADAS--------"<<endl;
            
                  cout<<"Tiene :"<<arch->getCant()<<endl<<endl<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl<<endl;
                  
                  cout<<"-------------ACTIVAS--------"<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl;
                  
                  if(!conv->listarCA()->iterator()->hasNext()){
                  cout<<"No tiene conversaciones activas"<<endl;
                  }

                }
                  
       
              itConv->next(); 
        }

             delete itConv;
             
             
             
             cout<<"------------------------------"<<endl;
             cout<<"Seleccione una opcion: "<<endl;
             cout<<"    1. Seleccionar conversacion activa"<<endl;
             cout<<"    2. Ver conversaciones archivadas"<<endl;
             cout<<"    3. Comenzar una nueva conversacion"<<endl;
             cout<<"    4. Regresar"<<endl;
             cin>>opcion;

             bool existe;
             if(opcion == 1)
             {
             if(conv->listarCA()->iterator()->hasNext()){
             cout<<"Ingrese Id de la conversacion"<<endl;
             cin>>subOp;
             
             try{
                 existe=conv->existeList(subOp);
             } catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
             }
             
             if(existe){
             
             
                conv->ingresarId(subOp);
             
             }
             
             }
             else{
                 cout<<"No tiene conversaciones activas para seleccionar"<<endl;
                 system("pause");
                 break;
             }
             }
             
             if(opcion == 2)
             {
                 cout<<"------------------------------"<<endl;
                 cout<<"--------Lista Archivada-------"<<endl;
                 cout<<"------------------------------"<<endl;
                 
                 
                  
            if (!itConvArch->hasNext())
            {
                cout<<"No tiene conversaciones archivadas"<<endl;
                system("pause");
                break;
            }
                 while(itConvArch->hasNext())
                 {
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConvArch->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConvArch->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                }
                 
                     itConvArch->next();
                 }
                  delete itConvArch;

                 cout<<"Ingrese ID de la conversacion archivada: ";
                 cin>>subOp;
                  bool ver;
                  try{
                      ver=conv->existeListAr(subOp);
                  }
                  catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
                 }
                  if(ver){
                  conv->ingresarIdConvArch(subOp);
                  }
             }
             if(opcion == 3)
             {
              cout<<"Lista de Contactos: "<<endl;
           
            IIterator *itCont = cont->iterator();
            
            if (!itCont->hasNext())
            {
                cout<<"No tienes contactos"<<endl;
                system("pause");
                break;
            }
            int numerito = 1;
            while(itCont->hasNext())
            {
                DtUsuario* dt = dynamic_cast <DtUsuario*> (itCont->getCurrent());
                cout<<"Contacto "<<numerito<<": "<<endl;
                cout<<"Nombre: "<<dt->getNombre()<<endl;
                cout<<"Celular: "<<dt->getCel()<<endl;
                cout<<"------------------------------"<<endl;
                numerito++;
                   itCont->next(); 
            }
            delete itCont;
            cout<<"Ingrese numero: ";
                 cin>>subOp;
                 bool existe;
                 bool conver;
                 try{
                     existe=conv->existeConv(subOp);
                     conver=conv->existeCont(subOp, cont);
                 }
                 catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=true;
                 conver=false;
                 system("pause");
                 break;
                 }
                 
                 if(!existe && conver){
                 conv->seleccionarContacto(subOp); 
                 conv->iniciarConversacion();
                 }
             }
             
             if(opcion==4)
                 break;
             
             
             cout<<"Ingrese tipo de mensaje a mandar: "<<endl;
             cout<<"    1.Simple  "<<endl;
             cout<<"    2.Imagen  "<<endl;
             cout<<"    3.Video  "<<endl;
             cout<<"    4.Contacto  "<<endl;
             cin>>opcion;
             
             
             
             if(opcion == 1)
             {
                cin.ignore();
                cout<<"Ingrese texto: ";
                getline(cin, texto);
                conv->ingresarTexto(texto);
                conv->crearMensaje(*( new DtSimple(texto, fec->mostrarFecha(), false)));
                cout<<"El mensaje se envio satisfactoriamente"<<endl;
                system("pause");
                break;
             }
             if(opcion == 2)
             {
                cin.ignore();
                cout<<"Ingrese formato imagen: ";
                getline(cin, formato);

                cout<<"Ingrese url imagen: ";
                getline(cin, url);
                
                cout<<"Ingrese tamanio: ";
                cin>>tamanio;
                
                cout<<"Desea ingresar texto? s/n ";
                cin>>respuesta;
                
                if(respuesta=='s'){
                cin.ignore();
                cout<<"Ingrese texto: ";
                getline(cin, texto);
                conv->ingresarImagen(formato,tamanio,texto,url);
                conv->crearMensaje(*( new DtImagen(url, formato, tamanio, texto,fec->mostrarFecha(), false)));
                cout<<"El mensaje se envio satisfactoriamente"<<endl;
                system("pause");
                break;
                }
                
                else {
                conv->ingresarImagen(formato,tamanio," ",url);
                conv->crearMensaje(*( new DtImagen(url, formato, tamanio, " ",fec->mostrarFecha(), false)));
                cout<<"El mensaje se envio satisfactoriamente"<<endl;
                system("pause");
                break;
                }

                
             
             }
             if(opcion == 3)
             {
                cin.ignore();
                cout<<"Ingrese url del video: ";
                getline(cin, formato);

                cout<<"Ingrese duracion: ";
                cin>>tamanio;
                
               
                conv->ingresarVideo(formato,tamanio);
                conv->crearMensaje(*(new DtVideo(formato, tamanio, fec->mostrarFecha(), false)));
                cout<<"El mensaje se envio satisfactoriamente"<<endl;
                system("pause");
                break;
                
             }
              if(opcion == 4)
             {
              cout<<"Lista de Contactos: "<<endl;
            IIterator *itCont = cont->iterator();
            
            if (!itCont->hasNext())
            {
                cout<<"No tienes contactos"<<endl;
                system("pause");
            }
            
            int numerito = 1;
            while(itCont->hasNext())
            {
                DtUsuario* dt = dynamic_cast <DtUsuario*> (itCont->getCurrent());
                cout<<"Contacto "<<numerito<<": "<<endl;
                cout<<"Nombre: "<<dt->getNombre()<<endl;
                cout<<"Celular: "<<dt->getCel()<<endl;
                cout<<"------------------------------"<<endl;
                numerito++;
                   itCont->next(); 
            }
            bool conver;
            cout<<"Ingrese numero: ";
                 cin>>subOp;
                 try{
                     conver=conv->existeCont(subOp, cont);
                 }
                 catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 conver=false;
                 system("pause");
                 break;
                 }
                 
                 if(conver){
                 Usuario* us=conv->seleccionarContactoM(subOp);
                 conv->crearMensaje(*(new DtContacto(us->getNombre(), us->getCel(), fec->mostrarFecha(), false)));
                 cout<<"El mensaje se envio satisfactoriamente"<<endl;
                 system("pause");
                 break;
                 }
             }
             

             
             break; 
    }
        case 6:
        {
        if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            cout<<"---------------------------------"<<endl;
            cout<<"------------Ver Mensajes---------"<<endl;
            cout<<"---------------------------------"<<endl<<endl<<endl;
        
            ICollection* convs = conv->listarConv();
            IIterator *itConv = convs->iterator();
            ICollection* convsArch = conv->listarConvArch();
            IIterator *itConvArch = convsArch->iterator();
            ICollection* cont = conv->listarContacto();
            
            

               while(itConv->hasNext())
            {
                
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConv->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConv->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"ID: "<<dtGrp->getId()<<endl;
                }
                 
                     

                  DtArchivada* arch = dynamic_cast <DtArchivada*> (itConv->getCurrent());
                
                  if(arch!=NULL){
                 cout<<"-------------ARCHIVADAS--------"<<endl;
            
                  cout<<"Tiene :"<<arch->getCant()<<endl<<endl<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl<<endl;
                  
                  cout<<"-------------ACTIVAS--------"<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl;
                  
                  if(!conv->listarCA()->iterator()->hasNext()){
                  cout<<"No tiene conversaciones activas"<<endl;
                  }

                }
                  
       
              itConv->next(); 
        }

             delete itConv;
             
             
             
             cout<<"------------------------------"<<endl;
             cout<<"Seleccione una opcion: "<<endl;
             cout<<"    1. Seleccionar conversacion activa"<<endl;
             cout<<"    2. Ver conversaciones archivadas"<<endl;
             cout<<"    3. Regresar"<<endl;
             cin>>opcion;

             bool existe;
             if(opcion == 1)
             {
             if(conv->listarCA()->iterator()->hasNext()){
             cout<<"Ingrese Id de la conversacion"<<endl;
             cin>>subOp;
             
             try{
                 existe=conv->existeList(subOp);
             } catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
             }
             
             if(existe){
             
             
                conv->ingresarId(subOp);
             
             }
             
             }
             else{
                 cout<<"No tiene conversaciones activas para seleccionar"<<endl;
                 system("pause");
                 break;
             }
             }
             
             if(opcion == 2)
             {
                 cout<<"------------------------------"<<endl;
                 cout<<"--------Lista Archivada-------"<<endl;
                 cout<<"------------------------------"<<endl;
                 
                 
                  
            if (!itConvArch->hasNext())
            {
                cout<<"No tiene conversaciones archivadas"<<endl;
                system("pause");
                break;
            }
                 while(itConvArch->hasNext())
                 {
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConvArch->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConvArch->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"ID: "<<dtGrp->getId()<<endl;
                }
                 
                     itConvArch->next();
                 }
                  delete itConvArch;

                 cout<<"Ingrese ID de la conversacion archivada: ";
                 cin>>subOp;
                  bool ver;
                  try{
                      ver=conv->existeListAr(subOp);
                  }
                  catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
                 }
                  if(ver){
                  conv->ingresaArch(subOp);
                  }
             }
             if (opcion == 3)
                 break;
          
              conv->actualizarvisto();

              ICollection* Menso = conv->mostrarMnsj();
              IIterator* itMenso = Menso->iterator();
              
              if(!itMenso->hasNext()){
                  cout<<"La conversacion seleccionada no tiene mensajes"<<endl;
                  system("pause");
                  break;
              }
              
              while(itMenso->hasNext())
              {
                  DtSimple* dtSim = dynamic_cast <DtSimple*> (itMenso->getCurrent());
                 if(dtSim!=NULL) {
                     cout<<"Codigo: "<<dtSim->getCodigo()<<endl;
                     cout<<"Fecha: "<<dtSim->getFecha()->getDia()<<"/"<<dtSim->getFecha()->getMes()<<"/"<<dtSim->getFecha()->getAnio()<<"   "<<dtSim->getFecha()->getHora()<<":"<<dtSim->getFecha()->getMin()<<":"<<dtSim->getFecha()->getSeg()<<endl;
                     cout<<"Texto: "<<dtSim->getTexto()<<endl;
                     if(dtSim->getVisto()==true)
                     cout<<"Fue visto"<<endl;
                     else
                         cout<<"No fue visto"<<endl;
                     cout<<"------------------------------------------------------------------"<<endl;
                 }
                  
                   DtImagen* dtImg = dynamic_cast <DtImagen*> (itMenso->getCurrent());
                  if(dtImg!=NULL){
                      cout<<"Codigo: "<<dtImg->getCodigo()<<endl;
                      cout<<"Fecha: "<<dtImg->getFecha()->getDia()<<"/"<<dtImg->getFecha()->getMes()<<"/"<<dtImg->getFecha()->getAnio()<<"   "<<dtImg->getFecha()->getHora()<<":"<<dtImg->getFecha()->getMin()<<":"<<dtImg->getFecha()->getSeg()<<endl;
                      cout<<"Formato: "<<dtImg->getFormato()<<endl;
                      cout<<"Texto: "<<dtImg->getTexto()<<endl;
                      cout<<"Tamanio: "<<dtImg->getTamanio()<<endl;
                      if(dtImg->getVisto()==true)
                     cout<<"Fue visto"<<endl;
                     else
                         cout<<"No fue visto"<<endl;
                      
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                   
                  DtVideo* dtVid = dynamic_cast <DtVideo*> (itMenso->getCurrent());
                  if(dtVid!=NULL){
                      cout<<"Codigo: "<<dtVid->getCodigo()<<endl;
                      cout<<"Fecha: "<<dtVid->getFecha()->getDia()<<"/"<<dtVid->getFecha()->getMes()<<"/"<<dtVid->getFecha()->getAnio()<<"   "<<dtVid->getFecha()->getHora()<<":"<<dtVid->getFecha()->getMin()<<":"<<dtVid->getFecha()->getSeg()<<endl;
                      cout<<"Duracion: "<<dtVid->getDuracion()<<endl;
                      cout<<"Url: "<<dtVid->getUrl()<<endl;
                      if(dtVid->getVisto()==true)
                      cout<<"Fue visto"<<endl;
                      else
                         cout<<"No fue visto"<<endl;
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                  
                  DtContacto* dtCon = dynamic_cast <DtContacto*> (itMenso->getCurrent());
                  
                  if(dtCon!=NULL){
                      cout<<"Celular: "<<dtCon->getCel()<<endl;
                      cout<<"Fecha: "<<dtCon->getFecha()->getDia()<<"/"<<dtCon->getFecha()->getMes()<<"/"<<dtCon->getFecha()->getAnio()<<"   "<<dtCon->getFecha()->getHora()<<":"<<dtCon->getFecha()->getMin()<<":"<<dtCon->getFecha()->getSeg()<<endl;
                      cout<<"Nombre:"<<dtCon->getNombre()<<endl;
                      cout<<"Codigo: "<<dtCon->getCodigo()<<endl;
                      if(dtCon->getVisto()==true)
                      cout<<"Fue visto"<<endl;
                      else
                         cout<<"No fue visto"<<endl;
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                  
                  itMenso->next();
                  
              }
              delete itMenso;
              cout<<endl;
              do{
              cout<<"Queres ver datos adicionales? s/n"<<endl;
              cin>>respuesta;
             if(respuesta == 's'){
                cout<<"Ingrese id de mensaje"<<endl;
                cin>>subOp;
                bool valido = true;
                try{
                    conv->idValido(subOp, Menso);
            } 
            catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 valido = false;
                 system("pause");
                 }
                if(valido)
                {
                ICollection* dtDatito =  conv->seleccionarMens(subOp);
                itMenso = dtDatito->iterator();
                
                if(!itMenso->hasNext())
                {
                    cout<<"Este mensaje aun no tiene informacion adicional"<<endl;
                    system("pause");
                }
                
                while(itMenso->hasNext())
                {
                   DtDatoM* dtM= dynamic_cast <DtDatoM*> (itMenso->getCurrent());
                   if(dtM!=NULL) {            
                     
                     cout<<"Nombre de usuario: "<<dtM->getNomRecept()<<endl;
                     cout<<"Celular: "<<dtM->getNumRecept()<<endl;
                     cout<<"Fecha: "<<dtM->getFecha()->getDia()<<"/"<<dtM->getFecha()->getMes()<<"/"<<dtM->getFecha()->getAnio()<<"   "<<dtM->getFecha()->getHora()<<":"<<dtM->getFecha()->getMin()<<":"<<dtM->getFecha()->getSeg()<<endl;
                     system("pause");
                    }
                          itMenso->next();
              }
              }
              
             }
              }while(respuesta == 's');
              break;
        }
        case 7:
            
            if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            do{
            cout<<"---Archivar conversacion---"<<endl;

            ICollection* convs = conv->listarCA();
            IIterator *itConv = convs->iterator();

            if (!itConv->hasNext())
            {
                cout<<"No tiene conversaciones activas"<<endl;
                system("pause");
                break;
            }
            
            while(itConv->hasNext())
            {
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConv->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConv->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"Id: "<<dtGrp->getId()<<endl;
                }
                
                   itConv->next(); 
            }
            bool convA;
            cout<<"Ingrese id de la conversacion a archivar: ";
            cin>>id;
//            if(id==1){
//                cout<<"No se puede archivar conversacion con id 1"<<endl;
//                system("pause");
//            }
//            else{
            try{
                convA=conv->existeList(id);
            } 
            catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 convA=false;
                 system("pause");
                 break;
                 }
            
            if(convA){
            conv->seleccionarConv(id);
            conv->archivarConv(id);
            cout<<"Desea seguir archivando conversaciones? s/n"<<endl;
            cin>>respuesta;
            }
            
            }while(respuesta=='s');
            
            break;
        case 8:
            if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            cout<<"---Modificar Usuario---"<<endl;
            cout<<"1.-Modificar nombre"<<endl;
            cout<<"2.-Modificar imagen"<<endl;
            cout<<"3.-Modificar descripcion"<<endl;
            cout<<"4.-Regresar"<<endl;
            cin>>subOp;
            if(subOp==1){
                cin.ignore();
                cout<<"Ingrese nuevo nombre de usuario: ";
                getline(cin, nombre);
                usu1->cambiarNombre(nombre);
                cout<<"Su nombre fue modificada correctamente"<<endl;
                system("pause");
                break;
            }
            if(subOp==2){
                cin.ignore();
                cout<<"Ingrese nueva url de imagen: ";
                getline(cin, img);
                usu1->cambiarImagen(img);
                cout<<"Su imagen fue modificada correctamente"<<endl;
                system("pause");
                break;
            }
            if(subOp==3){
                cin.ignore();
                cout<<"Ingrese nueva descripcion: ";
                getline(cin, desc);
                usu1->cambiarDes(desc);
                cout<<"Su descripcion fue modificada correctamente"<<endl;
                system("pause");
                break;
            }
            if(subOp==4){
                break;
            }

            break;
            
        case 9:
    {
        if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            cout<<"---------------------------------"<<endl;
            cout<<"------------Eliminar Mensajes---------"<<endl;
            cout<<"---------------------------------"<<endl<<endl<<endl;
        
            ICollection* convs = conv->listarConv();
            IIterator *itConv = convs->iterator();
            ICollection* convsArch = conv->listarConvArch();
            IIterator *itConvArch = convsArch->iterator();
            ICollection* cont = conv->listarContacto();
            
            

               while(itConv->hasNext())
            {
                
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConv->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConv->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"ID: "<<dtGrp->getId()<<endl;
                }
                 
                     

                  DtArchivada* arch = dynamic_cast <DtArchivada*> (itConv->getCurrent());
                
                  if(arch!=NULL){
                 cout<<"-------------ARCHIVADAS--------"<<endl;
            
                  cout<<"Tiene :"<<arch->getCant()<<endl<<endl<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl<<endl;
                  
                  cout<<"-------------ACTIVAS--------"<<endl;
                  
                  cout<<"-----------------------------"<<endl<<endl;
                  
                  if(!conv->listarCA()->iterator()->hasNext()){
                  cout<<"No tiene conversaciones activas"<<endl;
                  }

                }
                  
       
              itConv->next(); 
        }

             delete itConv;
             
             
             
             cout<<"------------------------------"<<endl;
             cout<<"Seleccione una opcion: "<<endl;
             cout<<"    1. Seleccionar conversacion activa"<<endl;
             cout<<"    2. Ver conversaciones archivadas"<<endl;
             cout<<"    3. Regresar"<<endl;
             cin>>opcion;

             bool existe;
             if(opcion == 1)
             {
             if(conv->listarCA()->iterator()->hasNext()){
             cout<<"Ingrese Id de la conversacion"<<endl;
             cin>>subOp;
             
             try{
                 existe=conv->existeList(subOp);
             } catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
             }
             
             if(existe){
             
             
                conv->ingresarId(subOp);
             
             }
             
             }
             else{
                 cout<<"No tiene conversaciones activas para seleccionar"<<endl;
                 system("pause");
                 break;
             }
             }
             
             if(opcion == 2)
             {
                 cout<<"------------------------------"<<endl;
                 cout<<"--------Lista Archivada-------"<<endl;
                 cout<<"------------------------------"<<endl;
                 
                 
                  
            if (!itConvArch->hasNext())
            {
                cout<<"No tiene conversaciones archivadas"<<endl;
                system("pause");
                break;
            }
                 while(itConvArch->hasNext())
                 {
                DtPrivada* dtPv = dynamic_cast <DtPrivada*> (itConvArch->getCurrent());
                if(dtPv!=NULL){
                cout<<"Nombre: "<<dtPv->getNombre()<<endl;
                cout<<"Celular: "<<dtPv->getNumero()<<endl;
                cout<<"Id: "<<dtPv->getId()<<endl;
                cout<<"------------------------------"<<endl;
                
                }
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConvArch->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"ID: "<<dtGrp->getId()<<endl;
                }
                 
                     itConvArch->next();
                 }
                  delete itConvArch;

                 cout<<"Ingrese ID de la conversacion archivada: ";
                 cin>>subOp;
                  bool ver;
                  try{
                      ver=conv->existeListAr(subOp);
                  }
                  catch (const invalid_argument &e){
                 cout<<"Error: "<<e.what()<<endl;
                 existe=false;
                 system("pause");
                 break;
                 }
                  if(ver){
                  conv->ingresaArch(subOp);
                  }
             }
             if (opcion == 3)
                 break;
          
              conv->actualizarvisto();
              ICollection* Menso = conv->mostrarMnsj();
              IIterator* itMenso = Menso->iterator();
              
              if(!itMenso->hasNext()){
                  cout<<"La conversacion seleccionada no tiene mensajes"<<endl;
                  system("pause");
                  break;
              }
              
              while(itMenso->hasNext())
              {
                  DtSimple* dtSim = dynamic_cast <DtSimple*> (itMenso->getCurrent());
                 if(dtSim!=NULL) {
                     cout<<"Codigo: "<<dtSim->getCodigo()<<endl;
                     cout<<"Fecha: "<<dtSim->getFecha()->getDia()<<"/"<<dtSim->getFecha()->getMes()<<"/"<<dtSim->getFecha()->getAnio()<<"   "<<dtSim->getFecha()->getHora()<<":"<<dtSim->getFecha()->getMin()<<":"<<dtSim->getFecha()->getSeg()<<endl;
                     cout<<"Texto: "<<dtSim->getTexto()<<endl;
                     if(dtSim->getVisto()==true)
                     cout<<"Fue visto"<<endl;
                     else
                         cout<<"No fue visto"<<endl;
                     cout<<"------------------------------------------------------------------"<<endl;
                 }
                  
                   DtImagen* dtImg = dynamic_cast <DtImagen*> (itMenso->getCurrent());
                  if(dtImg!=NULL){
                      cout<<"Codigo: "<<dtImg->getCodigo()<<endl;
                      cout<<"Fecha: "<<dtImg->getFecha()->getDia()<<"/"<<dtImg->getFecha()->getMes()<<"/"<<dtImg->getFecha()->getAnio()<<"   "<<dtImg->getFecha()->getHora()<<":"<<dtImg->getFecha()->getMin()<<":"<<dtImg->getFecha()->getSeg()<<endl;
                      cout<<"Formato: "<<dtImg->getFormato()<<endl;
                      cout<<"Texto: "<<dtImg->getTexto()<<endl;
                      cout<<"Tamanio: "<<dtImg->getTamanio()<<endl;
                      if(dtImg->getVisto()==true)
                     cout<<"Fue visto"<<endl;
                     else
                         cout<<"No fue visto"<<endl;
                      
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                   
                  DtVideo* dtVid = dynamic_cast <DtVideo*> (itMenso->getCurrent());
                  if(dtVid!=NULL){
                      cout<<"Codigo: "<<dtVid->getCodigo()<<endl;
                      cout<<"Fecha: "<<dtVid->getFecha()->getDia()<<"/"<<dtVid->getFecha()->getMes()<<"/"<<dtVid->getFecha()->getAnio()<<"   "<<dtVid->getFecha()->getHora()<<":"<<dtVid->getFecha()->getMin()<<":"<<dtVid->getFecha()->getSeg()<<endl;
                      cout<<"Duracion: "<<dtVid->getDuracion()<<endl;
                      cout<<"Url: "<<dtVid->getUrl()<<endl;
                      if(dtVid->getVisto()==true)
                      cout<<"Fue visto"<<endl;
                      else
                         cout<<"No fue visto"<<endl;
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                  
                  DtContacto* dtCon = dynamic_cast <DtContacto*> (itMenso->getCurrent());
                  
                  if(dtCon!=NULL){
                      cout<<"Celular: "<<dtCon->getCel()<<endl;
                      cout<<"Fecha: "<<dtCon->getFecha()->getDia()<<"/"<<dtCon->getFecha()->getMes()<<"/"<<dtCon->getFecha()->getAnio()<<"   "<<dtCon->getFecha()->getHora()<<":"<<dtCon->getFecha()->getMin()<<":"<<dtCon->getFecha()->getSeg()<<endl;
                      cout<<"Nombre:"<<dtCon->getNombre()<<endl;
                      cout<<"Codigo: "<<dtCon->getCodigo()<<endl;
                      if(dtCon->getVisto()==true)
                      cout<<"Fue visto"<<endl;
                      else
                         cout<<"No fue visto"<<endl;
                      cout<<"------------------------------------------------------------------"<<endl;
                  }
                  
                  itMenso->next();
                  
              }
              delete itMenso;
              
                 cout<<"------------------------------"<<endl;
                 cout<<"Ingese ID del mensaje que desea eliminar"<<endl;
             cin>>subOp;
             conv->selecMensaje(subOp);
             conv->eliminar();
             cout<<"El mensaje fue eliminado correctamente"<<endl;
             system("pause");
             break;
        }
        case 10:
        {
            bool valido4 = true;
            if(usu1->getSesion() == 0)
            {
		cout<<"No hay una sesion activa en el sistema"<<endl;
		system("pause");
		break;
            }
            
            ICollection* convs = conv->listarCA();
            IIterator *itConv = convs->iterator();
            if (!itConv->hasNext())
            {
                cout<<"No tiene conversaciones aún "<<endl;
                system("pause");
                break;
            }
                cout<<"------------------------------"<<endl;
                cout<<"--------CONVERSACIONES--------"<<endl;
                cout<<"------------------------------"<<endl;
                int part = 0;
               while(itConv->hasNext())
            {
                 DtGrupo* dtGrp = dynamic_cast <DtGrupo*> (itConv->getCurrent());
                 if(dtGrp!=NULL) {
                 cout<<"Nombre: "<<dtGrp->getNombre()<<endl;
                 cout<<"Identificador: "<<dtGrp->getId()<<endl;
                 part++;
                }
                itConv->next();
               }
                 delete itConv;
                 if(part == 0)
                 {
                     cout<<"Usted no participa en ningún grupo"<<endl;
                     system("pause");
                     break; 
                 }
                 
                 cout<<"Ingrese el id del grupo: "<<endl;
                 cin>>part;
                 ICollection* participantes = gru1->seleccionarGrupo(part);
                 
                 do
                 {
                     
                     ICollection* grup = gru1->listarMiembrosGrupo();
				IIterator *itM = grup->iterator();
				if(!itM->hasNext())
				{
					cout<<"No hay contactos seleccionados aun"<<endl;
				}
				
				else{
					int numeritoC = 1;
					cout<<"---Lista de contactos a formar parte del grupo---"<<endl;
					while(itM->hasNext())
					{
						DtUsuario* dt = dynamic_cast <DtUsuario*> (itM->getCurrent());
						cout<<"Contacto "<<numeritoC<<": "<<endl;
						cout<<"Nombre: "<<dt->getNombre()<<endl;
						cout<<"Celular: "<<dt->getCel()<<endl;
						cout<<"------------------------------"<<endl;
                                                numeritoC++;
						itM->next();
					}
					
                                    } 
                                
                 cout<<"-----------------------------"<<endl;
                 cout<<"--------PARTICIPANTES--------"<<endl;
                 cout<<"-----------------------------"<<endl;
                 IIterator *itP = participantes->iterator();
                 int par1 = 1;
                 while(itP->hasNext())
                 {
                     DtParticipante* dtP = dynamic_cast <DtParticipante*> (itP->getCurrent());
                     if(dtP!= NULL)
                     {
                         cout<<"Participante N: "<<par1<<endl;
                         cout<<"Nombre: "<<dtP->getNombre()<<endl;
                         cout<<"Celular: "<<dtP->getNum()<<endl;
                         cout<<"Fecha de ingreso: "<<dtP->getFecha()->getDia()<<"/"<<dtP->getFecha()->getMes()<<"/"<<dtP->getFecha()->getAnio()<<"   "<<dtP->getFecha()->getHora()<<":"<<dtP->getFecha()->getMin()<<":"<<dtP->getFecha()->getSeg()<<endl;
                         if(dtP->getAdmin())
                         {
                             cout<<"Es administrador"<<endl;
                         }
                         else
                             cout<<"No es administrador"<<endl;
                         par1++;
                     }
                     itP->next();
                 }
                 delete itP;
                 
                        cout<<"-----------------------------"<<endl;
                        cout<<"----------CONTACTOS----------"<<endl;
                        cout<<"-----------------------------"<<endl;
				ICollection* cont = usu1->listarContactos();
				IIterator *itCont = cont->iterator();
				
				int numerito = 1;
				while(itCont->hasNext())
				{
					DtUsuario* dt = dynamic_cast <DtUsuario*> (itCont->getCurrent());
					cout<<"Contacto "<<numerito<<": "<<endl;
					cout<<"Nombre: "<<dt->getNombre()<<endl;
					cout<<"Celular: "<<dt->getCel()<<endl;
					cout<<"------------------------------"<<endl;
					numerito++;
					itCont->next();
				}
                                
                                int respuestota;
				cout<<"1.- Ingresar un nuevo usuario al grupo"<<endl;
				cout<<"2.- Confirmar"<<endl;
                                cout<<"3.- Regresar"<<endl;
				cout<<"Seleccione una opcion: ";
				cin>>respuestota;
                               
                                if(respuestota == 1)
                                {
                                cout<<"Ingrese el celular del contacto a agregar al grupo: ";
                                        cin>>celu;
                                bool valido;
                                try{
					valido = usu1->numeroValid2(celu, cont, participantes, grup);
				}catch(const invalid_argument &e){
					cout<<"Error: "<<e.what()<<endl;
					valido = false;
					system("pause");
				}
                                if(valido)
                                {
                                    gru1->elegirContactos(celu);
                                    cout<<"Se ha agregado el integrante satisfactoriamente"<<endl;
                                    system("pause");
//                                    cout<<"Quiere seguir ingresando usuarios al grupo? s/n: ";
//                                    cin>>quiere;
                                }
                                }
                                
                                if(respuestota == 2)
                                {
                                    {
					IIterator* it = grup->iterator();
					if(!it->hasNext())
					{
						cout<<"Debe ingresar al menos 1 usuario al grupo"<<endl;
						cout<<"Desea ingresar algun usuario al grupo? s/n:";
						cin>>respuestal;
						if(respuestal == "n")
						{
							gru1->cancelar();
                                                        valido4 = false;
							break;
						}
					}
					else
					{
						quiere = "n";  
					}
				}
                                }
                                
                                 if(respuestota == 3)
                                {
                                    gru1->cancelar();
                                    valido4 = false;
                                    break;
                                }
                                
                                
                 }while(quiere != "n");
                 if(valido4)
                 {
                 if(usu1->esAdmin(part))
                 {
                 gru1->ingresarGrupo();
                 cout<<"Se han ingresado los usuario al grupo de manera satisfactoria"<<endl;
                 system("pause");
                        break;
                 }
                 gru1->cancelar();
                 cout<<"No se puede agregar participantes a un grupo del que no se es administrador"<<endl;
                 system("pause");
                 break;
                 }
                 
                 break;
        }
        case 11:
            cout<<"---Hora del sistema---"<<endl;
            cout<<"1.- Modificar fecha"<<endl;
            cout<<"2.- Mostrar fecha"<<endl;
            cout<<"3.- Regresar"<<endl;
            cin>>opcFecha;
           
                if(opcFecha == 1){
                       // DtFecha nombre;
                        cout << "Ingrese el año" << endl;
                        cin>>anio;
                        cout << "Ingrese el mes" << endl;
                        cin>>mes;
                        cout << "Ingrese el dia" << endl;
                        cin>>dia;
                        cout << "Ingrese la hora" << endl;
                        cin>>hora;
                        cout << "Ingrese minutos" << endl;
                        cin>>min;
                        bool valido = true;
                        DtFecha* nombre;
                        try{
				nombre = new DtFecha(anio,mes,dia,hora,min,seg);
				}catch(const invalid_argument &e){
					cout<<"Error: "<<e.what()<<endl;
                                        valido = false;
					system("pause");
				}
                        if(valido)
                        {
                        fec->modificarFecha(nombre);
                        cout<<"La fecha ha sido modificada"<<endl;
                        system("pause");
                        }
                        break;
                }

                if(opcFecha == 2){
                    cout<<"Fecha actual del sistema es: "<<endl;
                    cout<<fec->mostrarFecha()->getDia()<<"/"<<fec->mostrarFecha()->getMes()<<"/"<<fec->mostrarFecha()->getAnio()<<"   "<<fec->mostrarFecha()->getHora()<<":"<<fec->mostrarFecha()->getMin()<<":"<<fec->mostrarFecha()->getSeg()<<endl;
                    system("pause");
                }
                    if(opcFecha ==3)
                        break;
            break;
            
        case 12:
            {
            cout<<"-----Cargar datos de prueba----"<<endl;
            if(!datosP){
            fab->cargarDatos();
            usu1 = fab->getIusuario();
            conv = fab->getiConversacion();
            gru1 = fab->getiGrupo();
            fec = fab->getiFecha();
            datosP = true;
            cout<<"Datos cargados"<<endl;
            system("pause");
            if (usu1->getSesion()!=0)
                usu1->cerrarSesion();
            }
             break;
            }
        
        case 0: 
            break;

            }
           
    }while(opcion2!=0);
    return 0;
}

