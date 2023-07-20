#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string borrower;
};

// Function prototypes
void displayMenu();
void showBookshelf(const std::vector<Book>& books);
void addBook(std::vector<Book>& books);
void removeBook(std::vector<Book>& books);
void loanBook(std::vector<Book>& books);
bool isBookMatch(const Book& book, const std::string& title, const std::string& author);

// File handling functions
void loadBooksFromFile(std::vector<Book>& books);
void saveBooksToFile(const std::vector<Book>& books);

// Constants
const std::string BOOKSHELF_FILE = "bookshelf.txt";

int main() {
    std::vector<Book> books;
    loadBooksFromFile(books);

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showBookshelf(books);
                break;
            case 2:
                addBook(books);
                break;
            case 3:
                removeBook(books);
                break;
            case 4:
                loanBook(books);
                break;
            case 0:
                std::cout << "Exiting the program. Saving changes...\n";
                saveBooksToFile(books);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    std::cout << "************************************************\n";
    std::cout << "*        Welcome to My Bookshelf!              *\n";             
    std::cout << "************************************************\n\n";
    std::cout << "1. Show Bookshelf\n";
    std::cout << "2. Add Book\n";
    std::cout << "3. Remove Book\n";
    std::cout << "4. Loan Book\n";
    std::cout << "0. Exit\n";
}

void showBookshelf(const std::vector<Book>& books) {
    std::cout << "\n---- Bookshelf ----\n";
    for (const auto& book : books) {
        std::cout << "Title: " << book.title << "\n";
        std::cout << "Author: " << book.author << "\n";
        if (!book.borrower.empty()) {
            std::cout << "Borrower: " << book.borrower << "\n";
        }
        std::cout << "-------------------\n";
    }
    std::cout << "\n";
}

void addBook(std::vector<Book>& books) {
    Book newBook;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the title of the book: ";
    std::getline(std::cin, newBook.title);

    std::cout << "Enter the author of the book: ";
    std::getline(std::cin, newBook.author);

    newBook.borrower = "";

    // Check if the book already exists (based on title and author)
    bool bookExists = false;
    for (const Book& book : books) {
        if (book.title == newBook.title && book.author == newBook.author) {
            bookExists = true;
            break;
        }
    }

    if (bookExists) {
        std::cout << "This book already exists on the shelf.\n";
    } else {
        books.push_back(newBook);
        std::cout << "Book added to the shelf.\n";
    }
}

void removeBook(std::vector<Book>& books) {
    std::string title, author;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the title of the book you want to remove: ";
    std::getline(std::cin, title);

    std::cout << "Enter the author of the book you want to remove: ";
    std::getline(std::cin, author);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (isBookMatch(*it, title, author)) {
            books.erase(it);
            std::cout << "Book removed from the shelf.\n";
            return;
        }
    }

    std::cout << "Book not found on the shelf.\n";
}

void loanBook(std::vector<Book>& books) {
    std::string title, author, borrower;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the title of the book you want to loan: ";
    std::getline(std::cin, title);

    std::cout << "Enter the author of the book you want to loan: ";
    std::getline(std::cin, author);

    for (auto& book : books) {
        if (isBookMatch(book, title, author)) {
            if (book.borrower.empty()) {
                std::cout << "Enter the name of the borrower: ";
                std::getline(std::cin, borrower);
                book.borrower = borrower;
                std::cout << "Book loaned to " << borrower << ".\n";
            } else {
                std::cout << "Book is already loaned.\n";
            }
            return;
        }
    }

    std::cout << "Book not found on the shelf or already loaned.\n";
}

bool isBookMatch(const Book& book, const std::string& title, const std::string& author) {
    return book.title == title && book.author == author;
}

void loadBooksFromFile(std::vector<Book>& books) {
    std::ifstream file(BOOKSHELF_FILE);
    if (!file) {
        std::cout << "Could not open the bookshelf file. Starting with an empty bookshelf.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Book book;
        std::getline(iss, book.title, '|');
        std::getline(iss, book.author, '|');
        std::getline(iss, book.borrower);
        books.push_back(book);
    }
    file.close();
}

void saveBooksToFile(const std::vector<Book>& books) {
    std::ofstream file(BOOKSHELF_FILE, std::ofstream::trunc);
    if (!file) {
        std::cout << "Could not save changes to the bookshelf file.\n";
        return;
    }

    for (const auto& book : books) {
        file << book.title << "|" << book.author << "|" << book.borrower << "\n";
    }
    file.close();
}
