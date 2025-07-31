#include "BankAccount.hpp"
#include <iostream>

using namespace std;

BankAccount::BankAccount(string accountNumber, double balance): accountNumber(accountNumber), balance(balance) {}

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
  cout << "---> Your current balance is: " << this->getBalance() << " <---" << endl;
}

// create a transaction by adding a Transaction to the vector transactions
void BankAccount::addTransaction(const string description, double amount) {
  transactions.emplace_back(Transaction(description, amount));
  // cout << "--> [" << this->accountNumber << "] ";
  // transactions[0].printTransaction();
  // cout << endl;
}

void BankAccount::printTransactions(int numTransactions) const {
  cout << endl << "------ Transaction History ------" << endl;
  for (auto transaction : transactions) {
    transaction.printTransaction();
    --numTransactions;
    if (numTransactions == 0) break;
  }
  cout << " -------------------------------" << endl << endl;
}

// define a transaction
BankAccount::Transaction::Transaction(string description, double amount): description_(description), amount_(amount) {}

void BankAccount::Transaction::printTransaction() const {
  cout << this->description_;
  if (this->amount_ != 0) {
    cout << " -- " << this->amount_;
  }
  cout << endl;
}

bool BankAccount::Transaction::deposit(BankAccount* account, const double amount) {
  cout << endl;
  if (amount > 0) {
    account->setBalance(account->getBalance() + amount);
    // account->transactions.emplace_back(make_pair("DEPOSIT", amount)); // adds to transaction account's list
    // account->transactions.push_back({"DEPOSIT", amount}); // adds to transaction account's list
    account->addTransaction("DEPOSIT", amount);
    cout << account->printAccountNumber() << endl;
    cout << "--- " <<  amount << " was added to your balance." << endl;
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
  cout << endl;
  if (currentBalance >= amount) {
    account->setBalance(currentBalance - amount);
    account->addTransaction("WITHDRAW", amount);
    cout << account->printAccountNumber() << endl;
    cout << "--- " << amount << " was withdrawn from your account." << endl;
    account->printAccountBalance();
    return true;
  } else {
    cout << "----> " << account->printAccountNumber() << "You don't have enough funds to make that transaction. <----" <<endl;
    return false;
  }
}