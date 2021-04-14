#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

/*
*print the array with given length
*arr: int array
*size: the length you want to print out of the array
*/
void print_arr(int *arr, int size){
    
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");

}

/*
*Algorism: first determine the first k elements, then swap the "start" element with other elements after it
*arr: array for permutation
*n: the length of the array
*k: the number of elements you want to permutate from the array
*start: the element swapped with the element after it
*/
void permutation(int* arr, int n, int k, int start){

    if (start == k){
        print_arr(arr, k);
    } else {
        for (int i = start; i < n; i++){
            swap((arr + start), (arr + i));
            permutation(arr, n, k, start + 1);
            swap((arr + start), (arr + i));
        }
    }

}

/*
*Algorism: at each level, put the ith element in array arr into array data
*arr: array for combination
*data: array for saving the result of combination
*n: the length of arr
*k: the number of elements you want to combine from the array
*level: the index of data
*index: to determine the start value of i, must be -1 when first called
*/
void combination(int* arr, int* data, int n, int k, int level, int index){

    if (level == k){
        print_arr(data, k);
    } else {
        for (int i = index + 1; i < n; i++){
            if (level == 0 && i == (n - k + 1))
                break;
            *(data + level) = *(arr + i);
            combination(arr, data, n, k, level + 1, i);
        }
    }

}

int main(){
    
    printf("\nPERMUTATION=============================\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    permutation(arr, 7, 3, 0);

    printf("\nCOMBINATION=============================\n");
    int data[3];
    combination(arr, data, 7, 3, 0, -1);

    return 0;

}