#include "../head/modify.h"

void find() {
	printf("请输入要修改的学生学号:");
	char num[20];
	scanf("%s", num);
	FILE *fp = fopen("student.txt", "r");
	int count = 0;//当索引用
	Student s;
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (strcmp(s.ID, num) == 0) {
			fclose(fp);
			count++;
			//count指向了 目标 在文件里的位置
			revise(s, count);//参数传递
			break;
		}
	}
}

void revise(Student s, int index) {
	int choice;
	FILE *fp = fopen("student.txt", "r+");
	fseek(fp, index * sizeof(Student), SEEK_SET);
	showOne(s);
	printf("===========================\n");
	printf("1.姓名\t2.学号\n3.性别\t4.年龄\n5.计算机网络成绩\n6.数据结构成绩\n7.高数成绩\n");
	printf("请选择要修改的信息:");
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("请输入新的姓名:");
			scanf("%s", s.name);
			break;
		case 2:
			printf("请输入新的学号:");
			scanf("%s", s.ID);
			break;
		case 3:
			printf("请输入新的性别:");
			scanf("%s", s.gender);
			break;
		case 4:
			printf("请输入新的年龄:");
			scanf("%d", &s.age);
			break;
		case 5:
			printf("请输入新的计算机网络成绩:");
			scanf("%lf", &s.score1);
			break;
		case 6:
			printf("请输入新的数据结构成绩:");
			scanf("%lf", &s.score2);
			break;
		case 7:
			printf("请输入新的高数成绩:");
			scanf("%lf", &s.score3);
			break;
		default:
			
			break;
	}
	s.average = (s.score1 + s.score2 + s.score3) / 3;
	/*fclose(fp);
	fp = fopen("student.txt", "r+");*/
	fwrite(&s, sizeof(Student), 1, fp);
	fclose(fp);
	printf("修改成功\n");
}