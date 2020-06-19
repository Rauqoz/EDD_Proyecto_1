#ifndef arbol_H
#define arbol_H
#include "nodoABB.h"
#include <fstream>
using namespace std;

class arbol
{


public:
    arbol();
    nodoABB *raiz;
    nodoABB* depaReporte;
    bool vacio();
    void insertar(nodoABB *temporal,int valor_,string nombre_, string descripcion_);
    void mostrar(nodoABB *temporal);
    void mostrarPreOrden(nodoABB *temporal);
    void mostrarCatalogo(nodoABB *temporal);
    void mostrarActivosRentados(nodoABB *temporal);
    nodoABB* eliminar(nodoABB *& base, int valor_);
    bool buscar(nodoABB* temporal, int valor_);
    nodoABB* buscarParaTransaccion(nodoABB* temporal, int valor_);
    bool rentar_devolver(nodoABB* temporal, int valor_);
    void buscarParaModificar(nodoABB* temporal, int valor_,string descripcion_);
    nodoABB* predecesor(nodoABB *temporal);
    int calcularAltura(nodoABB* temporal);
    void equilibrarArbol(nodoABB*& temporal);
    void rotarIzquierda(nodoABB*& temporal);
    void rotarDerecha(nodoABB*& temporal);
    void startReporteActivosDeUsuario();
    void startReporteActivosRentadosDeUsuario();
    void reporteActivosDeUsuario(nodoABB*& temporal, ofstream& archivo);
    void reporteActivosRentadosDeUsuario(nodoABB*& temporal, ofstream& archivo);


protected:

private:

};

#endif // arbol_H
