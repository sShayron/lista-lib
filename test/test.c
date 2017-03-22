#include "../includes/greatest.h"
#include "../src/lista.c"

TEST inicia_lista_insere_no(void) {
    Lista lst  = inicList();
    anexLista(lst, 666);
    printf("\n\nDeve criar uma lista inserir um nó com valor 666");
    ASSERT_EQm("Não está criando a lista ou retornando valor correto", 666, lst -> iterador -> info);
    PASS();
}

TEST anexa_no_lista_apos_iterador(void) {
    Lista lst = inicList();
    anexLista(lst, 666);
    anexLista(lst, 555);
    printf("\n\nDeve criar uma lista inserir um nó com valor 555");
    ASSERT_EQm("Não está criando a lista ou retornando valor correto", 555, lst -> iterador -> info);
    PASS();
}

TEST adiciona_elem_antes_iterador(void) {
    Lista lst = inicList();
    anexLista(lst, 666);
    anexLista(lst, 555);
    insLista(lst, 444 );
    printf("\n\nDeve criar uma lista com 666, 444, 555 nó sob iterador com valor 444, e o proximo 555");
    ASSERT_EQm("Não está criando a lista ou retornando valor correto", 444, lst -> iterador -> info);
    ASSERT_EQm("Não está apontando o próximo corretamente", 555, lst -> iterador -> prox -> info);
    PASS();
}

SUITE(TESTE_LISTA) {
    RUN_TEST(inicia_lista_insere_no);
    RUN_TEST(anexa_no_lista_apos_iterador);
    RUN_TEST(adiciona_elem_antes_iterador);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    /* Individual tests can be run directly. */
    // RUN_TEST(inicia_lista_insere_no);

    RUN_SUITE(TESTE_LISTA);

    GREATEST_MAIN_END(); 
}   