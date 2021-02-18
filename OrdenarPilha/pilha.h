#ifndef PILHA_H
#define PILHA_H
#include <string>
#include <QString>
namespace lia
{
class Pilha
{
private:
    int tamanho;
    int *array;
    int topo;
public:
    Pilha(int tamanho);
    ~Pilha(){if(array) delete[] array;}
    void inserir(int valor);
    int remover();
    int consultar()const;
    bool estaVazia()const;
    int quantidadeDeElementos()const;
    bool estaCheio()const;
};
}

#endif // PILHA_H
