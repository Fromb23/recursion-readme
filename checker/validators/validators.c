#include <stdio.h>
#include <string.h>
#include "../main/checker.h"
#include "validators.h"
#include "./hash/registry_hash.h"
#include "./hash/hash.h"

int dispatch_validation(Task *task, const char *filepath)
{
	ValidatorFn fn = get_validator(task->task_name);
	if (fn)
		return fn(filepath);
	else {
		fprintf(stderr, "No validator found for task: %s\n", task->task_name);
		return -1;
	}
}

int validate_task(Task *task, const char *filepath)
{
	int is_python, result;

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

	/*
	   if (check_plagiarism(filepath, task) != 0)
	   {
	   fprintf(stderr, "Plagiarism check failed for file: %s\n", filepath);
	   return 1;
	   }
	   */
	return result;
}
