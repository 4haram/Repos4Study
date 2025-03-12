/*
 * This File's version is 0.7
 */
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"
 /*
  * Derived Class, NormalAccount
  */
class NormalAccount : public Account {
private:
	int interest_rate;
public:
	NormalAccount(const String temp_name, int temp_number, int temp_balance, int temp_interest);
	int Convert2Interest(int, int);
	void Deposit(int) override;
};

/*
 * Class NormalAccount's Functions
 */

NormalAccount::NormalAccount(const String temp_name, int temp_number, int temp_balance, int temp_interest) :
	Account(temp_name, temp_number, temp_balance), interest_rate(temp_interest) {
};

int NormalAccount::Convert2Interest(int money, int rate) {
	return (int)(money * 0.01 * rate);
}

void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit(Convert2Interest(money, interest_rate));
}
#endif