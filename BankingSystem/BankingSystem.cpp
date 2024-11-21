#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LENGTH 20 
#define ACCOUNT_MAX 100

void ShowMenu();

class Account {
private:
	char* name;
	int number, balance;
public:
	Account() : name(nullptr), number(0), balance(0) {}
	~Account() {
		delete[] name;
	}
	char* GetAccountName() const;
	void SetAccountName(const char*);

	int GetAccountNumber() const;
	void SetAccountNumber(int);

	int GetAccountBalance() const;
	void SetAccountBalance(int);

	void SetAccountData(const char* name, int number, int balance);

	void SetDepositInfo();
	void SetWithdrawInfo();

	void ShowAccountInfo();
};

char* Account::GetAccountName() const{
	return this->name;
}

void Account::SetAccountName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Account::GetAccountNumber() const{
		return this->number;
}
void Account::SetAccountNumber(int num) {
	this->number = num;
}
int Account::GetAccountBalance() const{
	return this->balance;
}
void Account::SetAccountBalance(int balance) {
	this->balance += balance;
}

void Account::SetAccountData(const char* name, int number, int balance) {
	this->SetAccountName(name);
	this->SetAccountNumber(number);
	this->SetAccountBalance(balance);
}

void Account::ShowAccountInfo() {
	cout << "����ID: " << this->GetAccountNumber()
		 << ", �̸�: " << (this->GetAccountName() ? this->GetAccountName() : "����")
		 << ", �ܾ�: " << this->GetAccountBalance()
		 << "��" << endl;
}

Account* CreateAccount();

int SearchAccountNumber(Account* acc[], int id, int max);

void Account::SetDepositInfo() {
	int deposit;
	cout << "[��   ��]" << endl;
	cout << "����ID: " << this->GetAccountNumber() << endl;
	cout << "�Աݾ�: ";
	cin>> deposit;
	if (deposit < 0) {
		cout << "�Ա��ϰ��� �ϴ� �ݾ��� �ǹٸ��� �ʽ��ϴ�." << endl;
		return;
	}
	else {
		cout << "�ԱݿϷ�" << endl;
		this->SetAccountBalance(deposit);
	}
}

void Account::SetWithdrawInfo() {
	int withdraw;
	cout << "[��    ��]" << endl;
	cout << "����ID: " << this->GetAccountNumber() << endl;
	cout << "��ݾ�: ";
	cin >> withdraw;
	if (withdraw > 0 && withdraw <= this->GetAccountBalance()) {
		this->SetAccountBalance(-withdraw);
		cout << "�ܾ�: " << this->GetAccountBalance() << endl;
		cout << "��ݿϷ�" << endl;
	}
	else if (withdraw > this->GetAccountBalance()){
		cout << "������ �ܾ��� �����մϴ�." << endl;
	}
	else {
		cout << "�߸��� �õ��Դϴ�. \n�ٽ� �õ����ּ���." << endl;
	}
}
enum class CHOICE{

};

int main() {
	int choice, accounts_now = 0, account_id = 0, temp_index;
	Account* account[ACCOUNT_MAX] = {nullptr};
	while (1) {
		ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			account[accounts_now] = CreateAccount();
			accounts_now++;
			break;
		case 2:
			cout << "��ȸ�� ���¹�ȣ:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "���� ��ȸ�� �����߽��ϴ�.\n�ٽ� �õ����ּ���." << endl;
				break;
			}
			account[temp_index]->SetDepositInfo();
			break;
		case 3:
			cout << "��ȸ�� ���¹�ȣ:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "���� ��ȸ�� �����߽��ϴ�.\n�ٽ� �õ����ּ���." << endl;
				break;
			}
			account[temp_index]->SetWithdrawInfo();
			break;
		case 4:
			cout << "��ȸ�� ���¹�ȣ:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "���� ��ȸ�� �����߽��ϴ�.\n�ٽ� �õ����ּ���." << endl;
				break;
			}
			account[temp_index]->ShowAccountInfo();
			break;
		case 5:
			for (int i = 0; i < accounts_now; i++) {
				delete account[i];
				account[i] = nullptr;
			}
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ȸ" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

Account* CreateAccount() {
	Account* account = new Account;
	char temp_string[NAME_LENGTH];
	int number;
	int balance;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> number;
	cout << "�̸�: ";
	cin >> temp_string;
	cout << "�Աݾ�: ";
	cin >> balance;
	account->SetAccountData(temp_string, number, balance);
	return account;
}

int SearchAccountNumber(Account* acc[], int id, int max) {
	for (int i = 0; i < max; i++) {
		if (acc[i] != nullptr && acc[i]->GetAccountNumber() == id) return i;
	}

	return -1;
}