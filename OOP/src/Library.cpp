#include "../include/Library.h"

// books management
void Library::addBook(const string &ISBN, const string &title, const string &author)
{
    try{
        booksManager.add(ISBN, title, author);
    }
    catch(exception &e){
        throw invalid_argument(e.what());
    }
}

void Library::removeBook(const string &ISBN)
{
    try
    {
        booksManager.remove(ISBN);
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

void Library::findBook(const string &ISBN) 
{
    try
    {
        booksManager.get(ISBN).print();
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

// members management
void Library::addMember(const string &firstName, const string &lastName, const string &nationalId, const string &phoneNumber)
{
    try
    {
        membersManager.add(firstName, lastName, nationalId, phoneNumber);
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

void Library::removeMember(const string &nationalId)
{
    try
    {
        membersManager.remove(nationalId);
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

void Library::findMember(const string &nationalId) 
{
    try
    {
        membersManager.get(nationalId).print();
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

// Transactions management
void Library::borrowBook(const string &nationalId, const string &ISBN)
{
    try{
        booksManager.get(ISBN).borrowBook();
        membersManager.get(nationalId).borrowBook(ISBN);
        transactions.makeTransaction(TransactionType::BORROW, nationalId, ISBN);
        booksManager.get(ISBN).print();
    }
    catch(exception &e){
        throw invalid_argument(e.what());
    }
}

void Library::returnBook(const string &nationalId, const string &ISBN)
{
    try
    {
        booksManager.get(ISBN).returnBook();
        membersManager.get(nationalId).returnBook(ISBN);
        transactions.makeTransaction(TransactionType::RETURN, nationalId, ISBN);
        booksManager.get(ISBN).print();
    }
    catch (exception &e)
    {
        throw invalid_argument(e.what());
    }
}

void Library::showTransactionsBeforeDays(int days)
{
    transactions.showTransactionBeforeDays(days);
}
