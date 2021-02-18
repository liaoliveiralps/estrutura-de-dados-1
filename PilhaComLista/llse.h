#ifndef LLSE_H
#define LLSE_H
#include <no.h>
#include <QString>
namespace lia{
class LLSE
{
private:
    No* pInicio; //ponteiro
    No* pFim;
    int quantidade;
public:
    LLSE();
    ~LLSE();
    int getQuantidade()const{return quantidade;}
    bool estaVazio()const{return(quantidade==0);}
    void inserirInicio(int elemento);
    int retirarInicio();
    void inserirFim(int elemento);
    int retirarFim();
    int operator[](int posicao)const;
    void inserirPorPosicao(int posicao, int elemento);
    int retirarPorPosicao(int elemento);
};
}
#endif // LLSE_H
