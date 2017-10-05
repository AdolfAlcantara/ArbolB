//
// Created by Chronos-Laptop on 19/9/2017.
//

#ifndef ARBOLB_ARBOLB_H
#define ARBOLB_ARBOLB_H
#include "BloqueArbolB.h"

class ArbolB
{
public:
    ArbolB();
    void Insertar(Llave*);
    Llave Buscar(int, BloqueArbolB*);
    BloqueArbolB* buscarBloqueObjetivo(Llave*,BloqueArbolB*sraiz);
    void crecer(BloqueArbolB*);
    virtual ~ArbolB();

    BloqueArbolB*Raiz;
};


#endif //ARBOLB_ARBOLB_H
