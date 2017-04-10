#if !defined(_LISTA_SIMPLESMENTE_H)
#include "../includes/lista-simplesmente.h"
#endif

/**
 * Função que retorna informação de onde esta o iterador
 * @param Lista
 */
static TipoL
infoLista( Lista lst ) {
    if ( lst -> iterador != NULL )
        return lst -> iterador -> info;
}

/**
 * Função que retornar tamanho atual da lista
 * @param Lista
 */
static int 
longLista( Lista lst ) {
    return lst -> longitude;
}

/**
 * Função que retorna quando lista está no fim
 * @param Lista
 */
static int 
fimLista( Lista lst ) {
    if ( lst -> iterador == NULL ) 
        return 1;
    return 0;
}

/**
 * Função auxiliar para limpar lista
 * @param Lista
 */
static void 
_limpaLista( Lista lst ) {
    lst -> longitude    = 0;
    lst -> primeiro     = NULL;
    lst -> ultimo       = NULL;
    lst -> iterador     = NULL;
}

/**
 * Função auxiliar para iniciar nó com elemento
 * @param TipoL
 */
static pListaNo
_inicNo( TipoL elem ) {
    pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) ) ;
    novoNo -> info = elem;
    novoNo -> prox = NULL;
    
    return novoNo;
}

/**
 * Função auxiliar para inserir nó na posição atual da lista
 * @param Lista
 * @param pListaNo
 */
static void
_insNoLista (Lista lst, pListaNo novoNo) {
    lst -> primeiro = novoNo;
    lst -> ultimo   = novoNo;
    lst -> iterador = novoNo;
    lst -> longitude++;
}

/**
 * Iniciar e reotrna uma Lista vazia
 */
static Lista
inicList() {
    Lista lst           = ( Lista )malloc( sizeof( TLista ) );
    lst -> longitude    = 0;
    lst -> primeiro     = NULL;
    lst -> ultimo       = NULL;
    lst -> iterador     = NULL;

    return lst;
}

/**
 * Função que insere elemento após o iterador na lista
 * @param TipoL elem
 * @param Lista lst
 */
static void
anexLista( Lista lst, TipoL elem ) {
    pListaNo novoNo = _inicNo( elem );

    if( lst -> longitude == 0  ) {
        _insNoLista( lst, novoNo );
    } else {
        if ( lst -> iterador == lst -> ultimo ) {
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
            lst -> ultimo           = novoNo;
        } else {
            novoNo -> prox          = lst -> iterador -> prox;
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
        }
        lst -> longitude++;
    }
}

/**
 * Função que insere elemento antes do iterador na lista
 * @param TipoL elem
 * @param Lista lst
 */
static void 
insLista( Lista lst, TipoL elem ) {
    
    pListaNo novoNo = _inicNo( elem );
    pListaNo atual = lst -> iterador;

    if( lst -> longitude == 0  ) {
        _insNoLista(lst, novoNo);
    } else {
        if (lst -> iterador == lst -> primeiro) {
            novoNo -> prox  = lst -> iterador;
            lst -> primeiro = novoNo;
            lst -> iterador = novoNo;
        } else {
            primLista(lst);
            for(; lst -> iterador -> prox != atual; lst -> iterador = lst -> iterador -> prox ) {
                printf("varrendo lista");
                if (lst -> iterador -> prox == atual) {
                    printf("achou posicao anterior");
                }
            }
            novoNo -> prox          = lst -> iterador -> prox;
            lst -> iterador -> prox = novoNo;
            lst -> iterador         = novoNo;
        }
    }
    lst -> longitude++;
    
}

/**
 * Função que remove todos elementos da lista
 * @param Lista
 */
static void 
elimLista( Lista lst ) {
    pListaNo aux;
    
    if (fimLista( lst )) {
        printf("Não há elemento para remover");
        return;
    }
    
    if (lst -> longitude == 1) {
        _limpaLista( lst );
    } else {
        while(!fimLista(lst)) {
            primLista(lst);
            for (aux = lst -> primeiro; aux != NULL; aux = aux -> prox) {
                lst -> iterador = lst -> iterador -> prox;
                free(lst -> iterador);
                lst -> longitude--;
                free(aux);
            }
        }
    }
}

/**
 * Função que avança o iterador em uma posição
 * @param Lista lst
 */
static void 
segLista( Lista lst ) {
    lst -> iterador = lst -> iterador -> prox;
}

/**
 * Função que coloca o iterador no primeiro da lista
 * @param Lista
 */
static void 
primLista( Lista lst ) {
    lst -> iterador = lst -> primeiro;
}

/**
 * Função que coloca o iterador no ultimo da lista
 * @param Lista
 */
static void
ultLista( Lista lst ) {
   lst -> iterador = lst -> ultimo;
}

/**
 * Função que avança quantidade de posições desejada
 * @param Lista
 * @param int
 */
static void
posLista( Lista lst, int pos ) {
    int i = 1;
    if (pos > lst -> longitude) {
        printf("Lista só tem %i posições", lst->longitude);
    } else {
        for( primLista( lst ); i != pos; i++ ){
            segLista( lst );
        }
    }
}

/**
 * Função que imprime a lista
 * @param Lista
 */
static void 
imprimeLista( Lista lst ) {
    int i = 1;
    pListaNo aux = _inicNo(0);
    if (lst -> longitude > 0 ){
        for(aux = lst -> primeiro; aux != NULL; aux = aux -> prox ) {
            printf("elemento[%i]: %i \n", i, aux -> info);
            i++;
        }
    } else {
        printf("Lista nao possui elementos");
    }
}
