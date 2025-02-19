#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <iostream>
#include <vector>
#include <Utils.h>
#include <Transaction.h>
using namespace std;

class Transactions
{

    vector <Transaction> transactionsList;

    public:
        void makeTransaction(const TransactionType &transactionType,const string &nationalId,const string &ISBN);
        void showTransactionBeforeDays(int days) ;
};
#endif