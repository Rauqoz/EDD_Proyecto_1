#include "menu.h"
#include "matrizD.h"
#include "nodoM.h"
#include <iostream>
using namespace std;

menu::menu()
{
    matriz.crearUsuario("Rau", "rau","0","guatemala","claro");
    usuarioActual = 0;
}
void menu::login()
{
    do
    {
        cout << "-------------------------------------------------------"<< endl;
        cout << "%%%%%%%%%% Renta de Activos %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% Iniciar Sesion %%%%%%%%%%"<< endl;
        cout << "Ingresa Usuario"<< endl;
        cin >> user ;
        cout << "Ingresa Password"<< endl;
        cin >> pass;
        cout << "Ingresa Departamento"<< endl;
        cin >> departamento;
        cout << "Ingresa Empresa"<< endl;
        cin >> empresa;
        if(user == "admin" && pass=="admin")
        {
            menuAdministrador();
        }
        else
        {
            usuarioActual = matriz.buscarUsuario(user,pass,departamento,empresa);
            if(usuarioActual != 0)
            {
                menuUser();
            }
            else
            {
                cout << "**No Existe el Usuario" << endl;;
            }
        }

    }
    while(seguir == true);

}
void menu::menuUser()
{

    do
    {
        cout << "-------------------------------------------------------"<< endl;
        cout << "%%%%%%%%%% Bienvenido "+ usuarioActual->nombre +" %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 1. Agregar Activo %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 2. Eliminar Activo %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 3. Modificar Activo %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 4. Rentar Activo %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 5. Activos Rentados %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 6. Mis Activos Rentados %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 7. Cerrar Sesion %%%%%%%%%%"<< endl;
        cout << "Ingresa Opcion"<< endl;
        cin >> opcion;
        switch(opcion)
        {
        case '1':
            crearActivos();
            break;
        case '2':
            eliminarActivos();
            break;
        case '3':
            modificarActivos();
            break;
        case '4':
            menuRentaActivos();
            break;
        case '5':
            menuActivosRentados();
            break;
        case '6':
            misActivosRentados();
            break;
        case '7':
            cout << "**Cerrando Sesion" << endl;;
            seguir = false;
            break;
        case '8':
            usuarioActual->arbolAVL.mostrar(usuarioActual->arbolAVL.raiz);
            break;

        default:
            break;


        }
    }
    while(seguir == true);
    seguir = true;

}
void menu::crearActivos()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Agregar Activo %%%%%%%%%%"<< endl;
    cout << "Ingrese Nombre"<< endl;
    cin>> nombreActivo;
    cout << "Ingrese Descripcion"<< endl;
    cin >> descripcionActivo;
    usuarioActual->aumentarContador();
    usuarioActual->arbolAVL.insertar(usuarioActual->arbolAVL.raiz,usuarioActual->idContador,nombreActivo,descripcionActivo);

}
void menu::eliminarActivos()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Eliminar Activo %%%%%%%%%%"<< endl;
    usuarioActual->arbolAVL.mostrar(usuarioActual->arbolAVL.raiz);
    cout << "Ingresa ID Activo"<< endl;
    cin >> idActivo;
    if(usuarioActual->arbolAVL.buscar(usuarioActual->arbolAVL.raiz,idActivo))
    {
        usuarioActual->arbolAVL.eliminar(usuarioActual->arbolAVL.raiz,idActivo);
    }

}
void menu::modificarActivos()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Modificar Activo %%%%%%%%%%"<< endl;
    usuarioActual->arbolAVL.mostrar(usuarioActual->arbolAVL.raiz);
    cout << "Ingresa ID Activo"<< endl;
    cin >> idActivo;
    cout << "Ingresa Descripcion Nueva"<< endl;
    cin >> descripcionActivo;
    usuarioActual->arbolAVL.buscarParaModificar(usuarioActual->arbolAVL.raiz,idActivo,descripcionActivo);

}
void menu::menuRentaActivos()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Catalogo Activos %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% 1. Rentar Activo %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% 2. Regresar a Menu %%%%%%%%%%"<< endl;
    cout << "Ingresa Opcion"<< endl;
    cin >> opcion;

}
void menu::menuActivosRentados()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Activos Rentados %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% 1. Registrar Devolucion %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% 2. Regresar a Menu %%%%%%%%%%"<< endl;
    cout << "Ingresa Opcion"<< endl;
    cin >> opcion;

}
void menu::misActivosRentados()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Mis Activos Rentados %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% 1. Regresar a Menu %%%%%%%%%%"<< endl;
    cout << "Ingresa Opcion"<< endl;
    cin >> opcion;

}
void menu::menuAdministrador()
{
    do
    {
        cout << "-------------------------------------------------------"<< endl;
        cout << "%%%%%%%%%% Menu Administrador %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 1. Registrar Usuario %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 2. Reporte Matriz Dispersa %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 3. Reporte Activos Disponibles de un Departamento %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 4. Reporte Activos Disponibles de una Empresa %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 5. Reporte Transacciones %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 6. Reporte Activos de un Usuario %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 7. Activos Rentados por un Usuario %%%%%%%%%%"<< endl;
        cout << "%%%%%%%%%% 8. Ordenar Transacciones %%%%%%%%%%"<< endl;
        cout << "Ingresa Opcion"<< endl;
        cin >> opcion;
        switch(opcion)
        {
        case '0':
            seguir = false;
            break;
        case '1':
            seguir = false;
            crearUsuarios();
            break;

        default:
            break;


        }
    }
    while(seguir == true);
    seguir = true;

}
void menu::crearUsuarios()
{
    cout << "-------------------------------------------------------"<< endl;
    cout << "%%%%%%%%%% Administrador %%%%%%%%%%"<< endl;
    cout << "%%%%%%%%%% Crear Usuario %%%%%%%%%%"<< endl;
    cout << "Ingresa Nombre"<< endl;
    cin >> nombre ;
    cout << "Ingresa Usuario"<< endl;
    cin >> user ;
    cout << "Ingresa Password"<< endl;
    cin >> pass;
    cout << "Ingresa Departamento"<< endl;
    cin >> departamento;
    cout << "Ingresa Empresa"<< endl;
    cin >> empresa;
    matriz.crearUsuario(nombre,user,pass,departamento,empresa);
    cout << "**Usuario Creado" << endl;

}
