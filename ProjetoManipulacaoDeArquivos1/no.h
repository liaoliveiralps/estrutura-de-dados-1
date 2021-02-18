#ifndef NO_H
#define NO_H
#include<QString>
namespace lia{
class No
{
private:
    No* pAnterior;
    QString dado;
    No* pProximo;
public:
    No();
    No(QString dado);
    QString getDado()const{return dado;}
    No* getPAnterior()const{return pAnterior;}
    No* getPProximo()const{return pProximo;}
    void setDado(int dado){this->dado = dado;}
    No* setPAnterior(No *pAnterior){this->pAnterior = pAnterior;}
    No* setPProximo(No *pProximo){this->pProximo = pProximo;}

};
}
#endif // NO_H
