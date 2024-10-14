#include "../head/sort.h"
#include <stdlib.h>

void face() {
	printf("1.按学号升序\n2.按学号降序\n");
	printf("3.按平均分升序\n4.按平均分降序\n");
	printf("请选择:");
	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			sortByNumAsc();
			break;
		case 2:
			sortByNumDesc();
			break;
		case 3:
			sortByScoreAsc();
			break;
		case 4:
			sortByScoreDesc();
			break;
		default:
			printf("输入有误\n");
			break;
	}
}

void sortByNumAsc() {
	int i = 0;
	FILE *fp = fopen("student.txt", "r");
	Student *s = malloc(length() * STUDENT_SIZE);
	Student temp;
	while (fread(&s[i], sizeof(Student), 1, fp)) {
		i++;
	}
	int ID1;
	int ID2;
	//冒泡排序
	for (int j = 0; j < length(); j++) {
		for (int k = 0; k < length() - 1; k++) {
			ID1 = atoi(s[k].ID);
			ID2 = atoi(s[k + 1].ID);
			if (ID1 > ID2) {
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	}
	for (int j = 0; j < length(); j++) {
		showOne(s[j]);
	}
	//动态分配的内存不会自己消失，要手动释放
	free(s);
}

void sortByNumDesc() {
	int i = 0;
	FILE *fp = fopen("student.txt", "r");
	Student *s = malloc(length() * STUDENT_SIZE);
	Student temp;
	while (fread(&s[i], sizeof(Student), 1, fp)) {
		i++;
	}
	int ID1;
	int ID2;
	for (int j = 0; j < length(); j++) {
		for (int k = 0; k < length() - 1; k++) {
			ID1 = atoi(s[k].ID);
			ID2 = atoi(s[k + 1].ID);
			if (ID1 < ID2) {
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	}
	for (int j = 0; j < length(); j++) {
		showOne(s[j]);
	}
	free(s);
}

void sortByScoreAsc() {
	int i = 0;
	FILE *fp = fopen("student.txt", "r");
	Student *s = malloc(length() * STUDENT_SIZE);
	Student temp;
	while (fread(&s[i], sizeof(Student), 1, fp)) {
		i++;
	}
	float score1;
	float score2;
	for (int j = 0; j < length(); j++) {
		for (int k = 0; k < length() - 1; k++) {
			score1 = s[k].average;
			score2 = s[k + 1].average;
			if (score1 > score2) {
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	}
	for (int j = 0; j < length(); j++) {
		showOne(s[j]);
	}
	free(s);
}

void sortByScoreDesc() {
	int i = 0;
	FILE *fp = fopen("student.txt", "r");
	Student *s = malloc(length() * STUDENT_SIZE);
	Student temp;
	while (fread(&s[i], sizeof(Student), 1, fp)) {
		i++;
	}
	float score1;
	float score2;
	for (int j = 0; j < length(); j++) {
		for (int k = 0; k < length() - 1; k++) {
			score1 = s[k].average;
			score2 = s[k + 1].average;
			if (score1 < score2) {
				temp = s[k];
				s[k] = s[k + 1];
				s[k + 1] = temp;
			}
		}
	}
	for (int j = 0; j < length(); j++) {
		showOne(s[j]);
	}
	free(s);
}