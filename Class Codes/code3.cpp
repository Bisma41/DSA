#include <iostream>

using namespace std;

int main() {
    int x = 2000000000;
    cout << x << '\n';//the range of integer is +2147483647
	x = x + 500000000;//2500000000, again this value is out of range
    cout << x << '\n';
    return 0;
}
