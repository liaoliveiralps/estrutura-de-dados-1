#include "mudarbase.h"
#include <pilha.h>
namespace ED1{
MudarBase::MudarBase():
    numero(1),
    base(2)
{
    if(numero<=0)
        throw QString("Número não pode ser menor ou igual a zero");
    if(base<2)
        throw QString("Base não pode ser menor que 2");
    if(base>16)
        throw QString("Base não pode ser maior que 16");
}
QString MudarBase::divisao(){
    ED1::Pilha pilha(100);
    //QString vetor = "0123456789ABCDEF";
    QString vetor[16] = {"0","1","2","3","4","5","6","7","8","9"};
    vetor[10]="A";
    vetor[11]="B";
    vetor[12]="C";
    vetor[13]="D";
    vetor[14]="E";
    vetor[15]="F";
    while(numero!=0)
    {
        pilha.inserir(numero%base);
        numero = numero/base;
    }
    int var;
    QString apoio;
    while (!pilha.estaVazio()) {
        if(pilha.consultar()){
            var = pilha.consultar();
            apoio+=vetor[var];
            pilha.retirar();
        }
        else{
            apoio+=QString::number(pilha.consultar());
            pilha.retirar();
        }
    }
    return apoio;
}
}
