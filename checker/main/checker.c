#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "checker.h"
#include "typewriter.h"
#include "../logs/logs.h"
#include "../utils/utils.h"
#include "../validators/validators.h"

int main(int argc, char *argv[])
{
	const char *repo_url = NULL;
	char repo_dir[256];
	char *task_names[MAX_TASK_NAMES];
	char main_script_path[1024];
	char msg[512];
	char *token, *end, *username;
	int task_name_count = 0, result;
	int task_count = 0;
	int clone_result = 0;
	int i, j, t, match, any_failed = 0;
	const char *name;
	Task tasks[MAX_TASKS];

	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--task-name") == 0 && i + 1 < argc)
		{
			token = strtok(argv[++i], ",");
			while (token != NULL && task_name_count < MAX_TASK_NAMES)
			{
				while (isspace((unsigned char)*token)) token++;
				end = token + strlen(token) - 1;
				while (end > token && isspace((unsigned char)*end)) *end-- = '\0';
				task_names[task_name_count++] = token;
				token = strtok(NULL, ",");
			}
		}
		else if (strcmp(argv[i], "--repo") == 0 && i + 1 < argc)
		{
			repo_url = argv[++i];
		}
	}

	if (!repo_url || task_name_count == 0)
	{
		fprintf(stderr, "Usage: %s --task-name <name1,name2,...> --repo <url>\n", argv[0]);
		return 1;
	}

	for (t = 0; t < task_name_count; t++)
	{
		printf("Task to process: %s\n", task_names[t]);
	}

	/* Assign globals for utils access */
	g_task_names = task_names;
	g_task_name_count = task_name_count;

	memset(tasks, 0, sizeof(tasks));
	typewrite(30000, "Starting Checker...\n");

	if (!is_valid_git_url(repo_url))
	{
		fprintf(stderr, "Error: Invalid Git repository URL: '%s'\n", repo_url);
		return 1;
	}

	username = extract_username(repo_url);
	if (!username)
	{
		fprintf(stderr, "Could not extract GitHub username.\n");
		return 1;
	}
	snprintf(repo_dir, sizeof(repo_dir), "cloned_repo_%s", username);
	if (access(repo_dir, F_OK) != 0)
	{
		typewrite(30000, "Cloning repository...\n");
		clone_result = clone_repo(repo_url, "cloned_repo");
		if (clone_result != 0)
		{
			fprintf(stderr, "Failed to clone the repository.\n");
			free(username);
			return 1;
		}
		printf("Repository cloned successfully into 'cloned_repo'\n");
		log_clone_time(username, repo_dir);

		typewrite(100000, "Renaming repository....\n");
		if (rename_repo("cloned_repo", repo_dir) != 0)
		{
			perror("Rename failed");
			free(username);
			return 1;
		}
	}
	else
	{
		snprintf(msg, sizeof(msg), "Repository already exists at '%s', updating....\n", repo_dir);
		typewrite(25000, msg);
		result = update_repo(repo_dir);
		if (result != 0)
		{
			fprintf(stderr, "Failed to update the repository.\n");
			return 1;
		}
		typewrite(3000, "Repository updated successfully...\n");
		printf("\n");
		printf("..............\n");
		printf("\n");
	}
	free(username);

	typewrite(30000, "Loading tasks...\n");

	if (load_tasks("json_tasks", repo_dir, tasks, &task_count) != 0)
	{
		fprintf(stderr, "Failed to load tasks from JSON.\n");
		return 1;
	}

	for (t = 0; t < task_name_count; t++)
	{
		int found = 0;
		for (i = 0; i < task_count; i++)
		{
			if (strcmp(task_names[t], tasks[i].task_name) == 0)
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "Warning: Task '%s' not found in tasks.json.\n", task_names[t]);
		}
	}

	for (i = 0; i < task_count; i++)
	{
		name = tasks[i].task_name ? tasks[i].task_name : "Unnamed";
		match = 0;
		for (j = 0; j < task_name_count; j++)
		{
			if (strcmp(task_names[j], name) == 0)
			{
				match = 1;
				break;
			}
		}
		if (!match)
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

		snprintf(main_script_path, sizeof(main_script_path), "%s/%s", tasks[i].expected_path, tasks[i].target_file);
		if (validate_task(&tasks[i], main_script_path) != 0)
		{
			fprintf(stderr, "Validation failed for %s\n", main_script_path);
			typewrite(25000, "Checker failed due to validation errors.\n");
			any_failed = 1;
			continue;
		}

		snprintf(main_script_path, sizeof(main_script_path), "%s/%s", tasks[i].expected_path, tasks[i].main_file);
		if (tasks[i].expected_output)
		{
			if (check_output(main_script_path, tasks[i].expected_output) != 0)
			{
				fprintf(stderr, "Main output check failed for task '%s'.\n", name);
				typewrite(25000, "Checker failed due to output mismatch.\n");
				any_failed = 1;
				continue;
			}
		}
		else
		{
			fprintf(stderr, "Missing expected output for task '%s'\n", name);
		}
	}

	free_tasks(tasks, task_count);
	if (!any_failed)
		typewrite(30000, "\nChecker completed successfully.\n");
	else
		typewrite(30000, "\nChecker completed with some failures.\n");

	return any_failed;
}
