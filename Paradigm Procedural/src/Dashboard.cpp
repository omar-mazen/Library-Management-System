#include "../include/Dashboard.h"

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string BLUE = "\033[34m";

void clearConsole()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
}

void printDivider()
{
    std::cout << "=========================" << std::endl;
}

void printHeader(const std::string &title)
{
    printDivider();
    std::cout << " " << title << std::endl;
    printDivider();
}


void printSuccess(const std::string &message)
{
    std::cout << GREEN << "SUCCESS: " << message << RESET << std::endl;
}

void printError(const std::string &message)
{
    std::cout << RED << "ERROR: " << message << RESET << std::endl;
}

void pauseConsole()
{
    std::cout << "Press enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    std::cin.get();
}

void showMainMenu()
{
    clearConsole();
    printHeader("Library Management System");
    std::cout << "1.  Add Book" << std::endl;
    std::cout << "2.  Get Book" << std::endl;
    std::cout << "3.  Delete Book" << std::endl;
    std::cout << "4.  Show Book" << std::endl;
    std::cout << "5.  Add Member" << std::endl;
    std::cout << "6.  Get Member" << std::endl;
    std::cout << "7.  Delete Member" << std::endl;
    std::cout << "8.  Show Member" << std::endl;
    std::cout << "9.  Borrow Book" << std::endl;
    std::cout << "10. Return Book" << std::endl;
    std::cout << "11. Show Transactions" << std::endl;
    std::cout << "12. Exit" << std::endl;
    printDivider();
    std::cout << "Select an option: ";
}

void handleAddBook()
{
    clearConsole();
    printHeader("Add Book");
    std::string ISBN, title, author;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    std::cout << "Enter Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    addBook(ISBN, title, author);
    printSuccess("Book added successfully.");
    pauseConsole();
}

void handleGetBook()
{
    clearConsole();
    printHeader("Get Book");
    std::string ISBN;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    clearConsole();
    printHeader("Get Book");
    try
    {
        Book &book = getBook(ISBN);
        showBook(book);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleDeleteBook()
{
    clearConsole();
    printHeader("Delete Book");
    std::string ISBN;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    try
    {
        deleteBook(ISBN);
        printSuccess("Book deleted successfully.");
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleShowBook()
{
    clearConsole();
    printHeader("View Book");
    std::string ISBN;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    clearConsole();
    printHeader("View Book");
    try
    {
        Book &book = getBook(ISBN);
        showBook(book);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleAddMember()
{
    clearConsole();
    printHeader("Add Member");
    std::string nationalId, firstName, lastName, phoneNumber;
    std::cout << "Enter National ID: ";
    std::cin >> nationalId;
    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter Phone Number: ";
    std::cin >> phoneNumber;
    addMember(nationalId, firstName, lastName, phoneNumber);
    printSuccess("Member added successfully.");
    pauseConsole();
}

void handleGetMember()
{
    clearConsole();
    printHeader("Get Member");
    std::string memberId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    clearConsole();
    printHeader("Get Member");
    try
    {
        Member &member = getMember(memberId);
        showMember(member);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleDeleteMember()
{
    clearConsole();
    printHeader("Delete Member");
    std::string memberId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    clearConsole();
    printHeader("Delete Member");
    try
    {
        deleteMember(memberId);
        printSuccess("Member deleted successfully.");
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleShowMember()
{
    clearConsole();
    printHeader("Member");
    std::string memberId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    clearConsole();
    printHeader("Member");
    try
    {
        Member &member = getMember(memberId);
        showMember(member);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleBorrowBook()
{
    clearConsole();
    printHeader("Borrow Book");
    std::string ISBN, memberId;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    clearConsole();
    printHeader("Borrow Book");
    borrowBook(ISBN, memberId);
    pauseConsole();
}

void handleReturnBook()
{
    clearConsole();
    printHeader("Return Book");
    std::string ISBN, memberId;
    std::cout << "Enter ISBN: ";
    std::cin >> ISBN;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    clearConsole();
    printHeader("Return Book");
    returnBook(ISBN, memberId);
    pauseConsole();
}

void handleShowTransactions()
{
    clearConsole();
    int days;
    std::cout << "Enter number of days: ";
    std::cin >> days;
    clearConsole();
    std::string header = "Transactions for " + std::to_string(days) + " days";
    printHeader(header);
    showTransactionBeforeDays(days);
    pauseConsole();
}
