#ifndef LISTD_H
#define LISTD_H

typedef int TipoL;

/* Estrutura do No */
typedef struct ListaNo
{
  struct ListaNo* ant; /* Ponteiro para o No anterior */
  struct ListaNo* prox; /* Ponteiro para o proximo No */
  TipoL info; /* Informação do nó */
} No;

/* Estrutura da Lista. */
typedef struct tLista
{
  struct ListaNo* primeiro; /* Ponteiro apontando para o primeiro Nó da lista */
  unsigned int tamanho; /* Tamanho da Lista */
} Lista;

/* Prototipos */
Lista* inicLista(void);    // Cria e retorna uma Listaa vazia

void exibirLista(Lista* lst); // Exibe a Lista

/* Adicionando */
void adicionaNoInicio(Lista* lst, TipoL info);               // Adiciona Elemento no inicio da Lista
void adicionaNoFim(Lista* lst, TipoL info);                  // Adiciona Elemento no fim da Lista
int adicionaNaPosicao(Lista* lst, TipoL info, int posicao); // Adiciona Elemento na posicao informada

/* Removendo */
int removeInicio(Lista* lst);                              // Remove Elemento no inicio da Lista
int eliminaElemNaPosicao(Lista* lst, int posicao);         // Remove Elemento da posicao escolhida
int removeFim(Lista* lst);                                 // Remove Elemento no Fim da Lista
int removeElemEscolhido(Lista* lst, const TipoL info);     // Remove Elemento com info escolhida
int destruirLista(Lista* lst);                             // Destroi a lista

/* Retornando */
int retornaPrimeiroElem(Lista* lst);                     // Retorna primeiro elemento da lista
int retornaUltimoElem(Lista* lst);                       // Retorna ultimo elemento da lista
int retornaElemNaPosicao(Lista* lst, int posicao);       // Retorna elemento na posicao escolhida
int listaVazia(Lista* lst);                              // Retorna se a lista está vazia
int tamanho(Lista* lst);                                 // Retorna o tamanho da lista

/* Procurando */
int procuraElem(Lista* lst, int procurado); // Procura elemento dentro da Lista

/* Verifica */
void esvaziaLista(Lista* lst); // Esvazia Lista

/* Percorre */
void percorre(Lista* lst); // Percorre os elementos da Lista


#endif