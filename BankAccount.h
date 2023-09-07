#pragma once
#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
public:
	double userBalance, userPin;
	string userName;

	BankAccount()
	{
		userBalance = 0;
		userPin = 0;
		userName = "";
	}
	~BankAccount()
	{
		userBalance = 0;
		userPin = 0;
		userName = "";
	}

	BankAccount(string name, double pin, double balance)
	{
		userPin = pin;
		userBalance = balance;
		userName = name;
	}

	void withdraw(double amount)
	{
		userBalance -= amount;
		cout << "You have successfully withdrawan $" << amount << ".\n";
		checkBalance();
	}
	void checkBalance()
	{
		cout << "Your current balance is $" << userBalance << ".\n";
	}
	void deposit(double amount)
	{
		userBalance += amount;
		cout << "You have successfully deposited $" << amount << ".\n";
		checkBalance();
	}

};

