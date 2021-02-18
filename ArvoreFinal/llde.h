#ifndef LDEC_H
#define LDEC_H
#include <nolista.h>
#include <QString>
namespace ed1{
class LDEC
{
private:
    int quantidade;
    No *pInicio;
    No *pFim;
public:
    LDEC();
    ~LDEC();
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
#endif // LDEC_H
