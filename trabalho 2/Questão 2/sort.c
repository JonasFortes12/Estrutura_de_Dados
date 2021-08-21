#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define TAM 10000

void printLength(){
	printf("TAMANHO DO VETOR: %d \n", TAM);
	printf("\n\n\n\n");
}

void swap (long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}


/*Bubble Sort*/
void bubbleSort (long n, long v[]){
    long i, j;
	for (j = 0; j < n; j++) {
        for (i = 0; i < (n - 1); i++) {
            if (v[i] > v[i + 1]) {
                swap(&v[i], &v[i + 1]);
            }
        }
    }
}

void bubbleSortOptimized(long n, long v[]){
	
	long i, j, troca;
	
	for(i = n-1; i > 0; i--){
		troca = 0;
		for(j = 0; j < i; j++){
		
			if(v[j] > v[j+1]){
				swap(&v[j], &v[j + 1]);
				troca = 1;
			}	
		}
	if(troca == 0) return;
	}
}

void bubbleSort_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	
	t_ini = clock();
	bubbleSort(TAM, vetor1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	bubbleSort(TAM, vetor2);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	bubbleSort(TAM, vetor3);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1); free(vetor2); free(vetor3);
	
}

void bubbleSortOptimized_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	
	t_ini = clock();
	bubbleSortOptimized(TAM, vetor1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	bubbleSortOptimized(TAM, vetor2);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	bubbleSortOptimized(TAM, vetor3);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1); free(vetor2); free(vetor3);
}

/*Quick Sort*/
void quickSort(long n, long v[]){
	if(n > 1){
		long x = v[0]; //Pivô
		long a = 1;
		long b = n-1;
		
		while(1){
		
			while(a < n && v[a] <= x) a++;
			while(v[b] > x) b--;
			
			if(a < b){
				swap(&v[a], &v[b]);
				a++; 
				b--;
			}else break;	
		}
		
		v[0] = v[b];
		v[b] = x;
		
		quickSort(b, v);
		quickSort(n - a, &v[a]);
	}
}

void quickSort_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	t_ini = clock();
	quickSort(TAM, vetor1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	quickSort(TAM, vetor2);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	quickSort(TAM, vetor3);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1);
	free(vetor2);
	free(vetor3);
	
}

/*Heap Sort*/
void heapSort(long a[], long n) {
   long i = n / 2, pai, filho, t;
   
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void heapSort_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	
	t_ini = clock();
	heapSort(vetor1, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	heapSort(vetor2, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	heapSort(vetor3, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1); free(vetor2); free(vetor3);

}

/*Insertion Sort*/
void insertionSort(long arr[], long n){
    long i, j, key;
    
	for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
		while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSort_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	
	t_ini = clock();
	insertionSort(vetor1, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	insertionSort(vetor2, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	insertionSort(vetor3, TAM);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1); free(vetor2); free(vetor3);

}

/*Merge Sort*/
void merge(long vetor[], long comeco, long meio, long fim) {
    long com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    long *vetAux;
    vetAux = (long*)malloc(tam * sizeof(long));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(long vetor[], long comeco, long fim){
    if (comeco < fim) {
        long meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void mergeSort_tempo(){
	clock_t tempo, t_ini, t_fin;
	long a, b = 0, c = 0;
	
	long *vetor1 = (long*) malloc(TAM * sizeof(long));
	long *vetor2 = (long*) malloc(TAM * sizeof(long));
	long *vetor3 = (long*) malloc(TAM * sizeof(long));
	
	for(a = 0; a < TAM; a++) vetor1[a] = ++b;
	for(a = 0; a < TAM; a++) vetor2[a] = rand()%TAM;
	for(a = TAM-1; a >= 0; a--) vetor3[a] = ++c;
	
	
	
	t_ini = clock();
	mergeSort(vetor1, 0, TAM-1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Crescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));

	t_ini = clock();
	mergeSort(vetor2, 0, TAM-1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Aleatorio]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));
	
	t_ini = clock();
	mergeSort(vetor3, 0, TAM-1);
	t_fin = clock();
	tempo = t_fin - t_ini;
	printf("Tempo [Vetor Decrescente]: %.0lf\n", ((double) tempo)/ ((CLOCKS_PER_SEC/1000)));	
	
	free(vetor1); free(vetor2); free(vetor3);

}








