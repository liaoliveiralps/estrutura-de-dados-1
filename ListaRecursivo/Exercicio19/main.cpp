#include <iostream>
#include <iomanip>

int Recursive(int n){
    if(n==1 or n==2)
        return 1;
    else
        return Recursive(n-1)+Recursive(n-2);
}
int main()
{
    for(int i=1; i<=20; i++)
        std::cout<<Recursive(i)<<" ";
}
