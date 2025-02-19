#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book;

const int MEMBER_MAX_BORROWS = 5; 

class Member{

    static int count;
    int totalBorrows;
    vector <string> borrowList;
    string firstName, lastName, nationalId ;
    
    public :
    string phoneNumber;
    Member(const string &firstName,const string &lastName,const string &nationalId,const string &phoneNumber);
    int getTotalBorrows()const;
    int getCurrentBorrows();
    vector<string> getBorrowList()const;
    void borrowBook(const string &ISBN);
    void returnBook(const string &ISBN);
    void print();
    string getName();
};

#endif