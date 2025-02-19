#include "../include/Member.h"

int Member::count = 0;
list<Member> members;
unordered_map<string, list<Member>::iterator> memberIndex;

void addMember(string &nationalId, string &firstName, string &lastName, string &phoneNumber)
{
    members.emplace_back(nationalId, firstName, lastName, phoneNumber);
    auto it = members.end();
    --it;
    memberIndex.insert({it->id, it});
}

Member &getMember(const string &memberId)
{
    auto it = memberIndex.find(memberId);
    if (it != memberIndex.end())
    {
        return *(it->second);
    }
    throw invalid_argument("Member with given ID not found.");
}

void deleteMember(string &memberId)
{
    auto it = memberIndex.find(memberId);
    if (it != memberIndex.end())
    {
        members.erase(it->second);
        memberIndex.erase(it);
    }
    else
    {
        throw invalid_argument("Member with given ID not found.");
    }
}

void showMember(Member &member)
{
    cout << "ID: " << member.id << "\n";
    cout << "Name: " << member.firstName << " " << member.lastName << "\n";
    cout << "Current Borrows: " << member.borrowList.size() << "\n";
    cout << "Total Borrows: " << member.totalBorrows << "\n";
    cout << "National ID: " << member.nationalId << "\n";
    cout << "Phone Number: " << member.phoneNumber << "\n";
    if (member.borrowList.empty())
        return;
    cout << "=========================" << "\n"
         << "current borrows" << "(" << member.borrowList.size() << ")  " << "\n"
         << "=========================" << "\n";
    for (auto it = member.borrowList.begin(); it != member.borrowList.end(); it++)
    {
        cout << "=> " << getBook(*it).title << "\n";
    }
}

void addBookToMemberBorrowList(Member &member, Book &book)
{
    member.borrowList.push_back(book.ISBN);
    member.totalBorrows++;
}

void removeBookFromMemberBorrowList(Member &member, Book &book)
{
    for (auto it = member.borrowList.begin(); it != member.borrowList.end(); ++it)
    {
        if (*it == book.ISBN)
        {
            member.borrowList.erase(it);
            return;
        }
    }
}

bool canBorrow(Member &member)
{
    return member.borrowList.size() < (MAX_BORROWS_FOR_MEMBER);
}
