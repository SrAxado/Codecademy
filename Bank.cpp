#include "Bank.hpp"
#include <iostream>

using namespace std;

BankAccount* Bank::findAccount(const string& accountToFind) {
  for (BankAccount& account : accounts) {
    if (account.getAccountNumber() == accountToFind) {
      return &account;
    }
  }
  return nullptr;
}

void Bank::createAccount(const string& accountNumber, const double balance) {
  accounts.emplace_back(accountNumber, balance);
  cout << "Account created: [" << accountNumber << "] with balance: " << balance << endl;
}

// the accountIDEmit and accountIDReceive are accounts from the vector<BankAccount>
int Bank::transferMoney(const string& accountIDEmit, const string& accountIDReceive, const double amount) {
  BankAccount* accountEmit = findAccount(accountIDEmit);  
  BankAccount* accountReceive = findAccount(accountIDReceive);

  if (accountEmit && accountReceive) {
    cout << endl << endl << " ==> Money Transfer initiated <==" << endl;
    // BankAccount::Transaction transaction("coiso", 10);  // <---------------
    // if (transaction.withdraw(accountEmit, amount)) {
    //   if (transaction.deposit(accountReceive, amount)) {
    if (BankAccount::Transaction::withdraw(accountEmit, amount)) {
      if (BankAccount::Transaction::deposit(accountReceive, amount)) {
        return 1;
      } else {
        return 3;
      }
    } else {
      return 3;
    }
  } else {
    return 2;
  }
}

// The struture design of Bank is not mine, it was Codecademy's
// They wanted everyting transaction related to be encapsulated in a class, thus having to create
// two static functions in order to have acess to them while accessing through their mother's class

// I would have created a transactions class acting as a single object related to the bank account object
// and created a vector of simple data objects, transaction

void Bank::deposit(const string& accountNumber, const double amount) {
  BankAccount* account = this->findAccount(accountNumber);

  if (account) {
    BankAccount::Transaction::deposit(account, amount);
  }
}

void Bank::withdraw(const string& accountNumber, const double amount) {
  BankAccount* account = this->findAccount(accountNumber);

  if (account) {
    BankAccount::Transaction::withdraw(account, amount);
  }
}