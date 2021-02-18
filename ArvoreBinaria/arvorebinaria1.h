#ifndef ARVOREBINARIA1_H
#define ARVOREBINARIA1_H
#include <llde.h>
#include <noarvore.h>
#include <QString>
#include <arvorebinaria2.h>
#include <iostream>

namespace lia{
template <class T>
class ArvoreBinaria1 : public ArvoreBinaria2<T>
{
private:
    NoArvore<T> *raiz;
    LLDE<T> lista;

    void inserirRecursivo(NoArvore<T>*&  raiz, T elemento);
    void removerRecursivo(NoArvore<T>** raiz, T elemento);
    T retornar_Maior(NoArvore<T> **raiz);

    void emOrdemEsq(NoArvore<T>* raiz);
    void preOrdemEsq(NoArvore<T>* raiz);
    void posOrdemEsq(NoArvore<T>* raiz);

    void emOrdemDir(NoArvore<T>* raiz);
    void preOrdemDir(NoArvore<T>* raiz);
    void posOrdemDir(NoArvore<T>* raiz);

    T consultarA(NoArvore<T>* raiz, T elemento);
    T profundidadeA(NoArvore<T>*raiz);

public:
    ArvoreBinaria1();
    ~ArvoreBinaria1();
    void inserir(T elemento) {this->inserirRecursivo(raiz, elemento);}
    void retirar(T elemento) {this->removerRecursivo(&raiz, elemento);}


    LLDE<T>& imprimirEmOrdemEsquerda();
    LLDE<T>& imprimirPreOrdemEsquerda();
    LLDE<T>& imprimirPosOrdemEsquerda();

    LLDE<T>& imprimirEmOrdemDireita();
    LLDE<T>& imprimirPreOrdemDireita();
    LLDE<T>& imprimirPosOrdemDireita();

    LLDE<T>& consultar(int elemento);
    LLDE<T>& profundidade();


};

template <class T>
ArvoreBinaria1<T>::ArvoreBinaria1()
    : raiz(0)
{

}

template <class T>
ArvoreBinaria1<T>::~ArvoreBinaria1<T>()
{
    if (raiz != 0)
        delete raiz;
}

template <class T>
void ArvoreBinaria1<T>::inserirRecursivo(NoArvore<T>*& raiz, T elemento)
{

    if(raiz == 0)
    {
        raiz = new NoArvore<T>(elemento);
        std::cout << "elemento inserido: " << raiz->getDado() << "\n";
    }
    else
    {
        if(elemento < (raiz)->getDado())
            inserirRecursivo((raiz)->esquerda, elemento);
        else
            if(elemento > (raiz)->getDado() )
                inserirRecursivo((raiz)->direita, elemento);
            else throw QString("Elemento já Existe");
    }
}

template <class T>
T ArvoreBinaria1<T>::retornar_Maior(NoArvore<T> **raiz)
{
    T valor;
    NoArvore<T> *aux = 0;
    if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));
    else
    {
        aux = *raiz;
        valor = (*raiz)->getDado();
        *raiz = (*raiz)->esquerda;
        aux->esquerda = 0;
        aux->direita = 0;
        delete aux;
        return valor;
    }
}
template <class T>
void ArvoreBinaria1<T>::removerRecursivo(NoArvore<T>** raiz, T elemento)
{
    NoArvore<T> *aux = 0;
    //std::cout<<std::endl<<"Remover Recursivo1"<<std::endl;
    if(*raiz != 0)
    {
        //std::cout<<std::endl<<"Remover Recursivo2"<<std::endl;
        //std::cout<<"dado = "<<(*raiz)->getDado();
        if((*raiz)->getDado() == elemento)
        {
            //std::cout<<std::endl<<"Remover Recursivo3"<<std::endl;
            aux = *raiz;
            if((*raiz)->esquerda == 0)
            {
                *raiz = (*raiz)->direita;
                aux->esquerda = 0;
                aux->direita = 0;
                delete aux;
            }
            else
                if((*raiz)->direita == 0)
                {
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;
                }
                else
                {
                    (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                }
        }
        else
        {
            if((*raiz)->getDado() < elemento)
                removerRecursivo(&(*raiz)->direita,elemento);
            else
                if((*raiz)->getDado() > elemento)
                    removerRecursivo(&(*raiz)->esquerda,elemento);
        }


    }//ok
    else throw QString("Elemento não Existe");//ok
}

//=======================================================

template <class T>
void ArvoreBinaria1<T>::preOrdemEsq(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        lista.inserirFim(raiz->getDado());
        preOrdemEsq(raiz->getEsquerda());
        preOrdemEsq(raiz->getDireita());
    }

}

template <class T>
void ArvoreBinaria1<T>::preOrdemDir(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        lista.inserirFim(raiz->getDado());
        preOrdemDir(raiz->getDireita());
        preOrdemDir(raiz->getEsquerda());
    }
}

template <class T>
void ArvoreBinaria1<T>::emOrdemEsq(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        emOrdemEsq(raiz->getEsquerda());
        lista.inserirFim(raiz->getDado());
        emOrdemEsq(raiz->getDireita());
    }
}

template <class T>
void ArvoreBinaria1<T>::emOrdemDir(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        emOrdemDir(raiz->getDireita());
        lista.inserirFim(raiz->getDado());
        emOrdemDir(raiz->getEsquerda());
    }
}

template <class T>
void ArvoreBinaria1<T>::posOrdemEsq(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        posOrdemEsq(raiz->getEsquerda());
        posOrdemEsq(raiz->getDireita());
        lista.inserirFim(raiz->getDado());
    }
}

template <class T>
void ArvoreBinaria1<T>::posOrdemDir(NoArvore<T>* raiz)
{
    if (raiz != 0)
    {
        posOrdemDir(raiz->getDireita());
        posOrdemDir(raiz->getEsquerda());
        lista.inserirFim(raiz->getDado());
    }
}
//==============================================================
template <class T>
T ArvoreBinaria1<T>::consultarA(NoArvore<T>* raiz, T elemento){
    if((*raiz)!=0){
        if(elemento==(*raiz)->getDado()){
            throw QString("Valor existente.");
        }
        else{
            if(elemento<(*raiz)->getDado()){
               return consultar(&(*raiz)->esquerda, elemento);
            }
            else{
                if(elemento>(*raiz)->getDado()){
                    return consultar(&(*raiz)->direita, elemento);
                }
            }
        }
    }
}
template <class T>
T ArvoreBinaria1<T>::profundidadeA(NoArvore<T>* raiz){
    int h1=0,h2=0;
    if(raiz!=0){
      if(raiz->esquerda!=0){
          h1++;
          profundidade(raiz->esquerda);
      }
      else{
          if(raiz->direita!=0){
              h2++;
              profundidade(raiz->direita);
          }
      }
      return (1 + h1 + h2);
     }
    else
        return 0;
}
template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirPreOrdemEsquerda()
{
    lista.~LLDE();
    preOrdemEsq(raiz);
    return lista;
}

template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirPreOrdemDireita()
{
    lista.~LLDE();
    preOrdemDir(raiz);
    return lista;
}

template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirEmOrdemEsquerda()
{
    lista.~LLDE();
    emOrdemEsq(raiz);
    return lista;
}

template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirEmOrdemDireita()
{
    lista.~LLDE();
    emOrdemDir(raiz);
    return lista;
}

template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirPosOrdemEsquerda()
{
    lista.~LLDE();
    posOrdemEsq(raiz);
    return lista;
}


template <class T>
LLDE<T>& ArvoreBinaria1<T>::imprimirPosOrdemDireita()
{
    lista.~LLDE();
    posOrdemDir(raiz);
    return lista;
}
template <class T>
LLDE<T>& ArvoreBinaria1<T>::consultar(int elemento){
    lista.~LLDE();
    consultarA(raiz, elemento);
    return lista;
}
template <class T>
LLDE<T>& ArvoreBinaria1<T>::profundidade(){
    lista.~LLDE();
    profundidade(raiz);
    return lista;
}
}
#endif // ARVOREBINARIA1_H
