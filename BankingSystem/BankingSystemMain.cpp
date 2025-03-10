/*
 * This File's version is 0.7
 */
#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main() {
	int choice;
	AccountHandler handler;
	while (1) {
		handler.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case CREATE:
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