#include <stdlib.h>
#include <stdio.h>

typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a);

/*busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*imprime os elementos de uma �rvore.*/
void arvb_imprime(ArvB *a);

/*insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*remove um inteiro em uma �rvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*retorna a altura da arvore*/
int arvb_altura(ArvB *a);

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

/*Letra A*/
int folhas_ndivp(ArvB* a, int n);

/*Letra B*/
int dois_filhos(ArvB* a);

/*Letra C*/
int nos_igual_altura(ArvB* a);

/*Letra D*/
int arv_iguais(ArvB* a, ArvB* b);

/*Letra E*/
void impressao_arv_niveis(ArvB* a);


