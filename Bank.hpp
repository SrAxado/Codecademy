#include <vector>
#include "BankAccount.hpp"

class Bank {
  private:
    vector<BankAccount> accounts;
  
  public:
    void createAccount(const string accountNumber, const double balance);
    BankAccount* findAccount(const string account);
    int transferMoney(const string account1, const string account2, const double amount);
    void deposit(const string accountNumber, const double amount);
    void withdraw(const string accountNumber, const double amount);
};