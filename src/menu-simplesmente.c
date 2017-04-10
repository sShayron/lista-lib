int MENU = 0; // Opção do menu

// Opções do menu
int escolha_menu()
{
    printf("\n\n");
    printf(" Lista \n");
    printf("--------------------------\n");
    printf(" 1 - Iniciar nova Lista \n");
    printf(" 2 - Inserir elemento apos do iterador \n");
    printf(" 3 - Inserir elemento antes o iterador \n");
    printf(" 4 - Remover elementos da lista \n");
    printf(" 5 - Exibir lista \n");
    printf(" 6 - Exibir elemento sob iterador \n");
    printf(" 7 - Exibir quantidade de elementos na lista \n");
    printf(" 8 - Colocar iterador sob posicao escolhida \n");
    printf("--------------------------\n");
    printf(" 0 - Sair \n");
    printf("\n");
    printf(" Digite uma opcao do menu: ");
    scanf("%i",&MENU);
}