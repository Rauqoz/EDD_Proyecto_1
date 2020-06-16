#include "nodoM.h"
#include <iostream>
using namespace std;

nodoM::nodoM()
{
    izquierda = 0;
    derecha = 0;
    arriba = 0;
    abajo = 0;
    zmas = 0;
    zmenos = 0;
    fnodoz = 0;
    idContador = 0;
}
void nodoM::aumentarContador()
{
    idContador++;
}
