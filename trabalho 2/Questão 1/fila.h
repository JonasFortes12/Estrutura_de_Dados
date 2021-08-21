#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

typedef struct fila Fila;

Fila* fila_cria(void);

int fila_vazia(Fila *f);

void fila_insere(Fila *f, ArvB* info);

ArvB* fila_remove(Fila *f);

void fila_imprime(Fila *f);

void fila_libera(Fila *f);

int fila_comprimento(Fila* f);

ArvB* fila_ponta(Fila* f);

