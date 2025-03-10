/*
 * This File's version is 0.7
 */
#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account() : name(nullptr), account_number(0), balance(0) {}

Account::Account(const char* temp_name, int temp_number, int temp_balance) : account_number(temp_number), balance(temp_balance) {
	name = new char[strlen(temp_name) + 1];
	strcpy(name, temp_name);
}

Account::Account(const Account& ref) : account_number(ref.account_number), balance(ref.balance) {
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}

Account& Account::operator=(const Account& ref) {
	account_number	= ref.account_number;
	balance			= ref.balance;

	delete[] name;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
	return *this;
}

Account::~Account() {
	delete[] name;
}

char* Account::GetName() const {
	return name;
}

int Account::GetAccountNumber() const {
	return account_number;
}

int Account::GetBalance() const {
	return balance;
}

void Account::SetName(const char*) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Account::SetAccountNumber(int num) {
	if (num < 0) {
		cout << "�߸��� �õ��� �߽��ϴ�.\n�ٽ� �Է����ּ���." << endl;
	}
	account_number = num;
}

void Account::Deposit(int money) {
	if (money < 0) cout << "�Ա��� �ݾ׿� ������ �ֽ��ϴ�." << endl;
	else balance += money;
}

void Account::Withdraw(int money) {
	if (money > balance) cout << "�ܾ��� �����մϴ�." << endl;
	else balance -= money;
}

void Account::ShowAccountInfo() const {
	cout << "����ID: " << GetAccountNumber()
		<< ", �̸�: " << (GetName() ? GetName() : "����")
		<< ", �ܾ�: " << GetBalance()
		<< "��" << endl;
}