#include <iostream>

using namespace std;

int main() {
    unsigned char c = 126;
    //we are casting char type to print integer value instead of character
    cout << (int)c << '\n';
	c = c + 5;//value will remain inside the range, which is now 255
    cout << (int)c << '\n';
	c = c + 135;//value will again out of the range, but it will remain in the range 0-255
    cout << (int)c << '\n';
    return 0;
}
