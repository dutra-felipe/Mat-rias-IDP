#include <stdio.h>


void troca(int *x, int *y){ //recebe p1 e p2 e transforma pra x e y
    int aux = *x;
    *x = *y;
    *y = aux;
    printf("x = %d e y = %d\n", *x, *y);
}


int main(){
    int a = 5, b = 3;
    int *p1 = &a, *p2 = &b; //recebe o end de a e b
    troca(p1, p2); //envia p1 e p2 para função e recebe os novos valores
    printf("a = %d, b = %d", a, b);

    return 0;
}