#ifndef BOOK_H
#define BOOK_H

#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

extern int MAX_BORROWS_FOR_MEMBER;

struct Book
{
    string ISBN, title, author;
    bool isBorrowed = false;
    int totalBorrows = 0;
    Book(string &ISBN, string &title, string &author) : ISBN(ISBN), title(title), author(author) {};
};

extern list<Book> books;
extern unordered_map<string, list<Book>::iterator> bookIndex;

void addBook(string &ISBN, string &title, string &author);
Book &getBook(const string &ISBN);
void deleteBook(const string &ISBN);
void showBook(const Book &book);
void setBookReturned(Book &book);
void setBookBorrowed(Book &book);
bool isBookExist(const string &ISBN);

#endif