#include "Library.hpp"
#include <iostream>

using namespace std;

double libraryBudget;

int main() {
  //Library library1;
  libraryBudget = 5000;
  
  cout << "Current library budget is: " << libraryBudget << endl;

  Library myLibrary;

  myLibrary.addBook("The Great Gatsby", 300);
  myLibrary.addBook("1984", 400);
  myLibrary.addBook("To Kill a Mockingbird", 350);

  myLibrary.listBooks();

  myLibrary.reserveBook("1984");
  myLibrary.borrowBook("To Kill a Mockingbird");

  myLibrary.borrowBook("1984");

  myLibrary.listBooks();

  cout << "The total number of borrowed books is: " << myLibrary.getTotalBorrowedBooks() << endl;

  cout << "The total number of reserved books is: " << myLibrary.getTotalReservedBooks() << endl;

}
