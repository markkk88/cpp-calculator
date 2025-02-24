#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Getter methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Display book details
    void display() const {
        cout << left << setw(25) << title 
             << setw(20) << author 
             << year << endl;
    }
};

class Library {
private:
    vector<Book> books; // Stores all books

public:
    // Add a book to the library
    void addBook(const string& title, const string& author, int year) {
        books.push_back(Book(title, author, year));
        cout << "Book added successfully!\n";
    }

    // Display all books in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << left << setw(25) << "Title"
             << setw(20) << "Author"
             << "Year" << endl;
        cout << string(55, '-') << endl;
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nMenu\n";
        cout << "1 - Add Book\n";
        cout << "2 - Display Books\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            string title, author;
            int year;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            cin.ignore();
            library.addBook(title, author, year);
            break;
        }
        case 2:
            cout << "\nBook List:\n";
            library.displayBooks();
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}