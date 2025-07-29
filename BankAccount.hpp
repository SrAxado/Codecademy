#include <string>
#include <iostream>

using namespace std;

class BankAccount {
  public:
    BankAccount(string accountNumber, double balance);
    string getAccountNumber() const;
    double getBalance() const;
    void setAccountNumber(const string& accountNum);
    void setBalance(const double amount);
    string printAccountNumber() const;
    void printAccountBalance() const;

    // Transaction class that will handle individual transactions, providing an additional layer of organization 
  // for transaction-related operations.
    class Transaction {
      public:
        bool deposit(BankAccount* account, const double amount);
        bool withdraw(BankAccount* account, const double amount);
    };
    
    private:
      string accountNumber;
      double balance;
      //vector<Transaction> transactions;
};
