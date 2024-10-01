#include <iostream>
using namespace std;

int main() {
    int num,i,j;
    char ch='A';
    cout << "Enter number of rows:";
    cin >> num;
    for(i=1;i<=num;i++){
	
        for(j=1; j<=4; j++)
	    {
		cout<<ch<<' '; 
		ch++;
		if (j%4==0){cout<<endl;};
		}
    }
    return 0;
}

	




