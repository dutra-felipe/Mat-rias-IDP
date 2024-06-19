#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} t_no;

typedef struct {
    t_no *topo;
} t_pilha;

int top(t_pilha *pilha){
    if (pilha->topo == NULL) {
        fprintf(stderr,"Erro: Lista nula!\n");
        return;
    } else {
        printf("%d",pilha->topo->valor);
        return;
    }
}

void push(t_pilha *pilha, int valor){
    t_no *novo_no = malloc(sizeof(t_no));
    novo_no->valor = valor; //valor do no
    novo_no->prox = pilha->topo; //proximo no aponta para o topo -> (NULL)
    pilha->topo = novo_no;  //topo aponta para o novo no
}

int deleta(t_pilha *pilha){
     if (pilha->topo == NULL) {
        fprintf(stderr,"Erro: Lista nula!\n");
        return;
    } else {
        int valor = pilha->topo->valor; //atribui valor ao topo da pilha
        t_no *no_a_ser_deletado = pilha->topo; //ponteiro para o topo que será deletado
        pilha->topo = pilha->topo->prox; //novo topo = 2°
        free(no_a_ser_deletado); //deleta o 1°
        printf("%d", valor);
        return;
    }
}

int main(){
    return 0;
}