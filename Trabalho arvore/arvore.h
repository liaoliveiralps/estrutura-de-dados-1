#ifndef ARVORE_H
#define ARVORE_H
#include<noarvore.h>
#include<iArvore.h>
#include<QString>
#include<iostream>
namespace ed1 {

class Arvore
{
private:
    Noarvore* raiz;
    int elementos;
    LDEC *lista;
private:
    void inserirRecursivo(Noarvore **raiz, int elemento);
    void emOrdem(Noarvore* raiz)const;
    void removerRecursivo(Noarvore **raiz, int elemento);
    int retornar_Maior(Noarvore **raiz);
    void central_esquerda(Noarvore* raiz);
    void pre_fixado_esquerda(Noarvore* raiz);
    void pos_fixado_esquerda(Noarvore* raiz);
    void central_direita(Noarvore* raiz);
    void pre_fixado_direita(Noarvore* raiz);
    void pos_fixado_direita(Noarvore* raiz);
    bool consultarA(Noarvore **raiz, int elemento);
    int profundidadeA(Noarvore* raiz);
public:
    Arvore();
    ~Arvore();
    bool estaVazia()const{if(raiz == 0);}
    void inserir(int elemento){this->inserirRecursivo(&raiz,elemento);}
    void imprimir(){emOrdem(raiz);}
    void remover(int elemento){this->removerRecursivo(&raiz, elemento);}
    void central_esquerda();
    LDEC CentralEsquerda();
    void pre_fixado_esquerda();
    LDEC PreEsquerda();
    void pos_fixado_esquerda();
    LDEC PosEsquerda();
    void central_direita();
    LDEC CentralDireita();
    void pre_fixado_direita();
    LDEC PreDireita();
    void pos_fixado_direita();
    LDEC PosDireita();
    QString consultar(int elemento);
    int profundidade();


};
}
#endif // ARVORE_H
