#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


struct lista {
	int info;
	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*) malloc(sizeof(Lista));
	
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

/* Insere um elemento de forma ordenada.*/
Lista* lst_insere_ordenado(Lista *l, int info){
	
	Lista *lNew = (Lista*) malloc(sizeof(Lista));
	lNew->info = info;
	
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	
	}else if(l->info >= info){
		lNew->prox = l;
		return lNew;	
	
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->prox;
		
		while(lProx != NULL && lProx->info < info){
			lAnt = lProx;
			lProx = lProx->prox;
		}
		
		lAnt->prox = lNew;
		lNew->prox = lProx;
		
		return l;
	}
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info) return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("info = %d\n", lAux->info);
		lAux = lAux->prox;
	}
}

/* Imprime uma lista de forma recursiva e invertida.*/
void lst_imprime_invertida_rec(Lista* l){
	
	if(lst_vazia(l)) return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n", l->info);
	}
}

/* Remove um elemento da lista.*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		
		if(l->info == info){
			free(l);
			return lAux;
		}else{
			Lista* lAnt = l;
			
			while(lAux!=NULL){
				if(lAux->info == info){
					lAnt->prox = lAux->prox;
					free(lAux);
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}	
			}
		}
	}
return l;
}

/* Remove uma estrutura de forma recursiva.*/
Lista* lst_remove_rec(Lista *l, int info){
	
	if(!lst_vazia(l)){
		
		if(l->info == info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
		}else{
			l->prox = lst_remove_rec(l->prox, info);
		}	
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}


//Letra A
int menores(Lista* l, int n){ 
	int cont = 0;
	Lista* lAux = l;

	while(lAux != NULL){
		if(lAux->info < n) cont++;
		lAux = lAux->prox;
	}
	
	return cont;
}

//Letra B
int soma(Lista* l){
	int soma = 0;
	Lista* lAux = l;

	while(lAux != NULL){
		soma += lAux->info; 
		lAux = lAux->prox;
	}
	
	return soma;
}

//Letra C
int num_ndivp(Lista* l, int n){
	
	Lista* lAux = l;
	int divs = 0;
	int quant = 0;	
	

	while(lAux != NULL){	
		
		int i;
		for (i = 1; i <= lAux->info; i++){
			if(lAux->info % i == 0) divs++;
		}
		
		if(divs == n) quant++;
		 
		lAux = lAux->prox;
		divs = 0;
		
	}
	
	return quant;
}

//Letra D
Lista* lst_intersec(Lista* l1, Lista* l2){
	
	Lista* lNew = lst_cria();
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	
	while(lAux1!=NULL){
		while(lAux2!=NULL){	
			if(lAux1->info == lAux2->info){
				lNew = lst_insere_ordenado(lNew, lAux1->info);
//				lAux2->info = NULL;
				break;	
			}
			lAux2 = lAux2->prox;
		}
		lAux1 = lAux1->prox;
		lAux2 = l2;
	}
	
	return lNew;
}

//Letra E
Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	Lista* lAux3 = lst_cria();
	Lista* lNew = lst_cria();
	
	while(lAux2!=NULL){
		lAux3 = lst_insere(lAux3, lAux2->info);
		
		if(lAux2->prox == NULL){
			while(lAux1!=NULL){
				lAux3 = lst_insere(lAux3, lAux1->info);
				lAux1 = lAux1->prox;	
			}
		}
		
		lAux2 = lAux2->prox;
	}
	
	while(lAux3!=NULL){
		lNew = lst_insere(lNew, lAux3->info);
		lAux3 = lAux3->prox;
	}
	
	return lNew;	
}

//Letra F
Lista* lst_diferenca(Lista* l1, Lista* l2){
    
    Lista* lNew = lst_cria();
    Lista* lAux1 = l1;
    Lista* lAux2 = l2;
	int aux = 0;
	
     while(lAux1!=NULL){
		aux = 0;
        lAux2 = l2;
        
		while(lAux2!=NULL){
			if(lAux1->info==lAux2->info) aux = 1;
            lAux2 = lAux2->prox;
        }
        
		if(aux == 0) lNew = lst_insere(lNew, lAux1->info);
    	lAux1 = lAux1->prox;
		}
    
	return lNew;
}






















	
	
	
	
	
	
	
	
	

