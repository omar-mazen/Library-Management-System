#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "Library.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

void showMainMenu();
void handleAddBook(Library &Library);
void handleDeleteBook(Library &Library);
void handleShowBook(Library &Library);
void handleAddMember(Library &Library);
void handleDeleteMember(Library &Library);
void handleShowMember(Library &Library);
void handleBorrowBook(Library &Library);
void handleReturnBook(Library &Library);
void handleShowTransactions(Library &Library);

#endif
