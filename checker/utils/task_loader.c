#include "utils.h"
#include <json-c/json.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../typewriter/typewriter.h"

/* External global task names and count declared in main */
char **g_task_names;
int g_task_name_count;

int load_tasks(const char *json_file, const char *repo_dir, Task *tasks, int *task_count)
{
	FILE *fp;
	long length;
	char *data;
	struct json_object *parsed;
	int i, j;
	int count;
	int loaded_count;
	struct json_object *obj;
	struct json_object *name_obj;
	struct json_object *path_obj;
	struct json_object *main_obj;
	struct json_object *target_obj;
	struct json_object *expected_obj;
	const char *name;
	char full_path[512];
	const char *path;
	const char *main;
	const char *target;
	const char *expected;
	char msg[512];
	int match;

	fp = fopen(json_file, "r");
	if (!fp)
	{
		fprintf(stderr, "Could not open JSON file: %s\n", json_file);
		return 1;
	}

	if (fseek(fp, 0, SEEK_END) != 0)
	{
		fprintf(stderr, "Failed to seek JSON file.\n");
		fclose(fp);
		return 1;
	}

	length = ftell(fp);
	if (length < 0)
	{
		fprintf(stderr, "Failed to get file length.\n");
		fclose(fp);
		return 1;
	}

	fseek(fp, 0, SEEK_SET);

	data = malloc(length + 1);
	if (!data)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		fclose(fp);
		return 1;
	}

	if (fread(data, 1, length, fp) != (size_t)length)
	{
		fprintf(stderr, "Failed to read JSON file.\n");
		free(data);
		fclose(fp);
		return 1;
	}
	data[length] = '\0';
	fclose(fp);

	parsed = json_tokener_parse(data);
	if (!parsed || !json_object_is_type(parsed, json_type_array))
	{
		fprintf(stderr, "Invalid JSON format.\n");
		free(data);
		return 1;
	}

	count = json_object_array_length(parsed);
	if (count > MAX_TASKS)
	{
		fprintf(stderr, "Warning: Only processing first %d of %d tasks.\n", MAX_TASKS, count);
		count = MAX_TASKS;
	}

	loaded_count = 0;
	for (i = 0; i < count; i++)
	{
		obj = json_object_array_get_idx(parsed, i);
		if (!json_object_object_get_ex(obj, "name", &name_obj) ||
				!json_object_object_get_ex(obj, "path", &path_obj) ||
				!json_object_object_get_ex(obj, "main", &main_obj) ||
				!json_object_object_get_ex(obj, "target", &target_obj) ||
				!json_object_object_get_ex(obj, "expected_output", &expected_obj))
		{
			fprintf(stderr, "Missing field(s) in task %d\n", i);
			continue;
		}

		name = json_object_get_string(name_obj);
		path = json_object_get_string(path_obj);
		main = json_object_get_string(main_obj);
		target = json_object_get_string(target_obj);
		expected = json_object_get_string(expected_obj);

		if (!name || !path || !main || !target || !expected)
		{
			fprintf(stderr, "Null value in string field(s) of task %d\n", i);
			continue;
		}

		match = 0;
		for (j = 0; j < g_task_name_count; j++)
		{
			if (strcmp(name, g_task_names[j]) == 0)
			{
				match = 1;
				break;
			}
		}

		if (!match)
			continue;
		snprintf(full_path, sizeof(full_path), "%s/%s", repo_dir, path);


		tasks[loaded_count].task_name = strdup(name);
		tasks[loaded_count].expected_path = strdup(full_path);
		tasks[loaded_count].main_file = strdup(main);
		tasks[loaded_count].target_file = strdup(target);
		tasks[loaded_count].expected_output = strdup(expected);

		tasks[loaded_count].expected_files[0] = strdup(tasks[loaded_count].main_file);
		tasks[loaded_count].expected_files[1] = strdup(tasks[loaded_count].target_file);
		tasks[loaded_count].file_count = 2;

		snprintf(msg, sizeof(msg), "Loaded Task %d: name=%s path=%s target=%s\n",
				loaded_count + 1, tasks[loaded_count].task_name,
				tasks[loaded_count].expected_path,
				tasks[loaded_count].target_file);
		typewrite(20000, "%s", msg);

		loaded_count++;
	}

	*task_count = loaded_count;
	free(data);
	json_object_put(parsed);
	return 0;
}
