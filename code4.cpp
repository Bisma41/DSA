#include <iostream>

using namespace std;

int main() {
    unsigned int x = 2000000000;
    cout << x << '\n';//the range of unsigned integer is 4294967295
    x = x + 500000000;//Therefore this value will remain in the range
	cout << x << '\n';
	x = x + 2500000000;//Again this value is out of range but remain within 0 to 4294967295 
	cout << x << '\n';
	return 0;
}