#include "r12.h"
#include<math.h>
namespace ed1 {

int R12::exR12(float num, float deno,int r){
    if(deno>=1){
        return (pow(num,r))/deno + exR12(num,deno-1,r+1);
    }
}
}
