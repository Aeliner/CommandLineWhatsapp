/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtFecha.h
 * Author: Aeliner
 *
 * Created on June 7, 2018, 2:31 PM
 */

#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;
class DtFecha
{
public:
    DtFecha(int, int, int, int, int, int);
    DtFecha();
    int getAnio();
    int getMes();
    int getDia();
    int getHora();
    int getMin();
    int getSeg();
    friend ostream& operator<<(ostream&, const DtFecha&);
    virtual ~DtFecha();
private:
    int anio;
    int mes;
    int dia;
    int hora;
    int min;
    int seg;
};

#endif /* DtFecha_H */

