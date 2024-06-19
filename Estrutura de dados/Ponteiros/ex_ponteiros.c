#include <stdio.h>

int main(){

    int n1 = 3, n2 = 5;

    int *p_n1, *p_n2, aux; // * serve para acessar, modificar ou trocar os dados de outra variável!!!!

    p_n1 = &n1; p_n2 = &n2; //recebe o end de n1 e n2

    aux = *p_n2; //aux = n2
    *p_n2 = *p_n1; //n2 = n1
    *p_n1 = aux; //n1 = aux(valor anterior de n2)
    

    printf("n1: %i, n2: %i", n1, n2);
    return 0;
}