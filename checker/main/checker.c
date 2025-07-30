#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "checker.h"
#include "typewriter.h"
#include "../utils/utils.h"
#include "../validators/validators.h"

int main(int argc, char *argv[])
{
	const char *repo_url = NULL;
	const char *task_name = NULL;
	const char *target_dir = "cloned_repo";

	Task tasks[MAX_TASKS];
	int task_count = 0;
	int found_task = 0;
	int clone_result = 0;
	int i;

	char main_script_path[1024];
	char msg[512];

	/* Parse CLI arguments */
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

	typewrite(30000, "Starting Checker...\n");

	/* Clone repository if not already present */
	if (!is_valid_git_url(repo_url))
	{
		fprintf(stderr, "Error: Invalid Git repository URL: '%s'\n", repo_url);
		return 1; 
	}
	if (access(target_dir, F_OK) != 0)
	{
		typewrite(30000, "Cloning repository...\n");
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
		typewrite(25000, msg);
	}

	/* Load tasks from JSON */
	typewrite(30000, "Loading tasks...\n");

	if (load_tasks("tasks.json", tasks, &task_count) != 0)
	{
		fprintf(stderr, "Failed to load tasks from JSON.\n");
		return 1;
	}

	/* Search for target task */
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

	/* Begin checking task(s) */
	for (i = 0; i < task_count; i++)
	{
		const char *name = tasks[i].task_name ? tasks[i].task_name : "Unnamed";

		if (strcmp(task_name, name) != 0)
			continue;

		printf("\n");
		typewrite(30000, "----------------------\n");
		typewrite(30000, "Checking task: ");
		typewrite(30000, "%s\n", name);

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
			free_tasks(tasks, task_count);
			typewrite(25000, "Checker failed due to validation errors.\n");
			return 1;
		}

		snprintf(main_script_path, sizeof(main_script_path), "%s/%s",
				tasks[i].expected_path, tasks[i].main_file);

		if (tasks[i].expected_output)
		{
			if (check_output(main_script_path, tasks[i].expected_output) != 0)
			{
				fprintf(stderr, "Main output check failed for task '%s'.\n", name);
				free_tasks(tasks, task_count);
				typewrite(25000, "Checker failed due to output mismatch.\n");
				return 1;
			}
		}
		else
		{
			fprintf(stderr, "Missing expected output for task '%s'\n", name);
		}
	}

	free_tasks(tasks, task_count);
	typewrite(30000, "\nChecker completed successfully.\n");

	return 0;
}
