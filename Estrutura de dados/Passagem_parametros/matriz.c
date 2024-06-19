#include <stdio.h>

void exibir(int lin, int col, int mat[lin][col]){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("mat[%d][%d]: %d\n", i, j, mat[i][j]);
        }
    }
}

void zerar(int lin, int col, int mat[lin][col]){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] % 3 == 0){
                mat[i][j] = 0;
            }
            printf("mat[%d][%d]: %d\n", i, j, mat[i][j]);
        }
    }
}

int main (){

    int mat[3][3] ={
        {1, 2 ,3},
        {4, 5, 6},
        {7, 8, 9}
    };
    exibir(3, 3, mat);
    zerar(3, 3, mat);
    return 0;
}