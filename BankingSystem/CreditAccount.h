/*
 * Banking System ver 0.6
 */
#ifndef __CREDIT_ACCOUNT_H__
#define __CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
 /*
  * Derived Class, CreditAccount
  */
class CreditAccount : public NormalAccount {
private:
	int grade;
public:
	CreditAccount(const char* temp_name, int temp_number, int temp_balance, int temp_interest, int temp_grade);
	void Deposit(int money) override;
};

/*
 * Class CreditAccount's Functions
 */

CreditAccount::CreditAccount(const char* temp_name, int temp_number, int temp_balance, int temp_interest, int temp_grade) :
	NormalAccount(temp_name, temp_number, temp_balance, temp_interest), grade(temp_grade) {};

void CreditAccount::Deposit(int money) {
	NormalAccount::Deposit(money);
	Account::Deposit(Convert2Interest(money, grade));
}
#endif