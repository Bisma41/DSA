#include <iostream>
using namespace std;

// Recursive function to print alternate elements of an array
void printAlternateArrayElements(int arr[], int n, int index = 0) {
    if (index >= n) return;
    cout << arr[index] << " ";
    printAlternateArrayElements(arr, n, index + 2);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Alternate array elements: ";
    printAlternateArrayElements(arr, n);
    cout << endl;

    return 0;
}
