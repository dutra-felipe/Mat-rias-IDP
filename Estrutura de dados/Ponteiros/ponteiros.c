#include <stdio.h>

int main(){
     
    int numero = 3;

    printf("%d\n", numero);
    
    int *p = &numero; //int *p; p = &numero; recebe o endereço de numero
    *p = 5; //acessa o end de numero e muda o valor

    printf("%i", numero);

    return 0;
}