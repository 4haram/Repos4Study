/*
 * Banking System ver 0.6
 */
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	char* name;				// �� ����
	int account_number;		// ���¹�ȣ
	int balance;			// �ܾ�
public:
	Account();
	Account(const char* temp_name, int temp_number, int temp_balance);
	Account(const Account& copy);
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
