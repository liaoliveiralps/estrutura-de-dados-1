#include "pilha.h"

namespace ED1{
Pilha::Pilha():
    tamanho(4),
    array(0),
    topo(-1)
{
    try{
        array = new int[tamanho];
    }catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
}
Pilha::Pilha(int tamanho):
    tamanho(0),
    array(0),
    topo(-1)
{
    if(tamanho <= 0) throw QString("tamanho fora do intervalo válido");
    try{
        array = new int[tamanho];
        this->tamanho = tamanho;
    }catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
}
void Pilha::inserir(int elemento){
    if(estaCheio()) throw QString("Pilha cheia");
    topo++;
    array[topo] = elemento;
}
void Pilha::retirar(){
    if(this->estaVazio()) throw QString("Pilha vazia");
    topo--;
}
int Pilha::consultar() const{
    if(this->estaVazio()) throw QString("Pilha vazia");
    return this->array[topo];
}

}

