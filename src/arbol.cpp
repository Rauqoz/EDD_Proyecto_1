#include "arbol.h"
#include <iostream>
#include "nodoABB.h"
using namespace std;

arbol::arbol()
{
    raiz = nullptr;
}
bool arbol::vacio()
{
    return (raiz == nullptr);
}
void arbol::insertar(nodoABB *temporal,int valor_)
{
    nodoABB *nuevo = new nodoABB(valor_);
    if(vacio())
    {
        raiz = nuevo;
        cout << raiz->valor <<endl;
    }
    else
    {
        if(valor_ < temporal->valor)
        {
            if(temporal->izquierda == nullptr)
            {
                temporal->izquierda = nuevo;
                cout << nuevo->valor <<endl;
            }
            else
            {
                temporal = temporal->izquierda;
                insertar(temporal,valor_);
            }
        }
        else
        {
            if(temporal->derecha == nullptr)
            {
                temporal->derecha=nuevo;
                cout << nuevo->valor <<endl;
            }
            else
            {
                temporal=temporal->derecha;
                insertar(temporal,valor_);
            }
        }

    }

}
void arbol::buscar(nodoABB *temporal, int valor_)
{
    if(!vacio())
    {
        if(valor_ < temporal->valor)
        {
            if (temporal->izquierda != nullptr)
            {
                temporal = temporal->izquierda;
                buscar(temporal,valor_);
            }
            else
            {
                cout<< "no existe el valor " << valor_ << endl;
            }
        }
        else if(valor_ > temporal->valor)
        {
            if (temporal->derecha != nullptr)
            {
                temporal = temporal->derecha;
                buscar(temporal,valor_);
            }
            else
            {
                cout<< "no existe el valor " << valor_ << endl;
            }
        }
        else
        {
            cout<< "Valor encontrado " << temporal->valor <<endl;
        }
    }
}
nodoABB* arbol::eliminar(nodoABB *temporal,int valor_)
{

    if (valor_ < temporal->valor)
    {
        temporal->izquierda = eliminar(temporal->izquierda,valor_);
    }
    else if (valor_ > temporal->valor)
    {
        temporal->derecha = eliminar(temporal->derecha,valor_);
    }
    else
    {
        if(temporal->izquierda!=nullptr && temporal->derecha!=nullptr)
        {
            nodoABB *cambio=  predecesor(temporal->izquierda);
            temporal->valor = cambio->valor;
        }
        else if(temporal->izquierda!=nullptr)
        {
            temporal = temporal->izquierda;
        }
        else if(temporal->derecha!=nullptr)
        {
            temporal = temporal->derecha;
        }
        else
        {
            temporal=nullptr;
        }
    }
    return temporal;
}
void arbol::mostrar(nodoABB *temporal)
{
    if(temporal != nullptr)
    {
        cout <<  " -----Arbol------ "<<endl;
        mostrar(temporal->izquierda);
        cout << temporal->valor <<endl;
        mostrar(temporal->derecha);
    }

}

nodoABB* arbol::predecesor(nodoABB *temporal)
{
    if(temporal->derecha == nullptr)
    {
        nodoABB *cambio = temporal;
        temporal = nullptr;
        return cambio;
    }
    else
    {
        return predecesor(temporal->derecha);
    }
}
