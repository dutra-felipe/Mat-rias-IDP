#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10

typedef unsigned int uint;

typedef struct {
  int id;
  char nome[100];
  int idade;
  char genero;
} Pessoa;

typedef struct {
  uint size;
  uint limite;
  Pessoa *pessoas;
} Vetor;

void zerar(Vetor *vetor);
void inicializar(Vetor *vetor, int limite);
void inserirFim(Vetor *vetor, Pessoa p);
void listar(Vetor *vetor);


// Implemente as seguintes funções


void inserirInicio(Vetor *vetor, Pessoa p){ //check
    for(int i = vetor->size-1; i >= 0; i--){ 
        vetor -> pessoas[i+1] = vetor->pessoas[i]; 
    }
    vetor->size++; 
    vetor -> pessoas[0] = p; 
}

void inserirIndice(Vetor *vetor, int indice, Pessoa p){ //check
    if(indice < 0 || indice > vetor->size){
        printf("Indice invalido\n");
        return;
    }
    for(int i = vetor->size; i > indice; i--){ 
        vetor -> pessoas[i] = vetor->pessoas[i-1]; 
    }
    vetor -> pessoas[indice] = p; 
    vetor->size++; 
}

void inserirOrdenadoPorIdade(Vetor *vetor, Pessoa p){ //check
    int indiceInsercao = vetor->size;

    for (int i = 0; i < vetor->size; i++) { 
        if (p.idade < vetor->pessoas[i].idade) {  
            indiceInsercao = i;
            break;
        }
    }

    inserirIndice(vetor, indiceInsercao, p);  
}

void inserirOrdenadoPorNome(Vetor *vetor, Pessoa p){ //check
     int indiceInsercao = vetor->size;

    for (int i = 0; i < vetor->size; i++) {  
        if (strcmp(p.nome, vetor->pessoas[i].nome) < 0) {  
            indiceInsercao = i;
            break;
        }
    }

    inserirIndice(vetor, indiceInsercao, p);  
}

void deletarInicio(Vetor *vetor){ //check
    for(int i = 0; i < vetor->size - 1; i++){
        vetor->pessoas[i] = vetor->pessoas[i+1]; 
    };
    vetor -> size--; 
}

void deletarFim(Vetor *vetor){ //check
     vetor -> size--;
}

void deletarIndice(Vetor *vetor, int indice){ //check
     if(indice > vetor -> limite){
        printf("Posiçao invalida\n");
    }
    for (int i = indice; i < vetor->size - 1; i++) {
        vetor->pessoas[i] = vetor->pessoas[i + 1];
    }
    vetor->size--;
}

void deletarPorNome(Vetor *vetor, char *nome){ //check
    int indiceExclusao = -1;

    for (int i = 0; i < vetor->size; i++) {
        if (strcmp(vetor->pessoas[i].nome, nome) == 0) {  
            indiceExclusao = i;
            break;
        }
    }

    if (indiceExclusao != -1) {
        for (int i = indiceExclusao; i < vetor->size - 1; i++) {
            vetor->pessoas[i] = vetor->pessoas[i + 1];
        }
        vetor->size--;
    } 
    else {
        printf("Pessoa com nome %s não encontrada no vetor.\n", nome);
    }
}

void atualizarIndice(Vetor *vetor, int indice, Pessoa p){ //check
    if (indice < 0 || indice >= vetor->size) {
        printf("Índice inválido para atualização.\n");
        return;
    }

    vetor->pessoas[indice] = p;
}

void atualizarPorNome(Vetor *vetor, Pessoa p, char *nome){ //check
    int indiceAtualizacao = -1;

    for (int i = 0; i < vetor->size; i++) {
        if (strcmp(vetor->pessoas[i].nome, nome) == 0) {
            indiceAtualizacao = i;
            break;
        }
    }

    if (indiceAtualizacao != -1) {
        vetor->pessoas[indiceAtualizacao] = p;
    } 
    else {
        printf("Pessoa com nome %s não encontrada no vetor.\n", nome);
    }
}

int main(void) {
  Vetor vetor;
  inicializar(&vetor, 11);
  inserirFim(&vetor, (Pessoa){.id = 1, .nome = "Ana", .idade = 25, .genero = 'F'});
  inserirFim(&vetor, (Pessoa){2, "Beto", 25, 'M'});
  inserirFim(&vetor, (Pessoa){3, "Caio", 25, 'M'});
  inserirFim(&vetor, (Pessoa){4, "Dani", 25, 'F'});
  inserirFim(&vetor, (Pessoa){5, "Fabio", 25, 'M'});
  inserirFim(&vetor, (Pessoa){6, "Gabi", 25, 'F'});

  listar(&vetor);
  return 0;
}

void inicializar(Vetor *vetor, int limite) {
  vetor->size = 0; // (*vetor).size = 0;
  vetor->limite = limite;
  vetor->pessoas = malloc(sizeof(Pessoa) * limite);
}

void inserirFim(Vetor *vetor, Pessoa p) {
  // restrição da função
  if(vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  vetor->pessoas[vetor->size] = p;
  vetor->size++;
}

void listar(Vetor *vetor) {
  for(int i = 0; i < vetor->size; i++) {
    printf("Pessoa %d: (id: %d, nome: %s, idade: %d, genero: %c)\n"
            , i
            , vetor->pessoas[i].id
            , vetor->pessoas[i].nome
            , vetor->pessoas[i].idade
            , vetor->pessoas[i].genero
    );
  } 
}

void zerar(Vetor *vetor) {
  vetor->size = 0;
}