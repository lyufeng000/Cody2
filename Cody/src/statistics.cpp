#include "../head/statistics.h"

void statistic() {
    //每门课程的总分，平均分，最高分，最低分，各分段人数
    FILE *fp = fopen("student.txt", "r");
    int i = 0;
    Student *s = new Student[STUDENT_SIZE * length()];
    while (fread(&s[i],STUDENT_SIZE, 1, fp)) {
        i++;
    }
    fclose(fp);
    process1(s);
    std::cout << "=========================" << std::endl;
    process2(s);
    std::cout << "=========================" << std::endl;
    process3(s);
    std::cout << "=========================" << std::endl;
    delete[] s;
}

void display(const long sum, const long ave, const long max, const long min) {
    printf("科目总分:%ld\n", sum);
    printf("科目平均分:%ld\n", ave);
    printf("最高分:%ld\n", max);
    printf("最低分:%ld\n", min);
    return;
}

void process1(const Student *s) {
    long sum = 0;
    long ave;
    long max = s[0].score1;
    long min = s[0].score1;
    for (int i = 0; i < length(); ++i) {
        sum = sum + s[i].score1;
        if (s[i].score1 > max) {
            max = s[i].score1;
        }
        if (s[i].score1 < min) {
            min = s[i].score1;
        }
    }
    ave = sum / length();
    std::cout << "计算机网络成绩统计:" << std::endl;
    display(sum, ave, max, min);
}

void process2(const Student *s) {
    long sum = 0;
    long ave;
    long max = s[0].score2;
    long min = s[0].score2;
    for (int i = 0; i < length(); ++i) {
        sum = sum + s[i].score2;
        if (s[i].score2 > max) {
            max = s[i].score2;
        }
        if (s[i].score2 < min) {
            min = s[i].score2;
        }
    }
    ave = sum / length();
    std::cout << "数据结构成绩统计:" << std::endl;
    display(sum, ave, max, min);
}

void process3(const Student *s) {
    long sum = 0;
    long ave;
    long max = s[0].score3;
    long min = s[0].score3;
    for (int i = 0; i < length(); ++i) {
        sum = sum + s[i].score3;
        if (s[i].score3 > max) {
            max = s[i].score3;
        }
        if (s[i].score3 < min) {
            min = s[i].score3;
        }
    }
    ave = sum / length();
    std::cout << "高数成绩统计:" << std::endl;
    display(sum, ave, max, min);
}