#include <stdio.h>

    typedef struct Data{
        int dia, ano;
        char mes[12];
    } t_data;

    typedef struct {//3  2  1  0
        unsigned char a, b, g, r;
    } t_rgba;

    typedef union Pixel{ //variáveis compartilhando mesmo espaço de memória
        int pixel;
        t_rgba rgba;
    } u_pixel1;

     typedef union Pixel2{ //variáveis compartilhando mesmo espaço de memória
        int pixel;
        unsigned char rgba[4];
    } u_pixel2;

    typedef struct Pessoa {
        char nome[100];
        int idade;
        float salario;
        struct Data data_nasc; //struct dentro de outra struct
    } t_pessoa;
    
int main(){
    u_pixel1 pix = {.pixel = 0x010203FF};
    printf("end de pixel: %u (%d)\n", &pix.pixel, pix.pixel);
    printf("&a: %u (%d)\n", &pix.rgba.a, pix.rgba.a);
    printf("&b: %u (%d)\n", &pix.rgba.b, pix.rgba.b);
    printf("&g: %u (%d)\n", &pix.rgba.g, pix.rgba.g);
    printf("&r: %u (%d)\n", &pix.rgba.r, pix.rgba.r);
    u_pixel2 pix2 = {.pixel = 0x010203FF};
    printf("end de pixel: %u (%d)\n", &pix2.pixel, pix2.pixel);
    printf("&a: %u (%d)\n", &pix2.rgba[0], pix2.rgba[0]);
    printf("&b: %u (%d)\n", &pix2.rgba[1], pix2.rgba[1]);
    printf("&g: %u (%d)\n", &pix2.rgba[2], pix2.rgba[2]);
    printf("&r: %u (%d)\n", &pix2.rgba[3], pix2.rgba[3]);

    return 0;
}