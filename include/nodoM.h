#ifndef NODOM_H
#define NODOM_H
#include <iostream>
#include "arbol.h"
using namespace std;

class nodoM
{
public:
    int fila = -1;
    int columna = -1;
    nodoM* izquierda ;
    nodoM* derecha ;
    nodoM* arriba ;
    nodoM* abajo ;
    nodoM* zmas ;
    nodoM* zmenos ;
    nodoM* fnodoz;
    string nombre ;
    string user,pass;
    int idContador;
    arbol arbolAVL;
    nodoM();
    void aumentarContador();

};
#endif // NODOM_H
