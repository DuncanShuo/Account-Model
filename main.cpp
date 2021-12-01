#include <iostream>
#include <iomanip> //***
#include "Account.h" // Account, SavingsAccount, CheckingAccount class definition
#include <vector>
#include <string>
#include <typeinfo> //***
using namespace std; 

bool PressEnterToContinue(string mesg = "Press ENTER to continue... ");

int main()
{
    vector <Account*> accounts;
	accounts.push_back(new Account(30));
	accounts.push_back(new CheckingAccount(45.0, 1.5));
	accounts.push_back(new Account(10));
	accounts.push_back(new CheckingAccount(20, 1.5));
	accounts.push_back(new SavingsAccount(50.0, 0.03));
    accounts.push_back(new Account(20));
    accounts.push_back(new SavingsAccount(50.0, 0.03));
	accounts.push_back(new SavingsAccount(160.0, 0.03));
    accounts.push_back(new CheckingAccount(80.0, 1.5));
    accounts.push_back(new SavingsAccount(55.0, 0.03));
    accounts.push_back(new CheckingAccount(75.0, 1.5));
    accounts.push_back(new Account(260));
	accounts.push_back(new SavingsAccount(70.0, 0.03));
    accounts.push_back(new Account(80));
    accounts.push_back(new CheckingAccount(65.0, 1.5));
   
	cout << fixed << setprecision(2);
    for(int i = 0; i < (int) accounts.size(); i++){
		cout << "--[" << i + 1 << "]-----------------------------------------" << endl;
    	// * * * * * * * * * * * * * *
		accounts[i]->getBalance();
		if (!accounts[i]->debit(35))
			cout << "Debit amount exceeded account balance." << endl;
		accounts[i]->getBalance();
		accounts[i]->credit(25);
		accounts[i]->getBalance();
		if (accounts[i]->getClass() == "SavingsAccount") {
			accounts[i]->callInterest();
		}
    }
	PressEnterToContinue();


bool PressEnterToContinue(string mesg)
{
	int c;
	cout << mesg << endl;
	cout.flush();
	do c = getchar(); while ((c != '\n') && (c != EOF));
	return true;
}