#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_book(char (*title)[30], char (*author)[30], char (*publisher)[30], int *borrowed, int *book_number);
int search_book(char(*title)[30], char(*author)[30], char(*publisher)[30], int *borrowed, int book_number);
int borrow_book(int(*borrowed));
int return_book(int(*borrowed));
int string_compare(char *str1, char *str2);

int main() {
	int choice;
	int book_number = 0;
	char title[100][30], author[100][30], publisher[100][30], temp_title[30];
	int borrowed[100];
	while (1) {
		printf("도서 관리 프로그램\n");
		printf("수행할 작업을 선택하시오\n");
		printf("1. 신규 도서 추가\n");
		printf("2. 도서 검색\n");
		printf("3. 도서 대출\n");
		printf("4. 도서 반납\n");
		printf("5. 프로그램 종료\n");

		scanf("%d", &choice);

		if (choice == 1)
			add_book(title, author, publisher, borrowed, &book_number);
		else if (choice == 2)
			search_book(title, author, publisher, borrowed, book_number);
		else if (choice == 3)
			borrow_book(borrowed);
		else if (choice == 4)
			return_book(borrowed);
		else if (choice == 5)	break;
	}
	return 0;
}

int add_book(char (*title)[30], char (*author)[30],
			 char (*publisher)[30], int *borrowed, int *book_number) {
	getchar();
	printf("신규 등록할 도서의 이름: ");
	scanf("%[^\n]", title[*book_number]);
	getchar();

	printf("신규 등록할 도서의 저자: ");
	scanf("%[^\n]", author[*book_number]);
	getchar();

	printf("신규 등록할 도서의 출판사: ");
	scanf("%[^\n]", publisher[*book_number]);
	getchar();

	borrowed[*book_number] = 1;

	printf("#신규 도서 등록 완료!\n");
	(*book_number)++;

	return 0;
}

int search_book(char (*title)[30], char (*author)[30], char (*publisher)[30],
				int *borrowed, int book_number) {
	int i = 0;
	int user_input;
	char user_search[30];
	printf("수행할 작업을 선택하시오.\n ");
	printf("1. 도서 이름으로 검색.\n ");
	printf("2. 저자 이름으로 검색.\n ");
	printf("3. 출판사 이름으로 검색.\n ");
	scanf("%d", &user_input);

	printf("검색할 단어를 입력하시오.\n ");
	getchar();
	scanf("%[^\n]", &user_search);

	switch (user_input) {
		case 1:
			for (i = 0; i < book_number; i++) {
				if (string_compare(title[i], user_search) == 1) {
					printf("검색 결과 찾으시는 도서는 다음과 같습니다.\n");
					printf("도서 이름: %s\n", title[i]);
					printf("도서 저자: %s\n", author[i]);
					printf("출판사: %s\n", publisher[i]);
					printf("도서 번호: %d\n", i);
					if (borrowed[i] == 0)
						printf("도서 대출 가능 여부: 불가능\n");
					else if (borrowed[i] == 1)
						printf("도서 대출 가능 여부: 가능\n");
				}
			}
		break;

		case 2:
			for (i = 0; i < book_number; i++) {
				if (string_compare(author[i], user_search) == 1) {
					printf("검색 결과 찾으시는 도서는 다음과 같습니다.\n");
					printf("도서 이름: %s\n", title[i]);
					printf("도서 저자: %s\n", author[i]);
					printf("출판사: %s\n", publisher[i]);
					printf("도서 번호: %d\n", i);
					if (borrowed[i] == 0)
						printf("도서 대출 가능 여부: 불가능\n");
					else if (borrowed[i] == 1)
						printf("도서 대출 가능 여부: 가능\n");
				}
			}
		break;

		case 3:
			for (i = 0; i < book_number; i++) {
				if (string_compare(publisher[i], user_search) == 1) {
					printf("검색 결과 찾으시는 도서는 다음과 같습니다.\n");
					printf("도서 이름: %s\n", title[i]);
					printf("도서 저자: %s\n", author[i]);
					printf("출판사: %s\n", publisher[i]);
					printf("도서 번호: %d\n", i);
					if (borrowed[i] == 0)
						printf("도서 대출 가능 여부: 불가능\n");
					else if (borrowed[i] == 1)
						printf("도서 대출 가능 여부: 가능\n");
				}
			}
		break;

	}
	return 0;
}

int borrow_book(int(*borrowed)) {
	int book_number = 0;
	printf("대출할 도서의 번호를 입력하시오.\n");
	printf("도서 번호: ");
	scanf("%d", &book_number);
	if (borrowed[book_number] == 0)
		printf("이미 대출 중인 도서입니다.\n");
	else {
		printf("도서 대출을 완료했습니다.\n");
		borrowed[book_number] = 0;
	}
	
	return 0;
}

int return_book(int(*borrowed)) {
	int book_number = 0;
	printf("반납할 도서의 번호를 입력하시오.\n");
	printf("도서 번호: ");
	scanf("%d", &book_number);
	if (borrowed[book_number] == 0) {
		printf("도서 반납을 완료했습니다.\n");
		borrowed[book_number] = 1;
	}
	else
		printf("이미 반납이 완료되었습니다.\n");
	return 0;
}

int string_compare(char *str1, char *str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;
	return 0;
}