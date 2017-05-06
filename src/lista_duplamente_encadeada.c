#if !defined(LISTD_H)
#include "../includes/lista_duplamente_encadeada.h"
#endif


static No* criaNo(TipoL info);

/** inicLista
  *
  * Cria uma lista vazia
  *
  * @return uma lista Vazia
  */
Lista* inicLista(void)
{
  Lista *l = malloc(sizeof(Lista));
  l->primeiro = NULL;
  l->tamanho = 0;
  return l;
}

/** criaNo
  *
  * Função auxiliar para criar um nó com um elemento
  *
  * @param info um elemento inteiro que deseja armazenar
  * @return um Nó com o elemento armazenado
  */
static No* criaNo(TipoL info)
{
  No *n = malloc(sizeof(No));
  n->info = info;
  n->ant = NULL;
  n->prox = NULL;
  return n;
}

/** exibirLista
  *
  * Função que printa os valores da lista
  * @return 0
  */
void exibirLista(Lista* lst)
{
  
  if(lst) {
      No *atual = lst->primeiro;
      printf("Exibindo Lista: \n\n");
      // percorre a lista
      for (int i=0; i<lst->tamanho; i++) {
        printf("Lista[%i]: %i \n", i+1, atual->info);
        atual = atual->prox;
      }
  } else {
      printf("Lista vazia!");
  }
}

/** adicionaNoInicio
  *
  * Adiciona elemento info no inicio na Lista
  *
  * @param lst um ponteiro para a Lista.
  * @param info elemento inteiro que deseja armazenar na Lista.
  */
void adicionaNoInicio(Lista* lst, TipoL info)
{
  No *n = criaNo(info);

  // Se o tamanho for 0
  if (!lst->tamanho) {
    // Entao o proximo e o anterior sao o mesmo 
    n->prox = n;
    n->ant = n;
  } else {
    No *primeiro = lst->primeiro;
    No *ant = primeiro->ant;
    
    // Atribui o ponteiro proximo e anterior do novo nó 
    n->prox = primeiro;
    n->ant = primeiro->ant;

    // Atribui  o ponteiro proximo e anterior da nó da lista para o novo nó
    primeiro->ant = n;
    ant->prox = n;
  }

  // Aponta o ponteiro primeiro da lista para o novo nó
  lst->primeiro = n;
  // Incrementa tamanho da lista
  lst->tamanho++;
}

/** adicionaNoFim
  *
  * Adiciona elemento info no fim na Lista
  *
  * @param lst um ponteiro para a Lista.
  * @param info elemento inteiro que deseja armazenar na Lista.
  */
void adicionaNoFim(Lista* lst, TipoL info)
{
  No *n = criaNo(info);

  // Se o tamanho for 0
  if (!lst->tamanho) {
    // Atribui o ponteiro proximo e anterior do novo nó 
    n->prox = n;
    n->ant = n;

    // Como nao nao há outros nós na lista o novo nó sera o primeiro 
    lst->primeiro = n;
  } else {
    No *primeiro = lst->primeiro;
    No *ant = primeiro->ant;

    // Insere no fim atribuindo o proximo para o primeiro
    n->prox = primeiro;
    n->ant = primeiro->ant;

    // Atribui o ponteiro proximo e anterior para o novo nó
    primeiro->ant = n;
    ant->prox = n;
  }
  lst->tamanho++;
}

int adicionaNaPosicao(Lista* lst, TipoL info, int posicao) {
    No *n = criaNo(info);
    // Se a lista tiver vazia ou a posicao maior que a lista
    if (lst->tamanho == 0 || posicao >= lst->tamanho) {
        return -1;
    }
    
    // Percorre a lista enquanto nao chegar na posicao 
    No *atual = lst->primeiro; // posicao = 0
    for (int i=0; i<posicao-1; i++) {
        atual = atual->prox;
    }
    No *prox = atual->prox;
    No *ant = atual->ant;
    n->prox = atual;
    n->ant = ant;
    
    atual->ant = n;
    if(posicao == 1) lst->primeiro = n;
    lst->tamanho++;
    return 0;
}

/** removeInicio
  *
  * Remove o nó no inicio da Lista
  *
  * @param lst um ponteiro para a Lista.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int removeInicio(Lista* lst)
{
  if (!lst->tamanho) return -1;

  No *primeiro = lst->primeiro;
  
  if (lst->tamanho == 1) {
    // Se tiver só um elemento na lista, atribui NULL para o primeiro 
    lst->primeiro = NULL;
  } else {
    No *prox = primeiro->prox;
    No *ant = primeiro->ant;

    // Atribui o proximo ao primeiro
    lst->primeiro = prox;

    // Ajusta os ponteiros
    prox->ant = ant;
    ant->prox = prox;
  }

  // Libera espaço de memoria
  free(primeiro);

  // Decrementa tamanho da lista
  lst->tamanho--;
  
  return 0;
}

/** eliminaElemNaPosicao
  *
  * Remove o elemento sob a posicao
  *
  * @param lst um ponteiro para a Lista.
  * @param posicao do no para remover.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int eliminaElemNaPosicao(Lista* lst, int posicao)
{
  if (!lst->tamanho || posicao > lst->tamanho) return -1;

  No *atual = lst->primeiro; 

  // percorre a lista até a posicao
  for (int i=0; i<posicao; i++) {
    atual = atual->prox;
  }

  // Se a lista tiver só um elemento
  if (lst->tamanho == 1) {
    lst->primeiro = NULL;
  } else {
    No *prox = atual->prox;
    No *ant = atual->ant;
    
    // Ajusta os ponteiros
    ant->prox = prox;
    prox->ant = ant;
  }
  
  // Libera espaço de memoria
  free(atual);
  
  // Decrementa tamanho da lista
  lst->tamanho--;

  return 0;
}

/** removeFim
  *
  * Remove o ultimo elemento da Lista
  *
  * @param lst um ponteiro para a Lista.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int removeFim(Lista* lst)
{
  if (!lst->tamanho) return -1;

  No *primeiro = lst->primeiro;
  No *tbr = primeiro->ant; // Elemento a ser removido
  No *nb = tbr->ant; // new back

  // if Lista if of tamanho 1
  if (lst->tamanho == 1) {
    // o primeiro aponta para NULL
    lst->primeiro = NULL;
  } else {
    // Ajusta os ponteiros
    primeiro->ant = nb;
    nb->prox = primeiro;
  }

  // Libera espaço de memoria
  free(tbr);
  
  // Decrementa tamanho da lista
  lst->tamanho--;

  return 0;
}

/** removeElemEscolhido
  *
  * Remove todos os nó da lista que tem info igual a passada
  *
  * @param lst um ponteiro para Lista
  * @param info que deseja eliminar
  * @return o numero de elementos removidos
  */
int removeElemEscolhido(Lista* lst, const TipoL info)
{
  int removido = 0;

  if (!lst->tamanho) return removido;

  No *atual = lst->primeiro;
  No *prox = atual->prox;
  No *ant = atual->ant;
  int is_primeiro = 1;

  for (int i=0; i<lst->tamanho; i++) {
    if (info == atual->info) {
      // Atribui o proximo caso ainda seja o primeiro
      if (is_primeiro) lst->primeiro = prox;

      // Ajusta os ponteiros
      prox->ant = ant;
      ant->prox = prox;

      // Libera espaço de memoria
      free(atual);

      // aponta o atual para o proximo Nó
      atual = prox;

      removido++;
    } else {
      is_primeiro = 0;
      
      // Atribui o proximo para atual
      atual = atual->prox;
    }

    // Ajusta os ponteiros prox e ant
    if (lst->tamanho > 1) {
      prox = atual->prox;
      ant = atual->ant;
    }
  }

  // Decrementa o tamanho da lista
  lst->tamanho-=removido;

  // Se remover todos elementos atribui NULL para primeiro
  if (!lst->tamanho) lst->primeiro = NULL;

  return removido;
}

/** destruirLista
  *
  * Remove todos Nós da Lista
  *
  * @param lst um ponteiro para Lista
  * @return numero de Nós que foram removidos
  */
int destruirLista(Lista* lst)
{
  if (!lst->tamanho) return 0;

  int removido = 0;
  No *atual = lst->primeiro;
  No *prox = atual->prox;
  No *ant = atual->ant;
  int is_primeiro = 1;

  for (int i=0; i<lst->tamanho; i++) {
    if (atual->info) {
      // Atribui o proximo caso ainda seja o primeiro
      if (is_primeiro) lst->primeiro = prox;

      // Ajusta os ponteiros
      prox->ant = ant;
      ant->prox = prox;

      // Libera espaço de memoria
      free(atual);

      // update the atual
      atual = prox;

      removido++;
    } else {
      // we're no longer on the primeiro
      is_primeiro = 0;

      // Atribui o proximo para atual
      atual = atual->prox;
    }

    // Ajusta os ponteiros prox e ant
    if (lst->tamanho > 0) {
      prox = atual->prox;
      ant = atual->ant;
    }
  }

  // Decrementa o tamanho da lista
  lst->tamanho-=removido;

  // Se remover todos elementos atribui NULL para primeiro
  if (!lst->tamanho) lst->primeiro = NULL;

  return removido;
}

/** retornaPrimeiroElem
  *
  * Retorna info do primeiro elemento da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info do primeiro No da Lista ou -1
  */
int retornaPrimeiroElem(Lista* lst)
{
  if (lst->tamanho) {
    return lst->primeiro->info;
  } else {
    return -1;
  }
}

/** retornaElemNaPosicao
  *
  * Retorna info do elemento da posicao da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info da posicao No da Lista ou -1
  */
int retornaElemNaPosicao(Lista* lst, int posicao)
{
  // Se a lista tiver vazia ou a posicao maior que a lista
  if (!lst->tamanho || posicao >= lst->tamanho) {
    return -1;
  }
  
  // Percorre a lista enquanto nao chegar na posicao 
  No *atual = lst->primeiro; // posicao = 0
  for (int i=0; i<posicao-1; i++) {
    atual = atual->prox;
  }

  return atual->info;
}

/** retornaUltimoElem
  *
  * Retorna info do ultimo elemento da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info do ultimo No da Lista ou -1
  */
int retornaUltimoElem(Lista* lst)
{
  // Se a lista tiver vazia retorna NULL
  if (!lst->tamanho) return -1;

  // Retorna o anterior do primeiro
  No *end = lst->primeiro->ant;
  return end->info;
}

/** listaVazia
  *
  * Verifica se a lista ta vazia
  *
  * @param lst um ponteiro para Lista
  * @return 1 if the Lista is indeed empty 0 otherwise.
  */
int listaVazia(Lista* lst)
{
  if (lst->tamanho == 0 && lst->primeiro == NULL) {
    return 1;
  } else {
    return 0;
  }
}

/** tamanho
  *
  * Gets the tamanho of the linked Lista
  *
  * @param lst um ponteiro para Lista
  * @return o tamanho da lista
  */
int tamanho(Lista* lst)
{
  return lst->tamanho;
}

/** procuraElem
  *
  * Procura um elemento na lista
  *
  * @param lst a ponteiro para Lista.
  * @param search info para procura
  * @return 1 se encontrar ou 0 se não
  */
int procuraElem(Lista* lst, int procurado)
{
  // percorre a lista
  No *atual = lst->primeiro;
  for (int i=0; i<lst->tamanho; i++) {
    // compara o info com o procurado
    if (procurado == atual->info) return 1;
    atual = atual->prox;
  }

  // nao encontrado
  return 0;
}

/** esvaziaLista
  *
  * Esvazia a lista
  *
  * @param lst a ponteiro para Lista.
  *
  */
void esvaziaLista(Lista* lst)
{
  // Se tamanho for 0
  if (!lst->tamanho) return;

  No *atual = lst->primeiro;
  No *prox = atual->prox;

  // Percorre a lista e libera espaço de memoria de todos nós e info
  for (int i=0; i<lst->tamanho; i++) {
    free(atual);
    atual = prox;
    
    // Se nao for o final da lista atribui o proximo nó
    if (i < lst->tamanho-1) prox = atual->prox;
  }

  // Reseta primeiro e tamanho da lista
  lst->primeiro=NULL;
  lst->tamanho=0;
}

/** percorre
  *
  * Percorre os nós da lista
  *
  * @param lst a ponteiro to a linked Lista.
  */
void percorre(Lista* lst)
{
  No *atual = lst->primeiro;
  for (int i=0; i<lst->tamanho; i++) {
    printf("Lista[%i]: %i", i+1, atual->info);
    atual = atual->prox;
  }
}