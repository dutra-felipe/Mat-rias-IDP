#include <stdio.h>

int main(){

    char s[]= "maria", *ptr = s;

    printf("%c\n", s[2]);   //localiza o 'r'
    printf("%c\n", *(ptr + 2));

    //ptr + 4000; --> acessa o end 5000

    printf ("1 = %d\n", *(ptr + 3)); 
    printf ("0 = %d\n", *(ptr + 2)); //retorna o 1000;
    printf ("0 = %d\n", *(ptr + 1));
    printf ("0 = %d\n", *ptr); 

    printf ("1 = %d\n", s[3] ); 
    printf ("0 = %d\n", s[2] ); //retorna o 1000;
    printf ("0 = %d\n", s[1] );
    printf ("0 = %d\n", s[0] ); 

    //*ptr = 1001;
    
    return 0;
}