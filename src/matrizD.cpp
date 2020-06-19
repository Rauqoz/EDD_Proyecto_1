#include "matrizD.h"
#include "nodoM.h"
#include "nodoABB.h"
#include <iostream>
#include <fstream>
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
    nodoM* depa = raiz;
    nodoM* empre = raiz;
    bool exDepa = false, exEmpre = false;
    while(depa->derecha != 0)
    {
        depa = depa->derecha;
        if(depa->nombre == depa_)
        {
            exDepa = true;
            break;
        }
    }
    while(empre->abajo!= 0)
    {
        empre = empre->abajo;
        if(empre->nombre == empre_)
        {
            exEmpre = true;
            break;
        }
    }
    nodoM* nuevo = new nodoM();
    nuevo->nombre = nombre_;
    nuevo->user = user_;
    nuevo->pass = pass_;
    if(exDepa== false && exEmpre == false)
    {
        nodoM* tempDepa = crearDepartamento(depa_);
        nodoM* tempEmpre = crearEmpresa(empre_);
        nuevo->fila = tempEmpre->fila;
        nuevo->columna = tempDepa->columna;
        tempDepa->abajo = nuevo;
        nuevo->arriba = tempDepa;
        tempEmpre->derecha = nuevo;
        nuevo->izquierda = tempEmpre;
    }
    else if (exDepa == true && exEmpre == false)
    {
        nodoM* tempEmpre = crearEmpresa(empre_);
        nuevo->fila = tempEmpre->fila;
        nuevo->columna = depa->columna;
        while(depa->abajo != 0)
        {
            depa = depa->abajo;
        }
        tempEmpre->derecha = nuevo;
        nuevo->izquierda = tempEmpre;
        depa->abajo = nuevo;
        nuevo->arriba = depa;

    }
    else if(exDepa == false && exEmpre == true)
    {
        nodoM* tempDepa = crearDepartamento(depa_);
        nuevo->fila = empre->fila;
        nuevo->columna = tempDepa->columna;
        while(empre->derecha!= 0)
        {
            empre = empre->derecha;
        }
        empre->derecha = nuevo;
        nuevo->izquierda = empre;
        tempDepa->abajo = nuevo;
        nuevo->arriba = tempDepa;

    }
    else if(exDepa == true && exEmpre == true)
    {
        int prefila = empre->fila;
        int precolumna = depa->columna;
        while(depa->abajo !=0)
        {
            depa = depa->abajo;
            if(depa->fila == prefila && depa->columna == precolumna)
            {
                cout << "encontro el nodo en comun \n";
                break;
            }
        }
        if(depa->user == user_)
        {
            cout << "Usuario ya Existe" << endl;
        }
        else
        {
            bool exNodoZ = false;
            while(depa->zmas != 0)
            {
                depa = depa->zmas;
                if(depa->user == user_ || (depa->user == user_ && depa->nombre == nombre_))
                {
                    cout << "Ya existe en Z" << endl;
                    exNodoZ = true;
                    break;
                }
            }
            if(exNodoZ == false)
            {
                nuevo->fila = prefila;
                nuevo->columna = precolumna;
                depa->zmas = nuevo;
                nuevo->zmenos = depa;

            }
        }

    }

}
nodoM* matrizD::buscarUsuario(string user_,string pass_,string depa_,string empre_)
{
    nodoM* depa = buscarDepartamento(depa_);
    nodoM* empre = buscarEmpresa(empre_);
    if(depa != 0 && empre != 0)
    {
        int prefila = empre->fila;
        int precolumna = depa->columna;
        while(depa->abajo !=0)
        {
            depa = depa->abajo;
            if(depa->fila == prefila && depa->columna == precolumna)
            {
                break;
            }
        }
        if(depa->user == user_ && depa->pass == pass_)
        {
            cout << "\n Login Usuario " << depa->user << endl;
            return depa;
        }
        else
        {
            while(depa->zmas != 0)
            {
                depa = depa->zmas;
                if(depa->user == user_&& depa->pass == pass_ )
                {
                    cout << "\n Login Usuario " << depa->user << endl;
                    return depa;
                }
            }
            return 0;
        }
    }
    return 0;

}
nodoM* matrizD::buscarDepartamento(string depa_)
{
    nodoM* depa = raiz;
    while(depa->derecha != 0)
    {
        depa = depa->derecha;
        if (depa->nombre == depa_)
        {
            return depa;
            break;
        }
    }
    return 0;

}
nodoM* matrizD::buscarEmpresa(string empre_)
{
    nodoM* empre = raiz;
    while(empre->abajo != 0)
    {
        empre = empre->abajo;
        if(empre->nombre == empre_)
        {
            return empre;
            break;
        }
    }
    return 0;
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
            nodoM* tempZ= depa;
            while(tempZ->zmas != 0)
            {
                tempZ = tempZ->zmas;
                cout << tempZ->nombre << " (" << tempZ->fila << "," << tempZ->columna << ")" << " << ";

            }
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
            nodoM* tempZ= empre;
            while(tempZ->zmas != 0)
            {
                tempZ = tempZ->zmas;
                cout << tempZ->nombre << " (" << tempZ->fila << "," << tempZ->columna << ")" << " << ";

            }
        }
        cout << endl;
    }

}
nodoM* matrizD::buscarUsuarioReportes(string user_)
{
    nodoM* depa = raiz->derecha;
    if(depa != 0)
    {
        while(depa->abajo !=0)
        {
            depa = depa->abajo;
            while(depa->zmas != 0)
            {
                depa = depa->zmas;
                if(depa->user == user_)
                {
                    cout << "\n Usuario Reportes " << depa->user << endl;
                    return depa;
                }
            }
            if(depa->user == user_)
            {
                cout << "\n Usuario Reportes " << depa->user << endl;
                return depa;
            }
        }
    }
    return 0;

}
