/*
 * This File's version is 0.1
 */
#include "BankingCommonDecl.h"
#include "String.h"

String::String() : str(NULL) {}

String::String(const char* s) {
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}

String::String(const String& ref) {
	str = new char[strlen(ref.str) + 1];
	strcpy(str, ref.str);
}

String& String::operator=(const char* s) {
	delete[] str;
	str = new char[strlen(s) + 1];
	strcpy(str, s);
	return *this;
}

String& String::operator=(const String& ref) {
	delete[] str;
	str = new char[strlen(ref.str) + 1];
	strcpy(str, ref.str);
	return *this;
}

String String::operator+(const char* s) {
	size_t len = strlen(str) + strlen(s) + 1;
	char* temp_str = new char[len];
	strcpy(temp_str, str);
	strcat(temp_str, s);
	String temp_string(temp_str);
	delete[] temp_str;
	return temp_string;
}

String String::operator+(const String& ref) {
	size_t len = strlen(str) + strlen(ref.str) + 1;
	char* temp_str = new char[len];
	strcpy(temp_str, str);
	strcat(temp_str, ref.str);
	String temp_string(temp_str);
	delete[] temp_str;
	return temp_string;
}

String& String::operator+=(const char* s) {
	size_t len = strlen(str) + strlen(s) + 1;
	char* temp = new char[len];
	strcpy(temp, str);
	strcat(temp, s);
	delete[] str;
	str = temp;
	return *this;
}

String& String::operator+=(const String& ref) {
	size_t len = strlen(str) + strlen(ref.str) + 1;
	char* temp = new char[len];
	strcpy(temp, str);
	strcat(temp, ref.str);
	delete[] str;
	str = temp;
	return *this;
}

bool String::operator==(const char* s) {
	if (strcmp(str, s) == 0) {
		return true;
	}
	return false;
}

bool String::operator==(const String& ref) {
	if (strcmp(str, ref.str) == 0) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const String& ref) {
	os << ref.str;
	return os;
}

istream& operator>>(istream& is, String& ref) {
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}

String::~String() { delete[] str; }