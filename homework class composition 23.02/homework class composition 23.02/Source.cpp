#include <iostream>
using namespace std;
//how to use getline
class Client
{
private:
	string name;
	string adress;
	int phone_number;
public:
	string GetName()
	{
		return name;
	}
	string GetAdress()
	{
		return adress;
	}
	friend ostream& operator<<(ostream& os, Client& person)
	{
		os << "Client name:" << person.name << ", adress: " << person.adress << ", phone number: "
			<< person.phone_number << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Client &person)
	{
		cout << "Enter name:";
		is >> person.name;
		cout << "Enter your adress:";
		is >> person.adress;
		cout << "Enter your phone number:";
		is >> person.phone_number;
		return is;
	}
	/*bool operator==(const Client& client2)
	{
		if (name == client2.name || adress == client2.adress)
			return true;
		else 
			return false;
	}*/
};
class Bank
{
private:
	Client client_;
	int account_number;
	float balance;
public:
	float AddBalance(float sum)
	{
		balance = balance + sum;
		return balance;
	}
	float MinusBalance(float sum)
	{
		return balance-= sum;
	}
	float ShowBalance()
	{
		return balance;
	}
	friend ostream& operator<<(ostream& os, Bank& bank)
	{
			os << bank.client_ << endl;
			os << "account number: " << bank.account_number << endl;
			os << "balance: " << bank.balance << endl; 
		return os;
	}
	friend istream& operator>>(istream& is, Bank& bank)
	{
		is >> bank.client_;
		cout << "enter account number: " << endl;
		is >> bank.account_number;
		cout << "enter balance: " << endl;
		is >> bank.balance;
		return is;
	}
	string GetName()
	{
		return client_.GetName();
	}
	string GetAdress()
	{
		return client_.GetAdress();
	}
	bool operator==(const Bank& bank2)
	{
		return account_number == bank2.account_number;
	}};
Bank FindClientbyName(Bank *accounts, string name, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (accounts[i].GetName() == name)
		{
			return accounts[i];
		}
	}
	return Bank();
}
Bank FindClientbyAdress(Bank* accounts, string adress, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (accounts[i].GetAdress() == adress)
		{
			return accounts[i];
		}
	}
	return Bank();
}
int main()
{
	const int size = 2;
	Bank accounts[size];
	cout << "Welcome!" << endl;
	cout << "Please enter data about 10 accounts" << endl;
	for (int i = 0; i < size; i++)
	{
		int n;
		float b;
		cout << i + 1 << "." << endl;
		cin >> accounts[i];
	}
	string answer;

	do
	{
		cout << "Do you want to find account by name or adress?" << endl;
		cin >> answer;
		Bank FoundAccount;
		if (answer == "name")
		{
			string name;
			cout << "Enter your name:" << endl;
			cin >> name;
			FoundAccount = FindClientbyName(accounts, name, size);
		}
		if (answer == "adress")
		{
			string adress;
			cout << "Enter your adress:" << endl;
			cin >> adress;
			FoundAccount = FindClientbyAdress(accounts, adress, size);
		}
		if (FoundAccount == Bank())
		{
			cout << "not found";
			continue;
		}
		int answer1;
		do
		{
			cout << "1. Show balance" << endl;
			cout << "2. Withdraw money" << endl;
			cout << "3. Get money" << endl;
			cout << "4. Exit" << endl;
			cin >> answer1;
			switch (answer1)
			{
			case 1: cout << FoundAccount.ShowBalance();
				break;
			case 2: cout << "How much money do you want to withdraw?";
				int sum;
				cin >> sum;
				cout << "your balance now:" << FoundAccount.MinusBalance(sum);
				break;
			case 3: cout << "How much money do you want to put?";
				cin >> sum;
				cout << "your balance now:" << FoundAccount.AddBalance(sum);
				break;
			default:
				break;
			}
		} while (answer1 != 4);
	} while (answer != "exit");

	return 0;
}