#ifndef CHECKER_H
#define CHECKER_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#define MAX_FILES 10
#define MAX_TASKS 100

typedef struct {
	char *task_name;
	char *expected_path;
	char *main_file;
	char *target_file;
	char *expected_output;
	char *expected_files[10];
	int file_count;
} Task;

char *lstrip(char *str);

#endif
