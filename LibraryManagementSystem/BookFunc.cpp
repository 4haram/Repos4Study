#include "BookFunc.h"

int AddBook(struct books* new_book) {
	int n = 0;
	if (new_book == NULL) {
		printf("���� ����ü�� �ҷ����� ���߽��ϴ�.");
		return -1;
	}

	while (new_book[n].number != 0 && n < MAX_BOOKS) {
		n++;
	}

	if (n == MAX_BOOKS) {
		printf("�� �̻� å�� ����� �� �����ϴ�.\n");
		return -1;
	}
	SetStringData("�ű� ����� ������ �̸�: ", new_book[n].name);
	SetStringData("�ű� ����� ������ ����: ", new_book[n].author);
	SetStringData("�ű� ����� ������ ���ǻ�: ", new_book[n].publisher);
	printf("�ű� ����� ������ ��ȣ: ");
	scanf("%d", &new_book[n].number);
	ClearInputBuffer();
	new_book[n].borrowed = 1;							//1 = ���� ����, 0 = ���� �Ұ���

	printf("#�ű� ���� ��� �Ϸ�!\n");
	return 0;
}

int SearchBook(struct books* new_book) {
	int i = 0;
	int user_input, found_sucess = 0;
	char user_search[MAX_CHAR];
	printf("������ �۾��� �����Ͻÿ�.\n"
		"1. ���� �̸����� �˻�.\n"
		"2. ���� �̸����� �˻�.\n"
		"3. ���ǻ� �̸����� �˻�.\n"
		"4. ���� ��ȣ�� �˻�.\n"
		"� ������� �˻��Ͻðڽ��ϱ�?.\n");
	scanf("%d", &user_input);
	ClearInputBuffer();

	printf("�˻�� �Է����ּ���.\n");
	//���� �̸�, ����, ���ǻ��� ũ�Ⱑ '\0'�����ؼ� �ִ� 31�̹Ƿ�, '\0' ������ �Է¹޴� scanf������ 30���� ũ�⸦ �����Ѵ�
	scanf("%30[^\n]", user_search);
	ClearInputBuffer();

	switch (user_input) {
	case NAME:
		if (strcmp(new_book[i].name, user_search) == 0) found_sucess = 1;
		break;
	case AUTHOR:
		if (strcmp(new_book[i].author, user_search) == 0) found_sucess = 1;
		break;
	case PUBLISHER:
		if (strcmp(new_book[i].publisher, user_search) == 0) found_sucess = 1;
		break;
	case NUMBER:
		if (new_book[i].number == atoi(user_search)) found_sucess = 1;
		break;
	default:
		printf("�߸��� �Է��Դϴ�.\n");
		return 0;
	}

	if (found_sucess == 1) {
		printf("�˻� ���, ã���ô� ������ ������ �����ϴ�.\n"
			"**���� �̸�: %s\n"
			"**���� ����: %s\n"
			"**���ǻ�:    %s\n"
			"**���� ��ȣ: %d\n"
			"**���� ���� ���� ����: %s\n",
			new_book[i].name,
			new_book[i].author,
			new_book[i].publisher,
			new_book[i].number,
			//���׿����� ?:
			//(����) ? (������ ���� ��) : (������ ������ ��)
			new_book[i].borrowed ? "����" : "�Ұ���");
		return 0;
	}
	printf("ã���ô� ������ �����ϴ�.");
	return 0;
}

int BorrowBook(struct books* new_book) {
	int i, book_number = 0;
	printf("������ ������ ��ȣ�� �Է��Ͻÿ�.\n");
	printf("���� ��ȣ: ");
	scanf("%d", &book_number);
	ClearInputBuffer();

	//å�� ��ȣ�� 1���� 100(MAX_BOOKS)���� ������ ���̱� ������ �Ʒ��� ���� if���� ������ �������ش�.
	if (book_number < 1 || book_number > MAX_BOOKS) {
		printf("��ȿ���� ���� ���� ��ȣ�Դϴ�.\n");
		return 0;
	}

	for (i = 0; i < MAX_BOOKS; i++) {
		if (new_book[i].number == book_number) {
			if (new_book[i].borrowed == 0)
				printf("�̹� ���� ���� �����Դϴ�.\n");
			else {
				printf("���� ������ �Ϸ��߽��ϴ�.\n");
				new_book[i].borrowed = 0;
			}
		}
	}

	return 0;
}

int ReturnBook(struct books* new_book) {
	int i, book_number = 0;
	printf("�ݳ��� ������ ��ȣ�� �Է��Ͻÿ�.\n");
	printf("���� ��ȣ: ");
	scanf("%d", &book_number);
	ClearInputBuffer();

	//å�� ��ȣ�� 1���� 100(MAX_BOOKS)���� ������ ���̱� ������ �Ʒ��� ���� if���� ������ �������ش�.
	if (book_number <= 0 || book_number > MAX_BOOKS) {
		printf("��ȿ���� ���� ���� ��ȣ�Դϴ�.\n");
		return 0;
	}

	for (i = 0; i < MAX_BOOKS; i++) {
		if (new_book[i].number == book_number) {
			if (new_book[i].borrowed == 0) {
				printf("���� �ݳ��� �Ϸ��߽��ϴ�.\n");
				new_book[i].borrowed = 1;
			}
			else
				printf("�̹� �ݳ��� �Ϸ�Ǿ����ϴ�.\n");
		}
	}
	return 0;
}

//scanf���Ŀ� �����ִ� ���۸� ���ִ� �뵵�� �Լ�
/*
*getchar�� ���������� ��ȯ�ȴ�.
*��ȯ�� ���� ������ ���� c��, c�� '\n'�� ���� ���ų� EOF�� �巯���� ������ getchar�� �����Ѵ�.
*/
void ClearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void SetStringData(const char* info_string, char* string_data) {
	while (1) {
		printf("%s", info_string);
		//30�ڷ� �����ؼ� �Է¹޴´�.
		if (scanf("%30[^\n]", string_data) == 1) {
			//���� �����ִ� ��� ���۸� �����Ѵ�.
			ClearInputBuffer();
			break;
		}
		else {
			//�̹� �Է��� �߸������Ƿ�, ������ ���۸� ��� ������ ���Ŀ� �ٽ� �ݺ����ش�.
			ClearInputBuffer();
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}
}