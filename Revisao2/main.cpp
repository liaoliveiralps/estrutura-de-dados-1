#include <QCoreApplication>
#include <iostream>
int main(void)
{
    const int tam=4;
    int array[tam]; //ARRAY guarda endereço de memória do primeiro elemento do vetor

    for(int pos=0; pos<tam; pos++)
        array[pos]=0;

    for(int pos=0; pos<tam; pos++) //imprimir vetor
        std::cout<<"Array["<<pos<<"]= "<<array[pos]<<std::endl;

    for(int pos=0; pos<tam; pos++) //atribuir valores ao vetor
        std::cin>>array[pos];

    for(int pos=0; pos<tam; pos++) //imprimir vetor
        std::cout<<"Array["<<pos<<"]= "<<array[pos]<<std::endl;

    for(int pos=0; pos<tam; pos++) //endereço de memória de cada elemento do vetor
        std::cout<<"Endereco: "<<&array[pos]<<std::endl;

    int *p1=array;
    for(int pos=0; pos<tam; pos++){
        std::cout<<"Valor: "<<*p1<<std::endl;
        p1++;
    }
}
