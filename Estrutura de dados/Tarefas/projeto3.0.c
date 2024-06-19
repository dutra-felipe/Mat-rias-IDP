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

t_lista inicializarLista() {
    t_lista lista = { .primeiro = NULL, .ultimo = NULL, .size = 0 };
    return lista;
}

t_no *criar_no(t_lista *lista, int valor) {
    t_no *novo_no = malloc(sizeof(t_no));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    lista->size++;
    return novo_no;
}

void inserirInicio(t_lista *lista, int valor) {
    t_no *novo_no = criar_no(lista, valor);
    if (!lista->primeiro) {
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
        return;
    }
    novo_no->prox = lista->primeiro; //novo no aponta para o primeiro antigo
    lista->primeiro = novo_no;  //primeiro aponta para o primeiro novo
}

void inserirFim(t_lista *lista, int valor) {
    t_no *novo_no = criar_no(lista, valor);
    if (!lista->primeiro) {
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
        return;
    }
    lista->ultimo->prox = novo_no; //proximo depois do ultimo
}

void inserirOrdenado(t_lista *lista, int valor){
    t_no *novo_no = criar_no(lista, valor);
    if (!lista->primeiro) {
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
        return;
    }
    t_no *atual = lista->primeiro;
    t_no *anterior = NULL;
    
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL) { //insere no início
        novo_no->prox = lista->primeiro;
        lista->primeiro = novo_no;
    } else {
        anterior->prox = novo_no;
        if (atual == NULL) {
            lista->ultimo = novo_no;
        } else {
            novo_no->prox = atual;
        }
    }
}

void deletarInicio(t_lista *lista){
     if (lista->size == 0) {
        return;
    }
    t_no *no_a_deletar = lista->primeiro;
    lista->primeiro = no_a_deletar->prox;
    free(no_a_deletar);
    lista->size--;
}

void deletarFim(t_lista *lista){
    if (lista->size == 0) {
        return;
    }
    t_no *no_a_deletar = lista->ultimo;
    t_no *no_anterior = lista->primeiro;

    while (no_anterior->prox != no_a_deletar) {
        no_anterior = no_anterior->prox;
    }
    no_anterior->prox = NULL;
    free(no_a_deletar);
    lista->size--;
}

void listar(t_lista *lista) {
    t_no *atual = lista->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    t_lista lista = inicializarLista();
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirFim(&lista, 40);
    inserirOrdenado(&lista, 35);
    listar(&lista);
    deletarInicio(&lista);
    listar(&lista);
    deletarFim(&lista);
    listar(&lista);
    return 0;
}