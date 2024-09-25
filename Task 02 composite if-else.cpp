//Input marks and print grades using if-else conditions. Repeat this task for simple if-else and composite if-else.


#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter your marks: ";
    cin >> marks;

    // Composite if-else conditions
    if ((marks >= 90 && marks <= 100)) {
        cout << "Grade: A+" << endl;
    }
    else if (marks >= 80 && marks < 90) {
        cout << "Grade: A" << endl;
    }
    else if (marks >= 70 && marks < 80) {
        cout << "Grade: B" << endl;
    }
    else if (marks >= 60 && marks < 70) {
        cout << "Grade: C" << endl;
    }
    else if (marks >= 50 && marks < 60) {
        cout << "Grade: D" << endl;
    }
    else if (marks >= 0 && marks < 50) {
        cout << "Grade: F (Fail)" << endl;
    }
    else {
        cout << "Invalid marks entered!" << endl;
    }

    return 0;
}

