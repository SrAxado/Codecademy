#include "BankAccount.hpp"
#include <iostream>

using namespace std;

BankAccount::BankAccount(const string& accountNumber, const double amount):
  accountNumber_(accountNumber), balance_(amount) {
    this->addTransaction("ACCOUNT CREATION", amount);
  }

string BankAccount::getAccountNumber() const { return accountNumber_; }

double BankAccount::getBalance() const { return balance_; }

void BankAccount::setAccountNumber(const string& accountNum) {
  accountNumber_ = accountNum;
}

void BankAccount::setBalance(const double amount) {
  balance_ = amount;
}

string BankAccount::printAccountNumber() const {
  return "["+ this->getAccountNumber() + "] ";
}

void BankAccount::printAccountBalance() const {
  cout << "---> Your current balance is: " << this->getBalance() << " <---" << endl;
}

// create a transaction by adding a Transaction to the vector transactions
void BankAccount::addTransaction(const string& description, double amount) {
  transactions_.emplace_back(Transaction(description, amount));
}

// prints the last numTransactions of the current BankAccount object
void BankAccount::printTransactions(int numTransactions) const {
  cout << endl << "------ Transaction History ------" << endl;
  auto transaction = transactions_.end();
  while (transaction != transactions_.begin() and numTransactions > 0) {
    --transaction;
    --numTransactions;
    transaction->printTransaction();
  }
  cout << " -------------------------------" << endl << endl;
}

// define a transaction
BankAccount::Transaction::Transaction(const string& description, const double amount): 
  description_(description), amount_(amount) {}

// prints the current transaction object
void BankAccount::Transaction::printTransaction() const {
  cout << this->description_;
  if (this->amount_ != 0) {
    cout << " -- " << this->amount_;
  }
  cout << endl;
}

// As commented in the Bank.cpp, this wouldn't be my Bank's struture design, but in order to follow:
/*
Inside the BankAccount class, create a nested Transaction class that will handle individual transactions, 
providing an additional layer of organization for transaction-related operations.

The Transaction class will be used to model deposits and withdrawals. By placing this class inside BankAccount, 
we ensure that the transaction logic remains tightly coupled with the bank account’s functionality. 
*/

bool BankAccount::Transaction::deposit(BankAccount* account, const double amount) {
  cout << endl;
  if (amount > 0) {
    account->setBalance(account->getBalance() + amount);
    // account->transactions_.emplace_back(make_pair("DEPOSIT", amount)); // adds to transaction account's list
    // account->transactions_.push_back({"DEPOSIT", amount}); // adds to transaction account's list
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