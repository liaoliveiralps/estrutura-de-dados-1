#include "llse.h"
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
        if(estaVazio()) pInicio=pFim=pAux;
        pAux->setElo(pInicio); //conexão entre os elos
        pInicio=pAux;
        quantidade++;
    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }

}
int LLSE::retirarInicio(){
        No *pAux;
        if(estaVazio())
            throw QString("Impossivel tirar elemento, lista vazia\n");
        pAux=pInicio;
        pInicio=pAux->getElo();
        int aux = pAux->getInformacao();
        quantidade--;
        delete pAux;
        if(estaVazio())
            pInicio=pFim=0;
        return aux;
}
void LLSE::inserirFim(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazio())
            pFim=pInicio=pAux;
        pFim->setElo(pAux); //conexão entre os elos
        pFim=pAux;
        quantidade++;
    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }
}
int LLSE::retirarFim(){
    if(estaVazio()) throw QString("Impossivel tirar elemento, lista vazia");
    if(quantidade==1){
        int valor = pFim->getInformacao();
        delete pFim;
        pFim = pInicio = 0;
        quantidade = 0;
        return valor;
    }
    No *pAux;
    pAux = pInicio;
    while(pAux->getElo()!=pFim)
        pAux = pAux->getElo();
    int valor = pFim->getInformacao();
    delete  pFim;
    pFim = pAux;
    pAux->setElo(0);
    quantidade--;
    return valor;
}
int LLSE::operator[](int posicao){
    if(posicao<0) throw QString("Posição não pode ser negativa");
    if(posicao>=quantidade) throw QString("Posição inválida");
    if(estaVazio()) throw QString("Lista vazia");
    if(posicao==0)
        return pInicio->getInformacao();
    if(posicao==quantidade-1)
        return pFim->getInformacao();
    No *pAux;
    pAux = pInicio;
    int cont=0;
    while(cont<posicao){
        pAux = pAux->getElo();
        cont++;
    }
    return pAux->getInformacao();

}
void LLSE::inserirPorPosicao(int posicao, int elemento){
    if(posicao<0 || posicao>quantidade) throw QString("Posição invalida");
    if(posicao==0) return inserirInicio(elemento);
    if(posicao==quantidade) return inserirFim(elemento);
    No *pAux;
    int cont=0;
    pAux=pInicio;
    while (cont<posicao-1) {
        pAux=pAux->getElo();
        cont++;
    }
    No *pNo=new No(elemento);
    pNo->setElo(pAux->getElo());
    pAux->setElo(pNo);
    quantidade++;
}
int LLSE::retirarPorPosicao(int posicao){
    if(estaVazio()) throw QString("Lista vazia");
    if(posicao<0) throw QString("Posição invalida");
    if(posicao>=quantidade) throw QString("Posição invalida");
    if(posicao==0) return retirarInicio();
    if(posicao==quantidade-1) return retirarFim();
    No *pAux;
    pAux = pInicio;
    int cont = 0;
    int valor=0;
    while (cont<posicao+1) {
        pAux = pAux->getElo();
        if(cont==posicao-1) valor = pAux->getInformacao();
        cont++;
    }
    No* pNo;
    pNo = pInicio;
    int contt=0;
    while (contt<posicao-1) {
        pNo = pNo->getElo();
        contt++;
    }
    pNo->setElo(pAux);
    quantidade--;
    return valor;
}
}
