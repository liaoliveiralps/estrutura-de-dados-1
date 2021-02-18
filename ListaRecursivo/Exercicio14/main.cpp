#include<iostream>
#include<iomanip>
#include<recursivo14.h>

int main (void){
    float num;
    int n,deno;
    ed1::Recursivo14 objeto;
    num=1;
    deno=1;
    n=3;
    std::cout<<"S = "<<objeto.exRecursivo14(num,deno,n)<<std::endl;
}
