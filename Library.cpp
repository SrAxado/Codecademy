#include "Library.hpp"
#include "removeElement.hpp"
#include <iostream>

using namespace std;

int Library::totalBorrowedBooks = 0;

Library::Library() {
  reservedCount = 0;
}

void Library::listBooks() {
  for (string book : bookList)
    cout << book << endl;
}

void Library::addBook(string title, double cost) {
  if (bookList.size() < 100) {
    bookList.push_back(title);
    libraryBudget += cost;
  } else {
    cout << "Library is full!" << endl;
  }
}

bool Library::borrowBook(string title) {
  for (string book : bookList) {
    if (book == title) {
      removeFromReservedBooks(book);
      cout << "Book borrowed!" << endl;
      totalBorrowedBooks++;
      removeElement(bookList, book);
      return true;
    }
  }
  cout << "Book not found!" << endl;
  return false;
}

int Library::getTotalBorrowedBooks() {
  return totalBorrowedBooks;
}

int Library::getTotalReservedBooks() const {
  return reservedCount;
}

void Library::reserveBook(string title) {
  if (reservedCount) {
    for (string book : reservedBooks) {
      if (book == title) {
        cout << "Book not reserved!" << endl; // already on the reservedBook list
        return;
      }
    }
  }
  for (string book : bookList) {
    if (book == title) {
      reservedBooks.push_back(book);
      reservedCount++;

      cout << "Book reserved: " << book << endl;
      cout << "Reserved book count: " << reservedCount << endl;
      return;
    }
  }
  cout << "Book not reserved!" << endl;
}

void Library::removeFromReservedBooks(string title) {
  if (reservedCount) {
    for (vector<string>::iterator it = reservedBooks.begin(); it != reservedBooks.end();) {
      if (*it == title) {
        it = reservedBooks.erase(it);
        reservedCount--;
        return;
      } else {
        ++it;
      }
    }
  }
};
