/*
 * This File's version is 0.1
 */
#include "BankingCommonDecl.h"
#include "AccountPtrArray.h"

AccountPtrArray::AccountPtrArray(int len) : arrlen(len) {
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& AccountPtrArray::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR AccountPtrArray::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int AccountPtrArray::GetArrLen() const { return arrlen; }
AccountPtrArray::~AccountPtrArray() { delete[] arr; }