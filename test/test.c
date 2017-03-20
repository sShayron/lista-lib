#include "../includes/greatest.h"
#include "../src/lista.c"

TEST inicia_lista_insere_no(void) {
    printf("Deve criar uma lista inserir um nó com valor 666");
    Lista lst  = inicList();
    anexLista(lst, 666);
    ASSERT_EQ(666, lst -> iterador -> info);
    PASS();
}

SUITE(TESTE_LISTA) {
    RUN_TEST(inicia_lista_insere_no);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    /* Individual tests can be run directly. */
    /* RUN_TEST(should_create_return_two_equal_list); */

    RUN_SUITE(TESTE_LISTA);

    GREATEST_MAIN_END(); 
}