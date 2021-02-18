#include <iostream>
#include <iomanip>
#include <cubo.h>

int main(void)
{
    int numero;
    lia::Cubo objeto;

    std::cout << "Digite um numero: ";
    std::cin >> numero;
    std::cout<<std::endl;
    std::cout<<"O resultado recursivo no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.cuboRecursive(numero)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"O resultado iterativo no numero: "<<numero;
    std::cout<<" e igual a "<<objeto.cuboIterative(numero)<<std::endl;

}
