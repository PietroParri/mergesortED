//PIETRO BORGES PARRI GRR20204445

#include<stdlib.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>

void mergeSort(int arr[], int esq, int meio, int dir);

int min(int x, int y) { return (x < y) ? x : y; }

void mergeSort_ordena(int arr[], int n){
   int tam;
   int esq;

   for (tam=1; tam<=n-1; tam = 2*tam){
       for (esq=0; esq<n-1; esq += 2*tam){
           int meio = min(esq + tam - 1, n-1);
           int dir = min(esq + 2*tam - 1, n-1);
           mergeSort(arr, esq, meio, dir);
       }
   }
}

void mergeSort(int arr[], int esq, int meio, int dir){

    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 =  dir - meio;
    int E[n1], D[n2];

    for (i = 0; i < n1; i++)
        E[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        D[j] = arr[meio + 1+ j];

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            arr[k] = E[i];
            i++;
        }else{
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = E[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = D[j];
        j++;
        k++;
    }
}

void print(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Vetor original \n");
    print(arr, n);

    mergeSort_ordena(arr, n);

    printf("\nVetor de forma ordenada \n");
    print(arr, n);
    return 0;
}
