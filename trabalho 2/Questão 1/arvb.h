#include <stdlib.h>
#include <stdio.h>

typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);

/*busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);

/*insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*retorna a altura da arvore*/
int arvb_altura(ArvB *a);

/*Libera o espaço alocado para uma Árvore.*/
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


