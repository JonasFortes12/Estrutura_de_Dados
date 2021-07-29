#include "../quest�o 1/Lista.h"

typedef struct pilha Pilha;

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void);

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p);

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);

/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);

/*Fun��o que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha *p);

/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha *p);


//Letra A
Pilha* inverte_pilha(Pilha* p);

//Letra B
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);















