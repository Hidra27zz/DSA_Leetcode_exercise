#include "Merge.h"


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;
    
    int leftArray[leftArraySize], rightArray[rightArraySize];
    
    for(int i = 0; i < leftArraySize; i++) {
        leftArray[i] = array[leftIndex + i];
    }
    
    for(int i = 0; i < rightArraySize; i++) {
        rightArray[i] = array[midIndex + i + 1];
    }
    
    int index = leftIndex;
    int i = 0;
    int j = 0;
    
    
    while(i < leftArraySize && j < rightArraySize) {
        if(leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }
    
    while(i < leftArraySize) {
        array[index] = leftArray[i];
        i++;
        index++;
    }
    while(j < rightArraySize) {
        array[index] = rightArray[j];
        j++;
        index++;
    }
    
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function merges two sorted arrays into one.  |
	//   | - It is a part of the Merge Sort algorithm.         |
	//   | - Takes three index values to divide the array.     |
	//   |                                                     |
	//   | Return type: void                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'leftArray' and 'rightArray' are temp arrays.     |
	//   | - They store parts of the original array.           |
	//   | - 'i' and 'j' loop through these arrays.             |
	//   | - 'index' is for placing sorted elements back.      |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
}

