#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb{
	char info;
	ArvB *esq;
	ArvB *dir;
};


/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void){
	return NULL;
}

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a){
	return a==NULL;	
}

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c){

	if(arvb_vazia(a)) return NULL;
	
	else if(a->info < c)
	 return arvb_busca(a->dir, c);
	
	else if(a->info > c)
	 return arvb_busca(a->esq, c);
	 
	else return a;
	
}

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a){
	
	if(!arvb_vazia(a)){
	
		arvb_imprime(a->esq);
		printf("%d", a->info);
		arvb_imprime(a->dir);	
	}
}

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c){
	
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	
	}else if(a->info > c)
	 a->esq = arvb_insere(a->esq,c);
	
	else if(a->info < c)
	 a->dir = arvb_insere(a->dir,c);
	
	else printf("\nElemento Ja pertence a Arvore");
	
	return a;	
}

/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c){
	
	if(!arvb_vazia(a)){
		
		if(a->info > c)
		 a->esq = arvb_remove(a->esq, c);
		
		else if(a->info < c)
		 a->dir = arvb_remove(a->dir, c);
		 
		 else{
		 	ArvB* t;
			
			if(a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if(a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir != NULL)
				 t = t->dir;
				
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq, c);
			}		 	
		 }	
	}
	return a;	
}

//---------------------------------------------------------------------------------------------------




























