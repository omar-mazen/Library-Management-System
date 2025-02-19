#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <ctime>
#include "Utils.h"
#include "TransactionType.h"
using namespace std;

class Transaction
{
    time_t dateAndTime;
    TransactionType transactionType;
    string memberId;
    string ISBN;


    public:
        Transaction(const TransactionType &transactionType,const string &memberId,const string &ISBN);
        time_t getDateAndTime();
        void print () const;
};

#endif