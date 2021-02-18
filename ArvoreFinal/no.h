#ifndef NO_H
#define NO_H
#include<iostream>
namespace ed1 {

class No
{
private:
    int dado;
public:
    No* direita;
    No* esquerda;
public:
    No(int dado);
    ~No();
    int getDado()const{return dado;}
    void setDado(int dado){this->dado=dado;}
    No* getDireita()const{return direita;}
    No* setDireita(){this->direita=direita;}
    No* getEsquerda()const{return esquerda;}
    No* setEsquerda(){this->esquerda=esquerda;}
};
}
#endif // NO_H
