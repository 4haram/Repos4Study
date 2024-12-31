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
	int choice;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> choice;
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
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "�ش� ���¹�ȣ�� �̹� ��� ���Դϴ�." << endl;
		return;
	}

	cout << "�̸�: "; cin >> temp_string;
	cout << "�Աݾ�: "; cin >> temp_balance;
	cout << "������: "; cin >> temp_interest;
	account[acc_num++] = new NormalAccount(temp_string, temp_number, temp_balance, temp_interest);

}

void AccountHandler::CreateCreditAccount() {
	char temp_string[NAME_LENGTH];
	int temp_number;
	int temp_balance;
	int temp_interest;
	int temp_grade;
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> temp_number;

	if (SearchAccountNumber(temp_number) != -1) {
		cout << "�ش� ���¹�ȣ�� �̹� ��� ���Դϴ�." << endl;
		return;
	}

	cout << "�̸�: "; cin >> temp_string;
	cout << "�Աݾ�: "; cin >> temp_balance;
	cout << "������: "; cin >> temp_interest;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> temp_grade;
	if (temp_grade < 1 || temp_grade > 3) {
		cout << "�ſ����� �߸� �Է��ϼ̽��ϴ�." << endl;
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
		account[index]->Deposit(money);
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
		account[index]->Withdraw(money);
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