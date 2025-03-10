/*
 * This File's version is 0.7
 */

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#define NAME_LENGTH 20 

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRY, EXIT };

enum { NORMAL = 1, CREDIT };

enum { GRADE_A = 7, GRADE_B = 4, GRADE_C = 2 };
#endif