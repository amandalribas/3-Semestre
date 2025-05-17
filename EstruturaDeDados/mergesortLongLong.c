#include <stdio.h>
#include <stdlib.h>

#define M 20

void mergeSortedArrays(long long n[], int leftIndex, int rightIndex, int m){
    int leftLenght = m - leftIndex + 1;
    int rightLenght = rightIndex - m;

    long long leftArray[leftLenght];
    long long rightArray[rightLenght];
    
    for (int i = 0; i < leftLenght; i++)
        leftArray[i] = n[leftIndex + i];

    for (int i = 0; i < rightLenght; i++)
        rightArray[i] = n[m + 1 + i];

    for (int i = 0, j = 0, k = leftIndex; k <= rightIndex; k++){
        if((i<leftLenght)&&(j>=rightLenght || leftArray[i]<=rightArray[j])){
            n[k] = leftArray[i];
            i++;
        }else{
            n[k] = rightArray[j];
            j++;
        }
    }
}

void mergeSortRecursion(long long n[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        int m = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSortRecursion(n,leftIndex,m);
        mergeSortRecursion(n,m+1, rightIndex);
        mergeSortedArrays(n, leftIndex, rightIndex, m);
    }

}

void mergeSort(long long n[]){
    mergeSortRecursion(n,0,M-1);
}