#include "BookFunc.h"
struct books new_books[MAX_BOOKS] = { 0 };

int main() {
	int choice;
	while (1) {
		printf("���� ���� ���α׷�\n"
			"������ �۾��� �����Ͻÿ�\n"
			"1. �ű� ���� �߰�\n"
			"2. ���� �˻�\n"
			"3. ���� ����\n"
			"4. ���� �ݳ�\n"
			"5. ���α׷� ����\n");

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