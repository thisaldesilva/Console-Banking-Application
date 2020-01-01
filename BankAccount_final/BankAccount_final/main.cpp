#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"BankAccount.h"
#include"CheckingAccount.h"
#include"SavingsAccount.h"
#include"CheckingAccountWithInterest.h"
#include "Transaction.h"


using namespace std;

const int MAXIMUMACCOUNTS = 10;

//function declarations
int getInt(string);
double getDouble(string);
void createATransferMoney();
void createAccount(CheckingAccount[] , SavingsAccount[] , CheckingAccountWithInterest[] , int* , int* , int* );
void addAccount(CheckingAccountWithInterest[], int);
void addAccount(CheckingAccount[], int);
void addAccount(SavingsAccount[], int);
void viewAccounts(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int);
void viewDetails(SavingsAccount, int);
void viewDetails(CheckingAccount, int);
void viewDetails(CheckingAccountWithInterest, int);
void writeAccountDetails(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int, string, string);
void getFileData(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int &, int &, int &, string &, string &);
void displayReport(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int, int, int);
void transfer(SavingsAccount[], int);
void transfer(CheckingAccount[], int);
void transfer(CheckingAccountWithInterest[], int);
void makeTrasAction(SavingsAccount[], CheckingAccount[], CheckingAccountWithInterest[], int , int , int );



int main()
{ 
	
	//Declare variables to store the username and password
	string username;
	string password;

	//declare 3 arrays of size 10 for different types of accounts
	SavingsAccount savingsAccounts[10];
	CheckingAccount checkingAccounts[10];
	CheckingAccountWithInterest checkAndInterest[10];

	int numSavingsAccounts = 0;
	int numCheckAccounts = 0;
	int numCheckAndInterestAccounts = 0;


	bool logged = false;


	//check if the file exist 
	ifstream ifile("BankAccounts.txt");
	if (ifile)
	{
		string checkUserName;
		string checkPassword;
		getFileData(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts, username, password);

		{
			cout << "Please enter the username: ";
			cin >> checkUserName;

			cout << "Please enter the password: ";
			cin >> checkPassword; 

			cout << "\n\nYou are now logged-in\n\n";

		} while ((checkUserName.compare(username) != 0 || checkPassword.compare(password) != 0));
	}
	else
	{
		cout << "Thank you choosing us ! \nCreate an Account\n\n ";
		//if not create an userAccount
		cout << "Please enter the username: ";
		getline(cin, username);

		std::cin.ignore();

		cout << "Please enter the password for the account: ";
		getline(cin, password);
		

	
		//at the initial attempt log the user in
		logged = true;
		cout << "\n\nYou are now logged-in\n\n";
	}

	int userChoice = 0;

	while (userChoice != 5)
	{


		//display the menue 
		cout << "\n\nWelcome to the Inter Banking Pty." << endl;

		cout << "\n1) Create an Account" << endl;
		cout << "2) Transfer Money " << endl;
		cout << "3) View Accounts" << endl;
		cout << "4) Produce Report" << endl;
		cout << "5) Exit the program\n" << endl;

		
		userChoice = getInt("Please select your choice: ");

		//validate user choice 
		while (userChoice > 5 || userChoice <= 0)
		{
			userChoice = getInt("Please select your choice: ");
		}

		switch (userChoice)
		{
		case 1:
			createAccount(checkingAccounts, savingsAccounts, checkAndInterest, &numSavingsAccounts, &numCheckAccounts, &numCheckAndInterestAccounts);
			cout << "_______________________________________________________________________________\n";
			break;
		case 2:
			//createATransferMoney();
			makeTrasAction(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts);
			break;

		case 3:
			viewAccounts(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts);
			cout << "_______________________________________________________________________________\n";
			break;

			//break;

		case 4:
			displayReport(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts);
			break;

		default:
			break;
		}

	}
	
	writeAccountDetails(savingsAccounts, checkingAccounts, checkAndInterest, numSavingsAccounts, numCheckAccounts, numCheckAndInterestAccounts, username, password);

	system("pause");
	return 0;
}

void getFileData(SavingsAccount sAccounts[], CheckingAccount cAccounts[], CheckingAccountWithInterest ciAccounts[], int &savingsNum, int &checkingNum, int &checkAndInterestNum, string &usename, string &password)
{
	int lineNum = 1;

	string line;
	
	std::ifstream input("BankAccounts.txt");

	getline(input, line);
	usename = line;

	getline(input, line);
	password = line;

	getline(input, line);
	savingsNum = stoi(line);

	getline(input, line);
	checkingNum = stoi(line);

	getline(input, line);
	checkAndInterestNum = stoi(line);

	int sNum = savingsNum;
	int cNum = checkingNum;
	int ciNum = checkAndInterestNum;
	
	//get the savings account to it's array
	for (int i = 0; i < sNum; i++)
	{
		
			string line;

			string accountNumber;
			string accountBalance;
			string interest;
			string BSB;
			string address;
			string postCode;
			 
			getline(input, accountNumber, ',');
			getline(input, accountBalance, ',');
			getline(input, interest, ',');
			getline(input, BSB, ',');
			getline(input, address, ',');
			getline(input, postCode, '\n');

			//creat an savings accout object
			SavingsAccount account(stoi(accountNumber), stoi(BSB), address, stoi(postCode), stod(accountBalance), stod(interest));
			//add the object to the array
			sAccounts[i] = account;
	}
	
	//get the checking accounts to it's array
	for (int i = 0; i < cNum; i++)
	{

		string line;

		string accountNumber;
		string accountBalance;
		string interest;
		string BSB;
		string address;
		string postCode;
		string monthlyFee;
		string checksPerMonth;


		getline(input, accountNumber, ',');
		getline(input, accountBalance, ',');
		getline(input, BSB, ',');
		getline(input, address, ',');
		getline(input, postCode, ',');
		getline(input, monthlyFee, ',');
		getline(input, checksPerMonth, ',');
		getline(input, interest, '\n');

		//creat an checkin accout object
		CheckingAccount account( stoi(checksPerMonth), stod(monthlyFee), stoi(accountNumber), stoi(BSB), address, stoi(postCode), stod(accountBalance), stod(interest) );
		//add the object to the array
		cAccounts[i] = account;
	}

	//get the checking accounts with interest to it's array
	for (int i = 0; i < ciNum; i++)
	{

		string line;

		string accountNumber;
		string accountBalance;
		string interest;
		string BSB;
		string address;
		string postCode;
		string monthlyFee;
		string checksPerMonth;


		getline(input, accountNumber, ',');
		getline(input, accountBalance, ',');
		getline(input, BSB, ',');
		getline(input, address, ',');
		getline(input, postCode, ',');
		getline(input, monthlyFee, ',');
		getline(input, checksPerMonth, ',');
		getline(input, interest, '\n');

		//creat an checkin accout object
		CheckingAccountWithInterest account(stoi(checksPerMonth), stod(monthlyFee), stoi(accountNumber), stoi(BSB), address, stoi(postCode), stod(accountBalance), stod(interest));
		//add the object to the array
		ciAccounts[i] = account;
	}

}
void viewDetails(CheckingAccountWithInterest accounts[], int withInterestNum)
{
	if (withInterestNum == 0)
	{
		cout << "No Checking Accounts with Interest exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Savings Accounts Details Below.\n\n";
		for (int i = 0; i < withInterestNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewDetails(CheckingAccount accounts[], int checkingNum)
{
	if (checkingNum == 0)
	{
		cout << "No Checking Accounts exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Checking Accounts Details Below.\n\n";
		for (int i = 0; i < checkingNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewDetails(SavingsAccount accounts[], int savingsNum)
{
	if (savingsNum == 0)
	{
		cout << "No Savings Accounts exist." << endl;
	}
	else
	{
		cout << "\nDisplaying Savings Accounts Details Below.\n\n";
		for (int i = 0; i < savingsNum; i++)
		{
			accounts[i].display();
			cout << endl;
		}

		cout << endl;
	}
}

void viewAccounts(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterestAccounts[], int savingsNum, int checkingNum, int checkingWithInterestNum)
{
	int userChoice = 0;

	while (userChoice != 4)
	{
		cout << "_______________________________________________________________________________\n";


		//display the menue 
		cout << "\nPlease Select the account type view details.  \n" << endl;

		cout << "1) Savings Accounts" << endl;
		cout << "2) Checking Accounts" << endl;
		cout << "3) Checking Accounts With Interest" << endl;
		cout << "4) Exit to main menu\n" << endl;

		userChoice = getInt("Please select your choice: ");

		//validate user choice 
		while (userChoice > 4 || userChoice <= 0)
		{
			userChoice = getInt("");
		}

		switch (userChoice)
		{
		case 1:
			viewDetails(savingAccounts, savingsNum);
			break;
		case 2:
			viewDetails(checkingAccounts, checkingNum);
			break;

		case 3:
			viewDetails(withInterestAccounts, checkingWithInterestNum);
			break;

		default:
			break;
		}

	}
}


void createATransferMoney()
{
	cout << "Transfer money " << endl;
}
void createAccount(CheckingAccount checkingAccounts[], SavingsAccount savingsAccounts[], CheckingAccountWithInterest checkAndInterest[], int* numSaving, int* numCheck, int* numcheckAndInterest)
{
	//declare a variable to store the user preferred user choice
	int userChoice = 0;

	//display the menu to the user
	cout << "Please enter the type of the account " << endl;
	
	if (*numSaving < MAXIMUMACCOUNTS)
	{
		cout << "1) Savigs Account" << endl;
	}
	if (*numCheck < MAXIMUMACCOUNTS)
	{
		cout << "2) Checking Account" << endl;
	}
	if (*numcheckAndInterest < MAXIMUMACCOUNTS)
	{
		cout << "3) Checking Account with Interest " << endl;
	}

	cout << "4) exit " << endl;

	do
	{
		userChoice = getInt("Please enter your choice: ");

	} while( (userChoice > 4 || userChoice < 1)  );


	//perform the relevent t
	switch (userChoice)
	{
	case 1:
		if (*numSaving < MAXIMUMACCOUNTS)
		{
			addAccount(savingsAccounts, *numSaving);
			*numSaving += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for Savings accounts" << endl;
		}
		break;

	case 2:
		if (*numCheck < MAXIMUMACCOUNTS)
		{
			addAccount(checkingAccounts, *numCheck);
			*numCheck += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for checking accounts" << endl;
		}
		break;
		
	case 3:
		if (*numcheckAndInterest < MAXIMUMACCOUNTS)
		{
			addAccount(checkAndInterest, *numcheckAndInterest);
			*numcheckAndInterest += 1;
		}
		else
		{
			cout << "Maximum Account limit reached for checking with interest accounts" << endl;
		}
		break;

	default:
		break;
	}

}


void addAccount(CheckingAccountWithInterest accounts[] , int index)
{
	//declare variables to hold the user inputs
	int accountNumber = 0;
	double balance;
	double monthlyFee;
	int numChecks;
	string address;
	int postcode;
	int BSB;
	 
	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);
	
	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode: ";
	postcode = getInt("");

	cout << "Enter the monthly fee: ";
	monthlyFee = getDouble("");

	cout << "Enter the check allocation: ";
	numChecks = getInt("");

	//create an object of the account type
	CheckingAccountWithInterest account(numChecks, monthlyFee, accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;

}

void addAccount(CheckingAccount accounts[], int index)
{
	//declare variables to hold the user inputs
	int accountNumber = 0;
	double balance;
	int BSB;
	string address;
	int postcode;
	double monthlyFee;
	int numChecks;

	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);

	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode: ";
	postcode = getInt("");

	cout << "Enter the monthly fee: ";
	monthlyFee = getDouble("");

	cout << "Enter the check allocation: ";
	numChecks = getInt("");

	//create an object of the account type
	CheckingAccount account(numChecks, monthlyFee, accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;

}

void addAccount(SavingsAccount accounts[], int index)
{
	//declare variables to hold the user inputs
	int accountNumber =0;
	double balance;
	int BSB;
	string address;
	int postcode;

	//generate the account number randomly between 1000 9999
	accountNumber = 1000 + (rand() % 1000);

	//promt the user for values
	cout << "\nEnter the account balance: ";
	balance = getDouble("");

	cout << "Enter the BSB number: ";
	BSB = getInt("");

	cout << "Enter the address: ";
	cin >> address;
	std::cin.ignore();

	cout << "Enter the Postcode";
	postcode = getInt("");

	//create an object of the account type
	SavingsAccount account(accountNumber, BSB, address, postcode, balance);

	// add the account to the relevent index
	accounts[index] = account;
}


int getInt(string message)
{
	cout << message;
	std::string line;
	int d;
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> d)
		{
			if (ss.eof())
			{   // Success
				break;
			}
		}
		std::cout << "Error!" << " " << message;
	}
	return d;;
}

double getDouble(string message)
{
	cout << message ;
	std::string line;
	double d;
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> d)
		{
			if (ss.eof())
			{   // Success
				break;
			}
		}
		std::cout << "Error!" << " " <<  message;
	}
	return d;


	system("pause");

}

void displayReport(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterest[], int savingsize, int checkingSize, int withInterestSize)
{
	

	//write savings accountst to the file

	cout << "\n\n..............................  Report Begins  ...............................\n\n";

	cout << "Savings Accounts: \n\n";
	cout << "Account No \t Account Balance \t BSB No  Branch address  Postcode \n\n";


	for (int i = 0; i < savingsize; i++)
	{
		cout << savingAccounts[i].getAccountNum() << " \t\t " << savingAccounts[i].getBalance() << " \t\t\t "  \
			<< savingAccounts[i].getBSB() << " \t " << savingAccounts[i].getAddress() << " \t " << savingAccounts[i].getPostCode() << endl;
	}

	cout << endl;

	//write checking accounts to the file

	cout << "\n\nChecking Accounts: \n\n";
	cout << "A/C No Balance  BSB No  Branch address Postcode Fees Monthly checks allowed \n\n";


	for (int i = 0; i < checkingSize; i++)
	{
		cout << checkingAccounts[i].getAccountNum() << "\t" << checkingAccounts[i].getBalance() << "\t"  \
			<< checkingAccounts[i].getBSB() << "\t" << checkingAccounts[i].getAddress() << "\t" << checkingAccounts[i].getPostCode() << "\t"
			<< checkingAccounts[i].getMonthlyFee() << "\t" << checkingAccounts[i].getChecksPerMonth() << endl;
	}

	cout << endl;

	//write checking accounts with interest to the file

	cout << "\n\nChecking Accounts with Interest: \n\n";
	cout << "A/C No Balance  BSB No  Branch address Postcode Fees Monthly checks allowed \n\n";


	for (int i = 0; i < withInterestSize; i++)
	{
		cout << withInterest[i].getAccountNum() << "\t" << withInterest[i].getBalance() << "\t"  \
			<< withInterest[i].getBSB() << "\t" << withInterest[i].getAddress() << "\t" << withInterest[i].getPostCode() << "\t"
			<< withInterest[i].getMonthlyFee() << "\t" << withInterest[i].getChecksPerMonth() << endl;
	}

	cout << "\n\n..............................  Report End  ....................................\n\n";
}

void writeAccountDetails(SavingsAccount savingAccounts[], CheckingAccount checkingAccounts[], CheckingAccountWithInterest withInterest[], int savingsize, int checkingSize, int withInterestSize, string username , string password)
{
	//open the file to write
	ofstream writeFile;
	writeFile.open("BankAccounts.txt");

	//writing the username and the password of the user at the top of the file
	writeFile << username << endl;
	writeFile << password << endl;
	writeFile << savingsize << endl;
	writeFile << checkingSize << endl;
	writeFile << withInterestSize << endl;
	
	//write savings accountst to the file

	//writeFile << "\nSavings Accounts: ";
	//writeFile << "Below account Details are in the format of - Account No, Account Balance, BSB No, Branch address and Postcode \n";


	for (int i = 0; i < savingsize; i++)
	{
		writeFile << savingAccounts[i].getAccountNum() << ", " << savingAccounts[i].getBalance() << ", "  \
			<< savingAccounts[i].getInterest() << ", " << savingAccounts[i].getBSB() << ", " << savingAccounts[i].getAddress() << ", " << savingAccounts[i].getPostCode() << endl;
	}

	
	
	for (int i = 0; i < checkingSize; i++)
	{
		writeFile << checkingAccounts[i].getAccountNum() << ", " << checkingAccounts[i].getBalance() << ", "  \
			<< checkingAccounts[i].getBSB() << ", " << checkingAccounts[i].getAddress() << ", " << checkingAccounts[i].getPostCode() << ", "
			<< checkingAccounts[i].getMonthlyFee() << ", " << checkingAccounts[i].getChecksPerMonth()  << ", " << checkingAccounts[i].getInterest() << endl;
	}



	for (int i = 0; i < withInterestSize; i++)
	{
		writeFile << checkingAccounts[i].getAccountNum() << ", " << checkingAccounts[i].getBalance() << ", "  \
			<< checkingAccounts[i].getBSB() << ", " << checkingAccounts[i].getAddress() << ", " << checkingAccounts[i].getPostCode() << ", "
			<< checkingAccounts[i].getMonthlyFee() << ", " << checkingAccounts[i].getChecksPerMonth() << ", " << checkingAccounts[i].getInterest() << endl;
	}



	//close the file
	writeFile.close();
}

void makeTrasAction(SavingsAccount sAccounts[], CheckingAccount cAccounts[], CheckingAccountWithInterest ciAccounts[], int sNum, int cNum, int ciNum)
{
	int withIndex;
	int depoIndex;
	int wacoount;
	int daccount;
	double ammount;

	SavingsAccount withdrawAccount;
	SavingsAccount depositAccount;

	int userChoice = 0;

	while (userChoice != 4)
	{
		cout << "_______________________________________________________________________________\n";


		//display the menue 
		cout << "\nPlease Select the transaction account types.  \n" << endl;

		cout << "1) Savings Accounts to savings account" << endl;
		cout << "2) Checking Account to cheching account" << endl;
		cout << "3) chechking with interest account to checking with interest account" << endl;
		cout << "4) Exit to main menu" << endl;

		userChoice = getInt("Please select your choice: ");

		//validate user choice 
		while (userChoice > 4 || userChoice <= 0)
		{
			userChoice = getInt("");
		}

		switch(userChoice)
		{
		case 1:
			transfer(sAccounts, sNum);
			break;
		case 2:
			transfer(cAccounts, cNum);
			break;
		case 3:
			transfer(ciAccounts, ciNum);
			break;

		default:
			break;
		}

	}

}


void transfer( SavingsAccount sAccounts[], int sNum)
{
	int withIndex;
	int depoIndex;
	int wacoount;
	int daccount;
	double ammount;

	SavingsAccount withdrawAccount;
	SavingsAccount depositAccount;

	cout << "Please Enter the withdraw account Number: ";
	cin >> wacoount;

	cout << "Please Enter the deposit  account Number: ";
	cin >> daccount;

	cout << "Please enter the amount: ";
	cin >> ammount;

	for (int accountIndex = 0; accountIndex < 10; accountIndex++)
	{
		if (sAccounts[accountIndex].getAccountNum() == wacoount)
		{
			withdrawAccount = sAccounts[accountIndex];
			withIndex = accountIndex;
		}
		if (sAccounts[accountIndex].getAccountNum() == daccount)
		{
			depositAccount = sAccounts[accountIndex];
			depoIndex = accountIndex;
		}
	}

	if ((depoIndex != NULL) && (withIndex != NULL))
	{

		Transaction::Transaction(withdrawAccount, depositAccount, ammount, withIndex, depoIndex, sAccounts);

	}
	else
	{
		cout << "Invalid Account Number" << endl;
	}

	
}

void transfer(CheckingAccount cAccounts[], int cNum)
{
	int withIndex;
	int depoIndex;
	int wacoount;
	int daccount;
	double ammount;

	CheckingAccount withdrawAccount;
	CheckingAccount depositAccount;

	cout << "Please Enter the withdraw account Number: ";
	cin >> wacoount;

	cout << "Please Enter the deposit  account Number: ";
	cin >> daccount;

	cout << "Please enter the amount: ";
	cin >> ammount;

	for (int accountIndex = 0; accountIndex < 10; accountIndex++)
	{
		if (cAccounts[accountIndex].getAccountNum() == wacoount)
		{
			withdrawAccount = cAccounts[accountIndex];
			withIndex = accountIndex;
		}
		if (cAccounts[accountIndex].getAccountNum() == daccount)
		{
			depositAccount = cAccounts[accountIndex];
			depoIndex = accountIndex;
		}
	}

	if ((depoIndex != NULL) && (withIndex != NULL))
	{

		Transaction::Transaction(withdrawAccount, depositAccount, ammount, withIndex, depoIndex, cAccounts);

	}
	else
	{
		cout << "Invalid Account Number" << endl;
	}
}

void transfer(CheckingAccountWithInterest ciAccounts[], int ciNum)
{
	int withIndex;
	int depoIndex;
	int wacoount;
	int daccount;
	double ammount;

	CheckingAccountWithInterest withdrawAccount;
	CheckingAccountWithInterest depositAccount;

	cout << "Please Enter the withdraw account Number: ";
	cin >> wacoount;

	cout << "Please Enter the deposit  account Number: ";
	cin >> daccount;

	cout << "Please enter the amount: ";
	cin >> ammount;

	for (int accountIndex = 0; accountIndex < 10; accountIndex++)
	{
		if (ciAccounts[accountIndex].getAccountNum() == wacoount)
		{
			withdrawAccount = ciAccounts[accountIndex];
			withIndex = accountIndex;
		}
		if (ciAccounts[accountIndex].getAccountNum() == daccount)
		{
			depositAccount = ciAccounts[accountIndex];
			depoIndex = accountIndex;
		}
	}

	if ((depoIndex != NULL) && (withIndex != NULL))
	{

		Transaction::Transaction(withdrawAccount, depositAccount, ammount, withIndex, depoIndex, ciAccounts);

	}
	else
	{
		cout << "Invalid Account Number" << endl;
	}
}
