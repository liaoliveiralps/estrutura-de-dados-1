#include <QCoreApplication>
#include <llse.h>
#include <no.h>
#include <iostream>

int main()
{
    lia::LLSE no;
    std::cout<<"Quantidade de elementos: "<<no.getQuantidade();
    for(int i=0; i<5; i++)
        no.inserirInicio(rand()%100);
    std::cout<<"Quantidade de elementos: "<<no.getQuantidade();
    for(int i=0; i<6; i++)
        no.inserirInicio(rand()%100);
}
