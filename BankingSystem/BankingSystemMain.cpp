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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "옳지 않은 접근을 시도했습니다." << endl;
			break;
		}
	}
	return 0;
}