#ifndef NOARVORE_H
#define NOARVORE_H
#include<iostream>
namespace ed1{
class Noarvore
{
private:
    int dado;
public:
    Noarvore *direita;
    Noarvore *esquerda;
public:
    Noarvore(int dado);
    ~Noarvore();
    int getDado()const{return dado;}
    void setDado(int dado){this->dado = dado;}
    Noarvore* getDireita(){return direita;}
    void setDireita(Noarvore* direita){this->direita = direita;}
    Noarvore* getEsquerda(){return esquerda;}
    void setEsquerda(Noarvore* esquerda){this->esquerda = esquerda;}
};
}
#endif // NOARVORE_H
