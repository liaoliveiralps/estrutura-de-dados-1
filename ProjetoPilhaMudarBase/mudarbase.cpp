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
        throw QString("Base não pode ser menor/igual a 2");
    if(base>16)
        throw QString("Base não pode ser maior/igual a 16");
}
void MudarBase::divisao(int numero, int base){
    ED1::Pilha pilha;
    while(numero/base!=0 or numero/base!=1)
    {
        int div = numero/base;
        int resto = numero%base;
        //precisa criar o vetor???
        pilha.inserir(resto);
        numero = div;
    }
}
}
