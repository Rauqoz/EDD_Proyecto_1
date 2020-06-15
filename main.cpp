#include <iostream>
#include "menu.h"
#include "matrizD.h"
using namespace std;

int main()
{
//    menu start;
//    start.login();
    matrizD p;
    cout << p.raiz->nombre <<endl;
    p.crearDepartamento("guatemala");
    p.crearUsuario("Rau","0","0","guatemala","tigo");
    p.crearUsuario("Jose","0","0","mixco","movistar");
    p.crearUsuario("Jaime","0","0","mixco","tigo");
    p.crearUsuario("Laura","0","0","guatemala","tigo");
    p.crearUsuario("Marisol","0","0","guatemala","claro");
    p.mostrarDepartamentos();
    p.mostrarEmpresas();
    p.mostrarUsuariosDepartamento("guatemala");
    p.mostrarUsuariosDepartamento("mixco");
    p.mostrarUsuariosEmpresa("tigo");
    p.mostrarUsuariosEmpresa("claro");
    p.mostrarUsuariosEmpresa("movistar");

    return 0;
}
