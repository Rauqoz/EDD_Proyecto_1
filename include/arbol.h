#ifndef arbol_H
#define arbol_H
#include "nodoABB.h"
using namespace std;

class arbol
{


public:
    arbol();
    nodoABB *raiz;
    bool vacio();
    void insertar(nodoABB *temporal,int valor_);
    void mostrar(nodoABB *temporal);
    nodoABB* eliminar(nodoABB *base, int valor_);
    void buscar(nodoABB *temporal, int valor_);
    nodoABB* predecesor(nodoABB *temporal);

protected:

private:

};

#endif // arbol_H
