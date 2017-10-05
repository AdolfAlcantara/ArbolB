//
// Created by Chronos-Laptop on 19/9/2017.
//

#include <iostream>
#include "ArbolB.h"
ArbolB::ArbolB()
{
    Raiz=0;
}

struct promocion{

public:
    promocion(Llave promoted,BloqueArbolB*hermano, BloqueArbolB*actual){
        llave = promoted;
        this->actual = actual;
        this->hermano = hermano;
    }

    Llave llave;
    BloqueArbolB*actual;
    BloqueArbolB*hermano;
};


promocion* split(BloqueArbolB*actual)
{
    BloqueArbolB *hermano = new BloqueArbolB();
    int mitad = ((m+1)/2);
    for(int i=0;mitad+i+1<=m+1;i++){
        if(mitad+i+1<m+1) {
            hermano->llaves[i] = actual->llaves[mitad + i + 1];
            actual->llaves[mitad+i+1].valor=-1;
        }
        hermano->hijos[i] = actual->hijos[mitad+i+1];
        actual->hijos[mitad+i+1] = 0;
    }

    Llave promo = actual->llaves[mitad];
    actual->llaves[mitad].valor=-1;
    return new promocion(promo,hermano,actual);
}

void promover(BloqueArbolB*padre, promocion*promo)
{
    int pos=0;
    for(int i=0;i<m+1;i++){
        if(padre->llaves[i].valor==-1){
            break;
        }
        if(padre->llaves[i].valor>promo->llave.valor){
            break;
        }
        pos++;
    }
    for(int i = padre->llaves.size()-1;i>pos;i--){
        padre->llaves[i] = padre->llaves[i-1];
    }
    for(int i = padre->hijos.size()-1;i>pos;i--){
        padre->hijos[i] = padre->hijos[i-1];
    }

    padre->llaves[pos] = promo->llave;
    padre->hijos[pos]= promo->actual;
    padre->hijos[pos+1] = promo->hermano;
}
void ArbolB::crecer(BloqueArbolB*actual)
{
    if(actual->llaves[m].valor==-1){
        return;
    }
    promocion *promo = split(actual);
    if(actual->padre==NULL){
        Raiz = new BloqueArbolB();
        actual->padre = Raiz;
        Raiz->cantHijos++;
    }
    promover(actual->padre,promo);
    crecer(actual->padre);
}


void ArbolB::Insertar(Llave *llave)
{
    BloqueArbolB *bloque;
    if(Raiz==0)
    {
        bloque = new BloqueArbolB();
        Raiz  = bloque;
    }
    else {
        bloque = buscarBloqueObjetivo(llave, Raiz);
        if (bloque == NULL) {
            return;
        }
    }
    int pos = 0;
    for (int i = 0; i < bloque->llaves.size(); i++) {
        if (bloque->llaves[i].valor == -1) {
            break;
        }
        else if (bloque->llaves[i].valor > llave->valor) {
            break;
        }
        pos++;
    }
    for (int i = bloque->llaves.size() - 1; i > pos; i--) {
        bloque->llaves[i] = bloque->llaves[i - 1];
    }
    bloque->llaves[pos] = *llave;
    crecer(bloque);
}

BloqueArbolB *ArbolB::buscarBloqueObjetivo(Llave *llave, BloqueArbolB *sraiz)
{
    if(sraiz==0){
        return 0;
    }
    int posHijo=0;
    for(int i=0;i<m;i++){
        if(sraiz->llaves[i].valor==-1){
            break;
        }
        if(sraiz->llaves[i].valor>llave->valor){
            break;
        }
        if(sraiz->llaves[i].valor==llave->valor)
        {
            std::cout<<"Repetido"<<std::endl;
            return NULL;
        }
        posHijo++;
    }
    if(sraiz->esHoja()){
        return sraiz;
    }
    return buscarBloqueObjetivo(llave,sraiz->hijos[posHijo]);
}

Llave ArbolB::Buscar(int v,BloqueArbolB*bab)
{
    if(bab==NULL){
        return 0;
    }
    int pos=0;
    for(int i=0;i<m;i++){
        if(bab->llaves[i].valor==-1){
            break;
        }
        if(bab->llaves[i].valor>v){
            break;
        }
        if(bab->llaves[i].valor == v){
            return bab->llaves[i];
        }
        pos++;
    }
    if(bab->esHoja()){
        std::cout<<"No existe"<<std::endl;
        return NULL;
    }

    return Buscar(v,bab->hijos[pos]);

}



ArbolB::~ArbolB()
{

}
