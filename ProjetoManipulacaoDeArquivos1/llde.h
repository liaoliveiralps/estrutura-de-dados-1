#ifndef LLDE_H
#define LLDE_H
#include <no.h>
#include<QString>
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
    void inserirInicio(QString elemento);
    QString retirarInicio();
    void inserirFim(QString elemento);
    QString retirarFim();
    QString operator[](int posicao)const;
    void inserirPosicao(int posicao,QString elemento);
    QString retirarPosicao(int posicao);
    void inserirOrdenado(QString elemento);

};
}
#endif // LLDE_H
