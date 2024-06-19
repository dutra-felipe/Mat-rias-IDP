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

//Escreva a função int altura(t_no *raiz); - que calcula e retorna a altura máxima de uma árvore binária
int altura(t_no *raiz){
    if(raiz == NULL){
        return 0;
    }
    int altura_esquerda = altura(raiz->esq);
    int altura_direita = altura(raiz->dir);

    if (altura_direita > altura_esquerda) {
      altura_esquerda = altura_direita;
    }
    return altura_esquerda + 1;
}

/*Escreva a função t_no *menor_ancestral_comum(t_no *raiz, int v1, int v2); - que
retorna o nó contendo menor ancestral comum entre os valores v1 e v2.*/
t_no *menor_ancestral_comum(t_no *raiz, int v1, int v2){
  if(raiz == NULL){
    return 0;
  }
  if (raiz->valor == v1 || raiz->valor == v2) {
        return raiz;
    }

  t_no *ancestral_esquerda = menor_ancestral_comum(raiz->esq, v1, v2);
  t_no *ancestral_direita = menor_ancestral_comum(raiz->dir, v1, v2);

  if (ancestral_esquerda != NULL && ancestral_direita != NULL) {
    return raiz;
  }

  return (ancestral_esquerda != NULL) ? ancestral_esquerda : ancestral_direita;
}

//Escreva a função void deletar_no(t_no **raiz, int valor);
void deletar_no(t_no **raiz, int valor) {
    if (*raiz == NULL) {
        return;
    }

    if ((*raiz)->valor == valor) {
        free(*raiz);
        *raiz = NULL; 
        return;
    }
    deletar_no(&((*raiz)->esq), valor);
    deletar_no(&((*raiz)->dir), valor);
}

//Escreva a função exibir_por_nivel(t_no *raiz);
void exibir_por_nivel(t_no *raiz) {
    if (raiz == NULL) {
        return;
    }
    t_no *fila[100];  
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;  

    while (inicio < fim) {
        t_no *no_atual = fila[inicio++];  
        printf("%d ", no_atual->valor);

        if (no_atual->esq) {
            fila[fim++] = no_atual->esq;
        }
        if (no_atual->dir) {
            fila[fim++] = no_atual->dir;
        }
    }
}
