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
	char* name;				// 고객 성함
	int account_number;		// 계좌번호
	int balance;			// 잔액
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
		cout << "잘못된 시도를 했습니다.\n다시 입력해주세요." << endl;
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
			// 새롭게 설정할 잔액이 기존 잔액보다 클 경우
			cout << "잘못된 접근을 시도했습니다.\n 다시 시도해주세요." << endl;
		else {
			balance -= money;
		}
	}
}

void Account::ShowAccountInfo() const {
	cout << "계좌ID: " << GetAccountNumber()
		<< ", 이름: " << (GetName() ? GetName() : "없음")
		<< ", 잔액: " << GetBalance()
		<< "원" << endl;
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

// 계좌를 생성할 때마다 num이 1씩 증가하므로, num은 생성된 계좌의 개수
int AccountHandler::SearchAccountNumber(int id) {
	for (int i = 0; i < acc_num; i++) {
		if (account[i] != nullptr && account[i]->GetAccountNumber() == id) return i;
	}
	/*
	 * 전체 계좌를 조회했음에도 불구하고 return 되지 않았다는 것은
	 * 해당 계좌번호가 존재하지 않는다는 의미
	*/
	return -1;
}

void AccountHandler::CreateAccount() {
	char temp_string[NAME_LENGTH];
	int temp_number;
	int temp_balance;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "해당 계좌번호는 이미 사용 중입니다." << endl;
		return;
	}

	cout << "이름: "; cin >> temp_string;
	cout << "입금액: "; cin >> temp_balance;
	account[acc_num++] = new Account(temp_string, temp_number, temp_balance);
}

void AccountHandler::Deposit() {
	int number;
	int index;
	int money;
	cout << "[입   금]" << endl;

	cout << "입금할 계좌번호: "; cin >> number;
	index = SearchAccountNumber(number);
	if (index == -1) {
		cout << "존재하지 않는 계좌번호입니다.\n다시 시도해주세요." << endl;
		return;
	}

	cout << "계좌ID: " << account[index]->GetAccountNumber() << endl;
	cout << "입금액: "; cin >> money;
	if (money < 0) {
		cout << "잘못된 시도입니다. \n다시 시도해주세요." << endl;
		return;
	}
	else {
		account[index]->SetBalance(money, true);
		cout << "잔액: " << account[index]->GetBalance() << endl;
		cout << "입금완료" << endl;
	}
}

void AccountHandler::Withdraw() {
	int number;
	int index;
	int money;
	cout << "[출    금]" << endl;
	cout << "출금할 계좌번호: "; cin >> number;
	index = SearchAccountNumber(number);
	if (index == -1) {
		cout << "존재하지 않는 계좌번호입니다.\n다시 시도해주세요." << endl;
		return;
	}
	cout << "계좌ID: " << account[index]->GetAccountNumber() << endl;
	cout << "출금액: "; cin >> money;
	if (money >= 0 && money <= account[index]->GetBalance()) {
		account[index]->SetBalance(money, false);
		cout << "잔액: " << account[index]->GetBalance() << endl;
		cout << "출금완료" << endl;
	}
	else if (money > account[index]->GetBalance()) {
		cout << "잔액이 부족합니다." << endl;
	}
	else {
		// 출금액이 음수일 경우
		cout << "잘못된 시도입니다. \n다시 시도해주세요." << endl;
	}
}

void AccountHandler::ShowAllAccountInfo() const {
	for (int i = 0; i < acc_num; i++) {
		account[i]->ShowAccountInfo();
	}
}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 조회" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
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
				cout << "계좌를 더 이상 생성할 수 없습니다." << endl;
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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "옳지 않은 접근을 시도했습니다." << endl;
			break;
		}
	}
	return 0;
}