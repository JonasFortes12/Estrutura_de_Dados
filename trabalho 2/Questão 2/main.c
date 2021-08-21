#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"


int main(void){
	
	printLength();
	
	printf("____________Bubble Sort_____________\n");
	bubbleSort_tempo();
	printf("\n");
	printf("____________Bubble Sort Otimizado_____________\n");
	bubbleSortOptimized_tempo();
	printf("\n");
	printf("____________Insertion Sort_____________\n");
	insertionSort_tempo();
	printf("\n");
	printf("____________Merge Sort_____________\n");
	mergeSort_tempo();
	printf("\n");
	printf("____________Heap Sort_____________\n");
	heapSort_tempo();
	printf("\n");
	printf("____________Quick Sort_____________\n");
	quickSort_tempo();
	printf("\n");

return 1;
}


