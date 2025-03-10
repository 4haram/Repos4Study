/*
 * This File's version is 0.1
 */
#ifndef __ACCOUNT_PTR_ARRAY_H__
#define __ACCOUNT_PTR_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class AccountPtrArray {
private:
	ACCOUNT_PTR* arr;
	int arrlen;

	AccountPtrArray(const AccountPtrArray& arr) {}
	AccountPtrArray& operator=(const AccountPtrArray& arr) {}
public:
	AccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~AccountPtrArray();
};
#endif