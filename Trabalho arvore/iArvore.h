#ifndef IARVORE_H
#define IARVORE_H
#include<llde.h>
namespace ed1 {
class IArvore{
    virtual void inserir(int elemento) = 0;
    virtual void imprimir() = 0;
    virtual bool consultar(int elemento) = 0;
    virtual int profundidade() = 0;
    virtual LDEC CentralEsquerda() = 0;
    virtual LDEC PreEsquerda() = 0;
    virtual LDEC PosEsquerda() = 0;

    virtual LDEC CentralDireita() = 0;
    virtual LDEC PreDireita() = 0;
    virtual LDEC PosDireita() = 0;
};
}
#endif // IARVORE_H
