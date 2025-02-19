#ifndef COLLECTION_MANAGER_H
#define COLLECTION_MANAGER_H

#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <type_traits>
#include "Book.h"
#include "Member.h"

template <class T>
class Manager
{
private:
    std::list<T> data;
    std::unordered_map<std::string, typename std::list<T>::iterator> dataIndex;

    // Changed from `find(string &id)` to `find(const std::string &id)` for const-correctness
    typename std::unordered_map<std::string, typename std::list<T>::iterator>::iterator find(const std::string &id);

public:
    // Book-specific add
    template <typename U = T, typename = typename std::enable_if<std::is_same<U, Book>::value>::type>
    void add(const std::string &ISBN, const std::string &title, const std::string &author);

    // Member-specific add
    template <typename U = T, typename = typename std::enable_if<std::is_same<U, Member>::value>::type>
    void add(const std::string &firstName, const std::string &lastName, const std::string &nationalId, const std::string &phoneNumber);

    T &get(const std::string &id);
    void remove(const std::string &id);
    bool isExist(const std::string &id) const;
};

// -------------------- Definitions --------------------

// Find method
template <class T>
typename std::unordered_map<std::string, typename std::list<T>::iterator>::iterator Manager<T>::find(const std::string &id)
{
    auto it = dataIndex.find(id);
    if (it != dataIndex.end())
        return it;
    throw std::invalid_argument("Item with the given ID not found.");
}

// Add method for Book
template <class T>
template <typename U, typename>
void Manager<T>::add(const std::string &ISBN, const std::string &title, const std::string &author)
{
    if (isExist(ISBN))
        throw std::invalid_argument("This book already exists.");

    data.emplace_back(ISBN, title, author); // Assumes Book has this constructor
    auto it = std::prev(data.end());        // More idiomatic than it--
    dataIndex.emplace(ISBN, it);
}

// Add method for Member
template <class T>
template <typename U, typename>
void Manager<T>::add(const std::string &firstName, const std::string &lastName, const std::string &nationalId, const std::string &phoneNumber)
{
    if (isExist(nationalId))
        throw std::invalid_argument("This member already exists.");

    data.emplace_back(firstName, lastName, nationalId, phoneNumber); // Assumes Member has this constructor
    auto it = std::prev(data.end());
    dataIndex.emplace(nationalId, it);
}

// Get method
template <class T>
T &Manager<T>::get(const std::string &id)
{
    auto it = find(id);
    return *(it->second);
}

// Remove method
template <class T>
void Manager<T>::remove(const std::string &id)
{
    auto it = find(id);
    if constexpr (std::is_same<T, Book>::value )
    {
        if ((*it->second).getIsBorrowed())
            throw logic_error("Unable to delete: Book is currently borrowed.");
    }
    else if constexpr (std::is_same<T, Member>::value)
    {
        if ((*it->second).getTotalBorrows() > 0)
            throw logic_error("Unable to delete: Member has borrowed books.");
    }
    // No need to delete since data stores objects, not pointers
    data.erase(it->second);
    dataIndex.erase(it);
}

// isExist method
template <class T>
bool Manager<T>::isExist(const std::string &id) const
{
    return dataIndex.find(id) != dataIndex.end();
}

#endif // COLLECTION_MANAGER_H
