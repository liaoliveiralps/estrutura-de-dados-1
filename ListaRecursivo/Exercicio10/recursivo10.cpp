#include "recursivo10.h"

namespace ed1 {

long double Recursivo10::exRecursivo10(float N1, float N2){
    if(N2==0)
        return 0;
    else{
       if(N2!=0){
       return N1 + exRecursivo10(N1, N2 - 1);
       }
    }
}
}
