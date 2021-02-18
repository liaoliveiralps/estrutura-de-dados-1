#include <iomanip>
#include <iostream>

void Recursive(int x){
    if(x%2==0 and x>=0){
        std::cout<<x<<" ";
        Recursive(x-=2);
    }
}

void Iterative(int x){
    std::cout<<"O resultado iterativo eh igual a: ";
    if(x%2==0){
        while(x>=0){
            std::cout<<x<<" ";
            x-=2;
        }
    }
}
int main()
{
    int numero;
    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<"O resultado recursivo eh igual a: ";
    Recursive(numero);
    std::cout<<std::endl;
    Iterative(numero);
    std::cout<<std::endl;
    return 0;
}
