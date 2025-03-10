/*
 * This File's version is 0.7
 */
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	char* name;
	int account_number;
	int balance;
public:
	Account();
	Account(const char* temp_name, int temp_number, int temp_balance);
	Account(const Account& copy);
	Account& operator=(const Account& ref);
	~Account();
	char* GetName() const;
	int GetAccountNumber() const;
	int GetBalance() const;
	void SetAccountNumber(int);
	void SetName(const char*);
	virtual void Deposit(int);
	virtual void Withdraw(int);
	void ShowAccountInfo() const;
};

#endif