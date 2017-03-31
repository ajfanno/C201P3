//Markus Cisneros, Anthony Fanno, Joseph Kamau Venanzio Project 2

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;

struct account
{
	int accountNumber;
	string firstName;
	string lastName;
	double balance;
	account * next;
};

void addAccount();
void deleteAccount();
void searchAccount();
void withdrawal();
void deposit();
void transfer();
void listAccounts();
void exitProgram();
void listIncreasingAccountNumber();
void listIncreasingBalance();
void listAllTransactions();
void buildLink(account *);
//void insertToHead(account * & header, account * node);
void showValues(account * current);
string displayTime();
void insertByAccount(account * & H, account * n);
void insertByBalance(account * & H, account * n);


