#include "validators/validators.h"
#include "typewriter.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checker.h"

int main(int argc, char *argv[])
{
	const char *repo_url;
	const char *task_name;
	const char *target_dir;
	Task tasks[MAX_TASKS];
	int task_count, found_task = 0;
	int clone_result;
	int i;
	char main_script_path[1024];
	char msg[512];

	repo_url = NULL;
	task_name = NULL;
	target_dir = "cloned_repo";
	task_count = 0;

	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--task-name") == 0 && i + 1 < argc)
			task_name = argv[++i];
		else if (strcmp(argv[i], "--repo") == 0 && i + 1 < argc)
			repo_url = argv[++i];
	}

	if (!repo_url || !task_name)
	{
		fprintf(stderr, "Usage: %s --task-name <name> --repo <url>\n", argv[0]);
		return 1;
	}

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
		if (strcmp(tasks[i].task_name, task_name) == 0)
		{
			found_task = 1;
			break;
		}
	}

	if (!found_task)
	{
		fprintf(stderr, "Error: Task '%s' not found in tasks.json\n", task_name);
		return 1;
	}


	for (i = 0; i < task_count; i++)
	{
		const char *name = tasks[i].task_name ? tasks[i].task_name : "Unnamed";

		if (strcmp(task_name, name) != 0)
			continue;

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

		if (validate_task(&tasks[i], main_script_path) != 0)
		{
			fprintf(stderr, "Validation failed for %s\n", main_script_path);
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

	free_tasks(tasks, task_count);
	typewrite("\nChecker finished.\n", 30000);
	return 0;
}
