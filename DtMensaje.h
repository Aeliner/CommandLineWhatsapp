#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "DtFecha.h"
#include "ICollectible.h"
class Usuario;

class DtMensaje:public ICollectible
{
public:
    DtMensaje(int, DtFecha*, bool, Usuario*);
    DtMensaje(DtFecha*, bool);
    int getCodigo();
    DtFecha* getFecha();
    Usuario* getEmisor();
    bool getVisto();
    virtual ~DtMensaje();
private:
    int codigo;
    DtFecha* fecha_env;
    bool visto;
    Usuario* emisor;
};

#endif /* DTMENSAJE_H */

