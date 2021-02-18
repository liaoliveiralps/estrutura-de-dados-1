#include <iostream>
#include <iomanip>

void Recursive(int x, int cont){
    if(x>=cont){
        std::cout<<cont<<" ";
        Recursive(x,++cont);
    }
}

void Iterative(int x){
    std::string fator;
    for(int i=0; i<=x; i++){
        fator += std::to_string(i) + " ";
    }
    std::cout<<"O resultado iterativo eh igual a: "<<fator<<std::endl;
}

int main()
{
    int numero;
    int cont=0;
    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<"O resultado recursivo eh igual a ";
    Recursive(numero,cont);
    std::cout<<std::endl;
    Iterative(numero);
}
