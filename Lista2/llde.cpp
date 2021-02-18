#include "llde.h"
#include <QString>
namespace lia{
LLDE::LLDE():
    pInicio(nullptr),
    pFinal(nullptr),
    quantidade(0)
{

}
bool LLDE::estaVazia() const{
    if(quantidade==0) return true;
    else
        return false;
}
void LLDE::inserirInicio(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazia()){
            pInicio=pFinal=pAux;
            quantidade++;
        }
        else{
            pAux->setPProximo(pInicio);
            pInicio->setPAnterior(pAux);
            pInicio = pAux;
            quantidade++;
        }
    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }
}
int LLDE::retirarInicio(){
    if(estaVazia()) throw QString("Lista vazia");
    if(quantidade==1){
        int valor=pInicio->getDado();
        delete pInicio;
        pInicio=pFinal=0;
        quantidade=0;
        return valor;
    }
    No* pAux = pInicio;
    pInicio = pInicio->getPProximo();
    pInicio->setPAnterior(0);
    quantidade--;
    int valor = pAux->getDado();
    delete pAux;
    return valor;
}
}
