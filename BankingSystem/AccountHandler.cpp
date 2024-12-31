/*
 * Banking System ver 0.6
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "CreditAccount.h"

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
	int choice;
	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: "; cin >> choice;
	switch (choice)
	{
	case NORMAL:
		CreateNormalAccount();
		break;
	case CREDIT:
		CreateCreditAccount();
	default:
		break;
	}
}

void AccountHandler::CreateNormalAccount() {
	char temp_string[NAME_LENGTH];
	int temp_number;
	int temp_balance;
	int temp_interest;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "해당 계좌번호는 이미 사용 중입니다." << endl;
		return;
	}

	cout << "이름: "; cin >> temp_string;
	cout << "입금액: "; cin >> temp_balance;
	cout << "이자율: "; cin >> temp_interest;
	account[acc_num++] = new NormalAccount(temp_string, temp_number, temp_balance, temp_interest);

}

void AccountHandler::CreateCreditAccount() {
	char temp_string[NAME_LENGTH];
	int temp_number;
	int temp_balance;
	int temp_interest;
	int temp_grade;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "해당 계좌번호는 이미 사용 중입니다." << endl;
		return;
	}

	cout << "이름: "; cin >> temp_string;
	cout << "입금액: "; cin >> temp_balance;
	cout << "이자율: "; cin >> temp_interest;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> temp_grade;
	if (temp_grade < 1 || temp_grade > 3) {
		cout << "신용등급을 잘못 입력하셨습니다." << endl;
		return;
	}
	switch (temp_grade)
	{
	case 1:
		account[acc_num++] = new HighCreditAccount(temp_string, temp_number, temp_balance, temp_interest, GRADE_A);
		break;
	case 2:
		account[acc_num++] = new HighCreditAccount(temp_string, temp_number, temp_balance, temp_interest, GRADE_B);
		break;
	case 3:
		account[acc_num++] = new HighCreditAccount(temp_string, temp_number, temp_balance, temp_interest, GRADE_C);
		break;
	default:
		break;
	}
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
		account[index]->Deposit(money);
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
		account[index]->Withdraw(money);
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