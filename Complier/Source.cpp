#include<iostream>
#include<string>

using namespace std;

/*
Create a protype of a bank's program

Rules : Store the Family name and given name
		Their Unique account number between 10000 and 10099
		Balance of their account

Functions :
	I) Add a Bank Account - DONE
	II) Remove a bank account ( always a shift back is mandatory ) -
	III) Display the information of a particular client's account (by account number) - DONE
	IV) Apply a deposit to a particular account (by account number) - DONE
	V) Apply a withdrawal from a particular account (by account number) - DONE
	VI) Sort and Display the list of clients according to their balance, family name and given name, in ascending or descending order. - DONE
	VII) Display the avarage balance value of the accounts - DONE
	VIII) Display the total balance value of the accounts - DONE
	IX ) You should be capable to create an account and insert it at any position of the array. This implies shifting back or forward the oder elements of the array).
	X) Exit the application


*/

/*TODO: 1) Display the information of a particular client’s account. (by account number) - DONE
		2) Sort and display the list of clients according to their balance, family name and given name, in ascending or descending order.
		3) Menu
*/



// STRUCT USED TO CREATE ACCOUNTDATA TYPE

struct AccountData {
	string givenName;
	string familyName;
	double balance;
	int accountNumber;
};

// FUNCTIONS PROTOTYPES
AccountData addAccount();
void deleteAccount(int);
void displayData(int);
int menu();
int subMenu();
void displayAll();
void deposit(double, int);
void withdrawal(double, int);
double averageOfBalances();
double totalBalance();
void sortingFunction(int);
double numberValidation();
string stringValidation();


// DECLARE AND INITIALIZING THE ARRAY WITH ACCOUNT NUMBERS
const int sizeofarray = 5;
int index{ 0 };
AccountData accounts[sizeofarray];


// GLOBAL VARIABLES
short menuOption;
double amount;
short quantityOfAccounts{ 0 };
int accountNumber{ 0 };
int sortingType{ 0 };

// MAIN SCOPE
int main() {

	menu();
	do {
		switch (menuOption) {
			//ADD ACCOUNT
		case 1:
			/*	cout << "Please insert the posistion of your account :" << " ";
				cin >> index;*/
			accounts[index] = addAccount();
			index++;
			break;

			//REMOVE ACCOUNT
		case 2:
			cout << "Delete Menu\t(WARNING!! This is an Irreversible Deletion) " << endl;
			/*	cout << "Would you still like to Continue (Type y or n) " << endl;*/
			cout << "Please insert account number :  " << endl;

			accountNumber = numberValidation();
			deleteAccount(accountNumber);
			break;

			//DISPLAY DATA
		case 3:
			cout << "Please, insert the account's number to search the data: ";
			accountNumber = numberValidation();
			displayData(accountNumber);
			break;
			//DEPOSIT
		case 4:
			cout << "Enter your account number: " << endl;
			accountNumber = numberValidation();
			cout << "Enter the amount you want to deposit : ";
			amount = numberValidation();
			deposit(amount, accountNumber);
			break;
			//WITHDRAWAL
		case 5:
			cout << "Enter your account number: " << endl;
			accountNumber = numberValidation();
			cout << "Enter how much money you want to withdraw: ";
			amount = numberValidation();
			withdrawal(amount, accountNumber);
			break;
			//SORTING
		case 6:
			cout << "Select a sorting type :\n";
			cout << "(0) - Ascending\n";
			cout << "(1) - Descending\n";
			cout << "(2) - Balance\n";

			sortingType = numberValidation();
			sortingFunction(sortingType);
			break;
			//AVERAGE
		case 7:
			cout << "The average balance for our portfolio is $: " << averageOfBalances() << " dollars." << endl;
			//TOTAL SUM

		case 8:
			cout << "The total sum of balances for our portfolio is $: " << totalBalance() << " dollars." << endl;

		case 9:
			displayAll();
			break;
		}
		system("pause");
		subMenu();
	} while (menuOption != 10);

	return 0;

}

// FUNCTION TO ADD A NEW ACCOUNT 
AccountData addAccount() {

	AccountData c;

	bool isExistent{ false };

	cout << endl;
	cout << "--- Adding a New Account ---" << endl << endl;

	/*LOOP TO VERIFY IF THE ACCOUNT NUMBER MATCH WITH THE PATTERN*/
	do {

		cout << "\nEnter your account number between 10000 and 10099 :" << " ";
		c.accountNumber = numberValidation();

		// For Loop to check if the account number already was assinged to another client.

		for (int i{ 0 }; i < quantityOfAccounts; i++) {
			if (accounts[i].accountNumber == c.accountNumber) {
				cout << "\nThis account number already was assigned to another cliente. Please choose another number.";
				isExistent = true;
			}

		} while (c.accountNumber < 10000 || c.accountNumber > 10999 );


		cout << "Enter your first name : " << " ";
		c.givenName = stringValidation();
		/*getline(cin, c.familyName);*/

		cout << "Enter your family name : " << " ";
		c.familyName = stringValidation();
		/*getline(cin, c.givenName);*/

		cout << "Enter the amount for your first deposit : " << " ";
		c.balance = numberValidation();

		quantityOfAccounts++;

		cout << "Account Created." << "At this moment you have " << quantityOfAccounts << " Accounts." << endl << endl;

		return c;
	}


	//FUNCTION TO REMOVE AN ACCOUNT

	void deleteAccount(int accountNumber) {

		for (int i{ 0 }; i < quantityOfAccounts; i++) {

			//bool accountActive = true;

			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance = 0;
				accounts[i].accountNumber = 0;
				accounts[i].givenName = " ";
				accounts[i].familyName = " ";

			}

		}

		for (int i{ 0 }; i < quantityOfAccounts; i++) {
			for (int j{ 0 }; j < quantityOfAccounts; j++) {
				if (accounts[i].balance > accounts[j].balance) {
					AccountData temp;
					temp = accounts[i];
					accounts[i] = accounts[j];
					accounts[j] = temp;
				}
			}
		}

		cout << "Your account was delete";


	}

	// FUNCTION TO DISPLAY ALL ACCOUNT INFORMATION 
	void displayData(int accountNumber) {

		//bool accountActive{ false };

		for (int i{ 0 }; i < sizeofarray; i++) {

			if (accountNumber == accounts[i].accountNumber) {
				bool accountActive = true;

				if (accounts[i].balance > 0) {

					cout << "Hello " << accounts[i].givenName << " " << accounts[i].familyName << ", your account number is " << accounts[i].accountNumber << ". At this moment your balance is $" << accounts[i].balance << " dollars in your account." << endl;
				}
				else {
					cout << "Hello " << accounts[i].givenName << " " << accounts[i].familyName << ", your account number is " << accounts[i].accountNumber << ". At this moment your balance is negative in $" << accounts[i].balance << " dollars, please make a deposit to avoid administrative taxes." << endl;
				}

			}

			/*if (i == sizeofarray && !accountActive) {
				cout << "Account not found. Return to menu to try again.";
			}*/
		}
	}


	//FUNCTION TO DISPLAY INFORMATION FOR ALL ACCOUNTS 
	void displayAll() {
		cout << "Account Number\t" << "\tGiven Name\t" << "\tFamily Name\t" << "\tBalance\t" << endl;
		for (int i{ 0 }; i < sizeofarray; i++) {
			cout << accounts[i].accountNumber << " " << accounts[i].givenName << " " << accounts[i].familyName << "  " << accounts[i].balance << "  " << endl;
		}
	}

	// FUNCTION TO CREATE THE MENU AND SUBMENU
	int menu() {

		cout << "Welcome to National Bank of Developers. " << endl;
		cout << "Slogan" << endl;
		cout << endl;
		cout << "MENU";
		cout << endl << endl;
		cout << "Please choose one option :" << endl;
		cout << endl;
		cout << "1) Add a Bank Account" << endl;
		cout << "2) Remove a Bank Account" << endl;
		cout << "3) Display the information of a particular client's account (by account number)" << endl;
		cout << "4) Apply a deposit to a particular account(by account number)" << endl;
		cout << "5) Apply a withdrawal from a particular account(by account number)" << endl;
		cout << "6) Sortand Display the list of clients according to their balance, family nameand given name, in ascending or descending order." << endl;
		cout << "7) Display the avarage balance value of the accounts" << endl;
		cout << "8) Display the total balance value of the accounts" << endl;
		cout << "9) You should be capable to create an accountand insert it at any position of the array.This implies shifting back or forward the oder elements of the array)." << endl;
		cout << "10) Exit the application" << endl << endl;
		cout << "Option : ";
		cin >> menuOption;




		return menuOption;
		system("pause");

	};

	int subMenu() {
		cout << endl << endl;
		cout << "Please choose one option :" << endl;
		cout << endl;
		cout << "1) Add a Bank Account" << endl;
		cout << "2) Remove a Bank Account" << endl;
		cout << "3) Display the information of a particular client's account (by account number)" << endl;
		cout << "4) Apply a deposit to a particular account(by account number)" << endl;
		cout << "5) Apply a withdrawal from a particular account(by account number)" << endl;
		cout << "6) Sortand Display the list of clients according to their balance, family nameand given name, in ascending or descending order." << endl;
		cout << "7) Display the avarage balance value of the accounts" << endl;
		cout << "8) Display the total balance value of the accounts" << endl;
		cout << "9) Display all accounts information" << endl;
		cout << "10) Exit the application" << endl << endl;
		cout << "Option : ";
		cin >> menuOption;

		return menuOption;
	}
	//function to create the deposit 
	void deposit(double amount, int accountNumber) {

		for (int i{ 0 }; i < quantityOfAccounts; i++) {

			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance += amount;
				cout << " Available balance : " << accounts[i].balance << " dollars." << endl;

			}
		}
	}

	// FUNCTION TO CREATE THE WITHDRAW
	void withdrawal(double amount, int accountNumber) {

		for (int i{ 0 }; i < quantityOfAccounts; i++) {

			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance -= amount;
				cout << "\n Available balance: " << accounts[i].balance << endl;
			}
		}
	}

	//FUNCTION TO CALCULATE THE AVERAGE BALANCE VALUE
	double averageOfBalances() {
		float totalBalanceOfAccounts{ 0 };
		float averageBalance{ 0 };
		for (int i{ 0 }; i < sizeofarray; i++) {
			totalBalanceOfAccounts = totalBalanceOfAccounts + accounts[i].balance;
		}

		averageBalance = totalBalanceOfAccounts / quantityOfAccounts;

		return averageBalance;

	}

	//FUNCTION TO CALCULATE THE TOTAL SUM OF THE ACCOUNTS
	double totalBalance() {

		float sum = 0;

		for (int i = 0; i < quantityOfAccounts; i++)
		{
			sum += accounts[i].balance;
		}

		return sum;
	}

	// SORTING FUNCTION 
	void sortingFunction(int sortingType) {

		AccountData temp;


		enum SortingType {
			Ascending,
			Descending,
			Balance
		};


		if (sortingType == Ascending) {
			for (int i{ 0 }; i < sizeofarray; i++) {
				for (int j = i + 1; j < sizeofarray; j++) {
					if (accounts[i].givenName > accounts[j].givenName) {
						temp = accounts[i];
						accounts[i] = accounts[j];
						accounts[j] = temp;
					}
				}
			}

			cout << "Account Number\t" << "\tGiven Name\t" << "\tFamily Name\t" << "\tBalance\t" << endl;
			for (int i{ 0 }; i < sizeofarray; i++) {

				cout << accounts[i].accountNumber << "\t\t" << accounts[i].givenName << "\t\t" << accounts[i].familyName << "\t" << accounts[i].balance << "\t" << endl;

			}
		}

		if (sortingType == Descending) {
			for (int i{ 0 }; i < sizeofarray; i++) {
				for (int j = i + 1; j < sizeofarray; j++) {
					if (accounts[i].givenName < accounts[j].givenName) {
						temp = accounts[i];
						accounts[i] = accounts[j];
						accounts[j] = temp;
					}
				}
			}

			cout << "Account Number\t" << "\tGiven Name\t" << "\tFamily Name\t" << "\tBalance\t" << endl;
			for (int i{ 0 }; i < sizeofarray; i++) {

				cout << accounts[i].accountNumber << "\t\t" << accounts[i].givenName << "\t\t" << accounts[i].familyName << "\t" << accounts[i].balance << "\t" << endl;

			}
		}

		if (sortingType == Balance) {
			for (int i{ 0 }; i < sizeofarray; i++) {
				for (int j = i + 1; j < sizeofarray; j++) {
					if (accounts[i].balance < accounts[j].balance) {
						temp = accounts[i];
						accounts[i] = accounts[j];
						accounts[j] = temp;
					}
				}
			}

			cout << "Account Number\t" << "\tGiven Name\t" << "\tFamily Name\t" << "\tBalance\t" << endl;
			for (int i{ 0 }; i < sizeofarray; i++) {

				cout << accounts[i].accountNumber << "\t\t" << accounts[i].givenName << "\t\t" << accounts[i].familyName << "\t" << accounts[i].balance << "\t" << endl;

			}
		}

	}

	//FUNCTION TO VALIDATE INPUTS FROM THE USER. 

	double numberValidation() {

		double value;
		cin >> value;

		while (cin.fail() || cin.peek() != '\n') {
			cin.clear(); // change the fail state.
			cin.ignore(512, '\n'); // clear the buffer
			cout << "Warning !! You need to enter a valid data.";
			cin >> value;
		}

		cin.ignore(512, '\n');

		return value;

	}

	string stringValidation() {

		string string;
		cin >> string;

		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(512, '\n');
			cout << "You're typing a wrong data , please insert the correct value : " << endl;
			cin >> string;
		}
		cin.ignore(512, '\n');

		return string;
	}

