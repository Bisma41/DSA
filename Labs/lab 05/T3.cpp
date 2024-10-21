#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library {
private:
    string libraryName;            // Name of the library
    vector<string> books;          // Collection of book titles

public:
    // Constructor
    Library(string name) {
        libraryName = name;        // Set library name
        // Books vector is automatically empty
    }

    // Function to add a book
    void addBook(string title) {
        books.push_back(title);    // Add the book to the list
    }

    // Function to remove a book by title
    void removeBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i] == title) {
                books.erase(books.begin() + i);    // Remove the book
                cout << "Book \"" << title << "\" removed." << endl;
                return;
            }
        }
        cout << "Book \"" << title << "\" not found." << endl;
    }

    // Function to print the library details
    void printLibraryDetails() {
        cout << "Library Name: " << libraryName << endl;
        cout << "Books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << "- " << books[i] << endl;
        }
        if (books.size() == 0) {
            cout << "No books available." << endl;
        }
    }

    // Function to get the total number of books
    int totalBooksCount() {
        return books.size();       // Return number of books
    }
};

int main() {
    // Create a library
    Library myLibrary("Beginner Library");

    // Add books to the library
    myLibrary.addBook("C++ for Beginners");
    myLibrary.addBook("Learn Python");
    myLibrary.addBook("Data Structures");

    // Print the library details
    myLibrary.printLibraryDetails();

    // Remove a book
    myLibrary.removeBook("Learn Python");

    // Print the library details again
    myLibrary.printLibraryDetails();

    // Print total number of books
    cout << "Total books: " << myLibrary.totalBooksCount() << endl;

    return 0;
}
