#include "stdio.h"
#include "stdlib.h"
#include "src/menu-duplamente.c"
#include "src/lista_duplamente_encadeada.c"

int MENU; // Opção do menu

/**
 * Função de apoio que inicia lista caso nao tenha sido iniciada
 */
Lista* listaExist(Lista* lst) {
    if (!lst) {
        lst  = inicLista();
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
/**
 * Função de apoia que retorna posicao escolhido pelo usuario
 */
int escolha_pos() {
    int pos;
    printf("Digite a posicao que deseja: ");
    scanf("%i", &pos);
    return pos;
}

int main() {
    do
    {
        int elem, pos;

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
                Lista* lst = inicLista();
                printf("Lista iniciada vazia");
                break;
            case 2:
                system("clear");
                lst = listaExist(lst);
                elem = escolha_elem();
                adicionaNoInicio(lst, elem);
                printf("Elemento %i inseriodo no inicio da lista", elem);
                break;
            case 3: 
                system("clear");
                system("clear");
                lst = listaExist(lst);
                elem = escolha_elem();
                adicionaNoFim(lst, elem);
                printf("Elemento %i inseriodo no fim da lista", elem);
                break;
            case 4:
                lst = listaExist(lst);
                pos = escolha_pos();
                elem = escolha_elem();
                int adc = adicionaNaPosicao(lst, elem, pos);
                if ( adc == 0) {
                    printf("Elemento %i inseriodo na posicao %i", elem, pos);
                }else if (adc == -1){
                    printf("Posicao informada maior que a lista, tamanho da lista: %i", tamanho(lst));
                }
                break;
            case 5:
                lst = listaExist(lst);
                pos = escolha_pos();
                printf("Lista[%i]: %i", pos, retornaElemNaPosicao(lst, pos) );
                break;
            case 6:
                lst = listaExist(lst);
                pos = escolha_pos();
                int elim = eliminaElemNaPosicao(lst, pos);
                if(elim == 0) {
                    printf("Elemento da posicao %i eliminado;", pos);
                }else if(elim == -1) {
                    printf("Posicao inválida, lista tem %i posicoes", tamanho(lst));
                }
                break;
            case 7:
                if(!lst) {
                    printf("Nenhuma lista iniciada");
                }else {
                    esvaziaLista(lst);
                    printf("Lista destruida");
                }
            case 8:
                lst = listaExist(lst);
                exibirLista(lst);
                break;
            case 9:
                lst = listaExist(lst);
                printf("Tamanho: %i", tamanho(lst));
            default:
             system("exit");
        }
    }
    while (MENU!=0);
}
