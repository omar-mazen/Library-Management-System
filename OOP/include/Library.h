#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "CollectionManager.h"
#include "Transactions.h"

class Book;
class Member;

using namespace std;

class Library
{
private:
    Manager <Book> booksManager;
    Manager <Member> membersManager;
    Transactions transactions;

public:
    Library() = default;

    void addBook(const string &ISBN, const string &title, const string &author);
    void removeBook(const string &ISBN);
    void findBook(const string &ISBN) ;

    void addMember(const string &firstName, const string &lastName, const string &nationalId, const string &phoneNumber);
    void removeMember(const string &nationalId);
    void findMember(const string &nationalId) ;

    void borrowBook(const string &nationalId, const string &ISBN);
    void returnBook(const string &nationalId, const string &ISBN);
    
    void showTransactionsBeforeDays(int days);
};

#endif
