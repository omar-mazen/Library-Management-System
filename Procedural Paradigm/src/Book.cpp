#include "../include/Book.h"

int MAX_BORROWS_FOR_MEMBER = 5;
list<Book> books;
unordered_map<string, list<Book>::iterator> bookIndex;

void addBook(string &ISBN, string &title, string &author)
{
    books.emplace_back(ISBN, title, author);
    auto it = books.end();
    --it;
    bookIndex.insert({ISBN, it});
}

Book &getBook(const string &ISBN)
{
    auto it = bookIndex.find(ISBN);
    if (it != bookIndex.end())
    {
        return *(it->second);
    }
    throw invalid_argument("Book with given ISBN not found.");
}

void deleteBook(const string &ISBN)
{
    auto it = bookIndex.find(ISBN);
    if (it != bookIndex.end())
    {
        books.erase(it->second);
        bookIndex.erase(it);
    }
    else
    {
        throw invalid_argument("Book with given ISBN not found.");
    }
}

void showBook(const Book &book)
{
    cout << "ISBN: " << book.ISBN << "\n";
    cout << "Title: " << book.title << "\n";
    cout << "Author: " << book.author << "\n";
    cout << "Status: " << (book.isBorrowed ? "Borrowed" : "Available") << "\n";
    cout << "This book borrowed " << book.totalBorrows << " times.\n";
}

void setBookReturned(Book &book)
{
    if (book.isBorrowed)
    {
        book.isBorrowed = false;
    }
    else
    {
        throw invalid_argument("Book with given ISBN not borrowed.");
    }
}

void setBookBorrowed(Book &book)
{
    if (!book.isBorrowed)
    {
        book.isBorrowed = true;
        book.totalBorrows++;
    }
    else
    {
        throw invalid_argument("Book with given ISBN is already borrowed.");
    }
}

bool isBookExist(const string &ISBN)
{
    return bookIndex.find(ISBN) != bookIndex.end();
}
