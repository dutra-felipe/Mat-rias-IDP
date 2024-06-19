#include <stdio.h>

typedef struct Data{
        int dia, ano;
        char mes[12];
    } t_data;
typedef struct Pessoa {
        char nome[100];
        int idade;
        float salario;
        struct Data data_nasc; //struct dentro de outra struct
    } t_pessoa;

int main(){
    
    t_pessoa p1; t_data *data_p1 = &p1.data_nasc;

    //usando p1
    printf("Idade: ");
    scanf("%d%*c", &p1.idade); //limpa o \n
    
    printf("Nome: ");
    scanf("%[^\n]", p1.nome); //lê tudo exceto o \n
    
    printf("Salario: ");
    scanf("%f", &p1.salario);

    printf("Nascimento: "); //lê tudo exceto o '/'
    scanf("%d/%[^/]/%d", &p1.data_nasc.dia, p1.data_nasc.mes, &p1.data_nasc.ano);
    
    //saída usando o p1
    printf("Nome: %s", p1.nome);
    printf("\nIdade: %d", p1.idade);
    printf("\nSalario: %.2f", p1.salario); 
    printf("\nData: (%d/%s/%d)", p1.data_nasc.dia, p1.data_nasc.mes, p1.data_nasc.ano);

    //saída usando ponteiro
    printf("\nNascimento: "); 
    scanf("%d/%[^/]/%d", &data_p1->dia, &data_p1->mes, &data_p1->ano); //'->' acessa o end da variável

    printf("Nome: %s", p1.nome);
    printf("\nIdade: %d", p1.idade);
    printf("\nSalario: %.2f", p1.salario); 
    printf("\nData: (%d/%s/%d)", data_p1->dia, data_p1->mes, data_p1->ano);

    return 0;
}