#include "../include/Dashboard.h"

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";

void clearConsole()
{
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");
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
    std::cout << GREEN << message << RESET << std::endl;
}

void printError(const std::string &message)
{
    std::cout << RED << message << RESET << std::endl;
}
void printWarning(const std::string &message)
{
    std::cout << YELLOW << message << RESET << std::endl;
}
void pauseConsole()
{
    std::cout << "Press enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

bool confirmSubmission()
{
    std::string choice;
    while (true)
    {
        printWarning ("Do you want to submit the data? (Y/N): ");
        std::cin >> choice;
        // Convert to uppercase for consistency
        std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
        if (choice == "Y" || choice == "YES")
            return true;
        else if (choice == "N" || choice == "NO")
            return false;
        else
            printError("Invalid input. Please enter Y or N.");
    }
}

void showMainMenu()
{
    clearConsole();
    printHeader("Library Management System");
    std::cout << "1.  Add Book" << std::endl;
    std::cout << "2.  Delete Book" << std::endl;
    std::cout << "3.  Show Book" << std::endl;
    std::cout << "4.  Add Member" << std::endl;
    std::cout << "5.  Delete Member" << std::endl;
    std::cout << "6.  Show Member" << std::endl;
    std::cout << "7.  Borrow Book" << std::endl;
    std::cout << "8.  Return Book" << std::endl;
    std::cout << "9.  Show Transactions" << std::endl;
    std::cout << "10. Exit" << std::endl;
    printDivider();
    std::cout << "Select an option: ";
}

void handleAddBook(Library &library)
{
    clearConsole();
    printHeader("Add Book");
    std::string ISBN, title, author;

    // Collect user input
    std::cout << "Enter ISBN   : ";
    std::cin >> ISBN;
    std::cin.ignore(); // Clear the newline character from the buffer
    std::cout << "Enter Title  : ";
    std::getline(std::cin, title);
    std::cout << "Enter Author : ";
    std::getline(std::cin, author);

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Add Book");
    printWarning("Please review the entered information:");
    std::cout << "ISBN   : " << ISBN << std::endl;
    std::cout << "Title  : " << title << std::endl;
    std::cout << "Author : " << author << std::endl;
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.addBook(ISBN, title, author);
            printSuccess("Book added successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. Book was not added.");
    }

    pauseConsole();
}

void handleDeleteBook(Library &library)
{
    clearConsole();
    printHeader("Delete Book");
    std::string ISBN;

    // Collect user input
    std::cout << "Enter ISBN of the book to delete: ";
    std::cin >> ISBN;

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Delete Book");
    printWarning("Are you sure you want to delete the following book?");
    library.findBook(ISBN);
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.removeBook(ISBN);
            printSuccess("Book deleted successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. Book was not deleted.");
    }

    pauseConsole();
}

void handleShowBook(Library &library)
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
        library.findBook(ISBN);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleAddMember(Library &library)
{
    clearConsole();
    printHeader("Add Member");
    std::string nationalId, firstName, lastName, phoneNumber;

    // Collect user input
    std::cout << "Enter National ID  : ";
    std::cin >> nationalId;
    std::cout << "Enter First Name   : ";
    std::cin >> firstName;
    std::cout << "Enter Last Name    : ";
    std::cin >> lastName;
    std::cout << "Enter Phone Number : ";
    std::cin >> phoneNumber;

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Add Member");
    printWarning("Please review the entered information:");
    std::cout << "National ID  : " << nationalId << std::endl;
    std::cout << "First Name   : " << firstName << std::endl;
    std::cout << "Last Name    : " << lastName << std::endl;
    std::cout << "Phone Number : " << phoneNumber << std::endl;
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.addMember(nationalId, firstName, lastName, phoneNumber);
            printSuccess("Member added successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. Member was not added.");
    }

    pauseConsole();
}

void handleDeleteMember(Library &library)
{
    clearConsole();
    printHeader("Delete Member");
    std::string nationalId;

    // Collect user input
    std::cout << "Enter Member ID to delete: ";
    std::cin >> nationalId;

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Delete Member");
    printWarning("Are you sure you want to delete the following member?");
    library.findMember(nationalId);
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.removeMember(nationalId);
            printSuccess("Member deleted successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. Member was not deleted.");
    }

    pauseConsole();
}

void handleShowMember(Library &library)
{
    clearConsole();
    printHeader("View Member");
    std::string nationalId;
    std::cout << "Enter Member ID: ";
    std::cin >> nationalId;
    clearConsole();
    printHeader("View Member");
    try
    {
        library.findMember(nationalId);
    }
    catch (const std::exception &e)
    {
        printError(e.what());
    }
    pauseConsole();
}

void handleBorrowBook(Library &library)
{
    clearConsole();
    printHeader("Borrow Book");
    std::string ISBN, nationalId;

    // Collect user input
    std::cout << "Enter ISBN      : ";
    std::cin >> ISBN;
    std::cout << "Enter Member ID : ";
    std::cin >> nationalId;

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Borrow Book");
    printWarning("Please review the entered information:");
    std::cout << "ISBN      : " << ISBN << std::endl;
    std::cout << "Member ID : " << nationalId << std::endl;
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.borrowBook(nationalId, ISBN);
            printSuccess("The book has been borrowed successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. The book was not borrowed.");
    }

    pauseConsole();
}

void handleReturnBook(Library &library)
{
    clearConsole();
    printHeader("Return Book");
    std::string ISBN, nationalId;

    // Collect user input
    std::cout << "Enter ISBN      : ";
    std::cin >> ISBN;
    std::cout << "Enter Member ID : ";
    std::cin >> nationalId;

    // Display entered data for confirmation
    clearConsole();
    printHeader("Confirm Return Book");
    printWarning("Please review the entered information:");
    std::cout << "ISBN      : " << ISBN << std::endl;
    std::cout << "Member ID : " << nationalId << std::endl;
    printDivider();

    // Ask for confirmation
    if (confirmSubmission())
    {
        try
        {
            library.returnBook(nationalId, ISBN);
            printSuccess("The book has been returned successfully.");
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
    }
    else
    {
        printError("Operation canceled. The book was not returned.");
    }

    pauseConsole();
}

void handleShowTransactions(Library &library)
{
    clearConsole();
    printHeader("Show Transactions");
    int days;

    std::cout << "Enter number of days: ";
    std::cin >> days;

        try
        {
            std::string header = "Transactions for the Last " + std::to_string(days) + " Days";
            printHeader(header);
            library.showTransactionsBeforeDays(days);
        }
        catch (const std::exception &e)
        {
            printError(e.what());
        }
        pauseConsole();
}
