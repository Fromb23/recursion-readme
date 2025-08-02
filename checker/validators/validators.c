#include <stdio.h>
#include <string.h>
#include "../main/checker.h"
#include "validators.h"

extern int validate_recursion_file(const char *);
extern int validate_factorial_file(const char *);
extern int validate_fibonacci_file(const char *);

static TaskValidator validators[] = {
	{"recursion", validate_recursion_file},
	{"factorial", validate_factorial_file},
	/* {fibonacci, validate_fibonacci_file}, */
};

const int validator_count = sizeof(validators) / sizeof(validators[0]);


int dispatch_validation(Task *task, const char *filepath)
{
	int i;
	for (i = 0; i < validator_count; i++) {
		if (strcmp(task->task_name, validators[i].task_name) == 0) {
			return validators[i].validator(filepath);
		}
	}

	fprintf(stderr, "No validator defined for task: %s\n", task->task_name);
	return 1;
}

int validate_task(Task *task, const char *filepath)
{
	int is_python, result = 1;

	if (!check_readme(task->expected_path))
	{
		fprintf(stderr, "Missing or empty README.md in %s\n", task->expected_path);
		return 1;
	}

	is_python = is_python_file(task->target_file);

	if (is_python) {
		if (run_pycodestyle(filepath) != 0)
			return 1;
	} else {
		if (run_betty_linter(filepath) != 0)
			return 1;
	}

	result = dispatch_validation(task, filepath);

	if (result != 0)
		return 1;

	/*
	   if (check_plagiarism(filepath, task) != 0)
	   {
	   fprintf(stderr, "Plagiarism check failed for file: %s\n", filepath);
	   return 1;
	   }
	   */
	return 0;
}

