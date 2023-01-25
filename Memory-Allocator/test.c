#include "allocator.h"

int main(){
   int * why = calloc(4,sizeof(int));

   if(!why){
       exit(10);
   }
}