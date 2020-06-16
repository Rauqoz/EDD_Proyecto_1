#ifndef nodoABB_H
#define nodoABB_H
#include <iostream>
using namespace std;


class nodoABB
{
public:
    nodoABB(int valor_);
    nodoABB *izquierda;
    nodoABB *derecha;
    int valor;
    string nombre, descripcion;

protected:

private:
};

#endif // nodoABB_H
