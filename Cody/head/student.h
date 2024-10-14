#ifndef CODY_STUDENT_H
#define CODY_STUDENT_H

#include <stdio.h>
#define STUDENT_SIZE sizeof(Student)

typedef struct {
	char name[20];
	char ID[13];
	char gender[3];
	int age;
	double score1;
	double score2;
	double score3;
	double average;
}Student;

#endif //CODY_STUDENT_H
