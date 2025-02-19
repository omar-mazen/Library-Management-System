#include "../include/Book.h"

Book::Book(const string &ISBN,const string &title,const string &author):ISBN(ISBN),title(title),author(author),totalBorrows(0),isBorrowed(false){};

bool Book::getIsBorrowed()
{
    return isBorrowed;
}

int Book::getTotalBorrows() const
{
    return totalBorrows;
}

void Book::borrowBook()
{
    if (isBorrowed)
        throw logic_error("This book is already borrowed.");
    
    isBorrowed = true;
    totalBorrows++;
    
}

void Book::returnBook()
{
    if (!isBorrowed)
        throw logic_error("This book is not borrowed.");
    isBorrowed = false;
}

void Book::print()
{
    cout
        << "ISBN: " << ISBN << "\n"
        << "Title: " << title << "\n"
        << "Author: " << author << "\n"
        << "Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n"
        << "This book borrowed " << totalBorrows << " times.\n";
}