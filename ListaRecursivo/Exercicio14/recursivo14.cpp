#include "recursivo14.h"
namespace ed1 {

float Recursivo14::exRecursivo14(float num, int deno, int n){
    int S=0;
   if(deno<=100){
       S=num/deno - exRecursivo14(num + 1,deno + n,n+2);
       if(deno%2==0){
           S+= exRecursivo14(num + 1,deno + n,n+2);
        }
        else{
             S-= exRecursivo14(num + 1,deno + n,n+2);

       }
   }
   return S;
}
}
