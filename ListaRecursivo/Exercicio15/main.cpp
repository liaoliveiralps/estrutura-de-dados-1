#include <iostream>

float Recursive(float num, float den, float aux){
    if(num>=0){
        aux += num/den;
        return Recursive(num-3,den+1,aux);
    }
    return aux;
}
int main()
{
    std::cout<<"A soma eh: "<<std::to_string(Recursive(1000,1,0));
    std::cout<<std::endl;
}
