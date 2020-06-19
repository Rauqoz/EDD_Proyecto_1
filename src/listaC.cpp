#include "listaC.h"
#include "nodoC.h"
#include <iostream>
#include <ctime>
#include <fstream>
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
void listaC::mostrar(nodoC* temporal)
{

    cout << "**Historial de Transacciones General" << endl;
    if(temporal != 0)
    {
        cout << "Transaccion " << temporal->idTransaccion << " - id_activo -  " << temporal->idActivo << " - codigo_activo - " << temporal->codigoActivo << " - " << temporal->user << " - " << temporal->departamento << " - " << temporal->empresa << " - " << temporal->fecha << " - " << temporal->tiempo << " Dias" << endl;
        if(temporal != fin)
        {
            mostrar(temporal->siguiente);
        }

    }

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
void listaC::startReporteTransacciones()
{
    ofstream archivo;
    string label = "Reporte de Transacciones";
    archivo.open("reporteTransacciones.dot");
    string inicioDot = "digraph G {";
    string finalDot = "}";
    archivo << inicioDot;
    archivo << "label = \"" + label  + "\""<< endl;
    archivo << "node[shape = rectangle];";

    reporteTransacciones(inicio,archivo);

    archivo << finalDot << endl;
    archivo.close();
    system("C:\\Graphviz2.38\\bin\\dot -Tpng reporteTransacciones.dot -o reporteTransacciones.png");

}
void listaC::reporteTransacciones(nodoC* temporal,ofstream& archivo)
{
    if(temporal != 0)
    {
        archivo <<   "\""+temporal->idTransaccion + " " + temporal->user + " " + temporal->departamento + " " + temporal->empresa + " " + temporal->fecha + "\"";
        if(temporal->siguiente != 0)
        {
            archivo <<   " -> \"" + temporal->siguiente->idTransaccion + " " + temporal->siguiente->user + " " + temporal->siguiente->departamento + " " + temporal->siguiente->empresa + " " + temporal->siguiente->fecha + "\"";
        }
        archivo << endl;
        if(temporal->siguiente != inicio)
        {
            reporteTransacciones(temporal->siguiente,archivo);
        }
    }
}
