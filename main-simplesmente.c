#include "stdio.h"
#include "stdlib.h"
#include "src/menu-simplesmente.c"
#include "src/lista-simplesmente.c"

int MENU; // Opção do menu

/**
 * Função de apoio que inicia lista caso nao tenha sido iniciada
 */
Lista listaExist(Lista lst) {
    if (!lst) {
        lst  = inicList();
        printf("Lista vazia iniciada\n");
    }
    return lst;
}
 
/**
 * Função de apoia que retorna elemento escolhido pelo usuario
 */
int escolha_elem() {
    int elem;
    printf("Digite o elemento que deseja incluir: ");
    scanf("%i", &elem);
    return elem;
}

int main() {
    
    do
    {
        int elem;

        //exibe opcoes do menu e atribui o numero da opcao na variavel MENU
        escolha_menu();
        //executa a ação do menu
        switch (MENU)
        {
            case 0:
                printf("Sistema finalizado!");
                system("exit");
                break;
            case 1:
                system("clear");
                Lista lst  = inicList();
                printf("Lista iniciada vazia.");
                break;
            case 2:
                system("clear");
                lst = listaExist(lst);
                elem = escolha_elem();
                anexLista( lst, elem );
                printf("Elemento %i inserido após iterador.", infoLista(lst));
                break;
            case 3:
                system("clear");
                lst = listaExist(lst);
                elem = escolha_elem();
                insLista( lst, elem );
                printf("Elemento %i inserido antes do iterador.", infoLista(lst));
                break;
            case 4:
                system("clear");
                lst = listaExist(lst);
                elimLista(lst);
                printf("Elementos da lista removidos");
                break;
            case 5:
                system("clear");
                lst = listaExist(lst);
                imprimeLista(lst);
                break;
            case 6:
                system("clear");
                lst = listaExist(lst);
                printf("Elemento sob iterador: %i \n", infoLista(lst));
                break;
            case 7:
                system("clear");
                lst = listaExist(lst);
                printf("Quantidade de elementos na lista: %i \n", longLista(lst));
                break;
            case 8:
                system("clear");
                int pos = 0;
                lst = listaExist(lst);
                printf("Escolha posicao que deseja colocar iterador: ");
                scanf("%i", &pos);
                posLista(lst, pos);
                break;
            default:
             system("exit");
        }
    }
    while (MENU!=0);
}
