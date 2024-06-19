#include <stdio.h>
#include <stdlib.h> //usar malloc

typedef struct {
    char nome[100];
    double valor;
} Produto;

int main(){
    Produto *produtos = malloc(sizeof(Produto) * 10); //aloca 10x o tamanho da struct(112 bytes)
    printf("sizeof(Produto): %d", (int)sizeof(Produto) * 10);
}