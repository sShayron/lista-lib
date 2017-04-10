# Lista lib
Implementação da biblioteca de lista

## Functions
```C
_limpaLista( Lista lst );                   // Limpa atributos da lista
_inicNo( TipoL elem );                      // Cria e retornar um novo nó com o elemento
_insNoLista (Lista lst, pListaNo novoNo);   // Adiciona novo nó em uma lista vazia
inicList( void );                           // Cria e retorna uma lista vazia
anexLista( Lista lst, TipoL elem );         // Adiciona um elemento depois do iterador
insLista( Lista lst, TipoL elem );          // Adiciona um elemento antes do iterador
elimLista( Lista lst );                     // Elimina o elemento que está sob o iterador
primLista( Lista lst );                     // Coloca o iterador sobre o primeiro elemento da lista
ultLista( Lista lst );                      // Coloca o iterador sobre o ultimo elemento da lista
segLista( Lista lst );                      // Avança o iterador uma posição
posLista( Lista lts, int pos );             // Coloca o iterador sobre a posição pos
infoLista( Lista lst );                     // Retorna o elemento sob o iterador
longLista( Lista lst );                     // Retorna a quantidade de elementos da lista
fimLista( Lista lst );                      // Retorna verdadeiro se o iterador estiver indefinido
```
