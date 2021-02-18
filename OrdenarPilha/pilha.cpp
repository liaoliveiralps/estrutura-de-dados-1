#include "pilha.h"
namespace lia
{
Pilha::Pilha(int tamanho):
    tamanho(0),
    array(nullptr),
    topo(-1)
{
    if(tamanho<=0)
        throw QString("Tamanho invalido");
    try
    {
        array = new int[tamanho];
        this->tamanho=tamanho;
    }
    catch (std::bad_alloc&)
    {
        throw QString("Maquina sem memoria");
    }
}

void Pilha::inserir(int valor)
{
    if(topo==tamanho-1)
    {
        throw QString("Pilha cheia");
    }
    topo++;
    *(array+topo)=valor;
}
int Pilha:: remover()
{
    if(topo==-1)
    {
        throw QString("Pilha vazia");
    }

    topo--;

    return *(array+(topo+1));
}
int Pilha:: consultar()const
{
    if(topo==-1)
    {
        throw QString("Pilha vazia");
    }
    return *(array+topo);

}
bool Pilha:: estaVazia()const
{
    if(topo==-1)
        return true;
    return false;

}
int Pilha:: quantidadeDeElementos()const
{
    return (topo+1);
}
bool Pilha:: estaCheio()const
{
    if(topo+1==tamanho)
        return true;
    return false;
}








}
