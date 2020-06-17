#include "listaC.h"
#include "nodoC.h"
#include <iostream>
#include <ctime>
using namespace std;
listaC::listaC()
{
    inicio = 0;
    fin = 0;
}
nodoC* listaC::insertar(int idActivo_,string codigoActivo_,string user_,string departamento_,string empresa_,string tiempo_)
{
    srand(time(0));
    string idCodigo;
    static const char letras[] = {'a','b','c','d','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < 15; i++)
    {
        int rango = 0 + (rand() % 33);
        idCodigo += letras[rango];
    }
    time_t tAct = time(0);
    string hora = ctime(&tAct);

    nodoC* nuevo = new nodoC();
    nuevo->idTransaccion = idCodigo;
    nuevo->idActivo = idActivo_;
    nuevo->codigoActivo = codigoActivo_;
    nuevo->user = user_;
    nuevo->departamento = departamento_;
    nuevo->empresa = empresa_;
    nuevo->fecha = hora;
    nuevo->tiempo = tiempo_;
    nuevo->activo = true;
    if(inicio == 0 && fin == 0)
    {
        inicio = nuevo;
        nuevo->siguiente = inicio;
        nuevo->anterior = fin;
        fin = nuevo;

    }
    else
    {
        fin->siguiente = nuevo;
        nuevo->anterior = fin;
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        fin = nuevo;
    }
    return nuevo;
}
void listaC::mostrar()
{
    nodoC* temporal = inicio;
    cout << "**Historial de Transacciones General" << endl;
    do
    {
        cout << "Transaccion " << temporal->idTransaccion << " - id_activo -  " << temporal->idActivo << " - codigo_activo - " << temporal->codigoActivo << " - " << temporal->user << " - " << temporal->departamento << " - " << temporal->empresa << " - " << temporal->fecha << " - " << temporal->tiempo << " Dias" << endl;
        temporal = temporal->siguiente;
        if(temporal == inicio){
            break;
        }
    }
    while(temporal->siguiente != 0);

}
void listaC::devolver(int idActivo_,string user_)
{
    nodoC* temporal = inicio;
    do
    {
        if(temporal->idActivo == idActivo_ && temporal->user == user_)
        {
            temporal->activo = false;
            break;
        }
        temporal = temporal->siguiente;
    }
    while(temporal->siguiente != 0 && temporal->siguiente != inicio);
}
