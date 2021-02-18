#ifndef NO_H
#define NO_H

namespace lia{
template<class T>
class No
{
public:
    No();
    No(T informacao);
    T getInformacao() const { return this->informacao; }
    No * getProximo() const { return this->proximo; }
    No * getAnterior() const { return this->anterior; }
    void setInformacao(T informacao) { this->informacao = informacao; }
    void setProximo(No * proximo) { this->proximo = proximo; }
    void setAnterior(No * anterior) { this->anterior = anterior; }

private:
    T informacao;
    No * proximo;
    No * anterior;

};
template <class T>
No<T>::No()
{

}

template <class T>
No<T>::No(T informacao)
    : informacao(informacao)
{

}

}

#endif // NO_H
