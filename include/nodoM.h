#ifndef NODOM_H
#define NODOM_H
#include <iostream>
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
    string user,pass,arbolAVL;
    nodoM();

};
#endif // NODOM_H
