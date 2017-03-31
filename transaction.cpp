#include <iostream>
#include "transaction.h"


//initialize bankaccount and set Customer_ID to id, first_name to fname, last_name to lname, and balance to b 
bank_account::bank_account(int id, string fname, string lname, double b)
{
	//Your code goes here
}

bank_account::bank_account()
{
	Customer_ID = 9999;
	first_name = "anonymous";
	last_name = "anonymous";
	balance = 0;
}

//rest first_name to s
void bank_account::reset_first_name(string s)
{
	//Your code goes here
}

//reset last_name to s
void bank_account::reset_last_name(string s)
{
	//Your code goes here
}

int bank_account::get_id()
{
	return Customer_ID;
}

string bank_account::get_first_name()
{
	return first_name;
}


//return last name
string bank_account::get_last_name()
{
	//Your code goes here
}


// return balance
double bank_account::get_balance()
{
	//Your code goes here
}


// initialize transaction and set account_number to act, transaction_type to type, amount to a, and date_and_time to day
transaction::transaction(int act, string type, double a, string day)
{
	//Your code goes here
}

transaction::transaction()
{
	account_number = 9999;
	transaction_type = "unknown";
	amount = 0;
	date_and_time = "unknown";
}

int transaction::get_account_number()
{
	return account_number;
}

string transaction::get_transaction_type()
{
	return transaction_type;
}

double transaction::get_amount()
{
	return amount;
}

string transaction::get_transaction_date()
{
	return date_and_time;
}

void transaction::output()
{
	if (transaction_type == "Deposit")
	{
		cout << date_and_time << "\t" << "+" << amount << " USD\n";
	}
	else if (transaction_type == "Withdraw")
	{
		cout << date_and_time << "\t" << "-" << amount << " USD\n";
	}
}

//constructor
account_analysis::account_analysis(int id)
{
	this->id = id;
}

//insert a transaction into the vector
void account_analysis::insert_transaction(transaction t)
{
	//Your code goes here
}

//return the nunber of transactions in the vector
int account_analysis::number_transactions()
{
	return all_trans.size();
}

//return the average amount of deposit
double account_analysis::average_deposit()
{
	//Your code goes here
}

//return the average amount of withdraw
double account_analysis::average_withdraw()
{
	//Your code goes here
}

//return the maximum amount of deposit
double account_analysis::max_deposit()
{
	//Your code goes here
}

// return the maximum amount of withdraw
double account_analysis::max_withdraw()
{
	//Your code goes here
}
