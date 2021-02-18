#include <iomanip>
#include <iostream>

void Recursive(int x, int cont){
    if(x%2==0 and x>=cont){
        std::cout<<cont<<" ";
        Recursive(x,cont+=2);
    }
}

void Iterative(int x){
    std::string saida;
    if(x%2==0){
        int cont=0;
        while(x>=cont){
            saida+=std::to_string(cont) + " ";
            cont+=2;
        }
        std::cout<<"O resultado iterativo eh igual a: "<<saida<<std::endl;
    }
    else
        std::cout<<"Numero nao eh par";
}
int main()
{
    int numero;
    int cont=0;
    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<"O resultado recursivo eh igual a: ";
    Recursive(numero, cont);
    std::cout<<std::endl;
    Iterative(numero);
    return 0;
}
