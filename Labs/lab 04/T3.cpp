#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 30;
const int SENTINEL = -1;

// Function to print an array in a single line
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i] << " ";
    }
    cout << endl;
}

// Function to print roll numbers and marks column-wise
void printRollAndMarks(int roll[], int marks[], int size) {
    cout << setw(4) << "Roll No" << setw(8) << "Marks" << endl;
    for (int i = 0; i < size; i++) {
        if (roll[i] != SENTINEL) {
            cout << setw(4) << roll[i] << setw(8) << marks[i] << endl;
        }
    }
}

int main() {
    srand(time(0));  // Seed for random number generation

    int marks[SIZE];
    int roll[SIZE];

    // Initialize marks and roll numbers
    for (int i = 0; i < SIZE; i++) {
        marks[i] = rand() % 101;  // Marks between 0-100
        roll[i] = i + 1;          // Roll numbers 1 to 30
    }

    // Print marks in a single line
    cout << "Marks: ";
    printArray(marks, SIZE);

    // Randomly remove 3 to 5 students by setting roll numbers to SENTINEL
    int numToRemove = rand() % 3 + 3;  // Randomly removing 3-5 students
    for (int i = 0; i < numToRemove; i++) {
        int index = rand() % SIZE;
        roll[index] = SENTINEL;
    }

    // Print roll numbers and marks column-wise
    printRollAndMarks(roll, marks, SIZE);

    // Count remaining students
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (roll[i] != SENTINEL) {
            count++;
        }
    }

    // Create new arrays for remaining roll numbers and marks
    int newRoll[count];
    int newMarks[count];
    int j = 0;
    for (int i = 0; i < SIZE; i++) {
        if (roll[i] != SENTINEL) {
            newRoll[j] = roll[i];
            newMarks[j] = marks[i];
            j++;
        }
    }

    // Print new roll numbers and marks horizontally
    cout << "\nNew Roll Numbers: ";
    printArray(newRoll, count);
    cout << "New Marks: ";
    printArray(newMarks, count);

    return 0;
}

