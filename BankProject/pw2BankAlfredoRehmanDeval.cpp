#include<iostream>
#include<string>
#include<iomanip>

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
bool checkedAccount(int);
bool accountNumbersCheck(int);


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

	system("Color 02");

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
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << "Delete Menu\t(WARNING!! This is an Irreversible Deletion) " << endl;
				/*	cout << "Would you still like to Continue (Type y or n) " << endl;*/
				cout << "Please insert account number :  " << endl;

				accountNumber = numberValidation();
				deleteAccount(accountNumber);
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;
			//DISPLAY DATA
		case 3:
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << "Please, insert the account's number to search the data: ";
				accountNumber = numberValidation();
				displayData(accountNumber);
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;
		case 4:
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << "Enter your account number: " << endl;
				accountNumber = numberValidation();
				cout << "Enter the amount you want to deposit : ";
				amount = numberValidation();
				deposit(amount, accountNumber);
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;
			
		case 5:
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << "Enter your account number: " << endl;
				accountNumber = numberValidation();
				cout << "Enter how much money you want to withdraw: ";
				amount = numberValidation();
				withdrawal(amount, accountNumber);
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;
			
		case 6:
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << "Select a sorting type :\n";
				cout << "(0) - Ascending\n";
				cout << "(1) - Descending\n";
				cout << "(2) - Balance\n";

				sortingType = numberValidation();
				sortingFunction(sortingType);
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;
			//AVERAGE
		case 7:
			
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << fixed << setprecision(2) <<  "The average balance for our portfolio is $: " << averageOfBalances() << " dollars." << endl;
				//TOTAL SUM
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;

		case 8:
			if (!accountNumbersCheck(quantityOfAccounts)) {
				cout << fixed << setprecision(2) << "The total sum of balances for our portfolio is $: " << totalBalance() << " dollars." << endl;
			}
			else {
				cout << "ERROR : We don't have any account in our database. Please create an account before to use this feature." << endl;
			}
			break;

		case 9:
			displayAll();
			break;

		default:
			cout << "Please choose a valid option\n";
		
		}
		system("pause");
		subMenu();
	} while (menuOption != 10);

	return 0;

}

//

// FUNCTION TO ADD A NEW ACCOUNT 
AccountData addAccount() {

	AccountData c;
	bool isExistent{ false };

	cout << endl;
	cout << "--- Adding a New Account ---" << endl ;

	/*LOOP TO VERIFY IF THE ACCOUNT NUMBER MATCH WITH THE PATTERN AND VALIDATE THE DATA*/
	do {

		isExistent = false;
		cout << "\nEnter your account number between 10000 and 10099 :" << " ";
		c.accountNumber = numberValidation();

		isExistent = checkedAccount(c.accountNumber); // Function to confirm if this account number is already assigned to another client
		if (isExistent) {
			cout << "\nERROR : This account number already was assigned to another cliente. Please choose another number.\n";
		}

	} while (c.accountNumber < 10000 || c.accountNumber > 10099 || isExistent == true);


		cout << "Enter your first name : " << " ";
		c.givenName = stringValidation();
		/*getline(cin, c.familyName);*/

		cout << "Enter your family name : " << " ";
		c.familyName = stringValidation();
		/*getline(cin, c.givenName);*/

		cout << "Enter the amount for your first deposit : " << " ";
		c.balance = numberValidation();

		quantityOfAccounts++; // Incrementor of accounts created. Will be use to check the lenght of account's array.

		cout << endl;
		cout << setw(20) << " \t --- Account Created --- \t" << endl << endl;
		cout << setw(20) << " \t --- Quantity Of Accounts : " << quantityOfAccounts << endl;
		cout << endl;

	return c;
}


//FUNCTION TO REMOVE AN ACCOUNT

void deleteAccount(int accountNumber) {

	if (checkedAccount(accountNumber)) {
		
		//FOR LOOP TO ERASE ALL CLIENT'S DATA.
		
		for (int i{ 0 }; i < quantityOfAccounts; i++) {
			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance = 0;
				accounts[i].accountNumber = 0;
				accounts[i].givenName = " ";
				accounts[i].familyName = " ";

			}

		}

		// FOR LOOP TO ORGANIZE THE INDEX AVOIDING HOLES INSIDE THE ARRAY.

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

		cout << setw(20) << "\t --- Operation Completed Successfully --- \t\n";
		cout << setw(20) << "\t --- The account number " << accountNumber <<  " was deleted --- \t\n";
		cout << endl;

	}
	else {
		cout << "Please insert an existent account number. ";
	}

}

// FUNCTION TO DISPLAY ALL ACCOUNT INFORMATION 
void displayData(int accountNumber) {

	
	if(checkedAccount(accountNumber)){

		//FOP LOOP TO FIND INFORMATION REGARDING THE REQUESTED ACCOUNT

		for (int i{ 0 }; i < sizeofarray; i++) {

			if (accountNumber == accounts[i].accountNumber) {

				if (accounts[i].balance > 0) {
					cout << endl;
					cout << setw(20) << " \t --- Client Information --- \t" << endl << endl;
					cout << setw(20) << " \t --- Account Number :  --- \t" << accounts[i].accountNumber << endl;
					cout << endl;
					cout << "Hello " << accounts[i].givenName << " " << accounts[i].familyName <<".At this moment your balance is $" << accounts[i].balance << " dollars in your account." << endl;
					cout << endl;
				}
				else {
					cout << endl;
					cout << setw(20) << " \t --- Client Information --- \t" << endl << endl;
					cout << setw(20) << " \t --- Account Number :  --- \t" << accounts[i].accountNumber << endl;
					cout << endl;
					cout << "Hello " << accounts[i].givenName << " " << accounts[i].familyName << ". At this moment your balance is negative in $" << accounts[i].balance << " dollars, please make a deposit to avoid administrative taxes." << endl;
					cout << endl;
				}

			}

		}
	}
	else {
		cout << "Please insert an existent account number. ";
	}
}

//FUNCTION TO DISPLAY INFORMATION FOR ALL ACCOUNTS 
void displayAll() {
	
	//IF TO CHECK IF THERE ARE ACCOUNTS TO BE DISPLAYED
	if (!accountNumbersCheck(quantityOfAccounts)) {
		//FOR LOOP TO PRINT THE DATA.
		cout << "Account Number\t" << "\tGiven Name\t" << "\tFamily Name\t" << "\tBalance\t" << endl;
		for (int i{ 0 }; i < sizeofarray; i++) {
			cout << accounts[i].accountNumber << " \t\t " << accounts[i].givenName << " \t\t\t " << accounts[i].familyName << " \t\t\t " << fixed << setprecision(2) << accounts[i].balance << "  " << endl;
		}
	}
	else {
		cout << " You don't have any account in our database. Please create an account before to use this function." << endl;
	}
}

// FUNCTION TO CREATE THE MENU AND SUBMENU
int menu() {
	cout << endl;
	cout << right; 
	cout << "\t\t\t\tWelcome to National Bank of Developers. " << endl;
	cout << "\t\t\t\tPushing Your Financial Life Without Bugs" << endl;
	cout << endl;
	cout << setw(55) << "MENU";
	cout << endl << endl;
	cout << "\tPlease choose one option :" << endl;
	cout << endl;
	cout << "\t1) Add a Bank Account" << endl;
	cout << "\t2) Remove a Bank Account" << endl;
	cout << "\t3) Display the information of a particular client's account (by account number)" << endl;
	cout << "\t4) Apply a deposit to a particular account(by account number)" << endl;
	cout << "\t5) Apply a withdrawal from a particular account(by account number)" << endl;
	cout << "\t6) Display the list of clients with Sorting options." << endl;
	cout << "\t7) Display the avarage balance value of the accounts" << endl;
	cout << "\t8) Display the total balance value of the accounts" << endl;
	cout << "\t9) Display all accounts information" << endl;
	cout << "\t10) Exit the application" << endl << endl;
	cout << "\tOption : ";
	cin >> menuOption;

	return menuOption;
	system("pause");

};

int subMenu() {
	cout << endl << endl;
	cout << "\tPlease choose one option :" << endl;
	cout << endl;
	cout << "\t1) Add a Bank Account" << endl;
	cout << "\t2) Remove a Bank Account" << endl;
	cout << "\t3) Display the information of a particular client's account (by account number)" << endl;
	cout << "\t4) Apply a deposit to a particular account(by account number)" << endl;
	cout << "\t5) Apply a withdrawal from a particular account(by account number)" << endl;
	cout << "\t6) Display the list of clients with Sorting options." << endl;
	cout << "\t7) Display the avarage balance value of the accounts" << endl;
	cout << "\t8) Display the total balance value of the accounts" << endl;
	cout << "\t9) Display all accounts information" << endl;
	cout << "\t10) Exit the application" << endl << endl;
	cout << "\tOption : ";
	cin >> menuOption;

	return menuOption;
}
//function to create the deposit 
void deposit(double amount, int accountNumber) {

	if (checkedAccount(accountNumber)) {
		for (int i{ 0 }; i < quantityOfAccounts; i++) {

			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance += amount;
				cout << "Available balance : " << accounts[i].balance << " dollars." << endl;

			}
		}
	}
	else {
		cout << "Please insert an existent account number. ";

	}
}

// FUNCTION TO CREATE THE WITHDRAW
void withdrawal(double amount, int accountNumber) {

	if (checkedAccount(accountNumber)) {
		for (int i{ 0 }; i < quantityOfAccounts; i++) {

			if (accountNumber == accounts[i].accountNumber) {

				accounts[i].balance -= amount;
				cout << "\n Available balance: " << accounts[i].balance << endl;
			}
		}
	}
	else {
		cout << "Please insert an existent account number. ";

	}
}

//FUNCTION TO CALCULATE THE AVERAGE BALANCE VALUE
double averageOfBalances() {
	double totalBalanceOfAccounts{ 0 };
	double averageBalance{ 0 };

	if (!accountNumbersCheck(quantityOfAccounts)) {
		for (int i{ 0 }; i < sizeofarray; i++) {
			totalBalanceOfAccounts = totalBalanceOfAccounts + accounts[i].balance;
		}

		averageBalance = totalBalanceOfAccounts / quantityOfAccounts;

		return averageBalance;
	}
}

//FUNCTION TO CALCULATE THE TOTAL SUM OF THE ACCOUNTS
double totalBalance() {

	double sum = 0;

	if (!checkedAccount(accountNumber)) {
		for (int i = 0; i < quantityOfAccounts; i++)
		{
			sum += accounts[i].balance;
		}

		return sum;
	}
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

	while (cin.fail() || cin.peek() != '\n' || value <= 0) {
		cin.clear(); // change the fail state.
		cin.ignore(512, '\n'); // clear the buffer
		cout << "Warning !! You need to enter a valid data : ";
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


//FUNCTION TO CHECK IF THE ACCOUNT NUMBER IS IN USE.
bool checkedAccount(int accountNumber) {
	
	bool  isExistent = false;
	
	for (int i{ 0 }; i < quantityOfAccounts; i++) {

		if (accounts[i].accountNumber == accountNumber) {
			isExistent = true;
			break;
		}
	}

	return isExistent;
}


//FUNCTION TO CHECK IF THERE ARE ALREADY CREATED ACCOUNTS
bool accountNumbersCheck(int quantityOfAccounts) {
	
	bool emptyDataBase{ true };

	if (quantityOfAccounts > 0) {
		emptyDataBase = false;
	}

	return emptyDataBase;
}