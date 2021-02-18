#include "Fatorial.h"
namespace ED1{
long unsigned int Fatorial::fatorialRecursive(unsigned int x){
    if(x == 0 || x ==1)
        return 1;
    else
        return x * fatorialRecursive(x-1);
}

long unsigned int Fatorial::fatorialIterative(unsigned int x){
    long unsigned int fator=1;
    for(long unsigned int counter=x; counter >= 1; counter--)
        fator*=counter;

    return fator;
}
}
