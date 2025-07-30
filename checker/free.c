#include <stdlib.h>
#include "checker.h"

void free_tasks(Task *tasks, int count) {
	int i, j;
	for (i = 0; i < count; i++) {
		free(tasks[i].task_name);
		free(tasks[i].expected_path);
		free(tasks[i].main_file);
		free(tasks[i].target_file);
		free(tasks[i].expected_output);
		for (j = 0; j < tasks[i].file_count; j++) {
			free(tasks[i].expected_files[j]);
		}
	}
}
