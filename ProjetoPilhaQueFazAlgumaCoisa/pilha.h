#ifndef PILHA_H
#define PILHA_H
#include <QString>
namespace ED1{
class Pilha
{
private:
    int tamanho;
    int *array;
    int topo;
public:
    Pilha();
    Pilha(int tamanho);
    ~Pilha(){if(array) delete[] array;}
    bool estaVazio() const{return topo==-1;}
    bool estaCheio() const{return topo == tamanho-1;}
    void inserir(int elemento);
    void retirar();
    int consultar()const;
    int quantidade()const{return topo+1;}
};
}

#endif // PILHA_H
