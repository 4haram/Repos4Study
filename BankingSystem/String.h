/*
 * This File's version is 0.1
 */
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
	char* str;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const char*);
	String& operator=(const String&);
	String operator+(const char*);
	String operator+(const String&);
	String& operator+=(const char*);
	String& operator+=(const String&);
	bool operator==(const char*);
	bool operator==(const String&);
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	~String();
};
#endif