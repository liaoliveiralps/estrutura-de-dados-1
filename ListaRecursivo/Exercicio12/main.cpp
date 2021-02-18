#include<iostream>
#include<iomanip>
#include<r12.h>

int main(void){
    float num,deno;
    int r;
    ed1::R12 objeto;
    num=2;
    deno=50;
    r=1;
    std::cout<<"S = "<<objeto.exR12(num,deno,r)<<std::endl;

}
