#include "../include/Member.h"


Member::Member(const string &firstName,const string &lastName,const string &nationalId,const string &phoneNumber) : firstName(firstName), lastName(lastName), nationalId(nationalId), phoneNumber(phoneNumber), totalBorrows(0) {}


int Member::getTotalBorrows() const
{
    return totalBorrows;
}

int Member::getCurrentBorrows()
{
    return borrowList.size();
}

vector<string> Member::getBorrowList() const
{
    return borrowList;
}

void Member::borrowBook(const string &ISBN)
{
    if (borrowList.size() >= MEMBER_MAX_BORROWS)
        throw logic_error("The member has reached the borrow limit.");
    borrowList.push_back(ISBN);
    totalBorrows++;
}

void Member::returnBook(const string &ISBN)
{
    auto it = find(borrowList.begin(), borrowList.end(), ISBN);
    if (it == borrowList.end())
        throw logic_error("The member is not borrow the book with the given ISBN: " + ISBN);
    borrowList.erase(it);
}
string Member::getName(){
    return firstName+" "+lastName;
}
void Member::print() 
{
    cout << "Name: " << getName() << "\n";
    cout << "Current Borrows: " << borrowList.size() << "\n";
    cout << "Total Borrows: " << totalBorrows << "\n";
    cout << "National ID: " << nationalId << "\n";
    cout << "Phone Number: " << phoneNumber << "\n";
    if (borrowList.empty())
        return;
    cout << "=========================" << "\n"
         << "current borrows" << "(" << borrowList.size() << ")  " << "\n"
         << "=========================" << "\n";
    // for (auto it = borrowList.begin(); it != borrowList.end(); it++)
    // {
    //     cout << "=> " << getBook(*it).title << "\n";
    // }
}