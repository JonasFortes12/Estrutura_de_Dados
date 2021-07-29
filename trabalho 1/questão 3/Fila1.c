#include <stdio.h>
#include <stdlib.h>

#include "Fila1.h"
#define N 5

typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;


Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f->n = 0;
	f->ini = 0;

return f;
}


void fila_insere(Fila *f, int info){
	int fim;
	
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
	f->n++;
}

/*Testa se uma fila é vazia.*/
int fila_vazia(Fila *f){
	return f->n==0;
}

/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f){
	int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	 
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	
return a;
}


void fila_imprime(Fila *f){
	int i; int k;
	
	for(i = 0; i<f->n; i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}


void fila_libera(Fila *f){
	free(f);
}

//Letra A
int qtd_primos(Fila* f){
	int i;
	int j;
	int k;
	
	int primos = 0;
	int cont = 0;
 	
	for(i = 0; i<f->n;i++){
 		cont = 0;
 		k = (f->ini+i) % N;
	 	
		for (j = 1; j <= f->v[k]; j++) {
	    	if (f->v[k] % j == 0) { 
	     		cont++;
	    		}
	  		}
	  	if (cont == 2) primos++;
 	}
 	
	 return primos;
}

//Letra B
Fila* inverte_fila(Fila* f){
	int i; int k;
	Fila* fNew = fila_cria();
	
	
	for(i = f->n-1; i >= 0 ; i--){
		k = (f->ini+i) % N;
		fila_insere(fNew, f->v[k]);
	}
	
	return fNew;	
}


















