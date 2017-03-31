#include "bank.h"
using namespace std;

int main()
{
	bool runLoop = true;
	int choice;

	while (runLoop == true)
	{
		cout << "\n\n\n";
		cout << "**************************************\n";
		cout << "Please make your selection: \n";
		cout << "1. Add an Account\n";
		cout << "2. Delete an Account\n";
		cout << "3. Search an Account\n";
		cout << "4. Make a Withdrawal\n";
		cout << "5. Make a Deposit\n";
		cout << "6. Transfer Money\n";
		cout << "7. List all Records\n";
		cout << "8. List all records in the increasing order of account number\n";
		cout << "9. List all records in the increasing order of account balance\n";
		cout << "10. List all the transactions (no order requirement)\n";
		cout << "11. Exit the Program\n";
		cout << "**************************************\n";
		cout << "\n\n\n";
		cout << "Your choice:";
		cin >> choice;


		switch (choice)
		{
		case 1:
			addAccount();
			break;
		case 2:
			deleteAccount();
			break;
		case 3:
			searchAccount();
			break;
		case 4:
			withdrawal();
			break;
		case 5:
			deposit();
			break;
		case 6:
			transfer();
			break;
		case 7:
			listAccounts();
			break;
		case 8:
			listIncreasingAccountNumber();
			break;
		case 9:
			listIncreasingBalance();
			break;
		case 10:
			listAllTransactions();
			break;
		case 11:
			cout << "Thanks for stopping by!" << endl;
			exitProgram();
			break;
		default:
			cout << "Invalid input, please try again!" << endl;
		}
	}


	return 0;
}


