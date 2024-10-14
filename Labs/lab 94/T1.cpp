#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";}
    cout << endl;}
void mergeArrays(int arr1[], int arr2[], int mergedArr[], int size1, int size2) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}
int main() {
    int S1 = 10;
    int S2 = 10;
    int MERGED_SIZE = S1 + S2;
    int arr1[S1] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[S2] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int mergedArr[MERGED_SIZE];
    cout << "Array 1: ";
    printArray(arr1, S1);
    cout << "Array 2: ";
    printArray(arr2, S2);
    mergeArrays(arr1, arr2, mergedArr, S1, S2);
    cout << "Merged Array: ";
    printArray(mergedArr, MERGED_SIZE);
    return 0;
}



