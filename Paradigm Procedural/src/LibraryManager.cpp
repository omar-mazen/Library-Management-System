#include "../include/Transaction.h"
void borrowBook(const string &ISBN, const string &memberId)
{
    try
    {
        Member &member = getMember(memberId);

        if (!canBorrow(member))
        {
            cout << "The member " << member.firstName << " " << member.lastName
                 << " has reached the borrow limit.\n";
            return;
        }

        Book &book = getBook(ISBN); // This will throw if the book is not found

        if (book.isBorrowed)
        {
            cout << "The book with ISBN: " << ISBN << " is already borrowed.\n";
            return;
        }

        setBookBorrowed(book);
        addBookToMemberBorrowList(member, book);
        makeTransaction(TransactionType::BORROW, member, book);
        cout << "Book borrowed successfully.\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << "\n";
    }
}

#include "transaction.h"
void returnBook(const string &ISBN, const string &memberId)
{
    try
    {
        Book &book = getBook(ISBN);
        if (!book.isBorrowed)
        {
            cout << "The book with ISBN: " << ISBN << " is not borrowed.\n";
            return;
        }
        Member &member = getMember(memberId);
        setBookReturned(book);
        removeBookFromMemberBorrowList(member, book);
        makeTransaction(TransactionType::RETURN, member, book);
        cout << "Book returned successfully.\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << "\n";
    }
}
