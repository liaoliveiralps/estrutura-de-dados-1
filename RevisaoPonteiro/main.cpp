#include <QCoreApplication>
#include <iostream>
int main(void)
{
    //ENDEREÇO DE MEMÓRIA DE UMA VARIÁVEL
    int x=10;
    std::cout<<"Valor: "<<x<<std::endl;
    std::cout<<"Endereco: "<<&x<<std::endl;
    std::cout<<"\n";
    //ENDEREÇO DE MEMÓRIA DE UM PONTEIRO
    int *p1=0;
    std::cout<<"Valor: "<<p1<<std::endl;
    std::cout<<"Endereco: "<<&p1<<std::endl;
    std::cout<<"\n";
    //
    p1=&x;
    std::cout<<"Valor: "<<p1<<std::endl;
    std::cout<<"Endereco: "<<&p1<<std::endl;
    std::cout<<"Valor X via P1: "<<*p1<<std::endl; //valor apontado
    std::cout<<"\n";
    //
    *p1=30;
    std::cout<<"Valor: "<<x<<std::endl;
    std::cout<<"Endereco: "<<&x<<std::endl;
    std::cout<<"\n";
    //REFERENCIA
    int &refx=x;
    std::cout<<"Valor: "<<refx<<std::endl;
    std::cout<<"Endereco: "<<&refx<<std::endl;
    std::cout<<"\n";
    //
    std::cout<<"Endereco X via P1: "<<&*p1<<std::endl;
    std::cout<<"\n";
}
