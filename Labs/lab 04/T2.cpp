#include <iostream>
using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swap(arr1[j], arr1[j + 1]);
                swap(arr2[j], arr2[j + 1]);
            }
        }
    }
}
void printOriginalPositions(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr1[i] << " at position " << arr2[i] << endl;
    }
}
int main() {
    const int SIZE = 10;
    int arr1[SIZE] = {31, 45, 18, 76, 20, 15, 97, 22, 35, 48};
    int arr2[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Original arrays: ";
    printArray(arr1, SIZE);
    bubbleSort(arr1, arr2, SIZE);
    cout << "Sorted arrays ";
    printArray(arr1, SIZE);
    cout << "Original positions:" << endl;
    printOriginalPositions(arr1, arr2, SIZE);
    return 0;
}











