#ifndef NO_H
#define NO_H
namespace lula {
template<class T>
class No
{
private:
    T dado;
    No * pProximo;
    No * pAnterior;
public:
    No();
    No(T dado);
    T getInformacao() const {return this->dado;}
    No * getProximo() const {return this->pProximo;}
    No * getAnterior() const {return this->pAnterior;}
    void setInformacao(T informacao) {this->dado = informacao;}
    void setProximo(No * proximo) {this->pProximo = proximo;}
    void setAnterior(No * anterior) {this->pAnterior = anterior;}

};
template <class T>
No<T>::No()
    : dado(0)
    , pProximo(0)
    , pAnterior(0)
{

}
template <class T>
No<T>::No(T informacao)
    : dado(informacao)
    , pProximo(0)
    , pAnterior(0)
{

}

}
#endif // NO_H
