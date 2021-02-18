#include "llde.h"
namespace ed1{
LDEC::LDEC():
    quantidade(0),
    pInicio(nullptr),
    pFim(nullptr)
{

}
LDEC::~LDEC(){
    while (quantidade!=0) {
        retirarInicio();
    }
}
bool LDEC::estaVazia() const{
    if(quantidade==0) return true;
    else
        return false;
}
void LDEC::inserirInicio(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazia()){
            pInicio=pFim=pAux;
            pAux->setAnterior(pAux);
            pAux->setProximo(pAux);
        }
        else{
            pAux->setProximo(pInicio);
            pInicio->setAnterior(pAux);
            pInicio=pAux;
            pFim->setProximo(pInicio);
            pInicio->setAnterior(pFim);
        }
        quantidade++;
    } catch (QString erro) {
        throw QString("Falta memoria\n");
    }
}
int LDEC::retirarInicio(){
    if(estaVazia()) throw QString("Lista vazia");
    No *pAux=pInicio;
    int valor;
    if(quantidade==1){
        //pAux=pInicio;
        pInicio=pFim=0;
        quantidade=0;
        valor=pAux->getInformacao();
        delete pAux;
        return valor;
    }
    else{
        pAux=pAux->getProximo();
        valor=pInicio->getInformacao();
        pAux->setAnterior(pFim);
        pFim->setProximo(pAux);
        delete pInicio;
        pInicio=pAux;
        quantidade--;
        return valor;
    }
}
void LDEC::inserirFim(int elemento){
    try {
        No *pAux = new No(elemento);
        if(estaVazia()){
            pInicio=pFim=pAux;
            pAux->setAnterior(pAux);
            pAux->setProximo(pAux);
        }
        else{
            pFim->setProximo(pAux);
            pAux->setAnterior(pFim);
            pFim=pAux;
            pInicio->setAnterior(pAux);
            pAux->setProximo(pInicio);
        }
        quantidade++;
    } catch (QString erro) {
        throw QString("Falta memoria\n");
    }
}
int LDEC::retirarFim(){
    if(estaVazia()) throw QString("Lista vazia");
    No *pAux;
    if(quantidade==1){
        pAux=pFim;
        pFim=pInicio=0;
        quantidade=0;
    }
    else{
        pAux=pFim;
        pFim=pAux->getAnterior();
        pFim->setProximo(pInicio);
        pInicio->setAnterior(pFim);
        quantidade--;
    }
    int valor=pAux->getInformacao();
    delete pAux;
    return valor;
}
int LDEC::operator[](int posicao)const{
    if(posicao<0) throw QString("Posição não pode ser negativa");
    if(posicao>=quantidade) throw QString("Posição inválida");
    if(estaVazia()) throw QString("Lista vazia");
    if(posicao==0)
        return pInicio->getInformacao();
    if(posicao==quantidade-1)
        return pFim->getInformacao();
    No *pAux;
    pAux = pInicio;
    int cont=0;
    while(cont<posicao){
        pAux = pAux->getProximo();//getElo()
        cont++;
    }
    return pAux->getInformacao();
}
void LDEC::inserirPosicao(int posicao, int elemento){
    try {
        if(posicao<0 or posicao>quantidade) throw QString("Posição inválida");
        if(posicao==0) return inserirInicio(elemento);
        if(posicao==quantidade) return inserirFim(elemento);
        No *pAux;
        int cont=0;
        pAux=pInicio;
        while (cont<posicao) {
            pAux=pAux->getProximo();
            cont++;
        }
        No *pNo=new No(elemento);
        pAux->getAnterior()->setProximo(pNo);
        pNo->setAnterior(pAux->getAnterior());
        pAux->setAnterior(pNo);
        pNo->setProximo(pAux);
        quantidade++;

    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }
}
int LDEC::retirarPosicao(int posicao){
    if(estaVazia()) throw QString("Lista vazia");
    if(posicao<0 or posicao>=quantidade) throw QString("Posição inválida");
    if(posicao==0) return retirarInicio();
    if(posicao==quantidade-1) return retirarFim();
    No *pAux;
    pAux = pInicio;
    int cont = 0;
    int valor=0;
    while (cont<posicao+1) {
        pAux = pAux->getProximo();
        if(cont==posicao-1) valor = pAux->getInformacao();
        cont++;
    }
    No* pNo;
    pNo = pInicio;
    int contt=0;
    while (contt<posicao-1) {
        pNo = pNo->getProximo();
        contt++;
    }
    pNo->setProximo(pAux);
    quantidade--;
    return valor;
}
void LDEC::inserirOrdenado(int elemento){
    if(quantidade==0) return inserirInicio(elemento);
    No *pAux = pInicio;
    No *pNo = new No(elemento);
    if(quantidade==1){
        if(pNo->getInformacao()>pAux->getInformacao())
            inserirFim(elemento);
        else
            inserirInicio(elemento);
    }
    else{
        int cont=1;
        while (pNo->getInformacao()>pAux->getInformacao() and cont!=quantidade) {
            pAux = pAux->getProximo();
            cont++;
        }
        if(pNo->getInformacao()>pAux->getInformacao() and cont==quantidade)
            inserirFim(elemento);
        else{
            if(pNo->getInformacao()>pAux->getInformacao())
                inserirPosicao(cont-1, elemento);
            else{
                if(cont==1)
                    inserirInicio(elemento);
                else
                    inserirPosicao(cont-1, elemento);
            }
        }
    }
}
}
