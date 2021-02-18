#include "ldec.h"
namespace lia{
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
            pAux->setPAnterior(pAux);
            pAux->setPProximo(pAux);
        }
        else{
            pAux->setPProximo(pInicio);
            pInicio->setPAnterior(pAux);
            pInicio=pAux;
            pFim->setPProximo(pInicio);
            pInicio->setPAnterior(pFim);
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
        valor=pAux->getDado();
        delete pAux;
        return valor;
    }
    else{
        pAux=pAux->getPProximo();
        valor=pInicio->getDado();
        pAux->setPAnterior(pFim);
        pFim->setPProximo(pAux);
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
            pAux->setPAnterior(pAux);
            pAux->setPProximo(pAux);
        }
        else{
            pFim->setPProximo(pAux);
            pAux->setPAnterior(pFim);
            pFim=pAux;
            pInicio->setPAnterior(pAux);
            pAux->setPProximo(pInicio);
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
        pFim=pAux->getPAnterior();
        pFim->setPProximo(pInicio);
        pInicio->setPAnterior(pFim);
        quantidade--;
    }
    int valor=pAux->getDado();
    delete pAux;
    return valor;
}
int LDEC::operator[](int posicao)const{
    if(posicao<0) throw QString("Posição não pode ser negativa");
    if(posicao>=quantidade) throw QString("Posição inválida");
    if(estaVazia()) throw QString("Lista vazia");
    if(posicao==0)
        return pInicio->getDado();
    if(posicao==quantidade-1)
        return pFim->getDado();
    No *pAux;
    pAux = pInicio;
    int cont=0;
    while(cont<posicao){
        pAux = pAux->getPProximo();//getElo()
        cont++;
    }
    return pAux->getDado();
}
void LDEC::inserirPosicao(int posicao, int elemento){
    try {
        if(posicao<0 or posicao>quantidade) throw QString("Posição inválida");
        if(posicao==0) return inserirInicio(elemento);
        if(posicao==quantidade) return inserirFim(elemento);
        No *pAux;
        int cont=0;
        pAux=pInicio;
        while (cont<posicao-1) {
            pAux=pAux->getPProximo();
            cont++;
        }
        No *pNo=new No(elemento);
        pNo->setPProximo(pAux->getPProximo());
        pAux->setPProximo(pNo);
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
        pAux = pAux->getPProximo();
        if(cont==posicao-1) valor = pAux->getDado();
        cont++;
    }
    No* pNo;
    pNo = pInicio;
    int contt=0;
    while (contt<posicao-1) {
        pNo = pNo->getPProximo();
        contt++;
    }
    pNo->setPProximo(pAux);
    quantidade--;
    return valor;
}
void LDEC::inserirOrdenado(int elemento){
    if(quantidade==0) return inserirInicio(elemento);
    No *pAux = pInicio;
    No *pNo = new No(elemento);
    if(quantidade==1){
        if(pNo->getDado()>pAux->getDado())
            inserirFim(elemento);
        else
            inserirInicio(elemento);
    }
    else{
        int cont=1;
        while (pNo->getDado()>pAux->getDado() and cont!=quantidade) {
            pAux = pAux->getPProximo();
            cont++;
        }
        if(pNo->getDado()>pAux->getDado() and cont==quantidade)
            inserirFim(elemento);
        else{
            if(pNo->getDado()>pAux->getDado())
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
QString LDEC::girarHorario(int num){
    if(num<=0) throw QString("Número inválido");
    if(estaVazia()) throw QString("Lista vazia");
    No* pAux=pInicio;
    QString saida;
    while (num!=0){
        saida+=QString::number(num) + "º giro: ";
        for(int i=0; i<quantidade; i++){
            int valor = pAux->getDado();
            saida+=QString::number(valor) + " , ";
            pAux = pAux->getPProximo();
        }
        saida+="\n";
        num--;
    }
    return saida;
}
QString LDEC::girarAnti(int num){
    if(num<=0) throw QString("Número inválido");
    if(estaVazia()) throw QString("Lista vazia");
    No* pAux=pFim;
    QString saida;
    while (num!=0){
        saida+=QString::number(num) + "º giro: ";
        for(int i=0; i<quantidade; i++){
            int valor = pAux->getDado();
            saida+=QString::number(valor) + " , ";
            pAux = pAux->getPAnterior();
        }
        saida+="\n";
        num--;
    }
    return saida;
}
}
