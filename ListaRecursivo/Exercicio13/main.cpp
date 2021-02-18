#include<iostream>
#include<iomanip>
#include<recursivo13.h>

int main(void){
    int num1,num2,deno;
    ed1::recursivo13 objeto;
    num1=37;
    num2=38;
    deno=1;
    std::cout<<"S = "<<objeto.exrecursivo13(num1,num2,deno)<<std::endl;
}
