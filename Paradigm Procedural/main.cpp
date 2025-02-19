#include "dashboard.h"
#include <iostream>

void initializeData();

int main()
{
    initializeData();
    int choice = 0;
    while (choice != 12)
    {
        showMainMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            handleAddBook();
            break;
        case 2:
            handleGetBook();
            break;
        case 3:
            handleDeleteBook();
            break;
        case 4:
            handleShowBook();
            break;
        case 5:
            handleAddMember();
            break;
        case 6:
            handleGetMember();
            break;
        case 7:
            handleDeleteMember();
            break;
        case 8:
            handleShowMember();
            break;
        case 9:
            handleBorrowBook();
            break;
        case 10:
            handleReturnBook();
            break;
        case 11:
            handleShowTransactions();
            break;
        case 12:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }
    return 0;
}

void initializeData()
{
    // 1. Pre-fill Books (20 Books)
    std::string isbn1 = "978-0321563842", title1 = "Effective C++", author1 = "Scott Meyers";
    std::string isbn2 = "978-0132350884", title2 = "Clean Code", author2 = "Robert C. Martin";
    std::string isbn3 = "978-0201616224", title3 = "The Pragmatic Programmer", author3 = "Andrew Hunt";
    std::string isbn4 = "978-0134685991", title4 = "The C++ Programming Language", author4 = "Bjarne Stroustrup";
    std::string isbn5 = "978-1491950357", title5 = "Programming Rust", author5 = "Jim Blandy";
    std::string isbn6 = "978-0596007126", title6 = "Head First Design Patterns", author6 = "Eric Freeman";
    std::string isbn7 = "978-0262033848", title7 = "Introduction to Algorithms", author7 = "Thomas H. Cormen";
    std::string isbn8 = "978-0131103627", title8 = "The C Programming Language", author8 = "Brian W. Kernighan";
    std::string isbn9 = "978-0321146533", title9 = "Design Patterns", author9 = "Erich Gamma";
    std::string isbn10 = "978-0201835953", title10 = "Refactoring", author10 = "Martin Fowler";
    std::string isbn11 = "978-0134494166", title11 = "Computer Networking: A Top-Down Approach", author11 = "James Kurose";
    std::string isbn12 = "978-1449331818", title12 = "Learning Python", author12 = "Mark Lutz";
    std::string isbn13 = "978-0201485677", title13 = "Code Complete", author13 = "Steve McConnell";
    std::string isbn14 = "978-0136086208", title14 = "Artificial Intelligence: A Modern Approach", author14 = "Stuart Russell";
    std::string isbn15 = "978-1118008188", title15 = "Operating System Concepts", author15 = "Abraham Silberschatz";
    std::string isbn16 = "978-1449355739", title16 = "Fluent Python", author16 = "Luciano Ramalho";
    std::string isbn17 = "978-0132126953", title17 = "Software Engineering", author17 = "Ian Sommerville";
    std::string isbn18 = "978-0137081073", title18 = "Agile Software Development", author18 = "Robert C. Martin";
    std::string isbn19 = "978-0262035613", title19 = "Deep Learning", author19 = "Ian Goodfellow";
    std::string isbn20 = "978-1617292231", title20 = "Functional Programming in Scala", author20 = "Paul Chiusano";

    addBook(isbn1, title1, author1);
    addBook(isbn2, title2, author2);
    addBook(isbn3, title3, author3);
    addBook(isbn4, title4, author4);
    addBook(isbn5, title5, author5);
    addBook(isbn6, title6, author6);
    addBook(isbn7, title7, author7);
    addBook(isbn8, title8, author8);
    addBook(isbn9, title9, author9);
    addBook(isbn10, title10, author10);
    addBook(isbn11, title11, author11);
    addBook(isbn12, title12, author12);
    addBook(isbn13, title13, author13);
    addBook(isbn14, title14, author14);
    addBook(isbn15, title15, author15);
    addBook(isbn16, title16, author16);
    addBook(isbn17, title17, author17);
    addBook(isbn18, title18, author18);
    addBook(isbn19, title19, author19);
    addBook(isbn20, title20, author20);

    // 2. Pre-fill Members
    std::string nationalId1 = "NID001", firstName1 = "Alice", lastName1 = "Smith", phoneNumber1 = "555-1234";
    std::string nationalId2 = "NID002", firstName2 = "Bob", lastName2 = "Jones", phoneNumber2 = "555-5678";
    std::string nationalId3 = "NID003", firstName3 = "Charlie", lastName3 = "Brown", phoneNumber3 = "555-9101";
    std::string nationalId4 = "NID004", firstName4 = "Diana", lastName4 = "Prince", phoneNumber4 = "555-1111";
    std::string nationalId5 = "NID005", firstName5 = "Eve", lastName5 = "Johnson", phoneNumber5 = "555-2222";

    addMember(nationalId1, firstName1, lastName1, phoneNumber1);
    addMember(nationalId2, firstName2, lastName2, phoneNumber2);
    addMember(nationalId3, firstName3, lastName3, phoneNumber3);
    addMember(nationalId4, firstName4, lastName4, phoneNumber4);
    addMember(nationalId5, firstName5, lastName5, phoneNumber5);

    // 3. Pre-fill Transactions (Borrow Books)
    std::string memberId1 = "m-1"; // Alice
    std::string memberId2 = "m-2"; // Bob
    std::string memberId3 = "m-3"; // Charlie
    std::string memberId4 = "m-4"; // Diana
    std::string memberId5 = "m-5"; // Eve

    // Alice borrows "Effective C++"
    borrowBook(isbn1, memberId1);

    // Bob borrows "Clean Code"
    borrowBook(isbn2, memberId2);

    // Charlie borrows "The Pragmatic Programmer"
    borrowBook(isbn3, memberId3);

    // Diana borrows "The C++ Programming Language"
    borrowBook(isbn4, memberId4);

    // Eve borrows "Programming Rust"
    borrowBook(isbn5, memberId5);

    returnBook(isbn2, memberId2); // Bob returns "Clean Code"
    returnBook(isbn4, memberId4); // Diana returns "The C++ Programming Language"
}