#ifndef LLDE_H
#define LLDE_H
#include <no.h>
namespace lia{
class LLDE
{
private:
    No* pInicio;
    No* pFinal;
    int quantidade;
public:
    LLDE();
    int getQuantidade()const{return quantidade;}
    bool estaVazia()const;
    void inserirInicio(int elemento);
    int retirarInicio();

};
}
#endif // LLDE_H
