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
void nodoM::startReporteActivosDepartamento(nodoM* temporal)
{
    ofstream archivo;
    string label = "Reporte de Activos de Departamento";
    archivo.open("reporteActivosDeparamento.dot");
    string inicioDot = "digraph G {";
    string finalDot = "}";
    archivo << inicioDot;
    archivo << "label = \"" + label  + "\""<< endl;
    archivo << "node[shape = circle];";

    reporteActivosDepartamento(temporal,archivo);

    archivo << finalDot << endl;
    archivo.close();
    system("C:\\Graphviz2.38\\bin\\dot -Tpng reporteActivosDeparamento.dot -o reporteActivosDeparamento.png");
}
void nodoM::reporteActivosDepartamento(nodoM* temporal, ofstream& archivo)
{
    if(temporal != 0)
    {

        nodoM* otro = temporal;
        while(otro->zmas != 0)
        {
            otro->arbolAVL.startReporteActivosDeUsuario();
            otro = otro->zmas;
        }

        temporal->arbolAVL.startReporteActivosDeUsuario();

        reporteActivosDepartamento(temporal->abajo,archivo);

    }

}
