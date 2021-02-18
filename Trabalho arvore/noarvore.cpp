#include "noarvore.h"

namespace ed1{
Noarvore::Noarvore(int dado):
    dado(dado),
    direita(0),
    esquerda(0)
{
}

Noarvore::~Noarvore()
{
    std::cout<<"Destrutor Elemento: "<<this->dado<<std::endl;
    if(this->esquerda != 0) delete this->esquerda;
    if(this->direita != 0)  delete this->direita;
}

}
