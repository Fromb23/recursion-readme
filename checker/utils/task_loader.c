#include "utils.h"
#include <json-c/json.h>
#include "../typewriter/typewriter.h"

int load_tasks(const char *json_file, Task *tasks, int *task_count)
{
	FILE *fp;
	long length;
	char *data;
	struct json_object *parsed;
	int i;
	int count;
	struct json_object *obj;
	struct json_object *name_obj;
	struct json_object *path_obj;
	struct json_object *main_obj;
	struct json_object *target_obj;
	struct json_object *expected_obj;
	const char *name;
	const char *path;
	const char *main;
	const char *target;
	const char *expected;
	char msg[512];

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

		tasks[i].task_name = strdup(name);
		tasks[i].expected_path = strdup(path);
		tasks[i].main_file = strdup(main);
		tasks[i].target_file = strdup(target);
		tasks[i].expected_output = strdup(expected);

		tasks[i].expected_files[0] = strdup("__init__.py");
		tasks[i].expected_files[1] = strdup(tasks[i].main_file);
		tasks[i].expected_files[2] = strdup(tasks[i].target_file);
		tasks[i].file_count = 3;

		snprintf(msg, sizeof(msg), "Loaded Task %d: name=%s path=%s target=%s\n",
				i + 1, tasks[i].task_name, tasks[i].expected_path, tasks[i].target_file);
		typewrite(20000, "%s", msg);
	}

	*task_count = count;
	free(data);
	return 0;
}
