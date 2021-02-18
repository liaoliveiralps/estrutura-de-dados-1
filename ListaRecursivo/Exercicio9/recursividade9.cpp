#include "recursividade9.h"

namespace ed1 {

long double recursividade9::exrecursividade9(float x, int y){
    if(y==0)
        return 1;
    else{
        if(y>0){
            return x * exrecursividade9(x,y-1);
        }

    }
}
}
