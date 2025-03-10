/*
 * This File's version is  0.7
 */
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountPtrArray.h"

 /*
  * Control Class, AccountHandler
  */
class AccountHandler {
private:
	AccountPtrArray account;
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