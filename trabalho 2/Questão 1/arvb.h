typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);

/*busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a, int c);

/*imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);

/*insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);

/*retorne a quantidade de folhas que possuem o campo info com n divisores positivos*/
int folhas_ndivp(ArvB* a, int n);

/*retorne a quantidade de nós que possuem os dois filhos*/
int dois_filhos(ArvB* a);

/*retorne a quantidade de nós cujas subárvores esquerda e direita tenham igual altura.*/
int nos_igual_altura(ArvB* a);

/*compare se duas árvores  são iguais*/
int arv_iguais(ArvB* a, ArvB* b);

/*imprima os elementos por níveis*/
void impressao_arv_niveis(ArvB* a);





























