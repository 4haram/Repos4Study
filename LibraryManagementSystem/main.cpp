#include "BookFunc.h"
struct books new_books[MAX_BOOKS] = { 0 };

int main() {
	int choice;
	while (1) {
		printf("도서 관리 프로그램\n"
			"수행할 작업을 선택하시오\n"
			"1. 신규 도서 추가\n"
			"2. 도서 검색\n"
			"3. 도서 대출\n"
			"4. 도서 반납\n"
			"5. 프로그램 종료\n");

		scanf("%d", &choice);
		ClearInputBuffer();

		if (choice == 1)
			AddBook(new_books);
		else if (choice == 2)
			SearchBook(new_books);
		else if (choice == 3)
			BorrowBook(new_books);
		else if (choice == 4)
			ReturnBook(new_books);
		else if (choice == 5)	break;
	}
	return 0;
}