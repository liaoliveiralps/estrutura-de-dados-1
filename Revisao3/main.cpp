#include <QCoreApplication>
#include <iostream>
int main(void)
{
    int tam=0;
    std::cout<<"Digite tamanho: ";
    std::cin>>tam;
    //new == cria um vetor de forma dinâmica; obs: precisa estar dentro de um Try and Catch
    int *array= new int[tam];
    int *p1=array;
    for(int pos=0; pos<tam; pos++){ //imprime o endereço de memória de cada elemento do vetor
        std::cout<<"Valor: "<<p1<<std::endl;
        p1++;
    }
    p1=array;
    for(int pos=0; pos<tam; pos++){
        std::cout<<"Digite um valor: ";
        std::cin>>*p1;
        p1++;
    }
    p1=array;
    for(int pos=0; pos<tam; pos++){
        std::cout<<"Valor: "<<p1<<std::endl;
        p1++;
    }
    delete[]array;
}
