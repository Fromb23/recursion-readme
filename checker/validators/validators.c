#include <string.h>
#include <stdio.h>
#include "../checker.h"
#include "validators.h"

int validate_task(Task *task, const char *filepath)
{
	if (strcmp(task->task_name, "recursion") == 0)
		return validate_recursion_file(filepath);

	else if (strcmp(task->task_name, "factorial") == 0)
		return validate_factorial_file(filepath);

	fprintf(stderr, "No validator defined for task: %s\n", task->task_name);
	return 1;
}
