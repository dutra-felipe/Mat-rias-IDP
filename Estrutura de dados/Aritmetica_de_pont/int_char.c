#include <stdio.h>

int main(){
    
    int n = 0x01020304;
    int *p_n = &n;
    //*p_n = 1025;
    printf("n: %d (%08x)\n", n, n);

    char *pchar = (char *)&n; //retira o warning
    printf("byte 1 de n: %d\n", *pchar);
    printf("byte 1 de n: %d\n", *(pchar + 1));


    return 0;
}