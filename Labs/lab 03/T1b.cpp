#include <iostream>
using namespace std;

int main() {
    int rows,columns;
    cout<<"enter rows:";
    cin>>rows;
    cout<<"enter columns:";
    cin>>columns;
    
    for (int i = 1; i <= rows; i++) {
        int sum = 0;
        int number = i;
        
        for (int j = 1; j <= columns; j++) {
            cout << number;
            sum += number;
            if (j < columns) cout << "+";
            number += i;
        }
        cout << "=" << sum << endl;
    }
    
    return 0;
}

