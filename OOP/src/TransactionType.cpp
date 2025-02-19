#include "../include/TransactionType.h"

std::string transactionType_to_string(TransactionType transactionType)
{    if (transactionType == TransactionType::BORROW)
    {
        return "borrow";
    }
    else if (transactionType == TransactionType::RETURN)
    {
        return "return";
    }
    else
        throw std::invalid_argument("Invalid transaction type");
}