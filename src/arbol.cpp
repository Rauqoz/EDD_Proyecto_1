#include "arbol.h"
#include <iostream>
#include <ctime>
#include "nodoABB.h"
#include <fstream>
using namespace std;

arbol::arbol()
{
    raiz = nullptr;
    depaReporte = 0;
}
bool arbol::vacio()
{
    return (raiz == nullptr);
}
void arbol::equilibrarArbol(nodoABB*& temporal)
{

    if(temporal != 0)
    {
        equilibrarArbol(temporal->izquierda);
        equilibrarArbol(temporal->derecha);
        int Izq, Dch;
        if(temporal->izquierda != 0)
        {
            Izq = temporal->izquierda->altura;
        }
        else
        {
            Izq = 0;
        }
        if(temporal->derecha != 0)
        {
            Dch = temporal->derecha->altura;
        }
        else
        {
            Dch = 0;
        }

        if(Izq - Dch < -1)
        {

            if(temporal->derecha->izquierda != 0)
            {
                Izq = temporal->derecha->izquierda->altura;
            }
            else
            {
                Izq = 0;
            }
            if(temporal->derecha->derecha != 0)
            {
                Dch = temporal->derecha->derecha->altura;
            }
            else
            {
                Dch = 0;
            }

            if(Izq <= Dch)
            {
                cout << "x";
                rotarIzquierda(temporal);
            }
            else
            {
                cout << "y";
                rotarDerecha(temporal->derecha);
                rotarIzquierda(temporal);
            }
        }
        else if(Izq - Dch > 1)
        {
            if(temporal->izquierda->izquierda != 0)
            {
                Izq = temporal->izquierda->izquierda->altura;
            }
            else
            {
                Izq = 0;
            }
            if(temporal->izquierda->derecha != 0)
            {
                Dch = temporal->izquierda->derecha->altura;
            }
            else
            {
                Dch = 0;
            }

            if(Izq >= Dch)
            {
                cout << "a";
                rotarDerecha(temporal);
            }
            else
            {
                cout << "b";
                rotarIzquierda(temporal->izquierda);
                rotarDerecha(temporal);
            }
        }
        calcularAltura(raiz);

    }


}
void arbol::rotarIzquierda(nodoABB*& temporal)
{
    bool esRaiz = false;
    if(raiz == temporal)
    {
        esRaiz = true;
        cout << "Es Raiz \n";
    }
    nodoABB* cambio = temporal->derecha;
    temporal->derecha = cambio->izquierda;
    cambio->izquierda = temporal;
    temporal = cambio;
    if(esRaiz)
    {
        raiz = cambio;
    }

}
void arbol::rotarDerecha(nodoABB*& temporal)
{
    bool esRaiz = false;
    if(raiz == temporal)
    {
        esRaiz = true;
        cout << "Es Raiz \n";
    }
    nodoABB* cambio = temporal->izquierda;
    temporal->izquierda = cambio->derecha;
    cambio->derecha = temporal;
    temporal = cambio;
    if(esRaiz == true)
    {
        raiz = cambio;
    }

}
int arbol::calcularAltura(nodoABB* temporal)
{
    int alturaI = 1, alturaD = 1 ;

    if(temporal->izquierda != 0)
    {
        alturaI += calcularAltura(temporal->izquierda);
    }
    if(temporal->derecha != 0)
    {
        alturaD += calcularAltura(temporal->derecha);
    }
    if(alturaI >= alturaD)
    {
        temporal->altura = alturaI;
    }
    else if(alturaD > alturaI)
    {
        temporal->altura = alturaD;
    }
    return temporal->altura;
}
void arbol::insertar(nodoABB *temporal,int valor_,string nombre_, string descripcion_)
{
    srand(time(0));
    string idCodigo;
    static const char letras[] = {'a','b','c','d','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < 15; i++)
    {
        int rango = 0 + (rand() % 33);
        idCodigo += letras[rango];
    }
    nodoABB *nuevo = new nodoABB(valor_);
    nuevo->nombre = nombre_;
    nuevo->descripcion = descripcion_;
    nuevo->codigo = idCodigo;
    nuevo->altura = 0;

    if(vacio())
    {
        raiz = nuevo;
        calcularAltura(raiz);
    }
    else
    {
        if(valor_ < temporal->valor)
        {
            if(temporal->izquierda == nullptr)
            {
                temporal->izquierda = nuevo;
                calcularAltura(raiz);
                equilibrarArbol(raiz);
            }
            else
            {
                temporal = temporal->izquierda;
                insertar(temporal,valor_,nombre_,descripcion_);
            }
        }
        else
        {
            if(temporal->derecha == nullptr)
            {
                temporal->derecha=nuevo;
                calcularAltura(raiz);
                equilibrarArbol(raiz);
            }
            else
            {
                temporal=temporal->derecha;
                insertar(temporal,valor_,nombre_,descripcion_);
            }
        }

    }

}
bool arbol::buscar(nodoABB* temporal, int valor_)
{
    if(!vacio())
    {
        if(valor_ < temporal->valor)
        {
            if (temporal->izquierda != nullptr)
            {
                temporal = temporal->izquierda;
                buscar(temporal,valor_);
            }
            else
            {
                return false;
            }
        }
        else if(valor_ > temporal->valor)
        {
            if (temporal->derecha != nullptr)
            {
                temporal = temporal->derecha;
                buscar(temporal,valor_);
            }
            else
            {
                return false;
            }
        }
        else
        {
            cout << "**Activo Eliminado \n";
            cout << "**ID = " << temporal->valor << endl;
            cout << "**Nombre = " << temporal->nombre<< endl;
            cout << "**Descripcion = " << temporal->descripcion<< endl;
            return true;

        }
    }
}
nodoABB* arbol::buscarParaTransaccion(nodoABB* temporal, int valor_)
{
    if(!vacio())
    {
        if(valor_ < temporal->valor)
        {
            if (temporal->izquierda != nullptr)
            {
                temporal = temporal->izquierda;
                buscarParaTransaccion(temporal,valor_);
            }
            else
            {
                return 0;
            }
        }
        else if(valor_ > temporal->valor)
        {
            if (temporal->derecha != nullptr)
            {
                temporal = temporal->derecha;
                buscarParaTransaccion(temporal,valor_);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return temporal;

        }
    }
}
bool arbol::rentar_devolver(nodoABB* temporal, int valor_)
{
    if(!vacio())
    {
        if(valor_ < temporal->valor)
        {
            if (temporal->izquierda != nullptr)
            {
                temporal = temporal->izquierda;
                rentar_devolver(temporal,valor_);
            }
            else
            {
                return false;
            }
        }
        else if(valor_ > temporal->valor)
        {
            if (temporal->derecha != nullptr)
            {
                temporal = temporal->derecha;
                rentar_devolver(temporal,valor_);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(temporal->enRenta == false)
            {
                cout << "**Activo a Rentar \n";
                cout << "**ID = " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre << " Descripcion = " << temporal->descripcion << endl;
                temporal->enRenta = true;
            }
            else
            {
                cout << "**Activo a Devolver \n";
                cout << "**ID = " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre << " Descripcion = " << temporal->descripcion << endl;
                temporal->enRenta = false;
            }
            return true;

        }
    }
}
void arbol::buscarParaModificar(nodoABB* temporal, int valor_,string descripcion_)
{
    if(!vacio())
    {
        if(valor_ < temporal->valor)
        {
            if (temporal->izquierda != nullptr)
            {
                temporal = temporal->izquierda;
                buscarParaModificar(temporal,valor_,descripcion_);
            }
            else
            {
                cout << "Activo no Existe" << endl;
            }
        }
        else if(valor_ > temporal->valor)
        {
            if (temporal->derecha != nullptr)
            {
                temporal = temporal->derecha;
                buscarParaModificar(temporal,valor_,descripcion_);
            }
            else
            {
                cout << "Activo no Existe" << endl;
            }
        }
        else
        {
            temporal->descripcion = descripcion_;
            cout << "**Activo Modificado \n";
            cout << "**ID = " << temporal->valor << " Codigo = " << temporal->codigo << "**Nombre = " << temporal->nombre << "**Descripcion = " << temporal->descripcion<< endl;

        }
    }
}
nodoABB* arbol::eliminar(nodoABB *&temporal,int valor_)
{

    if (valor_ < temporal->valor)
    {
        temporal->izquierda = eliminar(temporal->izquierda,valor_);
    }
    else if (valor_ > temporal->valor)
    {
        temporal->derecha = eliminar(temporal->derecha,valor_);
    }
    else
    {
        if(temporal->izquierda!=nullptr && temporal->derecha!=nullptr)
        {
            bool esRaiz = false;
            if(raiz == temporal)
            {
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            nodoABB *cambio =  predecesor(temporal->izquierda);
            temporal->valor = cambio->valor;
            temporal->nombre = cambio->nombre;
            temporal->descripcion = cambio->descripcion;
            temporal->codigo =  cambio->codigo;
            temporal->enRenta = cambio->enRenta;

            eliminar(temporal->izquierda,cambio->valor);

            cambio = nullptr;
            if(esRaiz == true)
            {
                raiz = temporal;
            }

        }
        else if(temporal->izquierda!=nullptr)
        {
            bool esRaiz = false;
            if(raiz == temporal)
            {
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            temporal = temporal->izquierda;
            calcularAltura(raiz);
            equilibrarArbol(raiz);
            if(esRaiz == true)
            {
                raiz = temporal;
            }
        }
        else if(temporal->derecha!=nullptr)
        {
            bool esRaiz = false;
            if(raiz == temporal)
            {
                esRaiz = true;
                cout << "Es Raiz \n";
            }
            temporal = temporal->derecha;
            calcularAltura(raiz);
            equilibrarArbol(raiz);
            if(esRaiz == true)
            {
                raiz = temporal;
            }
        }
        else
        {
            temporal=nullptr;
            calcularAltura(raiz);
            equilibrarArbol(raiz);
        }
    }
    return temporal;
}
void arbol::mostrar(nodoABB *temporal)
{
    if(temporal != nullptr)
    {
        cout <<  " -----Arbol------ "<<endl;
        mostrar(temporal->izquierda);
        cout << "id= " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre << " Descripcion = " << temporal->descripcion <<endl;
        mostrar(temporal->derecha);
    }

}
void arbol::mostrarPreOrden(nodoABB *temporal)
{
    if(temporal != nullptr)
    {
        cout <<  " -----Arbol------ "<<endl;
        cout << "id= " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre  << " Altura = " << temporal->altura <<endl;
        mostrarPreOrden(temporal->izquierda);
        mostrarPreOrden(temporal->derecha);
    }

}
void arbol::mostrarCatalogo(nodoABB *temporal)
{
    if(temporal != nullptr)
    {
        cout <<  " -----Arbol------ "<<endl;
        mostrarCatalogo(temporal->izquierda);
        if(temporal->enRenta == false)
        {
            cout << "id= " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre << " Descripcion = " << temporal->descripcion << " Tiempo de Renta = 100 dias" <<endl;
        }
        mostrarCatalogo(temporal->derecha);
    }

}
void arbol::mostrarActivosRentados(nodoABB *temporal)
{
    if(temporal != nullptr)
    {
        cout <<  " -----Arbol------ "<<endl;
        mostrarActivosRentados(temporal->izquierda);
        if(temporal->enRenta == true)
        {
            cout << "id= " << temporal->valor << " Codigo = " << temporal->codigo << " Nombre = " << temporal->nombre << " Descripcion = " << temporal->descripcion <<endl;
        }
        mostrarActivosRentados(temporal->derecha);
    }

}
nodoABB* arbol::predecesor(nodoABB *temporal)
{
    if(temporal->derecha == nullptr)
    {
        return temporal;
    }
    else
    {
        return predecesor(temporal->derecha);
    }
}
void arbol::startReporteActivosDeUsuario()
{
    ofstream archivo;
    string label = "Reporte de Activos de Usuario";
    archivo.open("reporteActivosUsuario.dot");
    string inicioDot = "digraph G {";
    string finalDot = "}";
    archivo << inicioDot;
    archivo << "label = \"" + label  + "\""<< endl;
    archivo << "node[shape = circle];";

    reporteActivosDeUsuario(raiz,archivo);

    archivo << finalDot << endl;
    archivo.close();
    system("C:\\Graphviz2.38\\bin\\dot -Tpng reporteActivosUsuario.dot -o reporteActivosUsuario.png");
}
void arbol::startReporteActivosRentadosDeUsuario()
{
    ofstream archivo;
    string label = "Reporte de Activos Rentados de Usuario";
    archivo.open("reporteActivosRentadosUsuario.dot");
    string inicioDot = "digraph G {";
    string finalDot = "}";
    archivo << inicioDot;
    archivo << "label = \"" + label  + "\""<< endl;
    archivo << "node[shape = circle];";

    reporteActivosRentadosDeUsuario(raiz,archivo);

    archivo << finalDot << endl;
    archivo.close();
    system("C:\\Graphviz2.38\\bin\\dot -Tpng reporteActivosRentadosUsuario.dot -o reporteActivosRentadosUsuario.png");
}
void arbol::reporteActivosRentadosDeUsuario(nodoABB*& temporal, ofstream& archivo)
{
    if(temporal != 0)
    {
        if(temporal->izquierda != 0 && temporal->enRenta == true && temporal->izquierda->enRenta == true)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo <<   " -> \"" +temporal->izquierda->codigo + " " + temporal->izquierda->nombre+ " " + temporal->izquierda->descripcion + "\"";
            archivo << endl;
        }
        if(temporal->derecha != 0 && temporal->enRenta == true && temporal->derecha->enRenta == true)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo <<   " -> \"" +temporal->derecha->codigo + " " + temporal->derecha->nombre+ " " + temporal->derecha->descripcion + "\"";
            archivo << endl;
        }
        if(temporal->izquierda != 0 && temporal->derecha != 0 && temporal->enRenta == true)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo << endl;
        }

        reporteActivosRentadosDeUsuario(temporal->izquierda,archivo);
        reporteActivosRentadosDeUsuario(temporal->derecha,archivo);

    }
}
void arbol::reporteActivosDeUsuario(nodoABB*& temporal, ofstream& archivo)
{
    if(temporal != 0)
    {
        if(temporal->izquierda != 0)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo <<   " -> \"" +temporal->izquierda->codigo + " " + temporal->izquierda->nombre+ " " + temporal->izquierda->descripcion + "\"";
            archivo << endl;
        }
        if(temporal->derecha != 0)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo <<   " -> \"" +temporal->derecha->codigo + " " + temporal->derecha->nombre+ " " + temporal->derecha->descripcion + "\"";
            archivo << endl;
        }
        if(temporal->izquierda != 0 && temporal->derecha != 0)
        {
            archivo <<   "\""+temporal->codigo + " " + temporal->nombre+ " " + temporal->descripcion + "\"";
            archivo << endl;
        }

        reporteActivosDeUsuario(temporal->izquierda,archivo);
        reporteActivosDeUsuario(temporal->derecha,archivo);

    }
}
