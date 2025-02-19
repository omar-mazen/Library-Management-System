#include "../include/Transaction.h"
Transaction::Transaction(const TransactionType &transactionType,const  string &memberId,const string &ISBN) : transactionType(transactionType), memberId(memberId), ISBN(ISBN)
{
    dateAndTime = time(nullptr);
}
time_t Transaction::getDateAndTime() {
    return this->dateAndTime;
};
void Transaction::print () const
{
    // it->member<< " "
    //  << it->book
    cout << transactionType_to_string(this->transactionType) << "s "
         << " book at " << ctime(&(this->dateAndTime));
}
