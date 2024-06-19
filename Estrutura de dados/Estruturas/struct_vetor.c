#include <stdio.h>
#include <stdlib.h>

#define LIMITE 10
typedef unsigned int uint; //redefine unsigned int

typedef struct {
    char nome[100];
    int idade;
    char genero;
} Pessoa;

typedef struct {
    uint size;
    uint limite;
    Pessoa pessoas[LIMITE];
} Vetor;

void inicializar(Vetor *vetor, int limite){ 
    vetor -> size = 0; //(*vetor).size é equivalente 
    if(limite > LIMITE){
        fprintf(stderr, "Limite invalido\n"); //saida pelo console de erros
        exit(0);
    }
    vetor->limite = limite;
}

void inserirInicio(Vetor *vetor, Pessoa p){
    for(int i = vetor->size-1; i >= 0; i--){ //percorre de (size - 1) até 0
        vetor -> pessoas[i+1] = vetor->pessoas[i]; //ocupa a posição seguinte
    }
    vetor->size++; 
    vetor -> pessoas[0] = p; //ocupa o início = 0
}

void inserirFim (Vetor *vetor, Pessoa p){
    if(vetor -> size >= vetor -> limite){ //compara o tamanho da lista com o limite
        printf("Lista cheia\n");
        return;
    }
    vetor -> pessoas[vetor->size] = p; //ocupa o final
    vetor -> size++;
}

void excluirInicio(Vetor *vetor){
    for(int i = 0; i < vetor->size - 1; i++){
        vetor->pessoas[i] = vetor->pessoas[i+1]; //copia a pessoa da frente para a anterior
    };
    vetor -> size--; 
}

void excluirFinal(Vetor *vetor){
    vetor -> size--;
}

void excluiIndice (Vetor *vetor, int posicao){
    if(posicao > vetor -> limite){
        printf("Posiçao invalida\n");
    }
    for(int i = 0; i < vetor -> size-1; i++){
        vetor -> pessoas[posicao] = vetor->pessoas[i+1];
    }
    vetor -> size--;
}

void listar(Vetor *vetor){
    for(int i = 0; i < vetor -> size; i++){
        printf("Pessoa %d: %s ", i, vetor->pessoas[i].nome); //percorre a lista
    }
}

int main(){
    Vetor vetor;
    inicializar(&vetor, 5);
    inserirFim(&vetor, (Pessoa){.nome = "Ana\n", .idade = 25, .genero = "F"});
    inserirFim(&vetor, (Pessoa){.nome = "Beto\n", .idade = 25, .genero = "M"});
    inserirFim(&vetor, (Pessoa){.nome = "Caio\n", .idade = 25, .genero = "M"});
    inserirFim(&vetor, (Pessoa){.nome = "David\n", .idade = 25, .genero = "M"});
    inserirFim(&vetor, (Pessoa){.nome = "Fabio\n", .idade = 25, .genero = "M"});
    listar(&vetor);
    printf("----------\n");

    inserirInicio(&vetor, (Pessoa){.nome = "Gabriel\n", .idade = 25, .genero = "M"});
    listar(&vetor);
    printf("----------\n");

    excluirInicio(&vetor);
    listar(&vetor);
    printf("----------\n");

    excluirFinal(&vetor);
    listar(&vetor);
    printf("----------\n");

    excluiIndice(&vetor, 2);
    listar(&vetor);
    printf("----------\n");

    return 0;
}