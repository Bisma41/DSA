#include <iostream>
#include <string>
using namespace std;

int main() {
	// two ways to initialize a pointer
    int i=5;
    // #1
    int *p=0;
    p=&i;
    
    cout<< p << endl;
    cout<< *p << endl;
    
    
    // #2
    int *q=&i;
    
    cout<< q << endl;
    cout<< *q << endl;
    return 0;
}
