#ifndef _LISTA_DE_H
#define _LISTA_DE_H

typedef int TipoL;

typedef struct ListaNo {
    TipoL  info;
    struct ListaNo*ant;
    struct ListaNo*prox;
} * pListaNo;

typedef struct {
    pListaNo primeiro, ultimo, iterador;
    int longitude;
} TLista, *Lista;

static void _limpaLista( Lista lst );                   // Limpa atributos da lista
static pListaNo _inicNo( TipoL elem );                  // Cria e retornar um novo nó com o elemento
static void _insNoLista (Lista lst, pListaNo novoNo);   // Adiciona novo nó em uma lista vazia
static Lista inicList( void );                          // Cria e retorna uma lista vazia
static void anexLista( Lista lst, TipoL elem );         // Adiciona um elemento depois do iterador
static void insLista( Lista lst, TipoL elem );          // Adiciona um elemento antes do iterador
static void elimLista( Lista lst );                     // Elimina o elemento que está sob o iterador
static void primLista( Lista lst );                     // Coloca o iterador sobre o primeiro elemento da lista
static void ultLista( Lista lst );                      // Coloca o iterador sobre o ultimo elemento da lista
static void segLista( Lista lst );                      // Avança o iterador uma posição
static void posLista( Lista lts, int pos );             // Coloca o iterador sobre a posição pos
static TipoL infoLista( Lista lst );                    // Retorna o elemento sob o iterador
static int longLista( Lista lst );                      // Retorna a quantidade de elementos da lista
static int fimLista( Lista lst );                       // Retorna verdadeiro se o iterador estiver indefinido

#endif