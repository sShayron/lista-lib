#if !defined(_LISTA_H)
#include "../includes/lista.h"
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
    novoNo -> info = elem;
    novoNo -> prox = NULL;
    
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

static void 
insLista( Lista lst, TipoL elem ) {
    
    pListaNo novoNo = _inicNo( elem );
    pListaNo aux;
    
    if( lst -> longitude == 0  ) {
        _insNoLista(lst, novoNo);
    } else {
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
    if (lst -> longitude == 1) {
        _limpaLista( lst );
    } else {
        if (lst -> iterador == lst -> ultimo) {
            lst -> ultimo   = lst -> iterador--; //MAYBE THIS DON'T EVEN WORK
            lst -> iterador = lst -> ultimo;
        } else {
            lst -> iterador-- -> prox = lst -> iterador -> prox; //MAYBE THIS DON'T EVEN WORK
            lst -> iterador           = lst -> iterador -> prox;
        }
        lst -> longitude--;
    }
}

static void 
primLista( Lista lst ) {
    if( lst -> longitude > 0 ) 
        lst -> iterador = lst -> primeiro;
}

static void
ultLista( Lista lst ) {
    if( lst -> longitude > 0 ) 
        lst -> iterador = lst -> ultimo;
}

static void 
segLista( Lista lst ) {
    if ( lst -> iterador != NULL ) {
        lst -> iterador++;                //MAYBE THIS DON'T EVEN WORK
    }
}

static void
posLista( Lista lst, int pos ) {
    if ( 1 > pos > lst -> longitude  ) {
        lst -> iterador = NULL;
    } else {
        lst -> iterador = lst -> primeiro + pos;
    }
}

static TipoL
infoLista( Lista lst ) {
    if ( lst -> iterador != NULL )
        return lst -> iterador -> info;
}

static int 
longLista( Lista lst ) {
    return lst -> longitude;
}

static int fimLista( Lista lst ) {
    if ( lst -> iterador == NULL ) 
        return 1;
    return 0;
}
