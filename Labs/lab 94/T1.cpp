#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE1 = 10;
const int SIZE2 = 20;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i] << " ";
    }
    cout << endl;
}

// Function to initialize a sorted array
void initializeSortedArray(int arr[], int size, int startValue) {
    arr[0] = startValue;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + rand() % 5;  // Next element is randomly 0-4 more than the previous element
    }
}

// Function to merge two sorted arrays into a third sorted array
void mergeArrays(int arr1[], int arr2[], int mergedArr[], int size1, int size2) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays into one
    while (i < size1 && j < size1) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // If there are remaining elements in arr1
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // If there are remaining elements in arr2
    while (j < size1) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    srand(time(0));  // Seed for random number generation

    int arr1[SIZE1], arr2[SIZE1], mergedArr[SIZE2];

    // Initialize two sorted arrays
    initializeSortedArray(arr1, SIZE1, rand() % 10);  // Starting from a random number between 0-9
    initializeSortedArray(arr2, SIZE1, rand() % 10 + 10);  // Starting from a random number between 10-19

    // Merge the two arrays into the third array
    mergeArrays(arr1, arr2, mergedArr, SIZE1, SIZE1);

    // Print all three arrays
    cout << "Array 1: ";
    printArray(arr1, SIZE1);

    cout << "Array 2: ";
    printArray(arr2, SIZE1);

    cout << "Merged Array: ";
    printArray(mergedArr, SIZE2);

    return 0;
}
