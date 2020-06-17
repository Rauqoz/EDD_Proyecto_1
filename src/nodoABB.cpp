#include "nodoABB.h"
using namespace std;
nodoABB::nodoABB(int valor_)
{
    izquierda = nullptr;
    derecha = nullptr;
    valor = valor_;
    enRenta = false;
}
