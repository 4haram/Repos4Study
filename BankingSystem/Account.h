/*
 * This File's version is 0.8
 */
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	String name;
	int account_number;
	int balance;
public:
	Account();
	Account(const String temp_name, int temp_number, int temp_balance);
	String GetName() const;
	int GetAccountNumber() const;
	int GetBalance() const;
	void SetAccountNumber(int);
	void SetName(const String);
	virtual void Deposit(int);
	virtual void Withdraw(int);
	void ShowAccountInfo() const;
};

#endif