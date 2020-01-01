#pragma once

#include"BankAccount.h";
#include"SavingsAccount.h";
#include"CheckingAccount.h";
#include"CheckingAccountWithInterest.h";


class Transaction
{
private:
	int amount;
	int account1ID;
	int account2ID;
	double account1StartBalance;
	double account2StartBalance;
	void rollBack(double, double, BankAccount, BankAccount);
	void rollBack(double, double, CheckingAccountWithInterest, CheckingAccountWithInterest);


public:
	Transaction(BankAccount, BankAccount, double, int, int, BankAccount[]);
	Transaction::Transaction(SavingsAccount , SavingsAccount , double , int , int , SavingsAccount[]);
	Transaction::Transaction(CheckingAccount, CheckingAccount, double, int, int, CheckingAccount[]);
	Transaction::Transaction(CheckingAccountWithInterest, CheckingAccountWithInterest, double, int, int, CheckingAccountWithInterest[]);


};
