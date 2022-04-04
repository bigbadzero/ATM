#include "Account.h"
#include <iostream>
using namespace std;

void Account::DisplayBalance()
{
	cout << "Current Balance: ";
	cout <<	this->Balance;
	cout << "\n\n";
}

void Account::Withdraw(double withdrawelAmount)
{
	
		this->Balance = this->Balance - withdrawelAmount;
		if (this->Balance < 100) {
			cout << "Low Balance: $" << this->Balance << "\n\n";
		}
		else
		{
			cout << "Withdrawing: $" << withdrawelAmount << "\n";
			cout << "New Balance : $" << this->Balance <<"\n\n";
		}
}

void Account::Deposit(double depositAmount)
{	
	double OldBalance = this->Balance;
	this->Balance = this->Balance + depositAmount;
	if (this->Balance < 100) {
		cout << "Old Balance: $" << OldBalance << "\n";
		cout << "New Balance: $" << this->Balance << "\n";
		cout << "Low Balance Warning. Balance below $100." << "\n\n";
	}
	else {
		cout << "Old Balance: $" << OldBalance << "\n";
		cout << "New Balance: $" << this->Balance << "\n\n";
	}
	
}

double Account::GetBalance()
{
	return this->Balance;
}


