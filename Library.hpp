#include <vector>
#include <string>

using namespace std;

extern double libraryBudget;

class Library {
  private:
    vector<string> bookList;
    static int totalBorrowedBooks;
    int reservedCount;
    vector<string> reservedBooks;
    void removeFromReservedBooks(string title);

  public:
    Library();
    void addBook(string title, double bookCost);
    bool borrowBook(string title);
    void listBooks();
    static int getTotalBorrowedBooks();
    int getTotalReservedBooks() const;
    void reserveBook(string title);
};
