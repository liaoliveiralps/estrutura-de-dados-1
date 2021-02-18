#include "ordenar.h"
namespace lia
{
Ordenar::Ordenar(int tamanho):
    tamanho(0),
    array(0)
{
    if(tamanho<=0)
        throw QString("Tamanho invalido");
    try
    {
        array = new int[tamanho];
        this->tamanho=tamanho;
        for(int i=0;i<tamanho;i++)
        {
            *(array+i)=rand()%100;
        }
    }
    catch (std::bad_alloc)
    {
        throw QString("Não tem memoria");
    }
}
QString Ordenar::vetorDesordenado()const{
    QString saida ="";
    for (int i=0; i <tamanho; i++) {
        saida+= QString::number(array[i]);
        if(i+1!=tamanho)
        saida+= ",";
    }
    return saida;
}
QString Ordenar::arrumar()
{
    Pilha aux2, aux3;
    aux2.inserir(array[0]);
    for(int i=1; i<tamanho; i++){
        while (!aux2.estaVazio() and array[i]>aux2.consultar()) {
            aux3.inserir(aux2.consultar());
            aux2.retirar();
        }
        aux2.inserir(array[i]);
        int max=aux3.quantidade();
        for(int y=0; y<max; y++){
            aux2.inserir(aux3.consultar());
            aux3.retirar();
        }
    }
    QString saida;
    for(int v=0; v<tamanho; v++){
        saida+=QString::number(aux2.consultar())+", ";
        aux2.retirar();
    }
    return saida;
}
}
