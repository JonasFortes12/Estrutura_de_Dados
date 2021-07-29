
typedef struct lista Lista;


/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l);

/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);

/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);

/*A retorna quantos n�s t�m info com valor menor que n.*/
int menores(Lista* l, int n);

/*B somar os valores do campo info de todos os n�s*/
int soma(Lista* l);

/*C retornar o n�mero de n�s da lista que possuem o campo info com n divisores positivos.*/
int num_ndivp(Lista* l, int n);

/*D gerar uma nova lista que � a intersec��o de duas listas.*/
Lista* lst_intersec(Lista* l1, Lista* l2);

/*E gera uma nova lista que � a concatena��o de uma lista l1 no final deuma lista l2.*/
Lista* lst_conc(Lista* l1, Lista* l2);

/*F fun��o que fa�a a diferen�a de duas listas l1 e l2*/
Lista* lst_diferenca(Lista* l1, Lista* l2);
























