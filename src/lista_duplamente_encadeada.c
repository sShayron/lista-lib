#if !defined(_LISTA_DE_H)
#include "../includes/lista_duplamente_encadeada.h"
#endif


static void 
_limpaLista( Lista lst ) {
    lst -> longitude    = 0;
    lst -> primeiro     = NULL;
    lst -> ultimo       = NULL;
    lst -> iterador     = NULL;
}

static pListaNo
_inicNo( TipoL elem ) {
    pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) ) ;
    novoNo -> info  = elem;
    novoNo -> prox  = NULL;
    novoNo -> ant   = NULL;
    
    return novoNo;
}


static void
_insNoLista (Lista lst, pListaNo novoNo) {
    lst -> primeiro = novoNo;
    lst -> ultimo   = novoNo;
    lst -> iterador = novoNo;
    lst -> longitude++;
}

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
    pListaNo novoNo = _inicNo( elem );

    if( lst -> longitude == 0  ) {
        _insNoLista(lst, novoNo);
    } else {
        if ( lst -> iterador == lst -> ultimo ) {
            novoNo -> ant           = lst -> iterador;
            novoNo -> prox          = NULL;
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
            lst -> ultimo           = novoNo;
            lst -> longitude++;
        } else {
            novoNo -> ant           = lst -> iterador;
            novoNo -> prox          = lst -> iterador -> prox;
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
            lst -> longitude++;
        }
    }
}


static void 
insLista( Lista lst, TipoL elem ) {
    
    pListaNo novoNo = _inicNo( elem );
    pListaNo aux;
    
    if( lst -> longitude == 0  ) {
        _insNoLista(lst, novoNo);
    } else {
        if ( lst -> primeiro == lst -> iterador  ) {
            novoNo -> prox          = lst -> iterador;
            lst -> iterador -> ant  = novoNo;
            lst -> iterador         = novoNo;
        } else if ( lst -> ultimo == lst -> iterador ) {
            
        }
        aux                 = lst -> iterador;
        lst -> iterador     = novoNo;
        novoNo -> prox      = aux;
        lst -> longitude++;
        if (lst -> primeiro == lst -> iterador) {
            lst -> primeiro = novoNo;
        }
    }
    
}

static void 
elimLista( Lista lst ) {
    
}

