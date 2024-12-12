#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 5

//Find the smallest value in an array
//The memory address of the first element is passed so it makes it more efficient as the address of 
//the first element of the array can be used to find the rest of the elements
int findSmallest(int *arr) { 

    //Stores the smallest value
    int smallest = arr[0];
    //Stores the index of the smallest value
    int smallest_index  = 0;
    for (int j = 1; j < SIZE; j++)
    {
        if (arr[j] < smallest){
            smallest = arr[j];
            smallest_index = j;
        } 
    }

    return smallest_index;
}

int *selectionSort(int *arr) {
    //Create new Array
    //Here the (int *) ensures that the malloc function returns a int pointer for *newArr, as it typically returns a void pointer, i.e typecast
    int *newArr = (int *)malloc(SIZE * sizeof(int)); 
    for (int i = 0; i < SIZE; i++){
        int smallest = findSmallest(arr);
        newArr[i] = arr[smallest]; //Adds the smallest element to the 
        //same as deleted by changing to the largest value
        arr[smallest] = INT_MAX; 
        //Sets the value of the smallest element to the maximum possible integer value in C (2147483647 for most systems), this essentially prevents it from being repeated later on
    }
    return newArr;
}

int main(void) {
    int arr[SIZE] = {5,3,6,200,10};
    int *sortarr = selectionSort(arr);

    //print result
    for(int i = 0; i < SIZE; i++){
        printf("%d ", sortarr[i]);
    }
    return 0;
}