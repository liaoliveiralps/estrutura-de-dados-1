#ifndef NOARVORE_H
#define NOARVORE_H

namespace lia {
template <class T>
class NoArvore{
private:
    T dado;

public:
    NoArvore* esquerda;
    NoArvore* direita;

public:
    NoArvore();
    NoArvore(T dado);
    ~NoArvore();

    T getDado() const { return this->dado; }
    void setDado(T dado) { this->dado = dado; }
    NoArvore* getEsquerda() const { return this->esquerda; }
    void setEsquerda(NoArvore* esquerda) { this->esquerda = esquerda; }
    NoArvore* getDireita() const { return this->direita; }
    void setDireita(NoArvore* direita) { this->direita = direita; }

    //bool operator == (const No & no) const { return no.getDado() == this->getDado();}


};

template <class T>
NoArvore<T>::NoArvore()
    : esquerda(0)
    , direita(0)
{

}


template <class T>
NoArvore<T>::NoArvore(T dado)
    : dado(dado)
    , esquerda(0)
    , direita(0)
{

}

template <class T>
NoArvore<T>::~NoArvore()
{
    if(this->esquerda != 0) delete this->esquerda;
    if(this->direita != 0)  delete this->direita;
}

}
#endif // NOARVORE_H
