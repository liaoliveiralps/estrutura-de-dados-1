#ifndef LLDE_H
#define LLDE_H
#include"no.h"
#include<QString>
namespace lula {
template <class T>
class LLDE
{
private:
    int quantidade;
    No<T> * pInicio;
    No<T> * pFim;
public:
    LLDE();
    ~LLDE();
    int getQuantidade() const {return this->quantidade;}
    void inserirInicio(T elemento);
    T retirarInicio();
    void inserirFim(T elemento);
    T retirarFim();
    void inserirMeio(int posicao, T elemento);
    T retirarMeio(int posicao);
    void inserirOrdenado(T elemento);
    T operator[](int posicao) const;
    bool ver(T elemento) const;
    int consultar(T elemento) const;
    bool estaVazia() const {return this->quantidade==0;}

};
template <class T>
LLDE<T>::LLDE()
    : quantidade(0)
    , pInicio(0)
    , pFim(0)
{

}
template <class T>
LLDE<T>::~LLDE(){
    while (!estaVazia()) retirarInicio();
}
template <class T>
void LLDE<T>::inserirInicio(T elemento){
    No<T> *pNo = new No<T>(elemento);
    No<T> *pAux = pNo;
    if (estaVazia()){
        pInicio = pNo;
        pFim = pNo;
    }
    else{
        pAux->setProximo(pInicio);
        pInicio->setAnterior(pAux);
        pInicio = pAux;
    }
    quantidade++;
}
template <class T>
void LLDE<T>::inserirMeio(int posicao, T elemento)
{
    if (estaVazia())
        return inserirInicio(elemento);
    if (posicao < 0 || posicao >= quantidade)
        throw QString ("Posição inválida!");
    if (posicao == 0)
        return inserirInicio(elemento);
    No<T> *pNo = new No<T>(elemento);
    No<T> *pAux = pInicio;
    for (int i = 0; i < posicao; i++)
        pAux = pAux->getProximo();
    pAux->getAnterior()->setProximo(pNo);
    pNo->setAnterior(pAux->getAnterior());
    pAux->setAnterior(pNo);
    pNo->setProximo(pAux);
    quantidade++;
}
template <class T>
void LLDE<T>::inserirFim(T elemento){
    No<T> *pAux  = new No<T>(elemento);
    if (estaVazia()){
        pFim = pAux;
        pInicio = pAux;
        quantidade++;
        return;
    }
    pAux->setAnterior(pFim);
    pFim->setProximo(pAux);
    pFim = pAux;
    quantidade++;
}
template <class T>
void LLDE<T>::inserirOrdenado(T elemento){
    if (estaVazia()) return inserirInicio(elemento);
    No<T> *pAux = pInicio;
    for (int i = 0; i < quantidade; i++){
        if (elemento <= pAux->getInformacao()){
            inserirMeio(i, elemento);
            break;
        }
        if (i == quantidade - 1){
            inserirFim(elemento);
            break;
        }
        pAux = pAux->getProximo();
    }
}
template <class T>
T LLDE<T>::retirarInicio(){
    if (estaVazia()) throw QString("A lista está vazia");
    if (quantidade == 1){
        T valor = pInicio->getInformacao();
        delete pInicio;
        pInicio = 0;
        pFim = 0;
        quantidade = 0;
        return valor;
    }
    No<T> *pAux = pInicio;
    pInicio = pInicio->getProximo();
    pInicio->setAnterior(0);
    quantidade--;
    T valor = pAux->getInformacao();
    delete pAux;
    return valor;
}
template <class T>
T LLDE<T>::retirarMeio(int posicao){
    if (estaVazia()) throw QString ("A lista está vazia");
    if (posicao < 0 || posicao >= quantidade) throw QString ("Posicao inválida");
    if (posicao == 0) return retirarInicio();
    if (posicao == quantidade -1) return retirarFim();
    No<T> *pAux = pInicio;
    for (int i = 0; i < posicao; i++)
        pAux = pAux->getProximo();
    T dado = pAux->getInformacao();
    pAux->getAnterior()->setProximo(pAux->getProximo());
    pAux->getProximo()->setAnterior(pAux->getAnterior());
    delete pAux;
    quantidade--;
    return dado;
}
template <class T>
T LLDE<T>::retirarFim(){
    if (estaVazia()) throw QString ("A lista está vazia");
    if (quantidade == 1){
        No<T> *pAux = pFim;
        pFim = 0;
        pInicio = 0;
        T dado = pAux->getInformacao();
        quantidade = 0;
        delete pAux;
        return dado;
    }
    No<T> *pAux = pFim;
    pFim = pFim->getAnterior();
    pFim->setProximo(0);
    T dado = pAux->getInformacao();
    quantidade--;
    delete pAux;
    return dado;
}
template <class T>
T LLDE<T>::operator[](int posicao) const{
    if (posicao < 0 || posicao >= quantidade) throw QString ("Posição inválida");
    if (posicao == 0) return pInicio->getInformacao();
    if (posicao == quantidade-1) return pFim->getInformacao();
    No<T> *pAux = pInicio;
    int contador = 0;
    while (contador < posicao){
        pAux = pAux->getProximo();
        contador++;
    }
    return pAux->getInformacao();
}
template <class T>
bool LLDE<T>::ver(T elemento) const{
    if (estaVazia()) return false;
    No<T> *pAux = pInicio;
    for (int i = 0; i < quantidade; i++){
        if (pAux->getInformacao() == elemento) return true;
        pAux = pAux->getProximo();
    }
    return false;
}
template <class T>
int LLDE<T>::consultar(T elemento) const{
    if (!ver(elemento)) return -1;
    No<T> *pAux = pInicio;
    for (int i = 0; i < quantidade; i++){
        if (elemento == pAux->getInformacao()) return i;
        pAux = pAux->getProximo();
    }
    return -1;
}
}
#endif // LLDE_H
