#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include "book.h"
#include "member.h"
#include "utils.h"

using namespace std;

enum class TransactionType
{
    BORROW,
    RETURN
};
struct Transaction
{
    string type; // borrow or return
    time_t dateAndTime;
    string member;
    string book;

    Transaction(string type, string &memberId, string &ISBN)
        : type(type), member(memberId), book(ISBN)
    {
        time(&dateAndTime);
    }
};
extern list<Transaction> transactions;

void makeTransaction(const TransactionType transactionType, Member &member, Book book);
void showTransactionBeforeDays(int days);

#endif