#include "recursivo8.h"
#include<iostream>
namespace ed1 {

int recursivo8::exrecursivo8(int num){
    if(num==0)
        return 0;
    else{
        if(num>0){
            exrecursivo8(num/2);
            std::cout<<num%2;
        }
    }
}
}
