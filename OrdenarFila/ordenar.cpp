#include "ordenar.h"
#include <fila.h>
namespace lia {
Ordenar::Ordenar(int tamanho):
    vetor(0),
    tamanho(0)
{
    try {
        this->tamanho = tamanho;
        vetor = new int[this->tamanho];
        for (int pos = 0; pos<this->tamanho;pos++) vetor[pos] = rand()%100;

    } catch (std::bad_alloc) {
        throw QString("Nao tem memoria.");
    }
}
void Ordenar::arrumarVetor(){
    Fila *fila1 = new Fila(tamanho);
    for(int pos = 0; pos < tamanho; pos++)
    {
        int tamanho1=fila1->getQuantidadeDeElementos();
        int i=0;
        for (; i<tamanho1 && vetor[pos] > fila1->consultar(); i++)
        {
            fila1->inserir(fila1->retirar());
        }

        fila1->inserir(vetor[pos]);

        for ( ;i<tamanho1;i++)
        {
            fila1->inserir(fila1->retirar());
        }
    }

    int tamanho1=fila1->getQuantidadeDeElementos();
    for (int pos = 0;pos<tamanho1;pos++) {
        vetor[pos]  = fila1->retirar();
    }
}
QString Ordenar::getVetor(){
    QString saida;
    for(int pos = 0; pos<tamanho; pos++)
    {
        saida += QString::number(vetor[pos]);
        if(pos+1 < tamanho) saida += " ,";
    }
    return saida;
}
}
