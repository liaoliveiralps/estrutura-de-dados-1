#include <iostream>

int Recursive(int num, int aux){
    int array[5];
    array[0]=10;
    array[1]=2;
    array[2]=3;
    array[3]=4;
    array[4]=5;
    if(num==0)
       aux = array[0];
    num++;
    if(num!=5){
        if(array[num]<aux){
            aux=array[num];
            Recursive(num,aux);
        }
        else
            Recursive(num,aux);
    }
    return aux;
}
int main()
{
    std::cout<<"Menor numero eh: "<<Recursive(0, 0)<<std::endl;
}
