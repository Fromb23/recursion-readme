#include "utils.h"
#include "../typewriter/typewriter.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 

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
	typewrite(20000, "%s", msg);
	return 1;
}
