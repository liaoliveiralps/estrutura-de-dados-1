#include "cubo.h"
#include <math.h>
namespace lia{
long unsigned int Cubo::cuboRecursive(unsigned int x){
    if(x == 0 || x ==1)
        return 1;
    else
        return std::pow(x,3) + cuboRecursive(x-1);
}

long unsigned int Cubo::cuboIterative(unsigned int x){
    long unsigned int fator=0;
    for(long unsigned int i=1; i<=x; i++){
        fator += std::pow(i,3);
    }
    return fator;
}
}
