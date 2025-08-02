#include <stdio.h>
#include <string.h>
#include "../main/checker.h"
#include "validators.h"

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

	if (strcmp(task->task_name, "recursion") == 0)
		result = validate_recursion_file(filepath);
	else if (strcmp(task->task_name, "factorial") == 0)
		result = validate_factorial_file(filepath);
	else {
		fprintf(stderr, "No validator defined for task: %s\n", task->task_name);
		return 1;
	}
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

