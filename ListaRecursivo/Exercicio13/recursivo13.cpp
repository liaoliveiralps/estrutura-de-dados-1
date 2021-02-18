#include "recursivo13.h"

namespace ed1 {

int recursivo13::exrecursivo13(int num1, int num2, int deno){
    if(deno<=37)
        return (num1*num2)/deno + exrecursivo13(num1-1,num2-1,deno+1);
}
}
