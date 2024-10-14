#include "../head/search.h"

//C++的一个命名空间
using namespace std;

void search() {
    char input[20];
    printf("请输入学生信息:");
    //cin = scanf
    cin >> input;
    if (isNumber(input)) {
        searchById(input);
    } else {
        searchByName(input);
    }
}

//boor 布尔类型，true，false
bool isNumber(const char x[20]) {
    //用一个char指针指向了参数数组，此时，指针指向数组开头
    for (const char *ch = x; *ch != '\0'; ch++) {
        if (*ch < '0' || *ch > '9') {
            return false; // 不是数字
        }
    }
    return true; // 所有字符都是数字
}


void searchById(char ID[12]) {
    FILE *fp = fopen("student.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return;
    }
    Student s;
    while (fread(&s,STUDENT_SIZE, 1, fp)) {
        if (strcmp(s.ID, ID) == 0) {
            showOne(s);
            fclose(fp);
            return;
        }
    }
    printf("没有学号为\"%s\"的学生\n", ID);
    fclose(fp);
    return;
}

void searchByName(char name[20]) {
    FILE *fp = fopen("student.txt","r");
    if (!fp) {
        printf("文件打开失败");
        return;
    }
    Student s;
    while (fread(&s,STUDENT_SIZE,1,fp)) {
        if (strcmp(s.name,name) == 0) {
            showOne(s);
            fclose(fp);
            return;
        }
    }
    printf("没有名为\"%s\"的学生\n",name);
    return;
}
