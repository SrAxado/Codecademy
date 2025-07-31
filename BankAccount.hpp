// #include <string>
#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
  public:
    BankAccount(string accountNumber, double balance);
    std::string getAccountNumber() const;
    double getBalance() const;
    void setAccountNumber(const string& accountNum);
    void setBalance(const double amount);
    string printAccountNumber() const;
    void printAccountBalance() const;
    void addTransaction(const string description, double amount);
    void printTransactions(int numTransactions) const;

    // Transaction class that will handle individual transactions, providing an additional layer of organization 
  // for transaction-related operations.
    class Transaction {
      private:
        string description_;
        double amount_;
        
      public:
        Transaction(string description, double amount);
        static bool deposit(BankAccount* account, const double amount);
        static bool withdraw(BankAccount* account, const double amount);
        void printTransaction() const;
    };
    
    private:
      string accountNumber;
      double balance;
      vector<Transaction> transactions;
};
