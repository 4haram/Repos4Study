#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*Updated on February 17, 2024.*/
int main() {
	int new_wage = 9860;
	int old_wage = 9620;
	int which_wage, hourly_wage, time, income;
	printf("�ñ��� �������� ������ִ� ���α׷��Դϴ�.\n");

	while (1) {
		printf("���ڷ� � �����ӱ����� �� ������ �����Ͻÿ�.\n");
		printf("1: �ű� �����ӱ�\n2: ���� �����ӱ�\n");
		scanf("%d", &which_wage);
		if (which_wage == 1 || which_wage == 2) {
			break;
		} else {
			printf("1�� 2�� ������ �� �ֽ��ϴ�.\n�ٽ� �����Ͻÿ�.\n");
		}
	}

	if (which_wage == 1) {
		hourly_wage = new_wage;
	} else {
		hourly_wage = old_wage;
	}

	printf("�� �ð��� ���ߴ��� �Է��Ͻÿ�.\n");
	scanf("%d", &time);
	income = hourly_wage * time;
	printf("�̹� �޿� �޾ƾ� �� �ݾ��� %d�Դϴ�.", income);

	return 0;
}