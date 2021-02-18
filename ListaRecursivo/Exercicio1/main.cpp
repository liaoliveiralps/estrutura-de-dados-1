#include <iostream>
#include <iomanip>
#include <soma.h>

int main(void)
{
    int numero;
    lia::Soma objeto;

    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<std::endl;
    std::cout<<"A soma recursiva no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.somaR(numero)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"A soma interativa no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.somaI(numero)<<std::endl;

}
