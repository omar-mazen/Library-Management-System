#include "../include/Transactions.h"

void Transactions::makeTransaction(const TransactionType &transactionType,const string &nationalId,const string &ISBN)
{
    transactionsList.emplace_back(transactionType, nationalId, ISBN);
}

void Transactions::showTransactionBeforeDays(int days)
{
    time_t dateBefore = time(NULL) - fromDayToSeconed(days);
    for (auto it = transactionsList.rbegin(); it != transactionsList.rend(); ++it)
    {
        if (it->getDateAndTime() > dateBefore)
            it->print();
    }
}