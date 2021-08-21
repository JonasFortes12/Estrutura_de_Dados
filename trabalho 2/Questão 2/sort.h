#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printLength();

/*Merge Sort*/
void merge(long vetor[], long comeco, long meio, long fim);
void mergeSort(long vetor[], long comeco, long fim);
void mergeSort_tempo();

/*Insertion Sort*/
void insertionSort(long arr[], long n);
void insertionSort_tempo();

/*Heap Sort*/
void heapSort(long a[], long n);
void heapSort_tempo();

/*Quick Sort*/
void quickSort(long n, long v[]);
void quickSort_tempo();

/*Bubble Sort*/
void bubbleSort(long n, long v[]);
void bubbleSortOptimized(long n, long v[]);
void bubbleSortOptimized_tempo();
void bubbleSort_tempo();







