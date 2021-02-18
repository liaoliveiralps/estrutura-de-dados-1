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
    ~LLDE();
    int getQuantidade()const{return quantidade;}
    bool estaVazia()const;
    void inserirInicio(int elemento);
    int retirarInicio();
    void inserirFim(int elemento);
    int retirarFim();
    int operator[](int posicao)const;
    void inserirPosicao(int posicao, int elemento);
    int retirarPosicao(int posicao);
    void inserirOrdenado(int elemento);

};
}
#endif // LLDE_H
