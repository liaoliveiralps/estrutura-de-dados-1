#include "llde.h"
#include <QString>
namespace ed1{
LLDE::LLDE():
    pInicio(nullptr),
    pFinal(nullptr),
    quantidade(0)
{

}
LLDE::~LLDE(){
    while (quantidade!=0) {
        retirarInicio();
    }
}
bool LLDE::estaVazia() const{
    if(quantidade==0) return true;
    else
        return false;
}
void LLDE::inserirInicio(QString elemento){
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
QString LLDE::retirarInicio(){
    if(estaVazia()) throw QString("Lista vazia");
    if(quantidade==1){
        QString valor=pInicio->getDado();
        delete pInicio;
        pInicio=pFinal=0;
        quantidade=0;
        return valor;
    }
    No* pAux = pInicio;
    pInicio = pInicio->getPProximo();
    pInicio->setPAnterior(0);
    quantidade--;
    QString valor = pAux->getDado();
    delete pAux;
    return valor;
}
void LLDE::inserirFim(QString elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazia()){
            pInicio=pFinal=pAux;
        }
        else{
            pFinal->setPProximo(pAux);
            pAux->setPAnterior(pFinal);
            pFinal = pAux;
        }
        quantidade++;
    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }
}
QString LLDE::retirarFim(){
    if(estaVazia()) throw QString("Lista vazia");
    No* pAux = pFinal;
    if(quantidade==1){
        pAux=pFinal;
        pInicio=pFinal=0;
        quantidade=0;
        QString valor = pAux->getDado();
        delete pAux;
        return valor;
    }
    pFinal = pAux->getPAnterior();
    pFinal->setPProximo(0);
    QString valor = pAux->getDado();
    quantidade--;
    delete pAux;
    return valor;
}
QString LLDE::operator[](int posicao)const{
    if(posicao<0) throw QString("Posição não pode ser negativa");
    if(posicao>=quantidade) throw QString("Posição inválida");
    if(estaVazia()) throw QString("Lista vazia");
    if(posicao==0)
        return pInicio->getDado();
    if(posicao==quantidade-1)
        return pFinal->getDado();
    No *pAux;
    pAux = pInicio;
    int cont=0;
    while(cont<posicao){
        pAux = pAux->getPProximo();//getElo()
        cont++;
    }
    return pAux->getDado();
}
void LLDE::inserirPosicao(int posicao, QString elemento){
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
QString LLDE::retirarPosicao(int posicao){
    if(estaVazia()) throw QString("Lista vazia");
    if(posicao<0 or posicao>=quantidade) throw QString("Posição inválida");
    if(posicao==0) return retirarInicio();
    if(posicao==quantidade-1) return retirarFim();
    No *pAux;
    pAux = pInicio;
    int cont = 0;
    QString valor=0;
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
void LLDE::inserirOrdenado(QString elemento){
    try {
        int valor1,valor2;
        if(quantidade==0)
            inserirInicio(elemento);
        else{
            No *Paux=pInicio;
            No *Pno = new No(elemento);
            if (quantidade==1){
                valor1=Paux->getDado().toStdString()[5];
                valor2=Pno->getDado().toStdString()[5];
                if(valor1>valor2)
                    inserirFim(elemento);
                else
                    inserirInicio(elemento);
            }
            else{
                int a=1;
                valor1=Pno->getDado().toStdString()[5];
                valor2=Paux->getDado().toStdString()[5];
                while(valor1>valor2 && a!=quantidade){
                    Paux=Paux->getPProximo();
                    valor2=Paux->getDado().toStdString()[5];
                    a++;
                }
                valor1=Pno->getDado().toStdString()[5];
                valor2=Paux->getDado().toStdString()[5];
                if(valor1>valor2 && a==quantidade)
                    inserirFim(elemento);
                else{
                    if(valor1>valor2)
                        inserirPosicao(a-1,elemento);
                    else{
                        if(a==1)
                            inserirInicio(elemento);
                         else
                            inserirPosicao(a-1,elemento);
                    }
                }
            }
        }


    } catch (std:: bad_alloc) {
        throw QString("Falta espaço na memória");
    }

}
}
