#include <stdio.h>

int soma(int x, int y){
    int z = x + y;
    return z;
}

int main(){
    int n1 = 5, n2 = 9, s;
    s = soma(n1, n2);
    printf("%d", s);
    return 0;
}