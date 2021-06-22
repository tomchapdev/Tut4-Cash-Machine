#include <iostream>

using namespace std;

int main()
{
	int setStudentAccount();
	char enterOption();
	void displayBalance(int accBalance), withdraw(int& accBalance), credit(int& accBalance), operateTill(char command, int& currentBal);

	cout << "Cash Machine v1.0";
	int balance = setStudentAccount();
	char option = enterOption();

	while (option != 'e')
	{
		operateTill(option, balance);
		option = enterOption();
	}
	return 0;
}

int setStudentAccount()
{
	//Hardcoded for now, this should connect to the student's account
	return 20;
}

char enterOption()
{
	char choice;
	cout << "\nOPTIONS: W for withdrawal, C for credit, B for balance, E for exit \nENTER YOUR CHOICE: ";
	cin >> choice;
	return tolower(choice);
}

void displayBalance(int accBal)
{
	cout << "YOUR BALANCE IS: \x9C" << accBal << endl;
}

void withdraw(int& accBalance)
{
	int debitAmount;
	cout << "ENTER AMOUNT TO BE DEBITED: \x9C";
	cin >> debitAmount;
	if (debitAmount <= accBalance)
		accBalance = accBalance - debitAmount;
	else
		cout << "ERROR: OPERATION REFUSED!\n";
}

void credit(int& accBalance)
{
	int creditAmount;
	cout << "ENTER AMOUNT TO BE CREDITED: \x9C";
	cin >> creditAmount;
	accBalance = accBalance + creditAmount;
}

void operateTill(char command, int& currentBal)
{
	switch (command)
	{
	case 'b':
		displayBalance(currentBal);
		break;
	case 'w':
		withdraw(currentBal);
		break;
	case 'c':
		credit(currentBal);
		break;
	default:
		cout << "ERROR: INVALID CHOICE, TRY AGAIN!\n";
	}
}