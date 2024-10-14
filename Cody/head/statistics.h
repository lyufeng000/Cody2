#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"
#include "show.h"

#ifdef __cplusplus
#include <iostream>

extern "C" {
#endif


void display(long sum, long ave, long max, long min);

void statistic();

void process1(const Student *s);

void process2(const Student *s);

void process3(const Student *s);


#ifdef __cplusplus
}
#endif


#endif //STATISTICS_H
