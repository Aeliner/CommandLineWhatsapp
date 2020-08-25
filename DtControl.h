/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtControl.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 3:51 PM
 */

#ifndef DTCONTROL_H
#define DTCONTROL_H

class DtControl {
public:
    DtControl(bool, bool);
    bool getExiste();
    bool getSesion();
    void setExiste(bool);
    void setSesion(bool);
    DtControl();
    virtual ~DtControl();
private:
    bool existe;
    bool sesion;
};

#endif /* DTCONTROL_H */

