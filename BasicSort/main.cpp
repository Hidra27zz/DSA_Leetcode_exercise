#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(int array[], int size) {
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size) {
    for(int i = 0; i < size; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(array[minIndex] > array[j] ){
                minIndex = j;
            }
        }
        if(i != minIndex) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void insertionSort(int array[], int size) {
    for(int i = 1; i < size; i++) {
        int temp = array[i];
        int j = i-1;
        while(j > -1 && temp < array[j]) {
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}


int main() {
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    //bubbleSort(myArray, size);
    //selectionSort(myArray, size);
 
    insertionSort(myArray, size);

    for(auto value : myArray) {
        cout << value << " ";
    }
}