#include "pilha.h"
#include <QString>
namespace lia{
Pilha::Pilha():
    tamanho(4),
    vetor(0),
    topo(-1)
{
    try {
        vetor = new int[this->tamanho];
    } catch (std::bad_alloc&) {
        throw QString("Falta espaço na memória");
    }
}
Pilha::Pilha(int tamanho):
    tamanho(1),
    vetor(0),
    topo(-1)
{
    try {
        if(tamanho<=0)
           throw QString("Tamanho não pode ser menor ou igual a zero");
        this->tamanho = tamanho;

        vetor = new int[this->tamanho];
    } catch (std::bad_alloc&) {
        throw QString("Falta espaço na memória");
    }

}
bool Pilha::Cheia()const{
    if(tamanho-1==topo)
        return true;
    else
        return false;
}
bool Pilha::Vazia()const{
    if(topo==-1)
       return true;
    else
        return false;
}
void Pilha::Inserir(int valor){
    bool resp = Cheia();
    if(resp == true)
        throw QString("Pilha cheia");
    else{
        topo++;
        vetor[topo] = valor;
    }
}
int Pilha::Consultar()const{
    return vetor[topo];
}
void Pilha::Retirar(){
    bool resp = Vazia();
    if(resp == true)
        throw  QString("Pilha vazia");
    else{
        topo--;
    }
}
}
