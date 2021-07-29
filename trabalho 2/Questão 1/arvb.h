typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a);

/*busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*imprime os elementos de uma �rvore.*/
void arvb_imprime(ArvB *a);

/*insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*remove um inteiro em uma �rvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

/*retorne a quantidade de folhas que possuem o campo info com n divisores positivos*/
int folhas_ndivp(ArvB* a, int n);

/*retorne a quantidade de n�s que possuem os dois filhos*/
int dois_filhos(ArvB* a);

/*retorne a quantidade de n�s cujas sub�rvores esquerda e direita tenham igual altura.*/
int nos_igual_altura(ArvB* a);

/*compare se duas �rvores  s�o iguais*/
int arv_iguais(ArvB* a, ArvB* b);

/*imprima os elementos por n�veis*/
void impressao_arv_niveis(ArvB* a);





























