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

int clone_repo(const char *url, const char *dest_folder);
int load_tasks(const char *json_file, Task *tasks, int *task_count);
int check_task_files(Task *task);
int validate_recursion_file(const char *filepath);
int check_output(const char *script_path, const char *expected_output);

#endif
