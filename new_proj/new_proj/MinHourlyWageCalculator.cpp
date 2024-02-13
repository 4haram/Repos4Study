#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int new_wage = 9860;
	int old_wage = 9620;
	int which_wage, hourly_wage, time, income;
	printf("시급을 월급으로 계산해주는 프로그램입니다.\n");
	printf("신규 최저임금인지, 기존 최저임금인지 입력하시오.\n");
	printf("예) 신규 = 1, 혹은 기존 = 2\n");
	scanf("%d", &which_wage);

	if (which_wage == 1) {
		hourly_wage = new_wage;
	}
	else {
		hourly_wage = old_wage;
	}

	printf("몇 시간을 일했는지 입력하시오.\n");
	scanf("%d", &time);
	income = hourly_wage * time;
	printf("이번 달에 받아야 할 금액은 %d입니다.", income);

	return 0;
}