#include<iostream>
#include<iomanip>
#include<recursivo8.h>

int main(void){
    int num;
    ed1::recursivo8 objeto;
    std::cout<<"Digite um numero: ";
    std::cin>>num;
    std::cout<<std::endl;
    objeto.exrecursivo8(num);
}
