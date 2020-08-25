#ifndef MENSAJE_H
#define MENSAJE_H

using namespace std;

#include "DtFecha.h"
#include <string.h>
#include "DtMensaje.h"
#include "Usuario.h"
#include "ICollectible.h"
#include "Visto.h"

#include "DtDatoM.h"
class Visto;
class Mensaje:public ICollectible
{
public:
    Mensaje();
    Mensaje(DtFecha*,bool, Usuario*);
    int getCodigo();
    DtFecha* getFecha();
    bool getVisto();
    Visto* getOtros();
    void setCodigo(int);
    void setFecha(DtFecha*);
    void setVisto(bool);
    bool esSimple();
    bool esImagen();
    bool esVideo();
    bool esContacto();
    void setVistos(Usuario*);
    void setearReceptores(Usuario*);
    DtMensaje getMens();
    void fueLeido();
    bool tenesDatos(int);
    ICollection* darDato();
    virtual Usuario* esEmisor();
    Visto* getOtros2();
     bool borrarvinculoEmisor(int, Conversacion*);
    bool borrarVinculoReceptor(int);
    void desv(int);
    Usuario* getEmisor();
    ~Mensaje();
protected:
    friend class ctrlConv;
    int codigo;
    DtFecha* fecha_env;
    bool visto;
    ICollection* vistos;
    Usuario* emisor;
    
    
};

#endif /* MENSAJE_H */

