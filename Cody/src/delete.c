#include "../head/delete.h"

void howToDelete() {
	printf("1.按学号删除\n2.按姓名删除\n3.全部删除\n0.返回上一级\n");
	printf("请选择:");
	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			deleteByNum();
			break;
		case 2:
			deleteByName();
			break;
		case 3:
			deleteAll();
			break;
		case 0:
			return;
		default:
			printf("输入有误\n");
			break;
	}
}


void deleteByNum() {
	char num[13];
	printf("请输入学号:");
	scanf("%s", num);
	FILE *fp = fopen("student.txt", "r");
	FILE *fpTemp = fopen("temp.txt", "w");
	Student s;
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (strcmp(s.ID, num) != 0) {
			//除了目标都在temp里
			fwrite(&s, sizeof(Student), 1, fpTemp);
		}
	}
	fclose(fp);
	fclose(fpTemp);
	remove("student.txt");//移除student
	rename("temp.txt", "student.txt");//重命名temp
	printf("删除成功\n");
}

void deleteByName() {
	char name[20];
	printf("请输入姓名:");
	scanf("%s", name);
	FILE *fp = fopen("student.txt", "r");
	FILE *fpTemp = fopen("temp.txt", "w");
	Student s;
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (strcmp(s.name, name) != 0) {
			fwrite(&s, sizeof(Student), 1, fpTemp);
		}
	}
	fclose(fp);
	fclose(fpTemp);
	remove("student.txt");
	rename("temp.txt", "student.txt");
	printf("删除成功\n");
}

void deleteAll() {
	FILE *fp = fopen("student.txt", "w");
	fclose(fp);
	printf("删除成功\n");
}