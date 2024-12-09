/*
 * Banking System ver 0.5
 */

#define _CRT_SECURE_NO_WARNINGS
#define NAME_LENGTH 20 
#define ACCOUNT_MAX 100

#include <iostream>
#include <cstring>
using namespace std;

enum {CREATE = 1, DEPOSIT, WITHDRAW, INQUIRY, EXIT};

/*
 * Entity Class, Account
 */
class Account {
private:
	char* name;				// �� ����
	int account_number;		// ���¹�ȣ
	int balance;			// �ܾ�
public:
	Account();
	Account(const char* temp_name, int temp_number, int temp_balance);
	Account(const Account& copy);
	~Account();
	char* GetName() const;
	void SetName(const char*);
	int GetAccountNumber() const;
	void SetAccountNumber(int);
	int GetBalance() const;
	void SetBalance(int, bool);
	void ShowAccountInfo() const;
};

/*
 * Class Account's Functions
 */
Account::Account() : name(nullptr), account_number(0), balance(0) {}

Account::Account(const char* temp_name, int temp_number, int temp_balance) : account_number(temp_number), balance(temp_balance) {
	name = new char[strlen(temp_name) + 1];
	strcpy(name, temp_name);
}

Account::Account(const Account& copy) : account_number(copy.account_number), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

Account::~Account() {
	delete[] name;
}

char* Account::GetName() const {
	return name;
}

void Account::SetName(const char*) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Account::GetAccountNumber() const {
	return account_number;
}

void Account::SetAccountNumber(int num) {
	if (num < 0) {
		cout << "�߸��� �õ��� �߽��ϴ�.\n�ٽ� �Է����ּ���." << endl;
	}
	account_number = num;
}

int Account::GetBalance() const {
	return balance;
}

void Account::SetBalance(int money, bool is_add) {
	if (is_add) balance += money;
	else {
		if (money > balance)
			// ���Ӱ� ������ �ܾ��� ���� �ܾ׺��� Ŭ ���
			cout << "�߸��� ������ �õ��߽��ϴ�.\n �ٽ� �õ����ּ���." << endl;
		else {
			balance -= money;
		}
	}
}

void Account::ShowAccountInfo() const {
	cout << "����ID: " << GetAccountNumber()
		<< ", �̸�: " << (GetName() ? GetName() : "����")
		<< ", �ܾ�: " << GetBalance()
		<< "��" << endl;
}

/*
 * Control Class, AccountHandler 
 */
class AccountHandler {
private:
	Account* account[ACCOUNT_MAX];
	int acc_num;
public:
	AccountHandler();
	~AccountHandler();
	int GetNum() const;
	int SearchAccountNumber(int);
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccountInfo() const;
	void ShowMenu() const;
};

/*
 * Class AccountHandler's Functions 
 */
AccountHandler::AccountHandler() : acc_num(0) {}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < ACCOUNT_MAX; i++) {
		delete account[i];
	}
}
int AccountHandler::GetNum() const { return acc_num; }

// ���¸� ������ ������ num�� 1�� �����ϹǷ�, num�� ������ ������ ����
int AccountHandler::SearchAccountNumber(int id) {
	for (int i = 0; i < acc_num; i++) {
		if (account[i] != nullptr && account[i]->GetAccountNumber() == id) return i;
	}
	/*
	 * ��ü ���¸� ��ȸ�������� �ұ��ϰ� return ���� �ʾҴٴ� ����
	 * �ش� ���¹�ȣ�� �������� �ʴ´ٴ� �ǹ�
	*/
	return -1;
}

void AccountHandler::CreateAccount() {
	char temp_string[NAME_LENGTH];
	int temp_number;
	int temp_balance;
	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "�ش� ���¹�ȣ�� �̹� ��� ���Դϴ�." << endl;
		return;
	}

	cout << "�̸�: "; cin >> temp_string;
	cout << "�Աݾ�: "; cin >> temp_balance;
	account[acc_num++] = new Account(temp_string, temp_number, temp_balance);
}

void AccountHandler::Deposit() {
	int number;
	int index;
	int money;
	cout << "[��   ��]" << endl;

	cout << "�Ա��� ���¹�ȣ: "; cin >> number;
	index = SearchAccountNumber(number);
	if (index == -1) {
		cout << "�������� �ʴ� ���¹�ȣ�Դϴ�.\n�ٽ� �õ����ּ���." << endl;
		return;
	}

	cout << "����ID: " << account[index]->GetAccountNumber() << endl;
	cout << "�Աݾ�: "; cin >> money;
	if (money < 0) {
		cout << "�߸��� �õ��Դϴ�. \n�ٽ� �õ����ּ���." << endl;
		return;
	}
	else {
		account[index]->SetBalance(money, true);
		cout << "�ܾ�: " << account[index]->GetBalance() << endl;
		cout << "�ԱݿϷ�" << endl;
	}
}

void AccountHandler::Withdraw() {
	int number;
	int index;
	int money;
	cout << "[��    ��]" << endl;
	cout << "����� ���¹�ȣ: "; cin >> number;
	index = SearchAccountNumber(number);
	if (index == -1) {
		cout << "�������� �ʴ� ���¹�ȣ�Դϴ�.\n�ٽ� �õ����ּ���." << endl;
		return;
	}
	cout << "����ID: " << account[index]->GetAccountNumber() << endl;
	cout << "��ݾ�: "; cin >> money;
	if (money >= 0 && money <= account[index]->GetBalance()) {
		account[index]->SetBalance(money, false);
		cout << "�ܾ�: " << account[index]->GetBalance() << endl;
		cout << "��ݿϷ�" << endl;
	}
	else if (money > account[index]->GetBalance()) {
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else {
		// ��ݾ��� ������ ���
		cout << "�߸��� �õ��Դϴ�. \n�ٽ� �õ����ּ���." << endl;
	}
}

void AccountHandler::ShowAllAccountInfo() const {
	for (int i = 0; i < acc_num; i++) {
		account[i]->ShowAccountInfo();
	}
}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ȸ" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

int main() {
	int choice;
	AccountHandler handler;
	while (1) {
		handler.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case CREATE:
			if (handler.GetNum() >= ACCOUNT_MAX) {
				cout << "���¸� �� �̻� ������ �� �����ϴ�." << endl;
				break;
			}
			handler.CreateAccount();
			break;
		case DEPOSIT:
			handler.Deposit();
			break;
		case WITHDRAW:
			handler.Withdraw();
			break;
		case INQUIRY:
			handler.ShowAllAccountInfo();
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "���� ���� ������ �õ��߽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}