#ifndef NODOC_H
#define NODOC_H
#include <iostream>
using namespace std;

class nodoC
{
    public:
        nodoC();
        nodoC* siguiente;
        nodoC* anterior;
        string idTransaccion;
        int idActivo;
        string codigoActivo;
        string user;
        string departamento,empresa;
        string fecha;
        string tiempo;
        bool activo;
};

#endif // NODOC_H
