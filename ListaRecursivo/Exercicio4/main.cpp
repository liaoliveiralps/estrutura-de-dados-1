#include <iostream>
#include <iomanip>

void Recursive(int x){
    if(x>=0){
        std::cout<<x<<" ";
        Recursive(x-1);
    }
}

void Iterative(int x){
    std::string fator;
    for(int i=x; i>=0; i--){
        fator += std::to_string(i) + " ";
    }
    std::cout<<"O resultado iterativo eh igual a: "<<fator<<std::endl;
}

int main()
{
    int numero;
    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<"O resultado recursivo eh igual a ";
    Recursive(numero);
    std::cout<<std::endl;
    Iterative(numero);
    return 0;
}
