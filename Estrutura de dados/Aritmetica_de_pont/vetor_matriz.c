#include <stdio.h>

int main(){

    //*p = 5 e p = 0x100
    // p++ ou = 0x104 (+4 bytes, pois é int)

  int v[10] = {3, 5, 6, 2, 8, 9, 1, 5, 0, 7};
	int *p = v;
	for(int i = 0; i < 10; i++) {
		printf("índice %d:\n", i);
		printf("\t   Notação de vetor: valor = %d, endereço = %p\n",   p[i], &p[i]); 
		printf("\tNotação de ponteiro: valor = %d, endereço = %p\n", *(p+i),   p+i);

	   // (*(p+n)= p[n]) acessar valores
	   //  (&p[n] = p++ )  acessar end
	}
	
	//matriz
    int num[3][4] = {
	{1,  2,  3,  4},
	{5,  6,  7,  8},
	{9, 10, 11, 12},
    };

    int *pi = (int *)num; //ponteiro acessando matriz
        for(int i = 0; i < 3 * 4; i++) { 
	    printf("posicao:[%d] valor: %d end: %d\n", i, pi[i], &pi[i]); // percorre os elementos da matriz, podendo tb ser *(p+i)
    }

  return 0;
}