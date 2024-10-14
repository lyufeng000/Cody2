#include "../head/show.h"

void showAll() {
	FILE *fp = fopen("student.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return;
	}
	Student s;
	while (fread(&s, STUDENT_SIZE, 1, fp)) {
		showOne(s);
	}
	fclose(fp);
}

void showOne(Student student) {
	printf("=============================\n");
	printf("姓名:%s\n", student.name);
	printf("学号:%s\n", student.ID);
	printf("性别:%s\n", student.gender);
	printf("年龄:%d\n", student.age);
	printf("计算机网络成绩:%.2lf\n", student.score1);
	printf("数据结构成绩:%.2lf\n", student.score2);
	printf("高数成绩:%.2lf\n", student.score3);
	printf("平均成绩:%.2lf\n", student.average);
	printf("=============================\n");
}

int length() {
	FILE *fp = fopen("student.txt", "r");
	int count = 0;
	Student s;
	while (fread(&s, sizeof(Student), 1, fp)) {
		count++;
	}
	fclose(fp);
	return count;
}