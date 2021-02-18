#include<iostream>
#include<iomanip>
#include<recursividade9.h>

int main(void){

    float k,x;
    int y;
    ed1::recursividade9 objeto;
    std::cout<<"Digite um valor para x:";
    std::cin>>x;
    std::cout<<"Digite um valor para y:";
    std::cin>>y;
    std::cout<<"K = "<<objeto.exrecursividade9(x,y)<<std::endl;
}
