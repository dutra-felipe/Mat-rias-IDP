#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} t_no;

typedef struct {
    t_no *primeiro;
    t_no *ultimo;
    int size;
} t_lista;

void enfileira(t_lista *lista, int valor) {
    t_no *novo_no = malloc(sizeof(t_no));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    if (lista->primeiro == NULL) {  //se tiver vazio, novo no é o primeiro
        lista->primeiro = lista->ultimo = novo_no;
    } 
    lista->ultimo->prox = novo_no;
    lista->ultimo = novo_no;
    lista->size++;
}

int desenfileira(t_lista *lista) {
    if (lista->primeiro == NULL) {
        fprintf(stderr,"Erro: Lista nula!\n");
        return;
    } else {
        int valor = lista->primeiro->valor;
        t_no *no_a_ser_deletado = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
        free(no_a_ser_deletado);
        lista->size--;
        printf("%d", valor);
        return;
    }
}

int main(){
    return 0;
}