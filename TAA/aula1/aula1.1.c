//MAIOR e MENOR
#include <stdio.h>
#include <stdint.h> 

int main(){

    int lista[] =  {80,127,32,17,55,51,46,14,18,70};
    int maior = lista[0], menor = INT32_MAX; //menor = lista[0]

    for(int i = 0; i < 10; i++){
        if(lista[i] > maior){
            maior = lista[i];
        }
        else if(lista[i] < menor){
            menor = lista[i];
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
