#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int new_wage = 9860;
	int old_wage = 9620;
	int which_wage, hourly_wage, time, income;
	printf("�ñ��� �������� ������ִ� ���α׷��Դϴ�.\n");
	printf("�ű� �����ӱ�����, ���� �����ӱ����� �Է��Ͻÿ�.\n");
	printf("��) �ű� = 1, Ȥ�� ���� = 2\n");
	scanf("%d", &which_wage);

	if (which_wage == 1) {
		hourly_wage = new_wage;
	}
	else {
		hourly_wage = old_wage;
	}

	printf("�� �ð��� ���ߴ��� �Է��Ͻÿ�.\n");
	scanf("%d", &time);
	income = hourly_wage * time;
	printf("�̹� �޿� �޾ƾ� �� �ݾ��� %d�Դϴ�.", income);

	return 0;
}