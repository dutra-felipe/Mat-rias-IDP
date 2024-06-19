#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *direito;
    struct No *esquerdo;
    int valor
} t_no;

typedef struct No novo_no;

novo_no *criar_no (int valor){
    novo_no *no = malloc (sizeof(novo_no));
    no->direito = NULL;
    no->esquerdo = NULL;
    no->valor = valor;
    return no;
}

void listar(novo_no *no){
    if(no == NULL){
        return;
    }
    printf("\n%d",no->valor);
    listar(no->esquerdo);
    listar(no->direito);

}
int main(){
    novo_no *no5 = criar_no(5);
    novo_no *no2 = criar_no(2);
    novo_no *no1 = criar_no(1);
    novo_no *no8 = criar_no(8);
    novo_no *no4 = criar_no(4);

   no5->esquerdo = no2;
   no2->esquerdo = no1;
   no5->direito = no8;
   no2->direito = no4; 
   listar(no5);
    return 0;
}