#include "soma.h"

namespace ed1 {

int Soma::ImprimaSoma(float num, float deno){
       if(deno<=50){
          return num/deno + ImprimaSoma(num + 2, deno + 1);
       }
}
}
