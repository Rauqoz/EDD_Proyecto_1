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
void arbol::insertar(nodoABB *temporal,int valor_,string nombre_, string descripcion_)
{
    nodoABB *nuevo = new nodoABB(valor_);
    nuevo->nombre = nombre_;
    nuevo->descripcion = descripcion_;
    if(vacio())
    {
        raiz = nuevo;
    }
    else
    {
        if(valor_ < temporal->valor)
        {
            if(temporal->izquierda == nullptr)
            {
                temporal->izquierda = nuevo;
            }
            else
            {
                temporal = temporal->izquierda;
                insertar(temporal,valor_,nombre_,descripcion_);
            }
        }
        else
        {
            if(temporal->derecha == nullptr)
            {
                temporal->derecha=nuevo;
            }
            else
            {
                temporal=temporal->derecha;
                insertar(temporal,valor_,nombre_,descripcion_);
            }
        }

    }

}
bool arbol::buscar(nodoABB* temporal, int valor_)
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
                return false;
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
                return false;
            }
        }
        else
        {
            cout << "**Activo Eliminado \n";
            cout << "**ID = " << temporal->valor << endl;
            cout << "**Nombre = " << temporal->nombre<< endl;
            cout << "**Descripcion = " << temporal->descripcion<< endl;
            return true;

        }
    }
}
void arbol::buscarParaModificar(nodoABB* temporal, int valor_,string descripcion_)
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
                cout << "Activo no Existe" << endl;
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
                cout << "Activo no Existe" << endl;
            }
        }
        else
        {
            temporal->descripcion = descripcion_;
            cout << "**Activo Modificado \n";
            cout << "**ID = " << temporal->valor << "**Nombre = " << temporal->nombre << "**Descripcion = " << temporal->descripcion<< endl;

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
            bool esRaiz = false;
            if(raiz == temporal){
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            nodoABB *cambio =  predecesor(temporal->izquierda);
            temporal->valor = cambio->valor;
            temporal->nombre = cambio->nombre;
            temporal->descripcion = cambio->descripcion;
            if(temporal->izquierda == cambio)
            {
                temporal->izquierda = nullptr;
            }
            else
            {
                eliminar(temporal->izquierda,cambio->valor);
            }
            cambio = nullptr;
            if(esRaiz == true){
                raiz = temporal;
            }

        }
        else if(temporal->izquierda!=nullptr)
        {
            bool esRaiz = false;
            if(raiz == temporal){
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            temporal = temporal->izquierda;
            if(esRaiz == true){
                raiz = temporal;
            }
        }
        else if(temporal->derecha!=nullptr)
        {
            bool esRaiz = false;
            if(raiz == temporal){
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            temporal = temporal->derecha;
            if(esRaiz == true){
                raiz = temporal;
            }
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
        cout << "id= " << temporal->valor << " Nombre = " << temporal->nombre <<endl;
        mostrar(temporal->derecha);
    }

}
nodoABB* arbol::predecesor(nodoABB *temporal)
{
    if(temporal->derecha == nullptr)
    {
        return temporal;
    }
    else
    {
        return predecesor(temporal->derecha);
    }
}
