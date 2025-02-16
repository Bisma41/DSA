#include <iostream>

using namespace std;

int main() {
    char c = 126;
    //we aree casting char type to print integer value instead of character
    cout << (int)c << '\n';
	c = c + 5;//value will exceed the range that is +127
    cout << (int)c << '\n';
    return 0;
}
