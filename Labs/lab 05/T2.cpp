#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string courseName;
    int courseCode;
    int credits;
    
public:
    // Constructor with validation logic
    Course(string courseName, int courseCode, int credits) {
        setcourseName(courseName);
        setcourseCode(courseCode);
        setcredits(credits);
    }

    // Setters with validation
    void setcourseName(string n) {
        if (n.empty()) {
            courseName = "COURSE";
        } else {
            courseName = n;
        }
    }

    void setcourseCode(int c) {
        if (c <= 0) {
            courseCode = 0;
        } else {
            courseCode = c;
        }
    }

    void setcredits(int C) {
        if (C >= 1 && C <= 6) {
            credits = C;
        } else {
            credits = 1;  // Default to 1 if invalid
        }
    }

    // Function to print the course details
    void printCourseDetails() {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

    // Function to compare credits between courses
    bool isGreater(Course& c) {
        return credits > c.credits;
    }
};

int main() {
    // Creating courses
    Course course1("Data Structures", 101, 4);  // Credits exceed limit, should default to 1
    Course course2("Linear Algebra", -202, 2);  // Negative course code, should default to 0

    // Printing course details
    course1.printCourseDetails();
    cout << endl;
    course2.printCourseDetails();
    cout << endl;

    // Comparing credits
    if (course1.isGreater(course2)) {
        cout << "Course1 has more credits" << endl;
    } else {
        cout << "Course2 has more credits or they are equal" << endl;
    }

    return 0;
}
