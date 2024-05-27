#include "BookFunc.h"

int AddBook(struct books* new_book) {
	int n = 0;
	if (new_book == NULL) {
		printf("도서 구조체를 불러오지 못했습니다.");
		return -1;
	}

	while (new_book[n].number != 0 && n < MAX_BOOKS) {
		n++;
	}

	if (n == MAX_BOOKS) {
		printf("더 이상 책을 등록할 수 없습니다.\n");
		return -1;
	}
	SetStringData("신규 등록할 도서의 이름: ", new_book[n].name);
	SetStringData("신규 등록할 도서의 저자: ", new_book[n].author);
	SetStringData("신규 등록할 도서의 출판사: ", new_book[n].publisher);
	printf("신규 등록할 도서의 번호: ");
	scanf("%d", &new_book[n].number);
	ClearInputBuffer();
	new_book[n].borrowed = 1;							//1 = 대출 가능, 0 = 대출 불가능

	printf("#신규 도서 등록 완료!\n");
	return 0;
}

int SearchBook(struct books* new_book) {
	int i = 0;
	int user_input, found_sucess = 0;
	char user_search[MAX_CHAR];
	printf("수행할 작업을 선택하시오.\n"
		"1. 도서 이름으로 검색.\n"
		"2. 저자 이름으로 검색.\n"
		"3. 출판사 이름으로 검색.\n"
		"4. 도서 번호로 검색.\n"
		"어떤 방법으로 검색하시겠습니까?.\n");
	scanf("%d", &user_input);
	ClearInputBuffer();

	printf("검색어를 입력해주세요.\n");
	//도서 이름, 저자, 출판사의 크기가 '\0'포함해서 최대 31이므로, '\0' 전까지 입력받는 scanf에서는 30까지 크기를 제한한다
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
		printf("잘못된 입력입니다.\n");
		return 0;
	}

	if (found_sucess == 1) {
		printf("검색 결과, 찾으시는 도서는 다음과 같습니다.\n"
			"**도서 이름: %s\n"
			"**도서 저자: %s\n"
			"**출판사:    %s\n"
			"**도서 번호: %d\n"
			"**도서 대출 가능 여부: %s\n",
			new_book[i].name,
			new_book[i].author,
			new_book[i].publisher,
			new_book[i].number,
			//삼항연산자 ?:
			//(조건) ? (조건이 참일 때) : (조건이 거짓일 때)
			new_book[i].borrowed ? "가능" : "불가능");
		return 0;
	}
	printf("찾으시는 도서가 없습니다.");
	return 0;
}

int BorrowBook(struct books* new_book) {
	int i, book_number = 0;
	printf("대출할 도서의 번호를 입력하시오.\n");
	printf("도서 번호: ");
	scanf("%d", &book_number);
	ClearInputBuffer();

	//책의 번호는 1부터 100(MAX_BOOKS)까지 존재할 것이기 때문에 아래와 같이 if문의 범위를 설정해준다.
	if (book_number < 1 || book_number > MAX_BOOKS) {
		printf("유효하지 않은 도서 번호입니다.\n");
		return 0;
	}

	for (i = 0; i < MAX_BOOKS; i++) {
		if (new_book[i].number == book_number) {
			if (new_book[i].borrowed == 0)
				printf("이미 대출 중인 도서입니다.\n");
			else {
				printf("도서 대출을 완료했습니다.\n");
				new_book[i].borrowed = 0;
			}
		}
	}

	return 0;
}

int ReturnBook(struct books* new_book) {
	int i, book_number = 0;
	printf("반납할 도서의 번호를 입력하시오.\n");
	printf("도서 번호: ");
	scanf("%d", &book_number);
	ClearInputBuffer();

	//책의 번호는 1부터 100(MAX_BOOKS)까지 존재할 것이기 때문에 아래와 같이 if문의 범위를 설정해준다.
	if (book_number <= 0 || book_number > MAX_BOOKS) {
		printf("유효하지 않은 도서 번호입니다.\n");
		return 0;
	}

	for (i = 0; i < MAX_BOOKS; i++) {
		if (new_book[i].number == book_number) {
			if (new_book[i].borrowed == 0) {
				printf("도서 반납을 완료했습니다.\n");
				new_book[i].borrowed = 1;
			}
			else
				printf("이미 반납이 완료되었습니다.\n");
		}
	}
	return 0;
}

//scanf이후에 남아있는 버퍼를 없애는 용도의 함수
/*
*getchar는 정수형으로 반환된다.
*반환된 값을 정수형 변수 c에, c가 '\n'의 값을 갖거나 EOF에 드러맞을 때까지 getchar를 대입한다.
*/
void ClearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void SetStringData(const char* info_string, char* string_data) {
	while (1) {
		printf("%s", info_string);
		//30자로 제한해서 입력받는다.
		if (scanf("%30[^\n]", string_data) == 1) {
			//이후 남아있는 모든 버퍼를 제거한다.
			ClearInputBuffer();
			break;
		}
		else {
			//이미 입력이 잘못됐으므로, 기존의 버퍼를 모두 제거한 이후에 다시 반복해준다.
			ClearInputBuffer();
			printf("잘못된 입력입니다.\n");
		}
	}
}