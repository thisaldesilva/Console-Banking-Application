#include "CheckingAccountWithInterest.h"
//#include "CheckingAccount.h"in
#include "BankAccount.h"
#include <iostream>

CheckingAccountWithInterest::CheckingAccountWithInterest(int checkPerMonths, double monthlyFee, int accountNumber, int BSB, std::string address, int postcode, double accountBalance, double interestRate) :SavingsAccount(accountNumber, BSB,address,postcode, accountBalance, interestRate), CheckingAccount(checkPerMonths, monthlyFee, accountNumber, BSB, address, postcode, accountBalance, interestRate)
{

}

CheckingAccountWithInterest::CheckingAccountWithInterest()
{

}

void CheckingAccountWithInterest::setBalance(double balance)
{
	return CheckingAccount::setBalance(balance);
}
void CheckingAccountWithInterest::setAccountNum(int account)
{
	return CheckingAccount::setAccountNum(account);
}
void CheckingAccountWithInterest::setBSB(int bsb)
{
	return CheckingAccount::setBSB(bsb);
}
void CheckingAccountWithInterest::setAddress(std::string address)
{
	return CheckingAccount::setAddress(address);
}
void CheckingAccountWithInterest::setInterest(double interest)
{
	return CheckingAccount::setInterest(interest);
}

double CheckingAccountWithInterest::getMonthlyFee()
{
	return CheckingAccount::getMonthlyFee();
}

int CheckingAccountWithInterest::getPostCode()
{
	return CheckingAccount::getPostCode();
}

int CheckingAccountWithInterest::getAccountNum()
{
	return CheckingAccount::getAccountNum();
}
int CheckingAccountWithInterest::getBSB()
{
	return CheckingAccount::homeBranch.getBsb();
}
std::string CheckingAccountWithInterest::getAddress()
{
	return CheckingAccount::homeBranch.getAddress();
}
double CheckingAccountWithInterest::getInterest()
{
	return CheckingAccount::getInterest();
}

double CheckingAccountWithInterest::getBalance()
{
	return CheckingAccount::getBalance();
}

void CheckingAccountWithInterest::display()
{
	CheckingAccount::display();
}


CheckingAccountWithInterest::~CheckingAccountWithInterest()
{
}
