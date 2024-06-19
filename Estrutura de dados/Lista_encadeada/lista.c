#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info; // elemento da lista
	struct no *prox;
} t_no;

typedef struct lista {
	t_no *primeiro;
} t_lista;

void inicializarListaV1(t_lista *lista) {
  lista->primeiro = NULL;
}
t_lista inicializarListaV2() {
  t_lista lista = { .primeiro = NULL };
  return lista;
}

t_no *criar_no(int info) {
  t_no *novo_no = malloc(sizeof(t_no));
  if(novo_no) {
    novo_no->info = info;
    novo_no->prox = NULL;
  }
  return novo_no;
}

void Listar(t_lista *lista){
  t_no *aux = lista->primeiro;
  while(aux != NULL) {
    printf("(%d)->", aux->info);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void addInicio(t_lista *lista, int info){
  t_no *novo_no = criar_no(info);
  if(!lista->primeiro){            //lista vazia, add o nó        
    lista->primeiro = novo_no;
    return;
  }
  novo_no->prox = lista->primeiro; //novo nó aponta para o antigo 1° nó
  lista->primeiro = novo_no; //antigo 1° nó aponta para o novo nó
}

void addFim(t_lista *lista, int info){
  if(lista == NULL){    //!lista                        
    fprintf(stderr,"Erro: Lista nula!\n");
    return;
  }
  t_no *novo_no = criar_no(info);
  if(novo_no == NULL){
    fprintf(stderr,"Erro ao alocar memoria!\n");
    return;
  }
  if(!lista->primeiro){
    lista->primeiro = novo_no;
  }
  else{
    t_no *aux = lista->primeiro;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

void deletarInicio(t_lista *lista){
  if(!lista){                            
    fprintf(stderr,"Erro: Lista nula!\n");
    return;
  }
  if(!lista->primeiro){                            
    fprintf(stderr,"Erro: Lista nula!\n");
    return;
  }
  t_no *aux = lista->primeiro;  
  lista->primeiro = aux->prox;

  free(aux);
}

void deletarFim(t_lista *lista){
  if(!lista){                            
    fprintf(stderr,"Erro: Lista nula!\n");
    return;
  }
  if(!lista->primeiro){                            
    fprintf(stderr,"Erro: Lista nula!\n");
    return;
  }
  if(!lista->primeiro->prox){
    free(lista->primeiro);
    lista->primeiro = NULL;
  } else {
    t_no *aux = lista->primeiro;
    while(aux->prox->prox){
      aux = aux->prox;  
    }
    free(aux->prox);
    aux->prox = NULL; 
  }
}

int main(void) {
  t_lista lista = inicializarListaV2();
  addInicio(&lista, 5);
  addInicio(&lista, 3);
  addInicio(&lista, 4);
  addInicio(&lista, 2);
  Listar(&lista);
  deletarInicio(&lista);
  Listar(&lista);
  deletarFim(&lista);
  Listar(&lista);
  return 0;
}