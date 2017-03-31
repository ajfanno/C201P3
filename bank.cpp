#include "bank.h"
using namespace std;

void addAccount()
{
	bool found = false;
	int accountNumber, accountNumber1;
	string firstName, firstName1, lastName, lastName1;
	double balance, balance1;

	ifstream fin;
	ofstream fout, fout2;

	fin.open("Data.txt");
	fout2.open("Transactions.txt", ios::app);

	cout << "Enter an account Number greater than 0: ";
	cin >> accountNumber;

	cout << "Enter a first name: ";
	cin >> firstName;

	cout << "Enter a last name: ";
	cin >> lastName;

	cout << "Enter a balance: ";
	cin >> balance;

	while (fin >> accountNumber1)
	{

		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
		}
	}

	fin.close();

	if (found == true)
	{
		cout << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		cout << "Account failed to add! Account already exists! " << endl;
	}
	else
	{
		fout.open("Data.txt", ios::app);
		fout << setw(0) << accountNumber << setw(15) << firstName << setw(15) << lastName << setw(15) << put_money(balance) << endl;
		fout2 << setw(0) << accountNumber << setw(15) << "Deposit " << setw(15) << put_money(balance) << "    " << displayTime() << endl;
		cout << "Account added successfully! " << endl;
	}

	fout.close();
	fout2.close();
	return;
}

void deleteAccount()
{
	bool found = false;
	int accountNumber, accountNumber1;
	string firstName, firstName1, lastName, lastName1;
	double balance, balance1;

	ifstream fin, fin2;
	ofstream fout;
	fin.open("Data.txt");
	fout.open("temp.txt");

	cout << "Which account would you like to delete? ";
	cin >> accountNumber;

	while (fin >> accountNumber1)
	{
		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
			cout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		}
		else
		{
			fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		}
	}

	fin.close();
	fout.close();

	if (found == true)
	{
		cout << "The account was deleted successfully! " << endl;

		remove("Data.txt");
		rename("temp.txt", "Data.txt");
	}
	else
	{
		cout << "Account not in data base! " << endl;
	}
	return;
}

void searchAccount()
{
	bool found = false;
	int accountNumber, accountNumber1;
	string firstName, firstName1, lastName, lastName1;
	double balance, balance1;

	ifstream fin;
	fin.open("Data.txt");

	cout << "Which account would you like to find? ";
	cin >> accountNumber;

	while (fin >> accountNumber1)
	{
		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
			break;
		}
	}

	if (found == true)
	{
		cout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
	}
	else
	{
		cout << "Account not in data base! " << endl;
	}

	fin.close();
	return;
}

void withdrawal()
{
	bool found = false;
	int accountNumber, accountNumber1;
	string firstName, firstName1, lastName, lastName1;
	double balance = 0, balance1, withdrawal;

	ifstream fin;
	ofstream fout, fout2;
	fin.open("Data.txt");
	fout.open("temp.txt");
	fout2.open("Transactions.txt",ios::app);

	cout << "Which account would you like to make a withdrawal? ";
	cin >> accountNumber;

	cout << "How much would you like to withdrawal? ";
	cin >> withdrawal;

	while (fin >> accountNumber1)
	{
		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
			if ((balance1 - withdrawal) < 0)
			{
				cout << "Insufficient funds! " << endl;
				fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
			}
			else
			{
				cout << "Funds removed successfully! ";
				balance1 = balance1 - withdrawal;
				fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
				fout2 << setw(0) << accountNumber << setw(15) << "Withdrawal " << setw(15) << put_money(withdrawal) << "    " << displayTime() << endl;

			}
			found = true;
		}
		else
		{
			fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		}
	}

	if (found == true)
	{
		cout << endl;
	}

	else
	{
		cout << "Account not in data base! " << endl;
	}

	fin.close();
	fout.close();
	fout2.close();

	remove("Data.txt");
	rename("temp.txt", "Data.txt");
	return;
}

void deposit()
{
	bool found = false;
	int accountNumber, accountNumber1;
	string firstName, firstName1, lastName, lastName1;
	double balance, balance1, deposit;

	ifstream fin;
	ofstream fout, fout2;
	fin.open("Data.txt");
	fout2.open("Transactions.txt",ios::app);
	fout.open("temp.txt");

	cout << "Which account would you like to make a deposit? ";
	cin >> accountNumber;

	cout << "How much would you like to deposit? ";
	cin >> deposit;

	while (fin >> accountNumber1)
	{

		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
			cout << "Funds added! ";
			balance1 = balance1 + deposit;
			fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
			fout2 << setw(0) << accountNumber1 << setw(15) << "Deposit " << setw(15) << put_money(deposit) << "    " << displayTime() << endl;
		}
		else
		{
			fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		}
	}

	fin.close();
	fout.close();

	if (found == true)
	{
		cout << endl;
	}
	else
	{
		cout << "Account not in data base! " << endl;
	}

	remove("Data.txt");
	rename("temp.txt", "Data.txt");
	return;
}

void transfer()
{
	bool found = false, foundSecond = false, noTransfer = false, unfound = false, unfoundSecond = false;
	int accountNumber, accountNumber1, accountNumber2, accountNumberTo;
	string firstName, firstName1, firstName2, lastName, lastName1, lastName2;
	double balance, balance1, balance2, transferAmount;

	ifstream fin;
	ofstream fout, fout2;
	fin.open("Data.txt");
	fout.open("temp.txt");
	fout2.open("Transactions.txt",ios::app);

	cout << "Which account do you want to transfer from? ";
	cin >> accountNumber;

	cout << "Which account do you want to transfer to? ";
	cin >> accountNumberTo;

	cout << "How much would you like to transfer? ";
	cin >> transferAmount;

	while (fin >> accountNumber1)
	{
		fin >> firstName1 >> lastName1 >> balance1;

		if (accountNumber1 == accountNumber)
		{
			found = true;
			if ((balance1 - transferAmount) < 0)
			{
				cout << "Insufficient funds " << endl;
				balance1 = balance1;
				noTransfer = true;
				fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
			}
			else
			{
				balance1 = balance1 - transferAmount;
				fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
				fout2 << setw(0) << accountNumber1 << setw(15) << "Withdrawal " << setw(15) << transferAmount << "    " << displayTime() << endl;
			}
		}
		else
		{
			unfound = true;
			fout << setw(0) << accountNumber1 << setw(15) << firstName1 << setw(15) << lastName1 << setw(15) << put_money(balance1) << endl;
		}
	}

	fin.close();
	fout.close();
	fout2.close();

	if (found == true && noTransfer == false)
	{
		fin.open("temp.txt");
		fout.open("temp2.txt");
		fout2.open("Transactions.txt", ios::app);

		while (fin >> accountNumber2)
		{
			fin >> firstName2 >> lastName2 >> balance2;
			unfoundSecond = false;
			if (accountNumber2 == accountNumberTo)
			{
				foundSecond = true;
				cout << "Transfer successful " << endl;
				balance2 = balance2 + transferAmount;
				fout << setw(0) << accountNumber2 << setw(15) << firstName2 << setw(15) << lastName2 << setw(15) << put_money(balance2) << endl;
				fout2 << setw(0) << accountNumber2 << setw(15) << "Deposit " << setw(15) << transferAmount << "    " << displayTime() << endl;
			}
			else
			{
				unfoundSecond = true;
				fout << setw(0) << accountNumber2 << setw(15) << firstName2 << setw(15) << lastName2 << setw(15) << put_money(balance2) << endl;
			}
		}
	}
	else if (noTransfer == true)
	{
		remove("Data.txt");
		rename("temp.txt", "Data.txt");
	}

	fin.close();
	fout.close();
	fout2.close();

	if (found == true && foundSecond == true)
	{
		remove("Data.txt");
		remove("temp.txt");
		rename("temp2.txt", "Data.txt");
	}
	else if (unfound == true)
	{
		cout << "Account not in data base!" << endl;
	}
	else if (unfoundSecond == true)
	{
		cout << "Account not in data base!" << endl;
	}
	return;
}

void listAccounts()
{
	int accountNumber;
	string firstName, lastName;
	double balance;

	ifstream fin;
	fin.open("Data.txt");

	while (fin >> accountNumber)
	{
		fin >> firstName >> lastName >> balance;
		cout << setw(0) << accountNumber << setw(15) << firstName << setw(15) << lastName << setw(15) << put_money(balance) << endl;
	}

	fin.close();
	return;
}

void exitProgram()
{
	exit(0);
	return;
}

/*
void insertToHead(account * & header, account * node)
{
	node->next = header;
	header = node;
}
*/

void showValues(account * current)
{
	string tab = "\t";

	while (current != NULL)
	{
		cout << current->accountNumber << tab;
		cout << current->firstName << tab;
		cout << current->lastName << tab;
		cout << put_money(current->balance) << tab;
		cout << endl;
		current = current->next;
	}
}

string displayTime()
{
	time_t seconds = time(NULL);
	const char * current = ctime(&seconds);
	return current;
}

void listIncreasingAccountNumber()
{
	ifstream fin;
	fin.open("Data.txt");

	account * head = NULL;

	while (!fin.eof())
	{
		account * nextAccount = new account;

		fin >> nextAccount->accountNumber >> nextAccount->firstName >> nextAccount->lastName >> nextAccount->balance;
		nextAccount->next = NULL;

		if (!fin.eof())
		{
			insertByAccount(head, nextAccount);
		}
	}

	showValues(head);

	fin.close();
	return;
}

void listIncreasingBalance()
{
	ifstream fin;
	fin.open("Data.txt");

	account * head = NULL;

	while (!fin.eof())
	{
		account * nextAccount = new account;

		fin >> nextAccount->accountNumber >> nextAccount->firstName >> nextAccount->lastName >> nextAccount->balance;
		nextAccount->next = NULL;

		if (!fin.eof())
		{
			insertByBalance(head, nextAccount);
		}
	}

	showValues(head);

	fin.close();
	return;
}

void listAllTransactions()
{
	ifstream fin2;
	string type, day, month, time, year;
	int accountNumber, dayNum;
	double balance;
	fin2.open("Transactions.txt");

	while (fin2 >> accountNumber)
	{
		fin2 >> type >> balance >> day >> month >> dayNum >> time >> year;
		cout << setw(0) << accountNumber << setw(15) << type << setw(15) << put_money(balance) << setw(15) << day << " " << month << " " << dayNum << "  " << time << " " << year << endl;
	}

	fin2.close();
	return;
}


void insertByAccount(account * & H, account * n)
{
	if (H == NULL)
	{
		H = n;
	}
	else if (n->accountNumber <= H->accountNumber)
	{
		n->next = H;
		H = n;
	}

	else
	{
		account * t1 = H;
		account  * t2 = t1->next;

		while (t2 != NULL && n->accountNumber > t2->accountNumber)
		{
			t1 = t2;
			t2 = t2->next;
		}

		n->next = t2;
		t1->next = n;
	}
}

void insertByBalance(account * & H, account * n)
{
	if (H == NULL)
	{
		H = n;
	}
	else if (n->balance <= H->balance)
	{
		n->next = H;
		H = n;
	}

	else
	{
		account * t1 = H;
		account  * t2 = t1->next;

		while (t2 != NULL && n->balance > t2->balance)
		{
			t1 = t2;
			t2 = t2->next;
		}

		n->next = t2;
		t1->next = n;
	}
}


