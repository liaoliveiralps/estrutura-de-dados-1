#ifndef PILHA_H
#define PILHA_H
#include <QString>
namespace lia{
class Pilha
{
private:
    int tamanho;
    int *vetor;
    int topo;
public:
    Pilha(int tamanho);
    Pilha();
    ~Pilha(){if(vetor) delete[]vetor;}
    int Consultar()const;
    void Retirar();
    void Inserir(int valor);
    bool Vazia()const;
    bool Cheia()const;
    int Quantidade()const{return topo+1;}
};
}
#endif // PILHA_H
