# 📚 Library Management System

A console-based Library Management System built in C++ using two programming paradigms:

-  **Procedural Paradigm**
-  **Object-Oriented Paradigm (OOP)**

This project was created to apply and demonstrate core programming skills and design concepts using C++, STL containers, and structured code organization.

---

## 🚀 Features

Both versions of the system support:

- Add, Delete, and View Books
-  Add, Delete, and View Members
-  Borrow and Return Books
-  View Transaction History
-  Pre-filled sample data (20 books, 5 members, and transactions)
-  Menu-based console interaction

---

## 🧠 Data Structures & Design

### 🧱 Procedural Paradigm

The procedural version uses a combination of:

- `std::list`: to maintain insertion order of books and members.
- `std::unordered_map`: to allow **fast lookup** by key (e.g., ISBN, National ID).

#### ✅ Why this combination?
- **`list`** allows easy iteration and display of items in the order they were added.
- **`unordered_map`** enables constant-time access to specific records by ID.
- This hybrid approach balances **performance** with **ordered output**, similar to a basic in-memory database.

---

### 🧱 Object-Oriented Paradigm (OOP)

The OOP version follows a modular, class-based design:

- `Book`: Represents a single book with ISBN, title, and author.
- `Member`: Represents a library member with personal details.
- `Transaction`: Records borrow and return operations.
- `Library`: Manages the collections of books, members, and transactions.
- `Dashboard`: Provides user interface methods for input/output operations.

The system uses encapsulation and clean separation of responsibilities for maintainability and scalability.

---

## 🗂️ Project Structure

```

Library-Management-System/
│
├── OOP/
│   ├── include/                 # Header files for all classes
│   │   ├── Book.h
│   │   ├── Member.h
│   │   ├── Transaction.h
│   │   ├── Library.h
│   │   └── Dashboard.h
│   ├── src/                     # Class implementations
│   │   ├── Book.cpp
│   │   ├── Member.cpp
│   │   ├── Transaction.cpp
│   │   ├── Library.cpp
│   │   └── Dashboard.cpp
│   └── main.cpp                 # OOP version entry point
│
├── Procedural/
├── include/
│   ├── Book.h
│   ├── Member.h
│   ├── Transaction.h
│   ├── Library.h
│   └── Dashboard.h
│
├── src/
│   ├── Book.cpp
│   ├── Member.cpp
│   ├── Transaction.cpp
│   ├── Library.cpp
│   └── Dashboard.cpp
│   └──main.cpp│
└── README.md                   # Project documentation
````

---

## ⚙️ How to Run

### 🔧 Requirements
- C++17 or later
- Any modern C++ compiler (g++, clang++, MSVC)

---

### ▶️ OOP Version

```bash
cd OOP
g++ src/*.cpp main.cpp -o oop_app
./oop_app
````

---

### ▶️ Procedural Version

```bash
cd Procedural
g++ dashboard.cpp main.cpp -o proc_app
./proc_app
```

---

## 📌 Motivation

The project was created to:

* Practice C++ fundamentals and STL
* Apply Object-Oriented Programming (OOP) in real design
* Understand and compare two paradigms by implementing the same system
* Build a foundation for future data-driven or GUI-based applications

---

## 🧠 What I Learned

### From Procedural Paradigm:

* Using `list` and `unordered_map` effectively
* Managing data with structured functions
* Designing a simple system using just control flow and standard containers

### From OOP Paradigm:

* Applying class-based encapsulation and abstraction
* Designing clean, modular, and maintainable code
* Separating data (classes) from interface (dashboard)

---

## 🔍 Procedural vs OOP – Key Differences

| Feature                | Procedural Paradigm             | Object-Oriented Paradigm      |
| ---------------------- | ------------------------------- | ----------------------------- |
| Code Structure         | Function-based                  | Class-based                   |
| Data Management        | `list` + `unordered_map` combos | Fully encapsulated in classes |
| Separation of Concerns | Low                             | High                          |
| Maintainability        | Moderate                        | Easy to extend and maintain   |
| Reusability            | Low                             | High                          |


