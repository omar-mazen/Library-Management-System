#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H
#include <iostream>
#include <vector>
#include "book.h"
#include "member.h"
#include "transaction.h"
#include <ctime>
using namespace std;

void borrowBook(const string &ISBN, const string &memberId);
void returnBook(const string &ISBN, const string &memberId);

#endif