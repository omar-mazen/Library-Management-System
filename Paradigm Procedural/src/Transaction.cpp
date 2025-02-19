#include "../include/Transaction.h"

list<Transaction> transactions;

void makeTransaction(const TransactionType transactionType, Member &member, Book book)
{
    string type_str;
    switch (transactionType)
    {
    case TransactionType::BORROW:
        type_str = "borrow";
        break;
    case TransactionType::RETURN:
        type_str = "return";
        break;
    default:
        throw std::invalid_argument("Invalid transaction type");
    }
    string member_srt = member.firstName + " " + member.lastName + " (id: " + member.id + ")";
    string book_srt = book.title + " (ISBN: " + book.ISBN + ")";
    transactions.emplace_back(type_str, member_srt, book_srt);
}

void showTransactionBeforeDays(int days)
{
    time_t currentTime;
    time(&currentTime);
    time_t dateBefore = currentTime - fromDayToSeconed(days);
    for (auto it = transactions.rbegin(); it != transactions.rend(); ++it)
    {
        if (it->dateAndTime > dateBefore)
        {
            cout << it->member
                 << " " << it->type
                 << "s "
                 << it->book
                 << " book at " << ctime(&(it->dateAndTime)) << "\n";
        }
    }
}
