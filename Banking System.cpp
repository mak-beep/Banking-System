#include <iostream>
#include "BankAccount.h"
using namespace std;

// GLOBAL VARIABLES
const int MAX_ACCOUNTS = 10;
BankAccount all_accounts[MAX_ACCOUNTS];
BankAccount login_account;
bool logged_in = false;
int index = 0;
string login_UserName;
double login_Pin;

// Functions

// Main menu
void main_menu()
{
    cout << "\n\t*\tWelcome to the Bank ATM\t\t*\t\n";
    cout << "1. Existing User\n";
    cout << "2. New User\n";
    cout << "3. Exit\n";
}

// User menu
void user_menu()
{
    cout << "\n\tWelcome "<<login_account.userName<<",\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw Cash\n";
    cout << "3. Check Balance\n";
    cout << "4. Log Out\n";
}

// Checking against user record
bool validation()
{
    for (int i = 0; i < index;i++)
    {
        if (all_accounts[i].userName == login_UserName)
        {
            if (all_accounts[i].userPin == login_Pin)
            {
                cout << "Login Successful.\n";
                login_account = all_accounts[i];
                return true;
            }
            else
            {
                cout << "Incorrect Password. Try Again.\n";
                return false;
            }
        }
    }
    cout << "No record found for " << login_UserName << endl;
    return false;
}

// Taking user input for login
bool login()
{
    cout << "Username : ";
    cin.ignore();
    getline(cin, login_UserName);
    cout << "Pin : ";
    cin >> login_Pin;
    bool validated = validation();
    return validated;
}

// Creating new account
void signUp()
{
    cout << endl;
    cout << "Username : ";
    cin.ignore();
    getline(cin, login_UserName);
    cout << "Pin : ";
    cin >> login_Pin;
    double balance;
    cout << "Balance : ";
    cin >> balance;
    BankAccount new_account(login_UserName, login_Pin, balance);
    all_accounts[index] = new_account;
    index++;
}

// Logging out and updating system
void logOut()
{
    for (int i = 0; i < index;i++)
    {
        if (all_accounts[i].userName == login_account.userName)
        {
            if (all_accounts[i].userPin == login_account.userPin)
            {
                all_accounts[i].userBalance = login_account.userBalance;
            }
        }
    }
    cout << "You have successfully logged out, " << login_account.userName << endl;
    login_account.~BankAccount();
    logged_in = false;
}

// Taking menu inputs
int take_input()
{
    cout << "Select an option : ";
    int x;
    cin >> x;
    return x;
}

// Main Function
int main()
{
    // Dummy accounts
    BankAccount account1("Moaaz", 726, 3000);
    BankAccount account2("Mak", 222, 1000);
    all_accounts[index] = account1;
    index++;
    all_accounts[index] = account2;
    index++;

    // Main operation
    while (true)
    {
        // main_menu
        main_menu();
        switch (take_input())
        {
        case 1:
            // Existinf user, check for login
            if (login())
            {
                // Logged in
                logged_in = true;
                while (logged_in)
                {
                    // User menu
                    user_menu();
                    switch (take_input())
                    {
                    case 1:
                        // Deposit
                        cout << "Enter amount you wish to deposit : ";
                        int deposit_amount;
                        cin >> deposit_amount;
                        login_account.deposit(deposit_amount);
                        break;
                    case 2:
                        // Withdraw
                        cout << "Enter amount you wish to withdraw : ";
                        int withdraw_amount;
                        cin >> withdraw_amount;
                        login_account.withdraw(withdraw_amount);
                        break;
                    case 3:
                        // Balance Inquiry
                        login_account.checkBalance();
                        break;
                    case 4:
                        // Log out
                        logOut();
                        break;
                    default:
                        // Handling exception
                        cout << "Invalid Option. Try Again.\n";
                        break;
                    }
                }
            }
            break;
        case 2:
            // New User Sign up
            signUp();
            break;
        case 3:
            // Exiting
            cout << "Exiting...\n";
            exit(0);
            break;
        default:
            // Handling exception
            cout << "Invalid Option. Try Again.\n";
            break;
        }
    }
}
