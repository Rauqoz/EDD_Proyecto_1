#include "matrizD.h"
#include "nodoM.h"
#include <iostream>
using namespace std;

matrizD::matrizD()
{
    raiz = new nodoM();
    raiz->nombre = "inicio";
    fDepartamentos = raiz;
    fEmpresas = raiz;
}
nodoM* matrizD::crearDepartamento(string nombre_)
{
    nodoM* nuevo = new nodoM();
    nuevo->nombre =  nombre_;
    cDepartamentos += 1;
    nuevo->fila = -1;
    nuevo->columna = cDepartamentos;
    fDepartamentos->derecha = nuevo;
    nuevo->izquierda = fDepartamentos;
    fDepartamentos = nuevo;
    return nuevo;

}
nodoM* matrizD::crearEmpresa(string nombre_)
{
    nodoM* nuevo = new nodoM();
    nuevo->nombre =  nombre_;
    cEmpresas += 1;
    nuevo->columna = -1;
    nuevo->fila = cEmpresas;
    fEmpresas->abajo = nuevo;
    nuevo->arriba = fEmpresas;
    fEmpresas = nuevo;
    return nuevo;

}
void matrizD::crearUsuario(string nombre_,string user_,string pass_,string depa_,string empre_)
{
    nodoM* depa = buscarDepartamento(depa_);
    nodoM* empre = buscarEmpresa(empre_);

    nodoM* nuevo = new nodoM();
    nuevo->nombre = nombre_;
    nuevo->user = user_;
    nuevo->pass = pass_;
    depa->abajo = nuevo;
    empre->derecha = nuevo;

}
nodoM* matrizD::buscarDepartamento(string depa_)
{
    nodoM* depa = raiz;
    bool existeDepa = false;
    while(depa->derecha != 0)
    {
        depa = depa->derecha;
        if (depa->nombre == depa_)
        {
            existeDepa = true;
            break;
        }
    }
    if(existeDepa == false)
    {
        depa = crearDepartamento(depa_);
        return depa;
    }
    else
    {
        while(depa->abajo != 0)
        {
            depa = depa->abajo;
        }
        return depa;
    }


}
nodoM* matrizD::buscarEmpresa(string empre_)
{
    nodoM* empre = raiz;
    bool existeEmpre = false;
    while(empre->abajo != 0)
    {
        empre = empre->abajo;
        if(empre->nombre == empre_)
        {
            existeEmpre = true;
            break;
        }
    }
    if(existeEmpre == false)
    {
        empre = crearEmpresa(empre_);
        return empre;
    }
    else
    {
        while(empre->derecha!= 0)
        {
            empre = empre->derecha;
        }
        return empre;
    }
}
void matrizD::mostrarDepartamentos()
{
    cout << "departamentos ---------- \n";
    nodoM* tempo = raiz;
    while(tempo->derecha != 0)
    {
        tempo = tempo->derecha;
        cout << tempo->nombre << " - ("<< tempo->fila << ","<< tempo->columna << ")" << endl;
    }
}
void matrizD::mostrarEmpresas()
{
    cout << "empresas ---------- \n";
    nodoM* tempo = raiz;
    while(tempo->abajo != 0)
    {
        tempo = tempo->abajo;
        cout << tempo->nombre << " - ("<< tempo->fila << ","<< tempo->columna << ")" << endl;
    }
}
void matrizD::mostrarUsuariosDepartamento(string depa_)
{
    nodoM* depa = raiz;
    bool existeDepa = false;
    while(depa->derecha != 0)
    {
        depa = depa->derecha;
        if (depa->nombre == depa_)
        {
            existeDepa = true;
            break;
        }
    }
    if(existeDepa == false)
    {
        cout << "Departamento no existe";
    }
    else
    {
        cout << "Departamento de " + depa_ + " -------------------- " << endl;
        while(depa->abajo != 0)
        {
            depa = depa->abajo;
            cout << depa->nombre << " (" << depa->fila << "," << depa->columna << ")" << " - ";
        }
        cout << endl;
    }

}
void matrizD::mostrarUsuariosEmpresa(string empre_)
{
    nodoM* empre = raiz;
    bool existeEmpre = false;
    while(empre->abajo != 0)
    {
        empre = empre->abajo;
        if(empre->nombre == empre_)
        {
            existeEmpre = true;
            break;
        }
    }
    if(existeEmpre == false)
    {
        cout << "Empresa no existe";
    }
    else
    {
        cout << "Empresa de " + empre_ + " -------------------- " << endl;
        while(empre->derecha!= 0)
        {
            empre = empre->derecha;
            cout << empre->nombre << " (" << empre->fila << "," << empre->columna << ")" << " - ";
        }
        cout << endl;
    }

}
