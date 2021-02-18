#include <iostream>
#include <iomanip>
#include <cmath>
double Recursive(double x, double y, double div, int cont){
    if(y>=10)
        return -1;
    else{
        if(cont%2==0){
            div+=x/y;
            Recursive(x,y+2,div,cont+1);
        }
        else{
            div-=x/y;
            Recursive(x,y+2,div,cont+1);
        }

    }
    return div;
}
int main()
{
    std::cout<<std::to_string(Recursive(4,1,0,0))<<std::endl;
}
