#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "libraryManager.h"
#include "book.h"
#include "member.h"
#include "transaction.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

void showMainMenu();
void handleAddBook();
void handleGetBook();
void handleDeleteBook();
void handleShowBook();
void handleAddMember();
void handleGetMember();
void handleDeleteMember();
void handleShowMember();
void handleBorrowBook();
void handleReturnBook();
void handleShowTransactions();

#endif
