#include <stdio.h>
#include <stdlib.h>

#define OFFSET 100

typedef unsigned int uint;

typedef struct{
    char nome[200];
    char categorias[200];
    char tamanho[200];
    int quantidade;
    float preco;
} Compra;

typedef struct{
    uint size;
    uint limite;
    Compra *compras;
} Vetor;

FILE *arquivo;  // Declara um ponteiro para um arquivo

void abrirArquivo(const char *nomeArquivo);
void fecharArquivo();
void salvarArquivo(Vetor *vetor);
void carregarArquivo(Vetor *vetor);

void zerar(Vetor *vetor);
void inicializar(Vetor *vetor, int limite);
void inserirFim(Vetor *vetor, Compra p);
void listar(Vetor *vetor);

//Funções 

void inserirInicio(Vetor *vetor, Compra c){
    if (vetor->size >= vetor->limite) {
        vetor->compras = realloc(vetor->compras, OFFSET);
    }
    for(int i = vetor->size-1; i >= 0; i--){ 
        vetor -> compras[i+1] = vetor->compras[i]; 
    }
    vetor->size++; 
    vetor -> compras[0] = c; 
}

void inserirIndice(Vetor *vetor, int indice, Compra c){ 
    if(indice < 0 || indice > vetor->size){
        printf("Indice invalido\n");
        return;
    }
    if (vetor->size >= vetor->limite) {
        vetor->compras = realloc(vetor->compras, OFFSET);
    }
    for(int i = vetor->size; i > indice; i--){ 
        vetor -> compras[i] = vetor->compras[i-1]; 
    }
    vetor -> compras[indice] = c; 
    vetor->size++; 
}

void inserirOrdenadoPorNome(Vetor *vetor, Compra c){ 
    if (vetor->size >= vetor->limite) {
        vetor->compras = realloc(vetor->compras, OFFSET);
    }
    int indiceInsercao = vetor->size;

    for (int i = 0; i < vetor->size; i++) {  
        if (strcmp(c.nome, vetor->compras[i].nome) < 0) {  
            indiceInsercao = i;
            break;
        }
    }

    inserirIndice(vetor, indiceInsercao, c);  
}
void deletarInicio(Vetor *vetor){ 
    for(int i = 0; i < vetor->size - 1; i++){
        vetor->compras[i] = vetor->compras[i+1]; 
    };
    vetor -> size--; 
}

void deletarFim(Vetor *vetor){
     vetor -> size--;
}

void deletarIndice(Vetor *vetor, int indice){
     if(indice > vetor -> limite){
        printf("Posiçao invalida\n");
    }
    for (int i = indice; i < vetor->size - 1; i++) {
        vetor->compras[i] = vetor->compras[i + 1];
    }
    vetor->size--;
}

void deletarPorNome(Vetor *vetor, char *nome){ 
    int indiceExclusao = -1;

    for (int i = 0; i < vetor->size; i++) {
        if (strcmp(vetor->compras[i].nome, nome) == 0) {  
            indiceExclusao = i;
            break;
        }
    }

    if (indiceExclusao != -1) {
        for (int i = indiceExclusao; i < vetor->size - 1; i++) {
            vetor->compras[i] = vetor->compras[i + 1];
        }
        vetor->size--;
    } 
    else {
        printf("Pessoa com nome %s não encontrada no vetor.\n", nome);
    }
}

void atualizarIndice(Vetor *vetor, int indice, Compra c){ 
    if (indice < 0 || indice >= vetor->size) {
        printf("Índice inválido para atualização.\n");
        return;
    }

    vetor->compras[indice] = c;
}

void atualizarPorNome(Vetor *vetor, Compra c, char *nome){ 
    int indiceAtualizacao = -1;

    for (int i = 0; i < vetor->size; i++) {
        if (strcmp(vetor->compras[i].nome, nome) == 0) {
            indiceAtualizacao = i;
            break;
        }
    }

    if (indiceAtualizacao != -1) {
        vetor->compras[indiceAtualizacao] = c;
    } 
    else {
        printf("Pessoa com nome %s não encontrada no vetor.\n", nome);
    }
}

int main(){
    Vetor vetor;
    abrirArquivo("C:\\Users\\55619\\Documents\\Lista\\Lista de Compras.txt");
    inicializar(&vetor, 50);
    inserirFim(&vetor, (Compra){.nome = "Arroz", .categorias = "Alimento", .tamanho = "2Kg", .quantidade = 2, .preco = 11});
    inserirFim(&vetor, (Compra){"Refri", "Bebida", "1,5L", 2, 5});
    inserirFim(&vetor, (Compra){"Milho", "Alimento", "0,5Kg", 2, 3.5});
    inserirFim(&vetor, (Compra){"Escova", "Higiene", "1", 1, 2.0});
    inserirFim(&vetor, (Compra){"Bucha", "Limpeza", "6", 6, 14.29});
    inserirFim(&vetor, (Compra){"Atum", "Alimento", "0,4Kg", 1, 35.45});
    salvarArquivo(&vetor);
    fecharArquivo();
   
    //listar(&vetor);
    return 0;
}
void inicializar(Vetor *vetor, int limite) {
  vetor->size = 0; // (*vetor).size = 0;
  vetor->limite = limite;
  vetor->compras = malloc(sizeof(Compra) * limite);
}

void inserirFim(Vetor *vetor, Compra c) {
  // restrição da função
  if(vetor->size >= vetor->limite) {
    vetor->compras = realloc(vetor->compras, OFFSET);
  }
  vetor->compras[vetor->size] = c;
  vetor->size++;
}

void listar(Vetor *vetor) {
  for(int i = 0; i < vetor->size; i++) {
    printf("Item %d: (Nome: %s, Categoria: %s, Tamanho: %s, Qtd: %d, Preco: %.2f)\n"
            , (i+1)
            , vetor->compras[i].nome
            , vetor->compras[i].categorias
            , vetor->compras[i].tamanho
            , vetor->compras[i].quantidade
            , vetor->compras[i].preco
    );
  } 
}

void zerar(Vetor *vetor) {
  vetor->size = 0;
}

void abrirArquivo(const char *nomeArquivo) {
    arquivo = fopen(nomeArquivo, "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
}

void fecharArquivo() {
    if (arquivo != NULL) {
        fclose(arquivo);
    }
}

void salvarArquivo(Vetor *vetor) { //escrever
    if (arquivo != NULL) {
        rewind(arquivo);  // Volte para o início do arquivo

        // Escreva cabeçalhos da tabela
        fprintf(arquivo, "%-13s %-13s %-10s %-15s %-15s\n\n", "Nome", "Categoria", "Tamanho", "Quantidade", "Preço");
        
        for (int i = 0; i < vetor->size; i++) {
            fprintf(arquivo, "%-13s %-13s %-15s %-10d %-15.2f\n",
                vetor->compras[i].nome,
                vetor->compras[i].categorias,
                vetor->compras[i].tamanho,
                vetor->compras[i].quantidade,
                vetor->compras[i].preco
            );
        }
    } else {
        printf("Arquivo não está aberto para salvar.\n");
    }
}

void carregarArquivo(Vetor *vetor) {
    if (arquivo != NULL) {
        rewind(arquivo);  // Volte para o início do arquivo

        while (fscanf(arquivo, "%199[^,],%199[^,],%199[^,],%d,%f\n",
            vetor->compras[vetor->size].nome,
            vetor->compras[vetor->size].categorias,
            vetor->compras[vetor->size].tamanho,
            &vetor->compras[vetor->size].quantidade,
            &vetor->compras[vetor->size].preco) == 5) {
            vetor->size++;
        }
    } else {
        printf("Arquivo não está aberto para carregar.\n");
    }
}
