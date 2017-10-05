//
// Created by Chronos-Laptop on 19/9/2017.
//

#ifndef ARBOLB_BLOQUEARBOLB_H
#define ARBOLB_BLOQUEARBOLB_H

#include <vector>
struct Llave
{
    int valor;
    int NumeroBloque=0;
    //int NRR;
public:
    Llave(){
        valor=-1;
    }
    Llave(int v){
        valor  = v;
    }
    Llave(int v,int nb){
        valor=v;
        NumeroBloque=nb;
    }
    ~Llave(){}



};
const int m=4;
class BloqueArbolB
{
public:
    BloqueArbolB();
    bool esHoja();
    virtual ~BloqueArbolB();

    int cantLaves;
    int cantHijos;
    BloqueArbolB*padre;
    std::vector<Llave> llaves;
    std::vector<BloqueArbolB*>hijos;
};


#endif //ARBOLB_BLOQUEARBOLB_H
