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
		printf("���� ���� ���α׷�\n");
		printf("������ �۾��� �����Ͻÿ�\n");
		printf("1. �ű� ���� �߰�\n");
		printf("2. ���� �˻�\n");
		printf("3. ���� ����\n");
		printf("4. ���� �ݳ�\n");
		printf("5. ���α׷� ����\n");

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
	printf("�ű� ����� ������ �̸�: ");
	scanf("%[^\n]", title[*book_number]);
	getchar();

	printf("�ű� ����� ������ ����: ");
	scanf("%[^\n]", author[*book_number]);
	getchar();

	printf("�ű� ����� ������ ���ǻ�: ");
	scanf("%[^\n]", publisher[*book_number]);
	getchar();

	borrowed[*book_number] = 1;

	printf("#�ű� ���� ��� �Ϸ�!\n");
	(*book_number)++;

	return 0;
}

int search_book(char (*title)[30], char (*author)[30], char (*publisher)[30],
				int *borrowed, int book_number) {
	int i = 0;
	int user_input;
	char user_search[30];
	printf("������ �۾��� �����Ͻÿ�.\n ");
	printf("1. ���� �̸����� �˻�.\n ");
	printf("2. ���� �̸����� �˻�.\n ");
	printf("3. ���ǻ� �̸����� �˻�.\n ");
	scanf("%d", &user_input);

	printf("�˻��� �ܾ �Է��Ͻÿ�.\n ");
	getchar();
	scanf("%[^\n]", &user_search);

	switch (user_input) {
		case 1:
			for (i = 0; i < book_number; i++) {
				if (string_compare(title[i], user_search) == 1) {
					printf("�˻� ��� ã���ô� ������ ������ �����ϴ�.\n");
					printf("���� �̸�: %s\n", title[i]);
					printf("���� ����: %s\n", author[i]);
					printf("���ǻ�: %s\n", publisher[i]);
					printf("���� ��ȣ: %d\n", i);
					if (borrowed[i] == 0)
						printf("���� ���� ���� ����: �Ұ���\n");
					else if (borrowed[i] == 1)
						printf("���� ���� ���� ����: ����\n");
				}
			}
		break;

		case 2:
			for (i = 0; i < book_number; i++) {
				if (string_compare(author[i], user_search) == 1) {
					printf("�˻� ��� ã���ô� ������ ������ �����ϴ�.\n");
					printf("���� �̸�: %s\n", title[i]);
					printf("���� ����: %s\n", author[i]);
					printf("���ǻ�: %s\n", publisher[i]);
					printf("���� ��ȣ: %d\n", i);
					if (borrowed[i] == 0)
						printf("���� ���� ���� ����: �Ұ���\n");
					else if (borrowed[i] == 1)
						printf("���� ���� ���� ����: ����\n");
				}
			}
		break;

		case 3:
			for (i = 0; i < book_number; i++) {
				if (string_compare(publisher[i], user_search) == 1) {
					printf("�˻� ��� ã���ô� ������ ������ �����ϴ�.\n");
					printf("���� �̸�: %s\n", title[i]);
					printf("���� ����: %s\n", author[i]);
					printf("���ǻ�: %s\n", publisher[i]);
					printf("���� ��ȣ: %d\n", i);
					if (borrowed[i] == 0)
						printf("���� ���� ���� ����: �Ұ���\n");
					else if (borrowed[i] == 1)
						printf("���� ���� ���� ����: ����\n");
				}
			}
		break;

	}
	return 0;
}

int borrow_book(int(*borrowed)) {
	int book_number = 0;
	printf("������ ������ ��ȣ�� �Է��Ͻÿ�.\n");
	printf("���� ��ȣ: ");
	scanf("%d", &book_number);
	if (borrowed[book_number] == 0)
		printf("�̹� ���� ���� �����Դϴ�.\n");
	else {
		printf("���� ������ �Ϸ��߽��ϴ�.\n");
		borrowed[book_number] = 0;
	}
	
	return 0;
}

int return_book(int(*borrowed)) {
	int book_number = 0;
	printf("�ݳ��� ������ ��ȣ�� �Է��Ͻÿ�.\n");
	printf("���� ��ȣ: ");
	scanf("%d", &book_number);
	if (borrowed[book_number] == 0) {
		printf("���� �ݳ��� �Ϸ��߽��ϴ�.\n");
		borrowed[book_number] = 1;
	}
	else
		printf("�̹� �ݳ��� �Ϸ�Ǿ����ϴ�.\n");
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