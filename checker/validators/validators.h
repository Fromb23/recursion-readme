#ifndef VALIDATORS_H
#define VALIDATORS_H

#include "../main/checker.h"
#include "linters/linters.h"

int validate_task(Task *task, const char *filepath);
int validate_recursion_file(const char *filepath);
int validate_factorial_file(const char *filepath);

#endif
