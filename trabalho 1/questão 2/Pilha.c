#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"
#include "../questão 1/Lista.c"



struct pilha{
	Lista *prim;
};

/*cria uma pilha*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	
	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

/*remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	
	free(l);
	return a;
}

/*imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(p);
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

//---------------------Funções Pedidas no Trabalho (questão 2)

//Letra A
Pilha* inverte_pilha(Pilha* p){
	Lista *lAux = p->prim;
    
    Lista *lNovo = lst_cria();
	Pilha *pNovo = pilha_cria();
	 
	while(lAux!=NULL){
		lNovo = lst_insere(lNovo, lAux->info);
		lAux = lAux->prox;
	}
	
	pNovo->prim = lNovo;
	
	return pNovo;
}

//Letra B
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	
	Pilha* pNova = pilha_cria();
	Lista* lNova = lst_cria();
	
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	Lista* lAux3 = lst_cria();
	
	while(lAux1!=NULL){
		while(lAux2!=NULL){	
			if(lAux1->info == lAux2->info){
				lAux3 = lst_insere_ordenado(lAux3, lAux1->info);
				lAux2->info = NULL;
				break;	
			}
			lAux2 = lAux2->prox;
		}
		lAux1 = lAux1->prox;
		lAux2 = l2;
	}
	
	while(lAux3!=NULL){
		pilha_push(pNova, lAux3->info);
		lAux3 = lAux3->prox;
	}
	
	
	return pNova;
	
}










