#include "arvore.h"
namespace ed1 {

Arvore::Arvore():
    raiz(0)
{

}
Arvore::~Arvore(){
    if(raiz != 0){
        delete raiz;
    }
}
void Arvore::inserirRecursivo(Noarvore **raiz, int elemento){
    if(*raiz == 0){
        *raiz = new Noarvore(elemento);
    }else
        if(elemento < (*raiz)->getDado())
            inserirRecursivo(&(*raiz)->esquerda, elemento);
        else
            if(elemento > (*raiz)->getDado() )
                inserirRecursivo(&(*raiz)->direita, elemento);
            else throw std::string("Elemento já Existe");
}

void Arvore::emOrdem(Noarvore* raiz)const{
    if(raiz != 0){
        emOrdem(raiz->getEsquerda());
        std::cout<<std::endl<<"Elemento=>  "<<raiz->getDado();
        emOrdem(raiz->getDireita());
    }
}
int Arvore::retornar_Maior(Noarvore **raiz){
    int valor;
    Noarvore *aux = 0;
    if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));
    else{
        aux = *raiz;
        valor = (*raiz)->getDado();
        *raiz = (*raiz)->esquerda;
        aux->esquerda = 0;
        aux->direita = 0;
        delete aux;
        return valor;
    }
}

void Arvore::removerRecursivo(Noarvore **raiz, int elemento){
    Noarvore *aux = 0;
    //std::cout<<std::endl<<"Remover Recursivo1"<<std::endl;
    if(*raiz != 0){
        //std::cout<<std::endl<<"Remover Recursivo2"<<std::endl;
        //std::cout<<"dado = "<<(*raiz)->getDado();
        if((*raiz)->getDado() == elemento){
            //std::cout<<std::endl<<"Remover Recursivo3"<<std::endl;
            aux = *raiz;
            if((*raiz)->esquerda == 0){
                *raiz = (*raiz)->direita;
                aux->esquerda = 0;
                aux->direita = 0;
                delete aux;
            }else
                if((*raiz)->direita == 0){
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;
                }else
                    {
                        (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                    }
        }else
            {
                if((*raiz)->getDado() < elemento)
                    removerRecursivo(&(*raiz)->direita,elemento);
                else
                    if((*raiz)->getDado() > elemento)
                        removerRecursivo(&(*raiz)->esquerda,elemento);
        }

    }//ok
    else throw std::string("Elemento não Existe");//ok
}
void Arvore::pre_fixado_direita(Noarvore *raiz){
    if(raiz!=0){
        lista->inserirFim(raiz->getDado());
        pre_fixado_direita(raiz->direita);
        pre_fixado_direita(raiz->esquerda);
    }

}
LDEC Arvore::PreDireita(){
    pre_fixado_direita(raiz);
    return *lista;
}
void Arvore::central_direita(Noarvore *raiz){
    if(raiz!=0){
        central_direita(raiz->direita);
        lista->inserirFim(raiz->getDado());
        central_direita(raiz->esquerda);
    }
}
LDEC Arvore::CentralDireita(){
    central_direita(raiz);
    return *lista;
}
void Arvore::central_esquerda(Noarvore *raiz){
    if(raiz!=0){
        central_esquerda(raiz->esquerda);
        lista->inserirFim(raiz->getDado());
        central_esquerda(raiz->direita);
    }

}
LDEC Arvore::CentralEsquerda(){
    central_esquerda(raiz);
    return *lista;
}
void Arvore::pre_fixado_esquerda(Noarvore *raiz){
    if(raiz!=0){
        lista->inserirFim(raiz->getDado());
        pre_fixado_esquerda(raiz->esquerda);
        pre_fixado_esquerda(raiz->direita);
    }
}
LDEC Arvore::PreEsquerda(){
    pre_fixado_esquerda(raiz);
    return *lista;
}
void Arvore::pos_fixado_direita(Noarvore *raiz){
    if(raiz!=0){
        pre_fixado_direita(raiz->direita);
        pre_fixado_direita(raiz->esquerda);
        lista->inserirFim(raiz->getDado());
    }
}
LDEC Arvore::PosDireita(){
    pos_fixado_direita(raiz);
    return *lista;
}
void Arvore::pos_fixado_esquerda(Noarvore *raiz){
    if(raiz!=0){
        pre_fixado_esquerda(raiz->esquerda);
        pre_fixado_esquerda(raiz->direita);
        lista->inserirFim(raiz->getDado());
    }
}
LDEC Arvore::PosEsquerda(){
    pos_fixado_esquerda(raiz);
    return *lista;
}
bool Arvore::consultarA(Noarvore **raiz, int elemento){
    if((*raiz)!=0){
        if(elemento==(*raiz)->getDado()){
            return ("Valor existente.");
        }
        else{
            if(elemento<(*raiz)->getDado()){
               return consultarA(&(*raiz)->esquerda, elemento);
            }
            else{
                if(elemento>(*raiz)->getDado()){
                    return consultarA(&(*raiz)->direita, elemento);
                }
            }
        }
    }
}
int Arvore::profundidadeA(Noarvore *raiz){
  int h1=0,h2=0;
  if(raiz!=0){
    if(raiz->esquerda!=0){
        h1++;
        profundidadeA(raiz->esquerda);
    }
    else{
        if(raiz->direita!=0){
            h2++;
            profundidadeA(raiz->direita);
        }
    }
    return (1 + h1 + h2);
   }
  else
      return 0;
}
QString Arvore::consultar(int elemento){
    consultarA(&raiz, elemento);
}
}
