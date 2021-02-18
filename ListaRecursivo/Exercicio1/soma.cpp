#include "soma.h"
namespace lia{
long unsigned int Soma::somaR(unsigned int x){
    if(x == 0 || x ==1)
        return 1;
    else
        return x + somaR(x-1);
}

long unsigned int Soma::somaI(unsigned int x){
    long unsigned int fator=0;
    for(long unsigned int counter=x; counter>=1; counter--)
        fator+=counter;

    return fator;
}
}
