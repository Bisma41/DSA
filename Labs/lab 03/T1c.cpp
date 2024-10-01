#include <iostream>
using namespace std;

int main() {
    int rows ;
    cout<<"enter rows:";
    cin>>rows;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        for (int j = 2; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    
    return 0;
}
