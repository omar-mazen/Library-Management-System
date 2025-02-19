#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include "book.h"

using namespace std;

struct Member
{
    static int count;
    string id, nationalId, firstName, lastName, phoneNumber;
    int totalBorrows = 0;
    vector<string> borrowList;
    Member(string &nationalId, string &firstName, string &lastName, string &phoneNumber) : nationalId(nationalId), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), id("m-" + to_string(++count)) {};
};

extern list<Member> members;
extern unordered_map<string, list<Member>::iterator> memberIndex;

void addMember(string &nationalId, string &firstName, string &lastName, string &phoneNumber);
Member &getMember(const string &memberId);
void deleteMember(string &memberId);
void showMember(Member &member);
void addBookToMemberBorrowList(Member &member, Book &book);
void removeBookFromMemberBorrowList(Member &member, Book &book);
bool canBorrow(Member &member);

#endif