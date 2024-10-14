#include "../head/add.h"
#include <string.h>

void add() {
    int studentNum;
    printf("请输入要添加的学生数量:");
    scanf("%d", &studentNum);
    for (int i = 0; i < studentNum; ++i) {
        Student s;
        //姓名，学号，性别，年龄，计算机网络成绩，数据结构成绩，高数成绩，平局成绩
        printf("请输入学生姓名:");
        scanf("%s", s.name);
        printf("请输入学生学号:(12位)");
        scanf("%s", s.ID);
        int len = strlen(s.ID);
        while (len != 12){
            printf("长度：%d",len);
            printf("学号有误，请重新输入:");
            scanf("%s",s.ID);
            len = strlen(s.ID);//......
        }
        printf("请输入学生性别:");
        scanf("%s", s.gender);
        printf("请输入学生年龄:");
        scanf("%d", &s.age);
        printf("请输入学生计算机网络成绩:");
        scanf("%lf", &s.score1);
        printf("请输入学生数据结构成绩:");
        scanf("%lf", &s.score2);
        printf("请输入学生高数成绩:");
        scanf("%lf", &s.score3);
        s.average = (s.score1 + s.score2 + s.score3) / 3;
        //至此，数据保存在了s中
        showOne(s);
        printf("确定要保存吗?(Y/N)");
        char ch;
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'n' || ch == 'N') {
            i--;
            continue;
        }
        //认为要保存
        if (save(s)) {
            printf("添加成功\n");
        }
    }
}

_Bool save(Student s) {
    //打开文件
    FILE *fp = fopen("student.txt", "a+");

    //fp == null 确定指针有没有正确指向文件
    if (fp == NULL) {
        printf("目标文件不存在\n");
        fclose(fp);
        return 0;
    }

    //FILE 自己提供的错误处理
    if (ferror(fp)) {
        printf("文件处理出错，请重试\n");
        clearerr(fp);//清理错误信息
        fclose(fp);
        return 0;
    }

    fwrite(&s,STUDENT_SIZE, 1, fp);
    fclose(fp);
    return 1;
}


/*
void saveAll(const Student *s) {
    int i = 0;
    FILE *fp = fopen("student.txt", "a+");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return;
    }
    while (fwrite(&s[i], sizeof(Student), 1, fp)) {
        i++;
    }
}
*/
