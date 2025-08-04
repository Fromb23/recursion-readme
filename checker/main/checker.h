#ifndef CHECKER_H
#define CHECKER_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#define MAX_FILES 10
#define MAX_TASKS 100
#define MAX_TASK_NAMES 20

#define LOG_PATH "logs/hashes.log"

typedef enum {
    SUCCESS = 0,
    FAILED  = 1,
    ERROR   = 2
} ValidationStatus;

typedef struct {
	char *task_name;
	char *expected_path;
	char *main_file;
	char *target_file;
	char *expected_output;
	char *expected_files[10];
	int file_count;
	char *username;
} Task;

char *lstrip(char *str);
int filter_tasks(Task *tasks, int task_count, const char *filter_names,
                 Task *filtered, int *filtered_count);

#endif
