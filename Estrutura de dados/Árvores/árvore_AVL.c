#include <stdio.h>
#include <stdlib.h>

struct No {
  int dado;
  struct No *dir, *esq;
  int altura;
};
typedef struct No No;

/* Altura da árvore, definição recursiva:
  h(no) = MAX(h(no->esq), h(no->dir)) + 1, no != NULL, -> passo recursivo
                                       -1, no == NULL  -> critério de parada
*/
// FB(no) = -2 e FB(no->dir) = -1, FB(no->dir->dir) = 0
int max(int a, int b){
  return(a > b) ? a : b;
}

int altura(No *no){
  if(no == NULL) return -1;
  no->altura = max(altura(no->esq), altura(no->dir)) + 1;
  return no->altura;
}

No *rotacao_esq(No *raiz) {
  No *aux = raiz->dir;
  raiz->dir = aux->esq;
  aux->esq = raiz;
 
  altura(aux);
  
  return aux;
}

No *rotacao_dir(No *raiz) {
  No *aux2 = raiz->esq;
  raiz->esq = aux2->dir;
  aux2->dir = raiz;

  altura(aux2);

  return aux2;
}

No *rotacao_esq_dir(No *raiz) {
  raiz->esq = rotacao_esq(raiz->esq);
  return rotacao_dir(raiz);
}

No *rotacao_dir_esq(No *raiz) {
  raiz->dir = rotacao_dir(raiz->dir);
  return rotacao_esq(raiz);
}

No *inserir(No *raiz, int dado){
  if(raiz == NULL){
    No *novo_no = malloc(sizeof(No));
    novo_no->dado = dado;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->altura = 0;
    return novo_no;
  }

  // realizar inserção em uma árvore de busca binária (BST)
  if(dado < raiz->dado){
    raiz->esq = inserir(raiz->esq, dado);
  }
  else if(dado > raiz->dado){
    raiz->dir = inserir(raiz->dir, dado);
  }
  else{
    return raiz;
  }
  
  // atualiza altura
  altura(raiz);
  
  // realiza balancemanento
  int fb = raiz->esq->altura - raiz->dir->altura;
  if(fb > 1 && dado < raiz->esq->dado){
    return rotacao_dir(raiz);
  }
  if(fb < -1 && dado > raiz->dir->dado){
    return rotacao_esq(raiz);
  }
  if(fb > 1 && dado > raiz->esq->dado){
    return rotacao_esq_dir(raiz);
  }
  if(fb < -1 && dado < raiz->dir->dado){
    return rotacao_dir(raiz);
  }    
  return raiz;
}

int main() {
  printf("Hello World\n");
  return 0;
}