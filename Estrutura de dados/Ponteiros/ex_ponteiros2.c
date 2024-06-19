#include <stdio.h>

int main(){
     
   int a, b, *c;
   a = 0;
   b = 3;
   c = &a;
   *c = *c + 1;
   c = &b;
   b = b + 4;
   *c = a;

   printf("%d %d %d", a, b, *c);

    return 0;
}