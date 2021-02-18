#ifndef ARVOREBINARIA2_H
#define ARVOREBINARIA2_H
#include <llde.h>

namespace lia {
template<class T>
class ArvoreBinaria2
{
public:
    virtual void inserir(T elemento) = 0;
    virtual void retirar(T elemento) = 0;

    virtual LLDE<T>& imprimirEmOrdemEsquerda() = 0;
    virtual LLDE<T>& imprimirPreOrdemEsquerda() = 0;
    virtual LLDE<T>& imprimirPosOrdemEsquerda() = 0;

    virtual LLDE<T>& imprimirEmOrdemDireita() = 0;
    virtual LLDE<T>& imprimirPreOrdemDireita() = 0;
    virtual LLDE<T>& imprimirPosOrdemDireita() = 0;

    virtual LLDE<T>& consultar() = 0;
    virtual LLDE<T>& profundidade() = 0;

};

}
#endif // ARVOREBINARIA2_H
