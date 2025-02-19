#ifndef TRANSACTION_TYPE_H
#define TRANSACTION_TYPE_H

#include <iostream>

enum class TransactionType
{
    RETURN,
    BORROW
};

std::string transactionType_to_string(TransactionType transactionType);

#endif