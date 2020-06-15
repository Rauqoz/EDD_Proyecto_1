#ifndef MENU_H
#define MENU_H
#include <iostream>
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
    string user, pass,departamento,empresa;
    char opcion;
    string nombreActivo,descripcionActivo,idActivo;
    bool seguir = true;

};


#endif // MENU_H
