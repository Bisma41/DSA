//Input marks and print grades using if-else conditions. Repeat this task for simple if-else and composite if-else.

#include <iostream>
using namespace std;

int main() {
    int num1,num2,num3,temp;
    cout << "Enter number1: "<<endl;
    cin >> num1;
    cout << "Enter number2: "<<endl;
    cin >> num2;
    cout << "Enter number3: "<<endl;
    cin >> num3;
    if(num1 > num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if(num2 > num3)
    {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if(num1 > num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    cout << num1 <<" "<<num2<<" "<<num3;


    return 0;
}

	




