#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "matrizD.h"
#include "nodoM.h"
using namespace std;


class menu
{
public:
    menu();
    void login();
    void menuUser();
    void crearActivos();
    void eliminarActivos();
    void modificarActivos();
    void menuRentaActivos();
    void menuActivosRentados();
    void misActivosRentados();
    void menuAdministrador();
    void crearUsuarios();

protected:

private:
    matrizD matriz;
    nodoM* usuarioActual;
    string nombre,user, pass,departamento,empresa;
    char opcion;
    string nombreActivo,descripcionActivo;
    int idActivo, diasRenta;
    bool seguir = true;

};


#endif // MENU_H
