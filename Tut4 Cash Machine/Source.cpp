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
	int initBal = 20;
	return initBal;
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
	int amountToBeDebited;
	cout << "ENTER AMOUNT TO BE DEBITED: \x9C";
	cin >> amountToBeDebited;
	if (amountToBeDebited <= accBalance)
		accBalance = accBalance - amountToBeDebited;
	else
		cout << "ERROR: OPERATION REFUSED!\n";
}

void credit(int& accBalance)
{
	int amountToBeCredited;
	cout << "ENTER AMOUNT TO BE CREDITED: \x9C";
	cin >> amountToBeCredited;
	accBalance = accBalance + amountToBeCredited;
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