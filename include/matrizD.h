#ifndef MATRIZD_H
#define MATRIZD_H
#include "nodoM.h"
#include <iostream>
#include <fstream>
using namespace std;


class matrizD
{
public:
    int cDepartamentos = -1, cEmpresas = -1;
    nodoM* raiz;
    nodoM* fDepartamentos;
    nodoM* fEmpresas;
    matrizD();
    nodoM* crearDepartamento(string nombre_);
    nodoM* crearEmpresa(string nombre_);
    void crearUsuario(string nombre_,string user_,string pass_,string depa_,string empre_);
    nodoM* buscarDepartamento(string depa_);
    nodoM* buscarEmpresa(string empre_);
    nodoM* buscarUsuario(string user_,string pass_,string depa_,string empre_);
    nodoM* buscarUsuarioReportes(string user_);
    void mostrarDepartamentos();
    void mostrarEmpresas();
    void mostrarUsuariosDepartamento(string depa_);
    void mostrarUsuariosEmpresa(string empre_);

};

#endif // MATRIZD_H
