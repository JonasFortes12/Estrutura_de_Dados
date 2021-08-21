#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"
#define TAM 100000

typedef struct fila {
    int n;
    int ini;
    ArvB* vetor[TAM];
} Fila;

Fila* fila_cria(void) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    f -> n = 0;
    f -> ini = 0;
    return f;
}

void fila_insere(Fila *f, ArvB* info) {
    int fim;
    if(f -> n == TAM) {
        printf("Capacidade da Fila Estourou!!!\n");
        exit(1);
    }
    
	fim = (f -> ini + f->n) % TAM;
    f -> vetor[fim] = info;
    f -> n++;
}

int fila_vazia(Fila *f){
    return f -> n == 0;
}

ArvB* fila_remove(Fila *f) {
    ArvB* a;
    if (fila_vazia(f)) {
        printf("Fila Vazia!!!\n");
        exit(1);
    }
    a = f -> vetor[f -> ini];
    f -> ini = (f -> ini + 1) % TAM;
    f -> n--;
    return a;
}

void fila_imprime(Fila *f){
    int i;
    int k;
    for (i = 0; i < (f -> n); i++) {
        k = (f -> ini + i) % TAM;
        arvb_imprime(f -> vetor[k]);
        // printf("%d\n", f -> v[k]);
    }
}

void fila_libera(Fila* f) {
    free(f);
}

int fila_comprimento(Fila* f) {
    return f->n;
}

ArvB* fila_ponta(Fila* f) {
    ArvB* arv = f->vetor[f->ini];
    return arv;
}












