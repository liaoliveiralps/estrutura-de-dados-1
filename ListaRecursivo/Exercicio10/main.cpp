#include<iostream>
#include<iomanip>
#include<recursivo10.h>

int main(void){
    float N1,N2;
    N1=0;
    N2=0;
    ed1::Recursivo10 objeto;
    std::cout<<"Digite o valor de N1: ";
    std::cin>>N1;
    std::cout<<"Digite o valor de N2: ";
    std::cin>>N2;
    std::cout<<objeto.exRecursivo10(N1,N2)<<std::endl;
}
