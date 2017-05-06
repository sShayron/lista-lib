#ifndef _LISTA_SIMPLESMENTE_H
#define _LISTA_SIMPLESMENTE_H

typedef int TipoL;

typedef struct ListaNo {
    TipoL  info;
    struct ListaNo*prox;
} * pListaNo;

typedef struct {
    pListaNo primeiro, ultimo, iterador;
    int longitude;
} TLista, *Lista;

 void _limpaLista( Lista lst );                   // Limpa atributos da lista
 pListaNo _inicNo( TipoL elem );                  // Cria e retornar um novo nó com o elemento
 void _insNoLista (Lista lst, pListaNo novoNo);   // Adiciona novo nó em uma lista vazia
 Lista inicList( void );                          // Cria e retorna uma lista vazia
 void anexLista( Lista lst, TipoL elem );         // Adiciona um elemento depois do iterador
 void insLista( Lista lst, TipoL elem );          // Adiciona um elemento antes do iterador
 void elimLista( Lista lst );                     // Elimina o elemento que está sob o iterador
 void primLista( Lista lst );                     // Coloca o iterador sobre o primeiro elemento da lista
 void ultLista( Lista lst );                      // Coloca o iterador sobre o ultimo elemento da lista
 void segLista( Lista lst );                      // Avança o iterador uma posição
 void posLista( Lista lts, int pos );             // Coloca o iterador sobre a posição pos
 TipoL infoLista( Lista lst );                    // Retorna o elemento sob o iterador
 int longLista( Lista lst );                      // Retorna a quantidade de elementos da lista
 int fimLista( Lista lst );                       // Retorna verdadeiro se o iterador estiver indefinido
 void imprimeLista( Lista lst );                   // Imprime os elementos da lista

#endif