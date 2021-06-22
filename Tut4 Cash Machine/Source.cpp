#include <iostream>

using namespace std;

int main()
{
	char enterOption();
	void displayBalance(int accBalance), withdraw(int& accBalance), credit(int& accBalance), operateTill(char command, int& currentBal);

	cout << "Cash Machine v1.0";
	int balance = 20;							//setStudentAccount initBal value in balance declaration instead of unnecessary function
	char option = enterOption();

	while (option != 'e')						//'e' to Exit
	{
		operateTill(option, balance);
		option = enterOption();
	}
	return 0;
}

char enterOption()								//precondition: true
{
	char choice;
	cout << "\nOPTIONS: W for withdrawal, C for credit, B for balance, E for exit \nENTER YOUR CHOICE: ";
	cin >> choice;
	return tolower(choice);
}

void displayBalance(int accBal)					//precondition: true
{
	cout << "YOUR BALANCE IS: \x9C" << accBal << endl;
}

void withdraw(int& accBalance)					//precondition: true
{
	int debitAmount;
	cout << "ENTER AMOUNT TO BE DEBITED: \x9C";
	cin >> debitAmount;
	if (debitAmount <= accBalance)
		accBalance = accBalance - debitAmount;
	else
		cout << "ERROR: OPERATION REFUSED!\n";
}

void credit(int& accBalance)					//precondition: true
{
	int creditAmount;
	cout << "ENTER AMOUNT TO BE CREDITED: \x9C";
	cin >> creditAmount;
	accBalance = accBalance + creditAmount;
}

void operateTill(char command, int& currentBal) //precondition: true
{
	switch (command)
	{
	case 'b':									//'b' for Balance
		displayBalance(currentBal);
		break;
	case 'w':									//'w' for Withdraw
		withdraw(currentBal);
		break;
	case 'c':									//'c' for Credit
		credit(currentBal);
		break;
	default:									//option is invalid
		cout << "ERROR: INVALID CHOICE, TRY AGAIN!\n";
	}
}