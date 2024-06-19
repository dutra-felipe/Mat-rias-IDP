#include <stdio.h>
#include <stdlib.h>

int *build_int_array(unsigned int size){
    return malloc(sizeof(int) * size);
}