#include <iostream>
#include <iomanip>
#include <cmath>

int Fatorial(int x){
    if(x == 0 || x ==1)
        return -1;
    else
        return x * Fatorial(x-1);
}
int Recursive(int x, int aux, int div){
    if(x==aux)
        return div;
    else{
       div += (pow(x,aux))/Fatorial(aux);
       return Recursive(x,aux+1,std::abs(div));
    }
}

int main()
{
    int x;
    std::cout<<"Informe o valor de x: ";
    std::cin>>x;
    std::cout<<"e^x = "<<Recursive(x,1,0)<<std::endl;
}
