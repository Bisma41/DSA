//Input three numbers, the numbers can be in any order. Using if condition print numbers in order


#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter the student's marks: ";
    cin >> marks;


     if (marks < 50) {
        cout << "Grade: F" << endl;}
     else if (marks <= 54) {
        cout << "Grade: D" << endl;}
     else if (marks <= 57) {
        cout << "Grade: C-" << endl;}
     else if (marks <= 60) {
        cout << "Grade: C" << endl;}
     else if (marks <= 64) {
        cout << "Grade: C+" << endl;}
     else if (marks <= 69) {
        cout << "Grade: B-" << endl;}
     else if (marks <= 74) {
        cout << "Grade: B" << endl;}
     else if (marks <= 79) {
        cout << "Grade: B+" << endl;}
     else if (marks <= 84) {
        cout << "Grade: A-" << endl;}
     else if (marks <= 100) {
        cout << "Grade: A" << endl;}
     else {
        cout << "Invalid marks entered." << endl;}
    

    return 0;
}

	

