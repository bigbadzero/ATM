

#include <iostream>
#include <vector>
#include <algorithm>
#include "Account.h"
using namespace std;

//methods
bool ValidateAccountNumber(int accountNum);
void GoodBye();

//variables
bool Exit = false;
bool LoggedIn;
int AccountNumber;
int choice;
double Amount;
string InitialMessage = "Welcome To Watsons Inc Global ATM Service\n\n Press 1 to Sign in or 0 to exit.\n";
string OptionsMessage = "Please select from the options below.\n1:Balance\n\n2:Deposit\n\n3:WithDraw\n\n0:Log Out\n\n";
string LogoutMessage = "Logging Out\n";
vector<Account> Accounts;
vector<int> ValidAccountNumbers = { 0, 1, 2, 3, 4, 5, 6 ,7, 8, 9 };

wchar_t bullet = L'\x2022';
int main()
{
    for (int number : ValidAccountNumbers) {
        Account account(number);
        Accounts.push_back(account);
    }

    while (!Exit)
    {
        cout << InitialMessage;
        cin >> choice;
        if (choice == 1) {
            system("cls");
            cout << "Please Enter Account Number: ";
            cin >> AccountNumber;
            LoggedIn = ValidateAccountNumber(AccountNumber);
            if (LoggedIn) {
                while (LoggedIn)
                {
                    cout << OptionsMessage;
                    cin >> choice;
                    if (choice == 1) {
                        Accounts[AccountNumber].DisplayBalance();
                    }
                    else if (choice == 2) {
                        cout << "Enter Amount: ";
                        cin >> Amount;
                        if (Amount > 0) {
                            Accounts[AccountNumber].Deposit(Amount);
                        }
                        else {
                            cout << "Invalid Amount\n";
                            cout << "Enter Amount: ";
                            cin >> Amount;
                            if (Amount > 0) {
                                Accounts[AccountNumber].Deposit(Amount);
                            }
                            else {
                                LoggedIn = false;
                                system("cls");
                            }
                        }
                        
                    }
                    else if (choice == 3) {
                        cout << "Enter Amount: ";
                        cin >> Amount;
                        if (Amount < Accounts[AccountNumber].GetBalance()) {
                            Accounts[AccountNumber].Withdraw(Amount);
                        }
                        else {
                            cout << "Insufficient Funds.\n";
                            cout << "Enter Amount: ";
                            cin >> Amount;
                            if (Amount < Accounts[AccountNumber].GetBalance()) {
                                Accounts[AccountNumber].Withdraw(Amount);
                            }
                            else
                            {
                                LoggedIn = false;
                                system("cls");
                            }
                        }
                        
                    }
                    else if (choice == 0) {
                        LoggedIn = false;
                        cout << LogoutMessage;
                        system("pause");
                        system("cls");
                    }
                }
            }
            else {
                cout << "Invalid Account Number Please Try Again\n";
                system("pause");
                system("cls");
            }
        }
        else
        {
            GoodBye();
            Exit = true;
        }
       
    }
    
}
bool ValidateAccountNumber(int accountNum) {
    if (find(ValidAccountNumbers.begin(), ValidAccountNumbers.end(), AccountNumber) != ValidAccountNumbers.end()) {
        return true;
    }
    else {
        return false;
    }
}

void GoodBye()
{
    cout << "Thank you for banking with us.\n Goodbye!!";
}




