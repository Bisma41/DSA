#include <iostream>
using namespace std;

// Recursive function to print all elements of an array
void printArrayElements(int arr[], int n, int index = 0) {
    if (index >= n) return;
    cout << arr[index] << " ";
    printArrayElements(arr, n, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements: ";
    printArrayElements(arr, n);
    cout << endl;

    return 0;
}
