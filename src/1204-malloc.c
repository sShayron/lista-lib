#include <stdio.h>
#include <stdlib.h>

typedef int TipoL;

typedef struct {
    TipoL info;
    struct ListaNo *prox, *ant;
}*pListaNo;

typedef struct ListaNo * Lista;

int main()
{
    int *p, b, *vet;
    // aloca o ponteiro que retorna inteiro e sizeof do tamanho de um inteiro
    p = (int *)malloc(sizeof(int));
    vet = (int *)malloc(10*sizeof(int)); // aloca 10 posições de inteiros (ao inves de um vet[10])
    *p = 50;

    printf("%d!\n", *p);
    return 0;
}
