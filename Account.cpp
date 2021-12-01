#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account(double m) : balance(m) {

}

void Account::credit(double m) {
	cout << "Credit $" << m << " to a class " << getClass() << endl;
	balance += m;
}

bool Account::debit(double m) {
	if (balance >= m) {
		cout << "Attempting to debit $" << m << " from a class " << getClass() << endl;
		balance -= m;
		return true;
	}
	else {
		return false;
	}
}

void Account::setBalance(double m) {
	balance = m;
}

double Account::getBalance(bool print) {
	if (print)
		cout << "Balance of the class " << getClass() << " is $" << balance << endl;
	return balance;
}

string Account::getClass() {
	return "Account";
}

void Account::callInterest() {

}

CheckingAccount::CheckingAccount(double a, double b)
	:Account(a), transactionFee(b) {

}

void CheckingAccount::credit(double m) {
	cout << "Credit $" << m << " to a class CheckingAccount" << endl;
	setBalance(getBalance(false) + m);
	chargeFee();
}

bool CheckingAccount::debit(double m) {
	if (getBalance(false) >= m) {
		cout << "Attempting to debit $" << m << " from a class CheckingAccount" << endl;
		setBalance(getBalance(false) - m);
		chargeFee();
		return true;
	}
	else {
		return false;
	}
}

void CheckingAccount::chargeFee() {
	cout << "$" << transactionFee << " transaction fee charged." << endl;
	setBalance(getBalance(false) - transactionFee);
}

string CheckingAccount::getClass() {
	return "CheckingAccount";
}

SavingsAccount::SavingsAccount(double a, double b)
	:Account(a), interestRate(b) {

}

bool SavingsAccount::debit(double m) {
	if (getBalance(false) >= m) {
		cout << "Attempting to debit $" << m << " from a class SavingsAccount" << endl;
		setBalance(getBalance(false) - m);
		return true;
	}
	else {
		return false;
	}
}

double SavingsAccount::calculateInterest() {
	double interest= interestRate * getBalance(false);
	cout << "Credit $" << interest << " interest into class SavingsAccount" << endl;

	return interest;
}

string SavingsAccount::getClass() {
	return "SavingsAccount";
}

void SavingsAccount::callInterest() {
	setBalance(getBalance(false) + calculateInterest());
	getBalance();
}