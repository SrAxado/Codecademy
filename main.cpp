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
