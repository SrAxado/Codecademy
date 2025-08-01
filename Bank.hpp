#include "BankAccount.hpp"
#include <vector>

class Bank {
  private:
    std::vector<BankAccount> accounts;
  
  public:
    void createAccount(const std::string& accountNumber, const double balance);
    BankAccount* findAccount(const std::string& account);
    int transferMoney(const std::string& account1, const std::string& account2, const double amount);
    void deposit(const std::string& accountNumber, const double amount);
    void withdraw(const std::string& accountNumber, const double amount);
};