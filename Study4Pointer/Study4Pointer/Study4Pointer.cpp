#define _CRT_SECURE_NO_WARNINGS
#define STUDENTS 5
#include <stdio.h>

void getAverage(int(*arr)[3], float *results, int count);
void sortData(float* arr, int* arri, int count);

int main() {
	char name[STUDENTS][20];
	int grade[STUDENTS][3];

	float average[STUDENTS];
	float class_average = 0;
	int tiers[STUDENTS];

	int const perfectScore = 100;

	for (int i = 0; i < STUDENTS; i++) {
		printf("�л��� �̸��� �Է��ϼ���.\n");
		scanf("%19s", name[i]);
		printf("%s �л��� ����, ����, ���� ������ �Է��ϼ���.\n", name[i]);

		int want_break = 0;
		while (!want_break) {
			if (scanf("%d" "%d" "%d", &grade[i][0], &grade[i][1], &grade[i][2]) != 3 || /*
				*/grade[i][0] < 0 || grade[i][0] > 100 || /*
				*/grade[i][1] < 0 || grade[i][1] > 100 || /*
				*/grade[i][2] < 0 || grade[i][2] > 100) {
				printf("�ùٸ��� ���� �Է��Դϴ�. ����, ����, ���� ������ 0���� 100 ������ ������ �ٽ� �Է��ϼ���.\n");
				while (getchar() != '\n');
			}
			else {
				want_break = 1;
			}
		}
		getAverage(grade, average, i + 1);
		printf("%s �л��� ����� %.2f�Դϴ�.\n", name[i], average[i]);
	}

	sortData(average, tiers, STUDENTS);
	for (int i = 0; i < STUDENTS; i++) {
		class_average += average[i];
	}
	class_average = class_average / STUDENTS;
	printf("���� ��� ������ %.2f�Դϴ�.\n", class_average);

	printf("��� ������ ���� �л����� ���� �л� ������ �����ϰڽ��ϴ�.\n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s�� ���: %.2f\t", name[tiers[i]], average[tiers[i]]);
		if (average[i] >= class_average) {
			printf("�հ�\n");
		}
		else {
			printf("���հ�\n");
		}
	}
	return 0;
}

void getAverage(int (*arr)[3], float *results, int count) {
	for (int i = 0; i < count; i++) {
		int temp_int = 0;
		for (int j = 0; j < 3; j++) {
			temp_int += arr[i][j];
		}
		results[i] = (float)temp_int / 3.0;
	}
}

void sortData(float *arr, int *arri, int count) {
	for (int i = 0; i < count; i++) {
		arri[i] = i;
	}	
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				float temp_float = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp_float;

				int temp_int = arri[j];
				arri[j] = arri[j + 1];
				arri[j + 1] = temp_int;
			}
		}
	}
}