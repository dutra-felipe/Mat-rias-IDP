#include <stdio.h>

int main(){
    int n = 3;
    int lista[] =  {3,1,5};
    int valor = 3;

    for(int i = 0; i < n; i++){
        if(lista[i] == valor){
            puts("Valor encontrado");
            break;
        }
    }
    return 0;
}
