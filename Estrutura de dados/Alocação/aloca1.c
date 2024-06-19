#include <stdio.h>
#include <stdlib.h>


float *medias_das_notas(int m, int n, float matriz[m][n]){
    float *media = malloc(sizeof(float) * m);
    for(int aluno = 0; aluno < m; aluno++){
        float soma = 0;
        for(int nota = 0; nota < n; nota++){
            soma += matriz[aluno][nota];
        }
        media[aluno] = soma/n;
    }
    return media;
}

void exibir( int n, float arr[n]){
    for(int i = 0; i < n; i++){
        printf("arr[%d]: %.2f\n", i, arr[i]);
    }
}

int main(){
    float mat[3][3] = {
        {7, 8, 9},
        {5, 6, 7},
        {4, 5, 6}
    };
    float *media = medias_das_notas(3, 3, mat);
    exibir(3, media);
    return 0;
}