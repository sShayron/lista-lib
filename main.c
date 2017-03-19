#include "stdio.h"
#include "stdlib.h"
#include "src/lista.c"

int main() {
    Lista lista1 = inicList();
    
    printf("Teste \n ________________\n");
    printf("\tLongitude: %i\n", lista1->longitude);
    
    return 0;
}
