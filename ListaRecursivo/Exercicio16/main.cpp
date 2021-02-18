#include <iostream>
#include <cmath>
int Fatorial(int x){
    if(x == 0 || x ==1)
        return 1;
    else
        return x * Fatorial(x-1);
}
long double Recursive(int x, int den, int cont, float aux, int termo){
    if(termo>=0){
        if(cont%2!=0)
            aux += ((pow(x,den))/Fatorial(den));
        else
            aux -= ((pow(x,den))/Fatorial(den));
        //std::cout<<std::to_string(aux)<<"\n";
        return Recursive(x, den+2, cont+1, aux, termo-1);
    }
    else
        return aux;
}
int main()
{
    int termo;
    float sen;
    std::cout<<"Infome o numero de termos: ";
    std::cin>>termo;
    std::cout<<"Infome o valor do sen(x): ";
    std::cin>>sen;
    std::cout<<"O sen(x) eh: ";
    std::cout<<std::to_string(Recursive(sen,1,1,0,termo));
    std::cout<<std::endl;
}
