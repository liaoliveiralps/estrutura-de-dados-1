#include <QCoreApplication>
#include <llse.h>
#include <iostream>
int main()
{
    try {
        lia::LLSE no;
        int num=0;
        std::cout<<"Quantidade de elementos: "<<no.getQuantidade()<<std::endl;
        for(int i=0; i<5; i++){
            num = rand()%100;
            no.inserirInicio(num);
            std::cout<<"Numero inserido: "<<num<<std::endl;
        }
        std::cout<<"Quantidade de elementos: "<<no.getQuantidade()<<std::endl;
        for(int i=0; i<6; i++){
            num = no.retirarInicio();
            std::cout<<"Numero retirado: "<<num<<std::endl;
        }
        std::cout<<"Quantidade de elementos: "<<no.getQuantidade()<<std::endl;
    } catch (QString &erro){
        std::cout<<erro.toStdString();
    }

}
