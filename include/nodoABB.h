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
    int altura;
    string codigo;
    string nombre, descripcion;
    bool enRenta;

protected:

private:
};

#endif // nodoABB_H
