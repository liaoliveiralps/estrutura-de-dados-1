#ifndef NO_H
#define NO_H
namespace lia{
class No
{
private:
    No* pAnterior;
    int dado;
    No* pProximo;
public:
    No(); //inicia todos
    No(int dado); //prox e o anterior recebem 0
    int getDado()const{return dado;}
    No* getPAnterior()const{return pAnterior;}
    No* getPProximo()const{return pProximo;}
    void setDado(int dado){this->dado = dado;}
    No* setPAnterior(No *pAnterior){this->pAnterior=pAnterior;}
    No* setPProximo(No *pProximo){this->pProximo=pProximo;}

};
}
#endif // NO_H
