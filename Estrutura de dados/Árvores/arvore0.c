#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  struct No *esq;
  struct No *dir;
  char valor;
} t_no;

void inicializarArvore(t_no *raiz) {
  if(!raiz) {
    fprintf(stderr, "Raiz inválida!\n");
    return;
  }
  raiz->esq = NULL;
  raiz->dir = NULL;
  raiz->valor = '\0';
}

t_no *criarNo(char valor) {
  t_no *no = malloc(sizeof(t_no));
  if(no) {
    no->esq = NULL;
    no->dir = NULL;
    no->valor = valor;
  }
  return no;
}

void exibir_pre_ordem(t_no *raiz) {
  if(raiz) {
    printf("%c ", raiz->valor);
    exibir_pre_ordem(raiz->esq);
    exibir_pre_ordem(raiz->dir);
  }
}

void exibir_in_ordem(t_no *raiz) {
  if(raiz) {
    exibir_in_ordem(raiz->esq);
    printf("%c ", raiz->valor);
    exibir_in_ordem(raiz->dir);
  }
}

void exibir_pos_ordem(t_no *raiz) {
  if(raiz) {
    exibir_pos_ordem(raiz->esq);
    exibir_pos_ordem(raiz->dir);
    printf("%c ", raiz->valor);
  }
}

int main(void) {
  t_no raiz;
  inicializarArvore(&raiz);
  raiz.valor = 'A';
  raiz.esq = criarNo('B');
  raiz.dir = criarNo('C');
  if(raiz.esq) {
    raiz.esq->esq = criarNo('D');
  }
  if(raiz.dir) {
    raiz.dir->esq = criarNo('E');
    raiz.dir->dir = criarNo('F');
  }
  if(raiz.dir->esq){
    raiz.dir->esq->dir = criarNo('G');
  }
  if(raiz.dir->dir){
    raiz.dir->dir->esq = criarNo('H');
    raiz.dir->dir->dir = criarNo('I');
  }
  exibir_in_ordem(&raiz);
  return 0;
}