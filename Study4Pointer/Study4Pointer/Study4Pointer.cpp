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
		printf("학생의 이름을 입력하세요.\n");
		scanf("%19s", name[i]);
		printf("%s 학생의 국어, 영어, 수학 성적을 입력하세요.\n", name[i]);

		int want_break = 0;
		while (!want_break) {
			if (scanf("%d" "%d" "%d", &grade[i][0], &grade[i][1], &grade[i][2]) != 3 || /*
				*/grade[i][0] < 0 || grade[i][0] > 100 || /*
				*/grade[i][1] < 0 || grade[i][1] > 100 || /*
				*/grade[i][2] < 0 || grade[i][2] > 100) {
				printf("올바르지 않은 입력입니다. 국어, 영어, 수학 성적을 0에서 100 사이의 정수로 다시 입력하세요.\n");
				while (getchar() != '\n');
			}
			else {
				want_break = 1;
			}
		}
		getAverage(grade, average, i + 1);
		printf("%s 학생의 평균은 %.2f입니다.\n", name[i], average[i]);
	}

	sortData(average, tiers, STUDENTS);
	for (int i = 0; i < STUDENTS; i++) {
		class_average += average[i];
	}
	class_average = class_average / STUDENTS;
	printf("반의 평균 성적은 %.2f입니다.\n", class_average);

	printf("평균 성적이 높은 학생부터 낮은 학생 순으로 나열하겠습니다.\n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s의 평균: %.2f\t", name[tiers[i]], average[tiers[i]]);
		if (average[i] >= class_average) {
			printf("합격\n");
		}
		else {
			printf("불합격\n");
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