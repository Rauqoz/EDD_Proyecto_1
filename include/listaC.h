#ifndef LISTAC_H
#define LISTAC_H
#include "nodoC.h"
#include <iostream>
#include <fstream>
using namespace std;


class listaC
{
    public:
        listaC();
        nodoC* inicio;
        nodoC* fin;
        nodoC* insertar(int idActivo_,string codigoActivo_,string user_,string departamento_,string empresa_,string tiempo_);
        void devolver(int idActivo_,string user_);
        void mostrar(nodoC* temporal);
        void startReporteTransacciones();
        void reporteTransacciones(nodoC* temporal,ofstream& archivo);

};

#endif // LISTAC_H
