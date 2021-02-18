#ifndef NOLISTA_H
#define NOLISTA_H

namespace ed1 {
class No
{
private:
    int informacao;
    No* proximo;
    No* anterior;
public:
    No();
    No(int informacao);
    int getInformacao() const {return this->informacao;}
    No* getProximo() const {return this->proximo;}
    No* getAnterior() const {return this->anterior;}
    void setInformacao(int informacao) {this->informacao=informacao;}
    void setProximo(No* proximo) {this->proximo = proximo;}
    void setAnterior(No* anterior) {this->anterior = anterior;}

};
}
#endif // NOLISTA_H
