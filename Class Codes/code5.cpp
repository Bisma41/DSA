#include <iostream>

using namespace std;

int main() {
    int i, j, temp, x[100];
	//Run this code multiple times and check the output will remain the same
    for (i = 0 ; i < 100 ; i++){
    	x[i] = rand(); 
    	cout << x[i] << ' ';
	}
	cout << "\n\n";
	for (i = 0 ; i < 100 ; i++)
		for (j = 0 ; j < 99 ; j++)
			if (x[j] < x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			} 
    for (i = 0 ; i < 100 ; i++)
    	cout << x[i] << ' ';
	cout << '\n';
    return 0;
}
