#include "ordenar.h"
namespace lia
{
Ordenar::Ordenar(int tamanho):
    tamanho(),
    array(nullptr)
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
QString Ordenar::vetorDesordenado(){
    QString saida ="";
    for (int i=0; i <tamanho; i++) {
        saida+= QString::number(array[i]);
        if(i+1!=tamanho)
        saida+= ",";
    }
    return saida;
}
void Ordenar::arrumar()
{
    Pilha *pilha = new Pilha(tamanho);
    Pilha *pilhaAux = new Pilha(tamanho);

    int pos = 0;
    pilha->inserir(*(array+pos));
    pos++;
    while((pos<tamanho)){
        while((!pilha->estaVazia())&&array[pos] > pilha->consultar()){
            pilhaAux->inserir(pilha->remover());
            //pilha->inserir(*(array+pos));
        }
        pilha->inserir(*(array+pos));
        while(!pilhaAux->estaVazia()){
            pilha->inserir(pilhaAux->remover());
        }
        pos++;
    }
    int i=0;
    while(!pilha->estaVazia()) {
        array[i] = pilha->remover();
        i++;
    }
    delete pilha;
    delete pilhaAux;

}

QString Ordenar::getVetor()const
{
    QString saida ="";
    for (int i=0; i <tamanho; i++) {
        saida+= QString::number(array[i]);
        if(i+1!=tamanho)
        saida+= ",";
    }
    return saida;
}


}
