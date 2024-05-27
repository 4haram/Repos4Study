#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 31
#define MAX_BOOKS 100

struct books {
	char name[MAX_CHAR];
	char author[MAX_CHAR];
	char publisher[MAX_CHAR];
	int borrowed;
	int number;
};

int AddBook(struct books* new_book);
int SearchBook(struct books* new_book);
int BorrowBook(struct books* new_book);
int ReturnBook(struct books* new_book);
void ClearInputBuffer();
void SetStringData(const char* info_string, char* string_data);
enum { NAME = 1, AUTHOR, PUBLISHER, NUMBER };