#if !defined(_LISTA_H)
#include "../includes/lista.h"
#endif

static Lista
inicList() {
    Lista lst           = ( Lista )malloc( sizeof( TLista ) );
    lst -> longitude    = 0;
    lst -> primeiro     = NULL;
    lst -> ultimo       = NULL;
    lst -> iterador     = NULL;

    return lst;
}

static void
anexLista( Lista lst, TipoL elem ) {
    pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) ) ;

    novoNo->info = elem;
    novoNo->prox = NULL;

    if( lst -> longitude == 0  ) {
        lst -> primeiro = novoNo;
        lst -> ultimo   = novoNo;
        lst -> iterador = novoNo;
        lst -> longitude++;
    } else {
        if ( lst -> iterador == lst -> ultimo ) {
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
            lst -> ultimo           = novoNo;
            lst -> longitude++;
        } else {
            novoNo -> prox          = lst -> iterador -> prox;
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
            lst -> longitude++;
        }
    }

}