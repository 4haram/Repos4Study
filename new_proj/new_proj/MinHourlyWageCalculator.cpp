#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*Updated on February 17, 2024.*/
int main() {
	int new_wage = 9860;
	int old_wage = 9620;
	int which_wage, hourly_wage, time, income;
	printf("시급을 월급으로 계산해주는 프로그램입니다.\n");

	while (1) {
		printf("숫자로 어떤 최저임금으로 할 것인지 선택하시오.\n");
		printf("1: 신규 최저임금\n2: 기존 최저임금\n");
		scanf("%d", &which_wage);
		if (which_wage == 1 || which_wage == 2) {
			break;
		} else {
			printf("1과 2만 선택할 수 있습니다.\n다시 선택하시오.\n");
		}
	}

	if (which_wage == 1) {
		hourly_wage = new_wage;
	} else {
		hourly_wage = old_wage;
	}

	printf("몇 시간을 일했는지 입력하시오.\n");
	scanf("%d", &time);
	income = hourly_wage * time;
	printf("이번 달에 받아야 할 금액은 %d입니다.", income);

	return 0;
}