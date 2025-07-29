#include "typewriter/typewriter.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checker.h"

int main(void)
{
	const char *repo_url = "https://github.com/Fromb23/recursion-readme.git";
	const char *target_dir = "cloned_repo";
	Task tasks[MAX_TASKS];
	int task_count = 0, clone_result, i;
	char main_script_path[1024];
	char msg[512];

	memset(tasks, 0, sizeof(tasks));

	typewrite("Starting Checker...\n", 30000);

	if (access(target_dir, F_OK) != 0)
	{
		typewrite("Cloning repository...\n", 30000);
		clone_result = clone_repo(repo_url, target_dir);
		if (clone_result != 0)
		{
			fprintf(stderr, "Failed to clone the repository.\n");
			return 1;
		}
		printf("Repository cloned successfully into '%s'\n", target_dir);
	}
	else
	{
		snprintf(msg, sizeof(msg), "Repository already exists at '%s', skipping clone.\n", target_dir);
		typewrite(msg, 25000);
	}

	typewrite("Loading tasks...\n", 30000);
	if (load_tasks("tasks.json", tasks, &task_count) != 0)
	{
		fprintf(stderr, "Failed to load tasks from JSON.\n");
		return 1;
	}

	for (i = 0; i < task_count; i++)
	{
		const char *name = tasks[i].task_name ? tasks[i].task_name : "Unnamed";

		printf("\n");
		typewrite("----------------------\n ", 30000);
		typewrite("Checking task: ", 30000);
		typewrite(name, 30000);
		printf("\n");

		printf("Path: %s\n", tasks[i].expected_path);
		printf("Target: %s\n", tasks[i].target_file);
		printf("Main file: %s\n", tasks[i].main_file);

		if (!check_task_files(&tasks[i]))
		{
			fprintf(stderr, "One or more required files are missing for task '%s'.\n", name);
			continue;
		}

		snprintf(main_script_path, sizeof(main_script_path), "%s/%s",
				tasks[i].expected_path, tasks[i].target_file);
		if (validate_recursion_file(main_script_path) != 0)
		{
			fprintf(stderr, "Validation recursion function failed for %s\n", main_script_path);
			continue;
		}

		snprintf(main_script_path, sizeof(main_script_path), "%s/%s",
				tasks[i].expected_path, tasks[i].main_file);

		if (tasks[i].expected_output)
		{
			if (check_output(main_script_path, tasks[i].expected_output) != 0)
			{
				fprintf(stderr, "Main output check failed for task '%s'.\n", name);
			}
		}
		else
		{
			fprintf(stderr, "Missing expected output for task '%s'\n", name);
		}
	}

	typewrite("\nChecker finished.\n", 30000);
	return 0;
}
