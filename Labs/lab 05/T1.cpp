#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    int marks;

public:
    Student(string name, int age, int marks) {
        setName(name);
        setAge(age);
        setMarks(marks);
    }

    void setName(string n) {
        if (n==" ") {
            name="NAME";
        } else if (n.length() < 3) {
            name="Unknown";
        } else {
            name=n;
        }
    }

    void setAge(int a) {
        if (a>=5 && a<=20) {
            age=a;
        } else {
            age=5;
        }
    }

    void setMarks(int m) {
        if (m>=0 && m<=100) {
            marks = m;
        } else {
            marks=50;
        }
    }

    void printStudentDetails() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
    
    
    

    bool isPassed() {
        return marks>=50;
    }

     char getGrade() {
        if (marks>=85) {
            return 'A';
        } else if (marks>=70 && marks<85) {
            return 'B';
        } else if (marks>=50 && marks<70) {
            return 'C';
        } else {
            return 'F';
        }
    }
};

int main() {
    Student student1("Bisma", 16, 88);

    student1.printStudentDetails();

    if (student1.isPassed()) {
        cout<<"Status: Passed"<<endl;
    } else {
        cout<<"Status: Failed"<<endl;
    }

    cout<<"Grade: "<<student1.getGrade()<<endl;

    return 0;
}
