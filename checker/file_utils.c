#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "checker.h"
#include "typewriter/typewriter.h"

int check_task_files(Task *task)
{
	struct stat st;
	int i;
	char filepath[1024];
	char msg[1024];

	if (stat(task->expected_path, &st) != 0 || !S_ISDIR(st.st_mode))
	{
		fprintf(stderr, "Directory not found: %s\n", task->expected_path);
		return 0;
	}

	for (i = 0; i < task->file_count; i++)
	{
		snprintf(filepath, sizeof(filepath), "%s/%s", task->expected_path, task->expected_files[i]);
		if (stat(filepath, &st) != 0)
		{
			fprintf(stderr, "Missing file: %s\n", filepath);
			return 0;
		}
	}

	snprintf(msg, sizeof(msg), "All expected files found in %s\n", task->expected_path);
	typewrite(msg, 20000);
	return 1;
}
