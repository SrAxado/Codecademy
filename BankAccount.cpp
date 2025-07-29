#include "BankAccount.hpp"
#include <iostream>

using namespace std;

BankAccount::BankAccount(string accountNumber, double balance): accountNumber(accountNumber), balance(balance) {};

string BankAccount::getAccountNumber() const { return accountNumber; }

double BankAccount::getBalance() const { return balance; }

void BankAccount::setAccountNumber(const string& accountNum) {
  accountNumber = accountNum;
}

void BankAccount::setBalance(const double amount) {
  balance = amount;
}

string BankAccount::printAccountNumber() const {
  return "["+ this->getAccountNumber() + "] ";
}

void BankAccount::printAccountBalance() const {
  cout << this->printAccountNumber() << "Your current balance is: " << this->getBalance() << endl;
}

bool BankAccount::Transaction::deposit(BankAccount* account, const double amount) {
  if (amount > 0) {
    account->setBalance(account->getBalance() + amount);
    cout << "----> " << account->printAccountNumber() << amount << " was added to your balance. <----" << endl;
    //cout << "[" << account->getAccountNumber() << "]" << "Your current balance is: " << account->getBalance() << endl;
    account->printAccountBalance();
    return true;
  } else {
    cout << "----> " << account->printAccountNumber() << "The amount to deposit can't be negative. <----" << endl;
    return false;
  }
}

bool BankAccount::Transaction::withdraw(BankAccount* account, const double amount) {
  double currentBalance = account->getBalance();
  if (currentBalance >= amount) {
    account->setBalance(currentBalance - amount);
    cout << "----> " << account->printAccountNumber() << amount << " was withdrawn from your account. <----" << endl;
    //cout << "Your current balance is: " << account->getBalance() << endl;
    account->printAccountBalance();
    return true;
  } else {
    cout << "----> " << account->printAccountNumber() << "You don't have enough funds to make that transaction. <----" <<endl;
    return false;
  }
}