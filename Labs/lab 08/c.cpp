#include <iostream>
using namespace std;

// Recursive function to print adjacent pairs in separate lines
void printAdjacentPairs(int arr[], int n, int index = 0) {
    if (index >= n - 1) return;
    cout << arr[index] << " " << arr[index + 1] << endl;
    printAdjacentPairs(arr, n, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Adjacent pairs: " << endl;
    printAdjacentPairs(arr, n);

    return 0;
}
