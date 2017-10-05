#include <iostream>
#include "ArbolB.h"

using namespace std;

int main()
{
    ArbolB *ab = new ArbolB();

    ab->Insertar(new Llave(1));
    ab->Insertar(new Llave(2));
    ab->Insertar(new Llave(3));
    ab->Insertar(new Llave(4));
    ab->Insertar(new Llave(5));
    ab->Insertar(new Llave(6));
    ab->Insertar(new Llave(14,69));

    Llave llave = ab->Buscar(14,ab->Raiz);
    cout<<llave.NumeroBloque<<endl;




}