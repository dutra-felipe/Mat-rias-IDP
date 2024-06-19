#include <stdio.h>

int main(){

    int rgba = 0x010203FF; //supondo 0x100 a 0x103
    unsigned char *c = (unsigned char *) &rgba; //ponteiro char para o rgba

    printf ("r = %d\n", *(c + 3)); //acessa o 0x103
    printf ("g = %d\n", *(c + 2)); //acessa o 0x102
    printf ("b = %d\n", *(c + 1)); //acessa o 0x101
    printf ("a = %d\n", *c); //acessa o 0x100

    //vetor 
    printf("a: %d\n", c[0]);
    printf("b: %d\n", c[1]);
    printf("g: %d\n", c[2]);
    printf("r: %d\n", c[3]);

    // utilizando ponteiro ++ (c++)
    printf("a: %d\n", *c);
    c++;
    printf("b: %d\n", *c);
    c++;
    printf("g: %d\n", *c);
    c++;
    printf("r: %d\n", *c);
    
    return 0;
}