#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "checker.h"

/**
 * filter_tasks - Filters tasks based on a comma-separated list of names.
 * @tasks: Full list of tasks loaded from JSON
 * @task_count: Total number of tasks in the list
 * @filter_names: Comma-separated string of task names (e.g. "recursion,factorial")
 * @filtered: Output array for filtered tasks
 * @filtered_count: Pointer to store how many tasks matched
 *
 * Return: 0 on success, -1 if none matched
 */
int filter_tasks(Task *tasks, int task_count, const char *filter_names,
		Task *filtered, int *filtered_count)
{
	char names_copy[256];
	char *token;
	int i, j = 0;

	strncpy(names_copy, filter_names, sizeof(names_copy) - 1);
	names_copy[sizeof(names_copy) - 1] = '\0';

	token = strtok(names_copy, ",");

	while (token)
	{
		for (i = 0; i < task_count; i++)
		{
			if (strcmp(tasks[i].task_name, token) == 0)
			{
				filtered[j++] = tasks[i];
				break;
			}
		}
		token = strtok(NULL, ",");
	}

	*filtered_count = j;
	return j > 0 ? 0 : -1;
}
