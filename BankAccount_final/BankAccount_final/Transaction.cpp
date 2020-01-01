
#include "Transaction.h"
#include <iostream>
//#include"BankAccount.h"


void Transaction::rollBack(double withdrawBalance, double depositedBalance, BankAccount account1, BankAccount account2)
{
	account1.setBalance(withdrawBalance);
	account2.setBalance(depositedBalance);
}

void Transaction::rollBack(double withdrawBalance, double depositedBalance, CheckingAccountWithInterest account1, CheckingAccountWithInterest account2)
{
	account1.setBalance(withdrawBalance);
	account2.setBalance(depositedBalance);
}


Transaction::Transaction(BankAccount withdrawAccount, BankAccount depositAccount, double amount, int withindex, int depoindex, BankAccount arra[])
{

	//declare two flag veriables to keep track of the transaction completion
	bool withdrawed = false;
	bool deposited = false;

	Transaction::amount = amount;
	account1ID = withdrawAccount.getAccountNum();
	account2ID = depositAccount.getAccountNum();

	//withdraw the amount from the 1st accont 
	if ((withdrawAccount.getBalance() - Transaction::amount) >= 0)
	{
		withdrawAccount.setBalance(withdrawAccount.getBalance() - Transaction::amount);
		withdrawed = true;

	}

	if ((depositAccount.getBalance() + amount) <= 100000)
	{
		depositAccount.setBalance(depositAccount.getBalance() + amount);
		deposited = true;
	}

	if ((withdrawed == false) || (deposited == false))
	{
		rollBack(account1StartBalance, account2StartBalance, withdrawAccount, depositAccount);
	}

	arra[withindex] = withdrawAccount;
	arra[depoindex] = depositAccount;


}

Transaction::Transaction(SavingsAccount withdrawAccount, SavingsAccount depositAccount, double amount, int withindex, int depoindex, SavingsAccount arra[])
{

	//declare two flag veriables to keep track of the transaction completion
	bool withdrawed = false;
	bool deposited = false;

	Transaction::amount = amount;
	account1ID = withdrawAccount.getAccountNum();
	account2ID = depositAccount.getAccountNum();


	//withdraw the amount from the 1st accont 
	if ((withdrawAccount.getBalance() - Transaction::amount) >= 0)
	{
		withdrawAccount.setBalance(withdrawAccount.getBalance() - Transaction::amount);
		withdrawed = true;

	}

	if ((depositAccount.getBalance() + amount) <= 100000)
	{
		depositAccount.setBalance(depositAccount.getBalance() + amount);
		deposited = true;
	}

	if ((withdrawed == false) || (deposited == false))
	{
		rollBack(account1StartBalance, account2StartBalance, withdrawAccount, depositAccount);
	}

	arra[withindex] = withdrawAccount;
	arra[depoindex] = depositAccount;


}

Transaction::Transaction(CheckingAccount withdrawAccount, CheckingAccount depositAccount, double amount, int withindex, int depoindex, CheckingAccount arra[])
{

	//declare two flag veriables to keep track of the transaction completion
	bool withdrawed = false;
	bool deposited = false;

	Transaction::amount = amount;
	account1ID = withdrawAccount.getAccountNum();
	account2ID = depositAccount.getAccountNum();


	//withdraw the amount from the 1st accont 
	if ((withdrawAccount.getBalance() - Transaction::amount) >= 0)
	{
		withdrawAccount.setBalance(withdrawAccount.getBalance() - Transaction::amount);
		withdrawed = true;

	}

	if ((depositAccount.getBalance() + amount) <= 100000)
	{
		depositAccount.setBalance(depositAccount.getBalance() + amount);
		deposited = true;
	}

	if ((withdrawed == false) || (deposited == false))
	{
		rollBack(account1StartBalance, account2StartBalance, withdrawAccount, depositAccount);
	}

	arra[withindex] = withdrawAccount;
	arra[depoindex] = depositAccount;


}


Transaction::Transaction(CheckingAccountWithInterest withdrawAccount, CheckingAccountWithInterest depositAccount, double amount, int withindex, int depoindex, CheckingAccountWithInterest arra[])
{

	//declare two flag veriables to keep track of the transaction completion
	bool withdrawed = false;
	bool deposited = false;

	Transaction::amount = amount;
	account1ID = withdrawAccount.getAccountNum();
	account2ID = depositAccount.getAccountNum();


	
	//withdraw the amount from the 1st accont 
	if ((withdrawAccount.getBalance() - Transaction::amount) >= 0)
	{
		withdrawAccount.setBalance(withdrawAccount.getBalance() - Transaction::amount);
		withdrawed = true;

	}

	if ((depositAccount.getBalance() + amount) <= 100000)
	{
		depositAccount.setBalance(depositAccount.getBalance() + amount);
		deposited = true;
	}

	if ((withdrawed == false) || (deposited == false))
	{
		rollBack(account1StartBalance, account2StartBalance, withdrawAccount, depositAccount);
	}

	arra[withindex] = withdrawAccount;
	arra[depoindex] = depositAccount;

}
