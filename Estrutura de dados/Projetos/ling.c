#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint; //redefine unsigned int

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[100];
    char tecnologia_utilizada[100];
    int dificuldade; 
    Data t_dataInicio, t_dataTermino;
} Projeto;

typedef struct {
    uint size;
    uint limite;
    Projeto p[20];
} Vetor;

void inicializar(Vetor *vetor, int limite){ 
    vetor -> size = 0; 
    if(limite > 20){
        fprintf(stderr, "Limite invalido\n"); //saida pelo console de erros
        exit(0);
    }
    vetor->limite = limite;
}

void ler_projeto(Projeto *linguagem){
    printf("Digite o nome do projeto: ");
    scanf("%[^\n]", linguagem->nome);
    printf("Digite a dificuldade (0 a 10): ");
    scanf("%d%*c", &linguagem->dificuldade);
    printf("Digite o nome da tecnologia utilizada: ");
    scanf("%[^\n]", linguagem->tecnologia_utilizada);
    printf("Digite a data de inicio no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d", &linguagem->t_dataInicio.dia, &linguagem->t_dataInicio.mes, &linguagem->t_dataInicio.ano);
    printf("Digite a data de termino no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d%*c", &linguagem->t_dataTermino.dia, &linguagem->t_dataTermino.mes, &linguagem->t_dataTermino.ano);
}
void inserirFim (Vetor *vetor, Projeto linguagem){
    if(vetor -> size >= vetor -> limite){ //compara o tamanho da lista com o limite
        printf("Lista cheia\n");
        return;
    }
    vetor -> p[vetor->size] = linguagem; //ocupa o final
    vetor -> size++;
}
void listar(Vetor *vetor){
    for(int i = 0; i < vetor -> size; i++){
        printf("Projeto %d: %s\nDificuldade: %d\nTecnologia(s): %s\n", i, vetor->p[i].nome, vetor->p[i].dificuldade, vetor->p[i].tecnologia_utilizada); 
    }
}

int main(){
    Vetor vetor;
    inicializar(&vetor, 20);
    Projeto html, javascript;
    ler_projeto(&html);
    inserirFim(&vetor, html);
    ler_projeto(&javascript);
    inserirFim(&vetor, javascript);
    listar(&vetor);
    return 0;
}