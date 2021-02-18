#include "llse.h"
#include <no.h>
#include <iostream>
namespace lia{
LLSE::LLSE():
    pInicio(0),
    pFim(0),
    quantidade(0)

{

}
LLSE::~LLSE()
{
    while (quantidade!=0) {
        retirarInicio();
    }
}

void LLSE::inserirInicio(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazio())
            pFim=pAux;
        pAux->setElo(pInicio); //conexão entre os elos
        pInicio=pAux;
        quantidade++;

    } catch (std::bad_alloc) {
        throw QString("Falta memoria");
    }

}
int LLSE::retirarInicio(){
    try {
        No *pAux;
        if(estaVazio())
            throw QString("Lista vazia");
        pAux=pInicio;
        pInicio=pAux->getElo();
        int aux = pAux->getInformacao();
        quantidade--;
        delete pAux;
        if(estaVazio())
            pFim=0;
        return aux;
    } catch (std::bad_alloc) {
        throw QString("Falta memoria");
    }
}
}
