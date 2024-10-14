#ifndef SEARCH_H
#define SEARCH_H

#include "student.h"
#include <stdbool.h>
#include "../head/show.h"


#ifdef __cplusplus
#include <iostream>

extern "C" {
#endif


void search();

bool isNumber(const char x[20]);

void searchById(char ID[12]);

void searchByName(char name[20]);

#ifdef __cplusplus
}
#endif

#endif //SEARCH_H
