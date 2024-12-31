/*
 * Banking System ver 0.6
 */
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BankingCommonDecl.h"
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
	void CreateNormalAccount();
	void CreateCreditAccount();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccountInfo() const;
	void ShowMenu() const;
};
#endif