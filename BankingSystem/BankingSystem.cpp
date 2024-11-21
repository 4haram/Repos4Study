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
	cout << "계좌ID: " << this->GetAccountNumber()
		 << ", 이름: " << (this->GetAccountName() ? this->GetAccountName() : "없음")
		 << ", 잔액: " << this->GetAccountBalance()
		 << "원" << endl;
}

Account* CreateAccount();

int SearchAccountNumber(Account* acc[], int id, int max);

void Account::SetDepositInfo() {
	int deposit;
	cout << "[입   금]" << endl;
	cout << "계좌ID: " << this->GetAccountNumber() << endl;
	cout << "입금액: ";
	cin>> deposit;
	if (deposit < 0) {
		cout << "입금하고자 하는 금액이 옳바르지 않습니다." << endl;
		return;
	}
	else {
		cout << "입금완료" << endl;
		this->SetAccountBalance(deposit);
	}
}

void Account::SetWithdrawInfo() {
	int withdraw;
	cout << "[출    금]" << endl;
	cout << "계좌ID: " << this->GetAccountNumber() << endl;
	cout << "출금액: ";
	cin >> withdraw;
	if (withdraw > 0 && withdraw <= this->GetAccountBalance()) {
		this->SetAccountBalance(-withdraw);
		cout << "잔액: " << this->GetAccountBalance() << endl;
		cout << "출금완료" << endl;
	}
	else if (withdraw > this->GetAccountBalance()){
		cout << "보유한 잔액이 부족합니다." << endl;
	}
	else {
		cout << "잘못된 시도입니다. \n다시 시도해주세요." << endl;
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
			cout << "조회할 계좌번호:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "계좌 조회에 실패했습니다.\n다시 시도해주세요." << endl;
				break;
			}
			account[temp_index]->SetDepositInfo();
			break;
		case 3:
			cout << "조회할 계좌번호:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "계좌 조회에 실패했습니다.\n다시 시도해주세요." << endl;
				break;
			}
			account[temp_index]->SetWithdrawInfo();
			break;
		case 4:
			cout << "조회할 계좌번호:";
			cin >> account_id;
			temp_index = SearchAccountNumber(account, account_id, accounts_now);
			if (temp_index == -1) {
				cout << "계좌 조회에 실패했습니다.\n다시 시도해주세요." << endl;
				break;
			}
			account[temp_index]->ShowAccountInfo();
			break;
		case 5:
			for (int i = 0; i < accounts_now; i++) {
				delete account[i];
				account[i] = nullptr;
			}
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 조회" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

Account* CreateAccount() {
	Account* account = new Account;
	char temp_string[NAME_LENGTH];
	int number;
	int balance;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> number;
	cout << "이름: ";
	cin >> temp_string;
	cout << "입금액: ";
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