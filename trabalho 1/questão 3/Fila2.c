#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
}; 

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
	f->fim->prox = l;
	else
	f->ini = l;
 	f->fim = l;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

int fila_remove(Fila *f){
	Lista *l; int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f))
	f->fim = NULL;
	return a;
}

void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
	printf("%d\n",lAux->info);
 	lAux = lAux->prox;
 	}
}

void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	while(l!=NULL){
	lAux = l->prox;
	free(l);
	l = lAux;
	}
	free(f);
}



//Letra A
int qtd_primos(Fila* f){
	
	int i;
	int k;
	int primos = 0;
	int cont = 0;
	
	Lista *lAux = f->ini;
	
 	while(lAux!=NULL){
 		cont = 0;
 		for (i = 1; i <= lAux->info; i++) {
	    	if (lAux->info % i == 0) { 
	     		cont++;
	    	}
	  	}
	  	if (cont == 2) primos++;
 		lAux = lAux->prox;
 	}
 	return primos;
}

//Letra B
Fila* inverte_fila(Fila* f){
	
	Fila* fNew = fila_cria();
 	Lista *lAux = f->ini;
 	
	int len = 0;
 	int i;
 	
	while(lAux!=NULL){
 		len++;
 		lAux = lAux->prox;
 	}
 	
	lAux = f->ini;
 	
	int *VetAux;
  	VetAux = (int*)malloc(sizeof(int)*len); 
  	
  	i = len-1;
  	
  	while(lAux!=NULL){
 		VetAux[i] = lAux->info;
 		lAux = lAux->prox;
 		i--;
 	}
 	
	lAux = f->ini;
 	i = 0;
 	
	while(lAux!=NULL){
		fila_insere(fNew, VetAux[i]);
		lAux = lAux->prox;
 		i++;
 	}
 	
	return fNew;
}






















