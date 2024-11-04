#include <iostream>
using namespace std;

int cumulativeSum(int n) {
    if (n == 0) return 0;
    int x = n + cumulativeSum(n - 1);
    cout << x << endl;  // Print each cumulative sum step
    return x;
}

int main() {
    int N = 5;  // You can change this value for different sums
    cout << "Cumulative sum of first " << N << " integers: " << endl;
    cumulativeSum(N);

    return 0;
}
