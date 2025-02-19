#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book{

    int totalBorrows;
    bool isBorrowed;
    
    public:
        string ISBN,title,author;
        Book(const string &ISBN,const string &title,const string &author);
        bool getIsBorrowed();
        int getTotalBorrows() const;
        void borrowBook();
        void returnBook();
        void print();
};
#endif