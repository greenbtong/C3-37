// acounts functions balance, get balance, withdraw, deposit
#include "Account.h"

// balance
Account::Account(double balance) {
	this->balance = balance;
}

// get balance
double Account::getBalance() {
	return balance;
}


// deposit
void Account::deposit(double amount) {
	balance = balance + amount;
}

// withdraw
void Account::withdraw(double amount) {
	if (balance < amount) {
		cout << "Insufficient balance, withdraw denied." << endl;
		return;
	}
	balance = balance - amount;
}

