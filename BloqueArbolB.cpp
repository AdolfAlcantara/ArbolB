//
// Created by Chronos-Laptop on 19/9/2017.
//

#include "BloqueArbolB.h"
BloqueArbolB::BloqueArbolB()
{
    cantHijos=-1;
    cantLaves=-1;
    hijos = std::vector<BloqueArbolB*>(m+2);
    llaves = std::vector<Llave>(m+1);
    padre=0;
}

bool BloqueArbolB::esHoja()
{
    return hijos[0] == 0;
}

BloqueArbolB::~BloqueArbolB()
{

}
