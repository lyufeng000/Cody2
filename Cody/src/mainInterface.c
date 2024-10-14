#include "../head/mainInterface.h"



void interface() {
	while (1) {
		printf("*******************************\n");
		printf("1.添加学生信息\t2.显示学生信息\n3.查询学生信息\t4.排序学生信息\n5.删除学生信息\t6.修改学生信息\n7.统计学生信息\t8.退出系统\n");
		printf("*******************************\n");
		printf("请选择:");
		char choice;
		fflush(stdin);
		scanf("%c", &choice);
		fflush(stdin);//清空输入区缓存
		switch (choice) {
			case '1':
				add();
				break;
			case '2':
				showAll();
				break;
			case '3':
				search();
				break;
			case '4':
				face();
				break;
			case '5':
				howToDelete();
				break;
			case '6':
				find();
				break;
			case '7':
				statistic();
				break;
			case '8':
				goto out;
			default:
				printf("输入有误\n");
				break;
		}
	}
	out:
}
