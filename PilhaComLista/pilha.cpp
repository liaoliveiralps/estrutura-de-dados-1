#include "pilha.h"
#include <llse.h>
#include <no.h>
namespace lia{
Pilha::Pilha()
{
}
void Pilha::inserir(int elemento){
    teste.inserirFim(elemento);
}
void Pilha::retirar(){
    if(estaVazio()) throw QString("Lista vazia");
    teste.retirarFim();
}
bool Pilha::estaVazio()const{
    if(teste.estaVazio())
        return true;
    else
        return false;
}
int Pilha::consultar() const{
    if(estaVazio()) throw QString("Lista vazia");
    int x = teste.getQuantidade();
    return teste[x-1];
}

}

