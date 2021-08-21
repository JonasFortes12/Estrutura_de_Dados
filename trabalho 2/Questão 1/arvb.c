#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"

struct arvb{
	int info;
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
		printf("%d \n", a->info);
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

/*retorna a altura da arvore*/
int arvb_altura(ArvB *a){
	
	if(arvb_vazia(a)) {
        return -1;
    } 
    
    int hSAE = arvb_altura(a -> esq);
    int hSAD = arvb_altura(a -> dir);
    int h = (hSAE > hSAD) ? hSAE : hSAD;
    return h + 1;
	
}

/*libera memoria*/
void arvb_libera(ArvB *a) {
    if (!arvb_vazia(a)) {
        arvb_libera(a -> esq);
        arvb_libera(a -> dir);
        free(a);
    }
}

/*Letra A*/
int qtd_divisores(int n){
	int i, cont = 0;
	
	for (i = 1; i <= n; i++) {
        if (n % i == 0) cont++;
    }
    return cont;
}

int folhas_ndivp(ArvB* a, int n){
	if(!arvb_vazia(a)){
			
        int divisores = qtd_divisores(a->info); 
        int eIgual = (divisores == n);
        
		return eIgual + folhas_ndivp(a->esq, n) + folhas_ndivp(a->dir, n); 	 	
	}
	return 0;	 
}

/*Letra B*/
int dois_filhos(ArvB* a){
	if(!arvb_vazia(a)){
		
		ArvB* esq = a->esq;
		ArvB* dir = a->dir;
		
		int temDois = (!arvb_vazia(esq) && !arvb_vazia(dir));
		
		return temDois + dois_filhos(esq) + dois_filhos(dir);		
	}
	return 0;
}

/*Letra C*/
int nos_igual_altura(ArvB* a){
	
	if(!arvb_vazia(a)){
		
		ArvB* esq = a->esq;
		ArvB* dir = a->dir;
		
		int mesmaAltura = (arvb_altura(esq) == arvb_altura(dir));
		
		return mesmaAltura + nos_igual_altura(esq) + nos_igual_altura(dir);	
	}
	return 0;
}

/*Letra D*/
int arv_iguais(ArvB* a, ArvB* b){
	
	if(arvb_vazia(a) || arvb_vazia(b)) return 1;
	
	if(a->info != b->info) return 0;
	
	ArvB* esqA = a->esq;
	ArvB* dirA = a->dir;
	
	ArvB* esqB = b->esq;
	ArvB* dirB = b->dir;
	
	return arv_iguais(esqA, esqB) && arv_iguais(dirA, dirB);
	
}

/*Letra E*/
void impressao_arv_niveis(ArvB* a){
	if (a == NULL) return;
 
    int level = 0;
    Fila* f = fila_cria();
    fila_insere(f, a);

    while (!fila_vazia(f)) {
        int countNode = fila_comprimento(f);

        while (countNode > 0) {
            ArvB* nodeAux = fila_ponta(f);

            printf("%d%s", nodeAux -> info, ((countNode == 1) ? "" : ", "));
            
            fila_remove(f);
            
            if (nodeAux->esq != NULL)
                fila_insere(f, nodeAux->esq);

            if (nodeAux->dir != NULL)
                fila_insere(f, nodeAux->dir);

            countNode--;
        }
        printf(" - nivel %d\n", level++);
    }	
}











