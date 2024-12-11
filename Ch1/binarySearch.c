#include <stdio.h>

int binarySearch(int[], int, int);

int main(){

    int myList[] = {1, 3, 5, 7, 9};
    int len = sizeof(myList) / sizeof(myList[0]);
    printf("%d\n", binarySearch(myList, 3, len)); 
    printf("%d\n", binarySearch(myList, -1, len));
    return 0;
}

int binarySearch(int list[], int item, int len){
    
    //Setting Up the Values for the low and high points
    int low = 0;
    int high = len;

    while (low <= high) {
        int mid = (low + high)/2; //Mid, i.e the guess is set as the midpoint of the current high and low guesses
        int guess = list[mid];

        if(guess == item)
        {
            return mid; //If the guess is correct
        }
        else if (guess > item)
        {
            high = mid - 1;//Incase guess is higher, set the new highest point as the current guess(mid) - 1(as it is not the mid itself)
        }
        else
        {
            low = mid + 1;//Incase guess is lower, set the new lowest point as current guess(mid) + 1(as it is not mid itself either)
        }
    }
    return -1;//number not found
}