#include <iostream>
#include <vector>

class BankAccount {
  public:
    BankAccount(const std::string& accountNumber, const double amount);
    std::string getAccountNumber() const;
    double getBalance() const;
    void setAccountNumber(const std::string& accountNum);
    void setBalance(const double amount);
    std::string printAccountNumber() const;
    void printAccountBalance() const;
    void addTransaction(const std::string& description, const double amount);
    void printTransactions(const int numTransactions) const;

    // Transaction class that will handle individual transactions, providing an additional layer of organization 
  // for transaction-related operations.
    class Transaction {
      private:
        std::string description_;
        double amount_;
        
      public:
        Transaction(const std::string& description, const double amount);
        static bool deposit(BankAccount* account, const double amount);
        static bool withdraw(BankAccount* account, const double amount);
        void printTransaction() const;
    };
    
    private:
      std::string accountNumber_;
      double balance_;
      std::vector<Transaction> transactions_;
};
