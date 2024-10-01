#include <iostream>
using namespace std;

int main() {
    int rows;
    cout<<"enter rows:";
    cin>>rows;
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << "|_";
        for (int j = 1; j <= 2 * (rows - i) - 1; j++) {
            cout << " ";
        }
        if (i != rows) {
            cout << "_|";
        } else {
            cout << "|";
        }
        cout << endl;
    }
    
    return 0;
}

