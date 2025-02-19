#include <iostream>
#include "./include/Dashboard.h"

void initializeData(Library &library);

int main(){
    Library myLibrary = Library();
    initializeData(myLibrary);
    int choice = 0;
    while (choice != 12)
    {
        showMainMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            handleAddBook(myLibrary);
            break;
        case 2:
            handleDeleteBook(myLibrary);
            break;
        case 3:
            handleShowBook(myLibrary);
            break;
        case 4:
            handleAddMember(myLibrary);
            break;
        case 5:
            handleDeleteMember(myLibrary);
            break;
        case 6:
            handleShowMember(myLibrary);
            break;
        case 7:
            handleBorrowBook(myLibrary);
            break;
        case 8:
            handleReturnBook(myLibrary);
            break;
        case 9:
            handleShowTransactions(myLibrary);
            break;
        case 10:
            std::cout << "Exiting...\n";
            exit(1);
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }
    return 1;
}
void initializeData(Library &library)
{
    // 1. Pre-fill Books (20 Books)
    library.addBook("978-0321563842", "Effective C++", "Scott Meyers");
    library.addBook("978-0132350884", "Clean Code", "Robert C. Martin");
    library.addBook("978-0201616224", "The Pragmatic Programmer", "Andrew Hunt");
    library.addBook("978-0134685991", "The C++ Programming Language", "Bjarne Stroustrup");
    library.addBook("978-1491950357", "Programming Rust", "Jim Blandy");
    library.addBook("978-0596007126", "Head First Design Patterns", "Eric Freeman");
    library.addBook("978-0262033848", "Introduction to Algorithms", "Thomas H. Cormen");
    library.addBook("978-0131103627", "The C Programming Language", "Brian W. Kernighan");
    library.addBook("978-0321146533", "Design Patterns", "Erich Gamma");
    library.addBook( "978-0201835953",  "Refactoring",  "Martin Fowler");
    library.addBook( "978-0134494166",  "Computer Networking: A Top-Down Approach",  "James Kurose");
    library.addBook( "978-1449331818",  "Learning Python",  "Mark Lutz");
    library.addBook( "978-0201485677",  "Code Complete",  "Steve McConnell");
    library.addBook( "978-0136086208",  "Artificial Intelligence: A Modern Approach",  "Stuart Russell");
    library.addBook( "978-1118008188",  "Operating System Concepts",  "Abraham Silberschatz");
    library.addBook( "978-1449355739",  "Fluent Python",  "Luciano Ramalho");
    library.addBook( "978-0132126953",  "Software Engineering",  "Ian Sommerville");
    library.addBook( "978-0137081073",  "Agile Software Development",  "Robert C. Martin");
    library.addBook( "978-0262035613",  "Deep Learning",  "Ian Goodfellow");
    library.addBook( "978-1617292231",  "Functional Programming in Scala",  "Paul Chiusano");

    
    // 2. Pre-fill Members
    library.addMember("Alice", "Smith", "NID001", "555-1234");
    library.addMember("Bob", "Jones", "NID002", "555-5678");
    library.addMember("Charlie", "Brown", "NID003", "555-9101");
    library.addMember("Diana", "Prince", "NID004", "555-1111");
    library.addMember( "Eve", "Johnson", "NID005", "555-2222");

    // 3. Pre-fill Transactions (Borrow Books)

    library.borrowBook("NID001","978-0321563842");

    // Bob borrows "Clean Code"
    library.borrowBook("NID002","978-0132350884");

    // Charlie borrows "The Pragmatic Programmer"
    library.borrowBook("NID003","978-0201616224");

    // Diana borrows "The C++ Programming Language"
    library.borrowBook("NID004","978-0134685991");

    // Eve borrows "Programming Rust"
    library.borrowBook("NID005"
                       ,"978-1491950357");

    library.returnBook("NID002", "978-0132350884"); // Bob returns "Clean Code"
    library.returnBook("NID004"
                       ,"978-0134685991"); // Diana returns "The C++ Programming Language"
}