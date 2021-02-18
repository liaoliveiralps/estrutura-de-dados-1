#include<iostream>
#include<iomanip>
#include<soma.h>
int main(void){
    float num,deno;
    ed1::Soma objeto;
    num=1;
    deno=1;
    std::cout<<"S = "<<objeto.ImprimaSoma(num,deno)<<std::endl;
}
