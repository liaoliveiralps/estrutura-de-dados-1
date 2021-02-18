#include "fila.h"
namespace lia{
Fila::Fila():
    tamanho(0),
    array(0),
    fim(-1),
    inicio(-1),
    quantidade(0)
{
    try {
        array = new int[tamanho];
    } catch (std::bad_alloc&) {
        throw QString("falta espaço na memória");
    }
}
Fila::Fila(int tamanho1):
    tamanho(0),
    array(0),
    fim(-1),
    inicio(-1),
    quantidade(0)
{
    if(tamanho1 <= 0) throw QString("tamanho fora do intervalo válido");
    try{
        array = new int[tamanho1];
        this->tamanho = tamanho1;
    }catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
}
void Fila::inserir(int elemento){
    //1) verificar se esta cheio, se quantidade==tamanho
    if(estaCheia()) throw QString("Fila cheia");
    //2) verificar se esta vazia, se quantidade==0 e inicio++
    if(estaVazia()) inicio++;
    fim++;
    if(fim==tamanho) fim=0;
    array[fim]=elemento;
    quantidade++;
}
int Fila::retirar(){
    //1) verificar se esta vazia
    if(estaVazia()) throw QString("Fila vazia");
    quantidade--;
    int valor = array[inicio];
    inicio++;
    if(inicio==tamanho) inicio=0;
    if(quantidade==0) inicio=fim==-1;
    return valor;
}
bool Fila::estaCheia()const{
    if(quantidade==tamanho)
        return true;
    else
        return false;
}
bool Fila::estaVazia() const{
    if(quantidade==0)
        return true;
    else
        return false;
}
int Fila::consultar() const{
    if(estaVazia()) throw QString("Pilha vazia");
    return array[inicio];
}
}
