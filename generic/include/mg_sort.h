#ifndef __mg_sort
#define __mg_sort
void bubbleSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
void linearSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
void selectionSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
void insertionSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
void mergeSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
void quickSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*));
#endif