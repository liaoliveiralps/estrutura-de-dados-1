#ifndef PILHA_H
#define PILHA_H
#include <QString>
#include <llse.h>
namespace lia{
class Pilha
{
private:
    LLSE teste;
public:
    Pilha();
    Pilha(int tamanho);
    ~Pilha(){teste.~LLSE();}
    bool estaVazio()const;
    void inserir(int elemento);
    void retirar();
    int consultar()const;
    int quantidade()const{return teste.getQuantidade();}
};
}
#endif // PILHA_H
