//Programa para demonstrar a execução da mesma tarefa com ou sem recursividade
//fatorial.cpp
#include <iostream>
#include <iomanip>
#include<Fatorial.h>

int main(void)
{
    int numero;
    ED1::Fatorial objeto;

    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<std::endl;
    std::cout<<"O Fatorial Recursivo no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.fatorialRecursive(numero)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"O Fatorial Interativo no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.fatorialIterative(numero)<<std::endl;

}
