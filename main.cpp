#include <iostream>
#include "Bank.hpp"

using namespace std;

int main() {
  Bank smallAndPoorBank;

  smallAndPoorBank.createAccount("1001", 5000);
  smallAndPoorBank.createAccount("1002", 3000);
  smallAndPoorBank.createAccount("1003", 2000);

  //BankAccount::Transaction bankTransaction;

  // bankTransaction.deposit(smallAndPoorBank.findAccount("1001"), 1000);
  // bankTransaction.withdraw(smallAndPoorBank.findAccount("1002"), 500);

  // BankAccount::Transaction::deposit(smallAndPoorBank.findAccount("1001"), 1000);
  // BankAccount::Transaction::deposit(smallAndPoorBank.findAccount("1002"), 500);

  smallAndPoorBank.deposit("1001", 1000);
  smallAndPoorBank.withdraw("1002", 500);

  
  int result = smallAndPoorBank.transferMoney("1001", "1002", 1000);
  
  switch (result) {
    case 1:
    cout << "[1] The transfer was successful." << endl;
    break;
    case 2:
    cout << "[2] -- ERROR: one of the accounts was not found." << endl;
    break;
    case 3:
    cout << "[3] -- ERROR: insufficient funds to complete the transfer." << endl;
    break;
    
    default:
    break;
  }

  smallAndPoorBank.findAccount("1002")->printTransactions(3);
 
  
  return 0;
}


/*

THE SECURE BANKING SYSTEM

In this project, you’ll build a basic banking system in C++ that uses encapsulation to manage account data. You’ll 
create a BankAccount class to store account details and manage how the data is accessed and changed, ensuring proper 
behaviour and efficient handling of account operations. Users interact with the account only through carefully designed 
methods, just as you interact with your bank account through an ATM or online banking platform.

BankAccount class: This class will store data like account numbers and balances as private members. It will also include 
transaction methods such as deposits, withdrawals, and balance inquiries.

Transaction class: This class will handle individual transactions, like deposits and withdrawals, within the BankAccount.

Bank class: This class will act as the overall manager of multiple BankAccount objects. It will be responsible for 
managing account creation, tracking balances, and securely handling transfers between accounts.

By the end of this project, you will have built an encapsulated banking system in which each class and method plays 
a defined role. We aim to keep the data well-organized and only accessible through proper channels, ensuring efficiency 
and security while adhering to good design principles.




*/